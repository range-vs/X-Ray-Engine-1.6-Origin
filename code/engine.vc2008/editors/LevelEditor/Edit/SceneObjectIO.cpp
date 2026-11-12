//----------------------------------------------------
// file: CSceneObject.cpp
//----------------------------------------------------

#include "stdafx.h"
#pragma hdrstop

#include "SceneObject.h"
#include "Scene.h"
//----------------------------------------------------
#define SCENEOBJ_CURRENT_VERSION		0x0012
//----------------------------------------------------
#define SCENEOBJ_CHUNK_VERSION		  	0x0900
#define SCENEOBJ_CHUNK_REFERENCE     	0x0902
#define SCENEOBJ_CHUNK_PLACEMENT     	0x0904
#define SCENEOBJ_CHUNK_FLAGS			0x0905

static bool LoadMissingReference(CSceneObject* obj, LPCSTR ref_name)
{
    if (MissingObjectSkipped("Object", ref_name))
        return		false;

    bool bRes		= false;
    int  mr			= mrNone;

    xr_string _new_name;
    if (Scene->GetSubstObjectName(ref_name, _new_name))
    {
        string1024 _message;
        sprintf		(_message,	"Object [%s] not found in library.\n\n"
                                "'Replace' - replace it with [%s].\n"
                                "'Select...' - choose another object from the library.\n"
                                "'Skip All' - skip all missing objects (see log for their names).%s",
                                ref_name, _new_name.c_str(), MissingObjectCloseHint());

        mr			= MissingObjectDlgEx("Replace", "Select...", _message);
        if (mrYes==mr)
            bRes	= (0!=obj->SetReference(_new_name.c_str()));
        else
        if (mrNo==mr)
            mr		= mrYes;	// 'Select...' in this dialog
    }else
    {
        mr			= MissingObjectDlg("Object", ref_name,
                                       "choose a replacement object.",
                                       "load the level without this object.");
    }

    if (!bRes&&(mrYes==mr))
    {
        LPCSTR new_val	= 0;
        if (TfrmChoseItem::SelectItem(smObject,new_val,1))
        {
            bRes		= (0!=obj->SetReference(new_val));
            if (bRes)
                Scene->RegisterSubstObjectName(ref_name, new_val);
        }
    }

    return bRes;
}

bool CSceneObject::LoadLTX(CInifile& ini, LPCSTR sect_name)
{
    bool bRes = true;
	do
    {
        u32 version = ini.r_u32(sect_name, "version");

		CCustomObject::LoadLTX						(ini, sect_name);

        xr_string ref_name  = ini.r_string			(sect_name, "reference_name");

        if (!SetReference(ref_name.c_str()))
            bRes = LoadMissingReference(this, ref_name.c_str());
//        if(!CheckVersion())
//            ELog.Msg( mtError, "CSceneObject: '%s' different file version!", ref_name.c_str() );

      	m_Flags.assign(ini.r_u32(sect_name, "flags"));

        if (!bRes) break;
    }while(0);

    return bRes;
}

void CSceneObject::SaveLTX(CInifile& ini, LPCSTR sect_name)
{
	CCustomObject::SaveLTX		(ini, sect_name);

    ini.w_u32					(sect_name, "version", SCENEOBJ_CURRENT_VERSION);

    // reference object version
    R_ASSERT					(m_pReference);
    ini.w_string				(sect_name, "reference_name", m_ReferenceName.c_str());

	ini.w_u32					(sect_name, "flags", m_Flags.get());
}

bool CSceneObject::LoadStream(IReader& F)
{
    bool bRes = true;
	do{
        u16 version = 0;
        string1024 buf;
        R_ASSERT(F.r_chunk(SCENEOBJ_CHUNK_VERSION,&version));

        if (version==0x0010)
        {
	        R_ASSERT(F.find_chunk(SCENEOBJ_CHUNK_PLACEMENT));
    	    F.r_fvector3(FPosition);
	        F.r_fvector3(FRotation);
    	    F.r_fvector3(FScale);
        }

		CCustomObject::LoadStream(F);

        R_ASSERT(F.find_chunk(SCENEOBJ_CHUNK_REFERENCE));
        if(version<=0x0011)
        {
                F.r_u32();
                F.r_u32();
        }
        F.r_stringZ	(buf,sizeof(buf));

        if (!SetReference(buf))
            bRes = LoadMissingReference(this, buf);
//        if(!CheckVersion()){
//            ELog.Msg( mtError, "CSceneObject: '%s' different file version!", buf );
//            }

        // flags
        if (F.find_chunk(SCENEOBJ_CHUNK_FLAGS)){
        	m_Flags.assign(F.r_u32());
        }

        if (!bRes) break;
    }while(0);

    return bRes;
}

void CSceneObject::SaveStream(IWriter& F)
{
	CCustomObject::SaveStream(F);

	F.open_chunk	(SCENEOBJ_CHUNK_VERSION);
	F.w_u16			(SCENEOBJ_CURRENT_VERSION);
	F.close_chunk	();

    // reference object version
    F.open_chunk	(SCENEOBJ_CHUNK_REFERENCE); R_ASSERT2(m_pReference,"Empty SceneObject REFS");
    F.w_stringZ		(m_ReferenceName);
    F.close_chunk	();

    F.open_chunk	(SCENEOBJ_CHUNK_FLAGS);
	F.w_u32			(m_Flags.flags);
    F.close_chunk	();
}
//----------------------------------------------------


