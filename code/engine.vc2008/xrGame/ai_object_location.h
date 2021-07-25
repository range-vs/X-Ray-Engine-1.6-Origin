////////////////////////////////////////////////////////////////////////////
//	Module 		: ai_object_location.h
//	Created 	: 27.11.2003
//  Modified 	: 27.11.2003
//	Author		: Dmitriy Iassenev
//	Description : AI object location
////////////////////////////////////////////////////////////////////////////

#pragma once

#include "game_graph_space.h"

namespace LevelGraph {
	class CVertex;
};

class CAI_ObjectLocation {
public:
	typedef GameGraph::_GRAPH_ID				_GRAPH_ID;
	typedef GameGraph::CVertex					CVertex;
	typedef LevelGraph::CVertex					CLevelVertex;

private:
	u32						m_level_vertex_id;
	_GRAPH_ID				m_game_vertex_id;

public:
	IC						CAI_ObjectLocation	();
	IC	void				init				();
	IC	void				reinit				();
	/*IC*/	void				game_vertex			(CVertex /*const*/ *game_vertex); // range fix
	/*IC*/	void				game_vertex			(const _GRAPH_ID /*const*/ &game_vertex_id); // range fix
	/*IC*/	const CVertex		*game_vertex		() const; // range fix
	IC	const _GRAPH_ID		game_vertex_id		() const;
	/*IC*/	void				level_vertex		(CLevelVertex /*const*/ *level_vertex); // range fix
	/*IC*/	void				level_vertex		(const u32 /*const*/ &level_vertex_id); // range fix
	/*IC*/	const CLevelVertex	*level_vertex		() const; // range fix
	IC	const u32			level_vertex_id		() const;
};

#include "ai_object_location_inline.h"