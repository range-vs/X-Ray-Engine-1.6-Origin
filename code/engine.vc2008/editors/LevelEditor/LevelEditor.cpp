#include "stdafx.h"
#pragma hdrstop
#include "splash.h"
#include "../ECore/Editor/LogForm.h"
#include "../ECore/Editor/EditMesh.h"
#include "main.h"
#include "scene.h"
#include "UI_LevelMain.h"
#include "UI_LevelTools.h"

#include "../Include/stack_trace.h"

//---------------------------------------------------------------------------
USEFORM("FrameObject.cpp", fraObject);
USEFORM("FramePortal.cpp", fraPortal);
USEFORM("FramePS.cpp", fraPS);
USEFORM("FrameSector.cpp", fraSector);
USEFORM("FrameShape.cpp", fraShape);
USEFORM("FrameAIMap.cpp", fraAIMap);
USEFORM("FrameDetObj.cpp", fraDetailObject);
USEFORM("FrameFogVol.cpp", fraFogVol);
USEFORM("FrameGroup.cpp", fraGroup);
USEFORM("FrameLight.cpp", fraLight);
USEFORM("FrameSpawn.cpp", fraSpawn);
USEFORM("TopBar.cpp", fraTopBar); /* TFrame: File Type */
USEFORM("LeftBar.cpp", fraLeftBar); /* TFrame: File Type */
USEFORM("FrameWayPoint.cpp", fraWayPoint);
USEFORM("FrmDBXpacker.cpp", DB_packer);
USEFORM("LEClipEditor.cpp", ClipMaker);
USEFORM("PropertiesEObject.cpp", frmPropertiesEObject);
USEFORM("RightForm.cpp", frmRight);
USEFORM("Splash.cpp", frmSplash);
USEFORM("main.cpp", frmMain);
USEFORM("ObjectList.cpp", frmObjectList);
USEFORM("previewimage.cpp", frmPreviewImage);
USEFORM("EditLightAnim.cpp", frmEditLightAnim);
USEFORM("Edit\AppendObjectInfoForm.cpp", frmAppendObjectInfo);
USEFORM("BottomBar.cpp", fraBottomBar); /* TFrame: File Type */
USEFORM("DOOneColor.cpp", frmOneColor);
USEFORM("DOShuffle.cpp", frmDOShuffle);
USEFORM("EditLibrary.cpp", frmEditLibrary);
//---------------------------------------------------------------------------
int WINAPI WinMain(HINSTANCE hInst, HINSTANCE, LPSTR, int)
{
//    try{
/*#ifdef TEST_SDK
		SetCurrentDirectory("D:\\Program Files\\X-Ray CoP SDK\\editors");
#endif */

		if (!Application->Handle){
            Application->CreateHandle	();
            Application->Icon->Handle 	= LoadIcon(MainInstance, "MAINICON");
			Application->Title 			= "Loading...";
        } 
        frmSplash 				= xr_new<TfrmSplash>((TComponent*)0);
        frmSplash->Show			();
        frmSplash->Repaint		();
        frmSplash->SetStatus	("Core initializing...");

		Core._initialize		("level",ELogCallback);
        CEditableMesh::SetDraftMeshMode(TRUE);
		//CEditableMesh::m_bDraftMeshMode = TRUE;

		Application->Initialize	();
		frmSplash->SetStatus	("Loading...");

// startup create
		Tools					= xr_new<CLevelTool>();
		UI						= xr_new<CLevelMain>();
        UI->RegisterCommands	();
		Scene					= xr_new<EScene>();
		Application->Title 		= UI->EditorDesc();
        TfrmLog::CreateLog		();
		Application->CreateForm(__classid(TfrmMain), &frmMain);
		Application->CreateForm(__classid(TfrmRight), &frmRight);
		frmMain->SetHInst		(hInst);

		xr_delete(frmSplash);
		Application->Run		();


        TfrmLog::DestroyLog		();

		UI->ClearCommands		();
        xr_delete				(Scene);
        xr_delete				(Tools);
        xr_delete				(UI);

    	Core._destroy			();
//    }
//    catch (Exception &exception)
//    {
//           Application->ShowException(&exception);
//    }
    return 0;
}
//---------------------------------------------------------------------------





