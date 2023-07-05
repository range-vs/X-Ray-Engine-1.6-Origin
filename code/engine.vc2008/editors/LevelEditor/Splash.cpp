#include "stdafx.h"
#pragma hdrstop

#include "Splash.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "MXCtrls"
#pragma resource "*.dfm"

#include "../../xrEProps/ui_scale.hpp"

TfrmSplash *frmSplash;
//---------------------------------------------------------------------------
__fastcall TfrmSplash::TfrmSplash(TComponent* Owner)
    : TForm(Owner)
{
	scaleBy(this);
}
//---------------------------------------------------------------------------
