#include "stdafx.h"
#pragma hdrstop

#include "main.h"
#include "splash.h"
#include "UI_ActorMain.h"
#include "UI_ActorTools.h"
#include "../ECore/Editor/LogForm.h"

#include <string>
//---------------------------------------------------------------------------
USEFORM("KeyBar.cpp", frmKeyBar);
USEFORM("LeftBar.cpp", fraLeftBar); /* TFrame: File Type */
USEFORM("main.cpp", frmMain);
USEFORM("BottomBar.cpp", fraBottomBar); /* TFrame: File Type */
USEFORM("BonePart.cpp", frmBonePart);
USEFORM("Splash.cpp", frmSplash);
USEFORM("TopBar.cpp", fraTopBar); /* TFrame: File Type */
//---------------------------------------------------------------------------
int WINAPI WinMain(HINSTANCE  hInst, HINSTANCE hInstOld, LPSTR arg, int s)
{
       //ShowMessage("Stop -> Debug!");

	try
	{

/*#ifdef TEST_SDK
		SetCurrentDirectory("D:\\Program Files\\X-Ray CoP SDK\\editors");
#endif */
		//char buff[256];
		//GetCurrentDirectory(256, buff);
		//ShowMessage(buff);


		if (!Application->Handle){
			Application->CreateHandle	();
			Application->Icon->Handle 	= LoadIcon(MainInstance, "MAINICON");
			Application->Title 			= "Loading...";
		}
		frmSplash 				= xr_new<TfrmSplash>((TComponent*)0);
		frmSplash->Show			();
		frmSplash->Repaint		();
		frmSplash->SetStatus	("Core initializing...");

		Core._initialize		("actor",ELogCallback, true, "fs.ltx");

		Application->Initialize	();

        frmSplash->SetStatus	("Loading...");

// startup create
		Tools					= xr_new<CActorTools>();
        UI						= xr_new<CActorMain>();
        UI->RegisterCommands	();

		Application->Title 		= UI->EditorDesc();
		TfrmLog::CreateLog		();

		Application->CreateForm(__classid(TfrmMain), &frmMain);
		Application->CreateForm(__classid(TfrmBonePart), &frmBonePart);
		frmMain->SetHInst		(hInst);

		xr_delete				(frmSplash);

		Application->Run		();

        TfrmLog::DestroyLog		(); 

		UI->ClearCommands		();
        xr_delete				(Tools);
		xr_delete				(UI);

		Core._destroy			();
	}
	catch(std::exception& ex)
	{
        	ShowMessage(ex.what());
    }
	catch (Exception &exception)
	{
		   Application->ShowException(&exception);
	}
	return 0;
}
//---------------------------------------------------------------------------

















