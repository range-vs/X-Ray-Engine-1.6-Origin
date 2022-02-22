#pragma once
//-
// ===========================================================================
// Copyright 2020 Autodesk, Inc. All rights reserved.
//
// Use of this software is subject to the terms of the Autodesk license
// agreement provided at the time of installation or download, or which
// otherwise accompanies this software in either electronic or hard copy form.
// ===========================================================================
//+
//
// CLASS:    MSharedPtr
//
// ****************************************************************************

#include <maya/SharedPtrBase.h>
#include <new>

OPENMAYA_MAJOR_NAMESPACE_OPEN

// ****************************************************************************
// CLASS DECLARATION (MSharedPtr)

//! \ingroup OpenMaya
//! \brief A reference counting pointer.
/*!
MSharedPtr is a smart pointer that retains ownership of an object through a pointer.
Several MSharedPtr objects may own the same object. The object is destroyed and its
memory deallocated when no MSharedPtr's exist which own the object.
*/

template<class T>
class MSharedPtr : public details::SharedPtrBase
{
public:
    using element_type = T;
    /*!
        \return the stored pointer.
    */
    T* get() const { return reinterpret_cast<T*>(ptr); }
    
    /*!
        \brief dereferences the stored pointer.
        \return the stored pointer.
    */
    T* operator->() const { return get(); }
    
    /*!
        \brief dereferences the stored pointer.
        
        MSharedPtr<void>::operator*() is unspecified and the behavior is undefined.
        
        \return T& of the stored pointer.
    */
    decltype(auto) operator*() const { return get_ref(get()); }
    
    /*!
        \brief checks if the stored pointer is not null
        \return true true if the stored pointer is not null
    */
    explicit operator bool() const { return ptr != nullptr; }

    // ****************************************************************************
    // Constructors

    /*!
        \brief construct an MSharedPtr with no managed object
    */
    constexpr MSharedPtr() noexcept {}

    /*!
        \brief construct an MSharedPtr with no managed object
        \param[in] _ptr a nullptr
    */
    constexpr MSharedPtr(std::nullptr_t _ptr) noexcept {}

    /*!
        \brief Constructs an MSharedPtr with _ptr as the managed object.

        U* must be a type which is convertible to T*.

        \param[in] _ptr A pointer to an object to manage.
    */
    template<class U, typename std::enable_if<std::is_convertible<U*,T*>::value, int>::type = 0> //SFINAE to ensure that we only generate functions when U converts to T
    explicit MSharedPtr(U* _ptr)
    : SharedPtrBase(allocWithPlacementNew<details::PtrAndControlBlock<U, details::DefaultDeleter<U>>>(_ptr, details::DefaultDeleter<U>()))
    {
        ptr = reinterpret_cast<void*>( const_cast<typename std::remove_const<T>::type*>( static_cast<T*>( reinterpret_cast<U*>(ptr) ) ) );
    }
    
    /*!
        \brief Constructs an MShared with _ptr as the managed object.

        Constructs an MSharedPtr with _ptr as the managed object. Deleter _d is used to delete
        the object. The expression _d(_ptr) must be well-formed, have well-defined behavior and
        not throw exceptions.

        U* must be a type which is convertible to T*.

        \param[in] _ptr A pointer to an object to manage.
        \param[in] _d A deleter object for _ptr.
    */
    template<class U, class Deleter, typename std::enable_if<std::is_convertible<U*,T*>::value, int>::type = 0>
    MSharedPtr(U* _ptr, Deleter _d)
    : SharedPtrBase(allocWithPlacementNew<details::PtrAndControlBlock<U, Deleter>>(_ptr, std::move(_d)))
    {
        ptr = reinterpret_cast<void*>( const_cast<typename std::remove_const<T>::type*>( static_cast<T*>( reinterpret_cast<U*>(ptr) ) ) );
    }

