////////////////////////////////////////////////////////////////////////////
//	Module 		: builder_allocator_constructor.h
//	Created 	: 21.03.2002
//  Modified 	: 28.02.2004
//	Author		: Dmitriy Iassenev
//	Description : Builder allocator constructor
////////////////////////////////////////////////////////////////////////////

#pragma once

template <typename _path_builder,typename _vertex_allocator>
struct CBuilderAllocatorConstructor 
{
	template <template <typename _T> class _vertex> 
	class CDataStorage : public _path_builder::template CDataStorage<_vertex>, public _vertex_allocator::template CDataStorage<_path_builder::template CDataStorage<_vertex>::CGraphVertex> // range fix template
	{
	public:
		typedef typename _path_builder::template CDataStorage<_vertex>	CDataStorageBase; // range fix template
		typedef typename _vertex_allocator::template CDataStorage<
			typename _path_builder::template CDataStorage<
				_vertex
			>::CGraphVertex
		>												CDataStorageAllocator; // range fix template
		typedef typename CDataStorageBase::CGraphVertex CGraphVertex;
		typedef typename CGraphVertex::_index_type		_index_type;

	public:
		IC							CDataStorage	(const u32 vertex_count);
		virtual						~CDataStorage	();
		IC		void				init			();
	};
};


#include "builder_allocator_constructor_inline.h"