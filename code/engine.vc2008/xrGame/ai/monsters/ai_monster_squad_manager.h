#pragma once

class CMonsterSquad;
class CEntity;

class CMonsterSquadManager {
	
	//------------------------------------------------------------------------
	// Monster classification: Team -> Level -> Squad
	// Note: Its names differ from global ones, which are: Team -> Squad -> Group
	//		 but nesting hierarchy logically means the same
	//		 Team->Level->Squad used only for private members and functions
	//------------------------------------------------------------------------

	typedef xr_vector< CMonsterSquad* > MONSTER_SQUAD_VEC; typedef MONSTER_SQUAD_VEC::iterator MONSTER_SQUAD_VEC_IT;
	typedef xr_vector< MONSTER_SQUAD_VEC > MONSTER_LEVEL_VEC; typedef MONSTER_LEVEL_VEC::iterator MONSTER_LEVEL_VEC_IT;
	typedef xr_vector< MONSTER_LEVEL_VEC > MONSTER_TEAM_VEC; typedef MONSTER_TEAM_VEC::iterator MONSTER_TEAM_VEC_IT;

	MONSTER_TEAM_VEC team;

public:
	CMonsterSquadManager	();
	~CMonsterSquadManager	();

	void			register_member			(u8 team_id, u8 squad_id, u8 group_id, CEntity *e);
	void			remove_member			(u8 team_id, u8 squad_id, u8 group_id, CEntity *e);

	CMonsterSquad	*get_squad				(u8 team_id, u8 squad_id, u8 group_id);
	CMonsterSquad	*get_squad				(const CEntity *entity);

	void			update					(CEntity *entity);

	void			remove_links			(CObject *O);
};


IC CMonsterSquadManager &monster_squad();
extern CMonsterSquadManager *g_monster_squad;

#include "ai_monster_squad_manager_inline.h"
