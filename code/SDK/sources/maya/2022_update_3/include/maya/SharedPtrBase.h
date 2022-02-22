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

#include <maya/MApiNamespace.h>
#include <utility>
#include <type_traits>
#include <cstddef>

OPENMAYA_MAJOR_NAMESPACE_OPEN

/*!
    The details namespace contains classes which are not meant to be used independently
    as a part of the Maya API.

    The classes in this file implement the API class MSharedPtr. As a user of the Maya
    API there is nothing in this file that you need to know to understand and use MSharedPtr.

    These classes are included here because of the nature of template programming with C++.
*/
namespace details {

// ****************************************************************************
// CLASS DECLARATION (PtrAndControlBlock)
//! \ingroup OpenMaya
//! \brief Holds a pointer to a managed object and the number of references.
struct OPENMAYA_EXPORT ControlBlock
{
    alignas(8) char ref[4];
    void* ptr{nullptr};

    explicit ControlBlock(void* _ptr);
    virtual ~ControlBlock();
    virtual void destroy()=0;

    void inc();
    bool dec();
};

// ****************************************************************************
// CLASS DECLARATION (PtrAndControlBlock)
//! \ingroup OpenMaya
//! \brief Control block which holds a functor that can delete objects of type U, which are managed by *this control block.
template<class U, class Deleter>
struct PtrAndControlBlock final : public ControlBlock // No OPENMAYA_EXPORT for template classes
{
    // we'll be explicitly calling the destructor of deleter, so put it in a union to
    // explicitly prevent any generated destructor for PtrAndControlBlock from calling
    // ~Deleter.
    union { Deleter deleter; };

    PtrAndControlBlock(U* _ptr, Deleter _deleter) : ControlBlock(_ptr), deleter(_deleter) {}
    ~PtrAndControlBlock(){}
    void destroy() override {
        deleter(reinterpret_cast<U*>(ptr));
        deleter.~Deleter();
    }
};

// ****************************************************************************
// CLASS DECLARATION (DefaultDeleter)
//! \ingroup OpenMaya
//! \brief Functor which can safely delete objects of type U
template<class U>
struct DefaultDeleter // No OPENMAYA_EXPORT for template classes
{
    void operator()(U* p) const { delete p; }
};

// ****************************************************************************
// CLASS DECLARATION (ObjectAndControlBlock)

//! \ingroup OpenMaya
//! \brief Control block which holds an object whose lifetime is managed by an MSharedPtr
template<class U>
struct ObjectAndControlBlock final : public ControlBlock // No OPENMAYA_EXPORT for template classes
{
    // We want to destroy the object before this is destroyed, which means
    // when this is destroyed object has already been destroyed, so don't call
    // the destructor twice.
    union { U object; };

    template<class ... Args>
    ObjectAndControlBlock(Args && ...args) : ControlBlock(nullptr), object(std::forward<Args>(args)...) { ptr = &object; }
    ~ObjectAndControlBlock(){}
    void destroy() override { object.~U(); }
};

// ****************************************************************************
// CLASS DECLARATION (SharedPtrBase)

//! \ingroup OpenMaya
//! \brief Base class for MSharedPtr 
/*!
SharedPtrBase is the internal implementation of MSharedPtr. SharedPtrBase should
not be used directly, instead use MSharedPtr.
*/
class OPENMAYA_EXPORT SharedPtrBase
{
protected:
    void* ptr{nullptr};
    ControlBlock* controlBlock{nullptr};
    
    SharedPtrBase() = default;
    SharedPtrBase(const SharedPtrBase&) = delete;
    SharedPtrBase(SharedPtrBase&&) = delete;
    SharedPtrBase& operator=(const SharedPtrBase&) = delete;
    SharedPtrBase& operator=(SharedPtrBase&&) = delete;

    explicit SharedPtrBase(ControlBlock* _controlBlock)
    : ptr(_controlBlock->ptr)
    , controlBlock(_controlBlock)
    {}

    ~SharedPtrBase()
    {
        release();
    }

    void release();
    void copy_assign(const SharedPtrBase& _rhs);
    void move_assign(SharedPtrBase&& _rhs);
    
    static void* controlBlockAlloc(std::size_t _size, std::size_t _alignment);
    static void controlBlockDealloc(void* _ptr);
};

} // details

OPENMAYA_NAMESPACE_CLOSE
