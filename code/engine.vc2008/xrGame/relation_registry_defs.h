//////////////////////////////////////////////////////////////////////////
// relation_registry_defs.h:	реестр для хранения данных об отношении персонажа к 
//								другим персонажам
//////////////////////////////////////////////////////////////////////////

#pragma once

#include "object_interfaces.h"


//структура, описывающая отношение одного персонажа к другому или к группировке
struct SRelation
{
	SRelation();
	~SRelation();
	CHARACTER_GOODWILL		Goodwill		() const							{return m_iGoodwill;};
	void					SetGoodwill		(CHARACTER_GOODWILL new_goodwill)	{m_iGoodwill = new_goodwill;};
private:
	//благосклонность
	CHARACTER_GOODWILL m_iGoodwill;
};

typedef xr_map< u16,SRelation > PERSONAL_RELATION_MAP; typedef PERSONAL_RELATION_MAP::iterator PERSONAL_RELATION_MAP_IT;
typedef xr_map< CHARACTER_COMMUNITY_INDEX,SRelation > COMMUNITY_RELATION_MAP; typedef COMMUNITY_RELATION_MAP::iterator COMMUNITY_RELATION_MAP_IT;


//структура, существует для каждого персонажа в игре
struct RELATION_DATA : public IPureSerializeObject<IReader,IWriter>
{
	virtual void clear();

	virtual void load (IReader&);
	virtual void save (IWriter&);

	//личные отношения
	PERSONAL_RELATION_MAP personal; 
	//отношения с группировками
	COMMUNITY_RELATION_MAP communities;
};