    /*!
        \brief Constructs an MSharedPtr with no managed object
        \param[in] _ptr A pointer to an object to manage.
        \param[in] _d A deleter object for _ptr.
    */
    template<class Deleter>
    MSharedPtr(std::nullptr_t _ptr, Deleter _d) {}

    /*!
        \brief Constructs an MShared with the same management as _rhs, but which stores _ptr.

        Create an MSharedPtr which shared ownership information with _rhs, but holds an unrelated,
        unmanaged pointer _ptr. It is the responsibility of the programmer to ensure that _ptr 
        remains valid as long as this shared_ptr exists.

        \param[in] _rhs An MSharedPtr to share ownership with.
        \param[in] _ptr A pointer to an object.
    */
    template<class U> // no SFINAE here intentionally! element_type does not need to be related to U
    MSharedPtr(const MSharedPtr<U>& _rhs, element_type* _ptr) noexcept
    {
        copy_assign(_rhs);
        ptr = _ptr;
    }

    /*!
        \brief Constructs an MSharedPtr which shares ownership with _rhs.
        \param[in] _rhs An MSharedPtr to share ownership with.
    */
    MSharedPtr(const MSharedPtr& _rhs) noexcept : SharedPtrBase() { copy_assign(_rhs); }

    /*!
        \brief Constructs an MSharedPtr which shares ownership with _rhs.

        U* must be a type which is convertible to T*.

        \param[in] _rhs An MSharedPtr to share ownership with, whose held type U* is convertible to T*.
    */
    template<class U, typename std::enable_if<std::is_convertible<U*,T*>::value, int>::type = 0>
    MSharedPtr(const MSharedPtr<U>& _rhs) noexcept : SharedPtrBase() {
        copy_assign(_rhs);
        ptr = reinterpret_cast<void*>( const_cast<typename std::remove_const<T>::type*>( static_cast<T*>( reinterpret_cast<U*>(ptr) ) ) );
    }

    /*!
        \brief Move-constructs an MSharedPtr from _rhs.

        After construction *this contains the original state of _rhs, and _rhs is empty and stores a nullptr.

        \param[in] _rhs An MSharedPtr whose state should move into *this.
    */
    MSharedPtr(MSharedPtr&& _rhs) noexcept : SharedPtrBase() { move_assign(std::move(_rhs)); }

    /*!
        \brief Move-constructs an MSharedPtr from _rhs.

        After construction *this contains the original state of _rhs, and _rhs is empty and stores a nullptr.
        U* must be a type which is convertible to T*.

        \param[in] _rhs An MSharedPtr to whose state should move into this, and whose held type U* is convertible to T*.
    */
    template<class U, typename std::enable_if<std::is_convertible<U*,T*>::value, int>::type = 0>
    MSharedPtr(MSharedPtr<U>&& _rhs) noexcept : SharedPtrBase() {
        move_assign(std::move(_rhs));    
        ptr = reinterpret_cast<void*>( const_cast<typename std::remove_const<T>::type*>( static_cast<T*>( reinterpret_cast<U*>(ptr) ) ) );
    }

    // ****************************************************************************
    // Assignment operators

    /*!
        \brief Replaces the managed object with the object managed by _rhs. Shares ownership with _rhs.
        \param[in] _rhs An MSharedPtr to share ownership with.
    */
    MSharedPtr& operator=(const MSharedPtr& _rhs) noexcept { copy_assign(_rhs); return *this;}
    
    /*!
        \brief Replaces the managed object with the object managed by _rhs. Shares ownership with _rhs.

        U* must be a type which is convertible to T*.

        \param[in] _rhs An MSharedPtr to share ownership with, whose held type U* is convertible to T*.
    */
    template<class U, typename std::enable_if<std::is_convertible<U*,T*>::value, int>::type = 0>
    MSharedPtr& operator=(const MSharedPtr<U>& _rhs) noexcept {
        copy_assign(_rhs);
        ptr = reinterpret_cast<void*>( const_cast<typename std::remove_const<T>::type*>( static_cast<T*>( reinterpret_cast<U*>(ptr) ) ) );
        return *this;
    }

