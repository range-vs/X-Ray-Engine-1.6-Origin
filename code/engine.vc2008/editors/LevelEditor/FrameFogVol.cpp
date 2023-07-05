#include "stdafx.h"
#pragma hdrstop

#include "FrameFogVol.h"
#include "ESceneFogVolumeTools.h"
#include "../ECore/Editor/ui_main.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "ExtBtn"
#pragma resource "*.dfm"

#include "../xrEProps/ui_scale.hpp"

//---------------------------------------------------------------------------
__fastcall TfraFogVol::TfraFogVol(TComponent* Owner, ESceneFogVolumeTool* gt)
	: TForm(Owner)
{
	ParentTools = gt;
    scaleBy(this);
}
//---------------------------------------------------------------------------
void __fastcall TfraFogVol::ebGroupClick(TObject *Sender)
{
	ParentTools->GroupSelected();
}
//---------------------------------------------------------------------------
void __fastcall TfraFogVol::ebUngroupClick(TObject *Sender)
{
	ParentTools->UnGroupCurrent();
}
//---------------------------------------------------------------------------

void __fastcall TfraFogVol::ExtBtn2Click(TObject *Sender)
{
     collapseExpandPanel(Sender);
}
//---------------------------------------------------------------------------

