#ifndef ObjectAnimatorH
#define ObjectAnimatorH
#pragma once

///*defined(_WIN64) &&*/
#ifdef _LEVEL_EDITOR // range fix
#define ECORE_API		__declspec(dllimport)
#define ENGINE_API		__declspec(dllimport)
#include "xrCore.h"
#endif

#include "motion.h"

// refs
class
#ifndef _EDITOR
ENGINE_API
#endif
CObjectAnimator
{
private:
	typedef xr_vector< COMotion* > MotionVec; typedef MotionVec::iterator MotionIt;
protected:
	bool				bLoop;

    shared_str			m_Name;
    
	Fmatrix				m_XFORM;
    SAnimParams			m_MParam;
	MotionVec			m_Motions;
    float				m_Speed;

    COMotion*			m_Current;
	void				LoadMotions		(LPCSTR fname);
	void				SetActiveMotion	(COMotion* mot);
	COMotion*			FindMotionByName(LPCSTR name);
public:
						CObjectAnimator	();
	virtual				~CObjectAnimator();

	void				Clear			();
	void				Load			(LPCSTR name);
    IC LPCSTR			Name			(){return *m_Name;}
    float&				Speed			(){return m_Speed;}

	COMotion*			Play			(bool bLoop, LPCSTR name=0);
	void				Pause			(bool val){return m_MParam.Pause(val);}
	void				Stop			();
	IC BOOL				IsPlaying		(){return m_MParam.bPlay;}

    IC const Fmatrix&	XFORM			(){return m_XFORM;}
	float				GetLength		();
	// Update
	void				Update			(float dt);
    void				DrawPath		();
};

#endif //ObjectAnimatorH