    /*!
        \brief Transfers ownership of the managed object in _rhs to this.
        
        After assignment *this contains the original state of _rhs, and _rhs is empty and stores a nullptr.

        \param[in] _rhs An MSharedPtr whose state should move into *this.
    */
    MSharedPtr& operator=(MSharedPtr&& _rhs) noexcept { move_assign(std::move(_rhs)); return *this;}

    /*!
        \brief Transfers ownership of the managed object in _rhs to this.

        After assignment *this contains the original state of _rhs, and _rhs is empty and stores a nullptr.
        U* must be a type which is convertible to T*.

        \param[in] _rhs An MSharedPtr whose state should move into *this.
    */
    template<class U, typename std::enable_if<std::is_convertible<U*,T*>::value, int>::type = 0>
    MSharedPtr& operator=(MSharedPtr<U>&& _rhs) noexcept {
        move_assign(std::move(_rhs));
        ptr = reinterpret_cast<void*>( const_cast<typename std::remove_const<T>::type*>( static_cast<T*>( reinterpret_cast<U*>(ptr) ) ) );
        return *this;
    }

    // ****************************************************************************
    // Comparison operators

    /*!
        \return get() == _rhs.get()
    */
    template< class U >
    bool operator==( const MSharedPtr<U>& _rhs) const noexcept { return get() == _rhs.get(); }

    /*!
        \return !(*this == _rhs)
    */
    template< class U >
    bool operator!=( const MSharedPtr<U>& _rhs) const noexcept { return !(*this == _rhs); }
    
    /*!
        \return get() < _rhs.get()
    */
    template< class U >
    bool operator<( const MSharedPtr<U>& _rhs) const noexcept {
        // In Maya all pointers are implemented as addresses within a continuous virtual address space, so no need
        // to get a composite pointer type for T and U and use std::less<> to get a strict total ordering.
        return get() < _rhs.get();
    }

    /*!
        \return _rhs < *this
    */
    template< class U >
    bool operator>( const MSharedPtr<U>& _rhs) const noexcept { return _rhs < *this; }

    /*!
        \return !(_rhs < *this)
    */
    template< class U >
    bool operator<=( const MSharedPtr<U>& _rhs) const noexcept { return !(_rhs < *this); }

    /*!
        \return !(*this < _rhs)
    */
    template< class U >
    bool operator>=( const MSharedPtr<U>& _rhs) const noexcept { return !(*this < _rhs); }

    // ****************************************************************************
    // Pointer Casts

    /*!
        \return static_cast<T*>(_rhs.get())
    */
    template< class U >
    static MSharedPtr<T> static_pointer_cast(const MSharedPtr<U>& _rhs) noexcept { return MSharedPtr<T>(_rhs, static_cast<T*>(_rhs.get())); }

    /*!
        \return static_cast<T*>(_rhs.get())
    */
    template< class U >
    static MSharedPtr<T> static_pointer_cast(MSharedPtr<U>&& _rhs) noexcept { return MSharedPtr<T>(std::move(_rhs), static_cast<T*>(_rhs.get())); }

    /*!
        \return dynamic_cast<T*>(_rhs.get())
    */
    template< class U >
    static MSharedPtr<T> dynamic_pointer_cast(const MSharedPtr<U>& _rhs) noexcept { return MSharedPtr<T>(_rhs, dynamic_cast<T*>(_rhs.get())); }

    /*!
        \return dynamic_cast<T*>(_rhs.get())
    */
    template< class U >
    static MSharedPtr<T> dynamic_pointer_cast(MSharedPtr<U>&& _rhs) noexcept { return MSharedPtr<T>(std::move(_rhs), dynamic_cast<T*>(_rhs.get())); }

