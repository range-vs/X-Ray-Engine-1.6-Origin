#include "stdafx.h"
#pragma hdrstop

#include "Splash.h"

#include "../xrEProps/ui_scale.hpp"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfrmSplash *frmSplash;
//---------------------------------------------------------------------------
__fastcall TfrmSplash::TfrmSplash(TComponent* Owner)
    : TForm(Owner)
{
	scaleBy(this);
}
//---------------------------------------------------------------------------