    /*!
        \return const_cast<T*>(_rhs.get())
    */
    template< class U >
    static MSharedPtr<T> const_pointer_cast(const MSharedPtr<U>& _rhs) noexcept { return MSharedPtr<T>(_rhs, const_cast<T*>(_rhs.get())); }

    /*!
        \return const_cast<T*>(_rhs.get())
    */
    template< class U >
    static MSharedPtr<T> const_pointer_cast(MSharedPtr<U>&& _rhs) noexcept { return MSharedPtr<T>(std::move(_rhs), const_cast<T*>(_rhs.get())); }

    /*!
        \return reinterpret_cast<T*>(_rhs.get())
    */
    template< class U >
    static MSharedPtr<T> reinterpret_pointer_cast(const MSharedPtr<U>& _rhs) noexcept { return MSharedPtr<T>(_rhs, reinterpret_cast<T*>(_rhs.get())); }

    /*!
        \return reinterpret_cast<T*>(_rhs.get())
    */
    template< class U >
    static MSharedPtr<T> reinterpret_pointer_cast(MSharedPtr<U>&& _rhs) noexcept { return MSharedPtr<T>(std::move(_rhs), reinterpret_cast<T*>(_rhs.get())); }

    /*!
        \brief Release ownership of the managed object. After the call, *this manages no object.
    */
    void reset() noexcept { release(); }

    /*!
        \brief Replace the managed object with _ptr.

        U* must be a type which is convertible to T*.

        \param[in] _ptr A pointer to an object to manage.
    */
    template<class U, typename std::enable_if<std::is_convertible<U*,T*>::value, int>::type = 0> //SFINAE to ensure that we only generate functions when U converts to T
    void reset(U* _ptr) { move_assign(MSharedPtr<T>(_ptr)); }
    
    /*!
        \brief Replace the managed object with _ptr and use Deleter _d as the deleter.

        Deleter _d is used to delete the object. The expression _d(_ptr) must be well-formed,
        have well-defined behavior and not throw exceptions.

        U* must be a type which is convertible to T*.

        \param[in] _ptr A pointer to an object to manage.
        \param[in] _d A deleter object for _ptr.
    */
    template<class U, class Deleter, typename std::enable_if<std::is_convertible<U*,T*>::value, int>::type = 0>
    void reset(U* _ptr, Deleter _d) { move_assign(MSharedPtr<T>(_ptr, _d)); }

    /*!
        \brief Constructs an object of type T using args as the paramter list of the constructor of T and wraps the resulting object in an MSharedPtr.

        The memory for the constructed object and the MSharedPtr are allocated together in a single heap allocation, improving performance.

        \param[in] args parameter list used for the constructor of held object.
        \return MSharedPtr which manages the lifetime of constructed object.
    */
    template<class ... Args>
    static MSharedPtr<T> make(Args&& ... _args)
    {
        return MSharedPtr<T>{ allocWithPlacementNew<details::ObjectAndControlBlock<T>>(std::forward<Args>(_args)...) };
    }
private:
    /*!
        \brief Constructor for makeMSharedPtr.
    */
    explicit MSharedPtr(details::ObjectAndControlBlock<T>* _controlBlock)
    : SharedPtrBase(_controlBlock)
    {}

    /*!
        MSharedPtr<void>::operator*() is unspecified. operator*() has no parameters for us
        to specify an implementation for element_type = void, so create a function get_ref
        which does take a parameter and which allows us to create an implementation which
        safely compiles.
    */
    template <class U>
    U& get_ref(U* _ptr) const { return *_ptr; }
    
    struct void_ref_t {};

    void_ref_t get_ref(void*) const { return {}; }

    template <class V, class ... Args>
    static V* allocWithPlacementNew(Args&& ... _args)
    {
        void* _ptr = controlBlockAlloc(sizeof(V), alignof(V));
        return ::new (_ptr) V {std::forward<Args>(_args)...};
    }
};

OPENMAYA_NAMESPACE_CLOSE
