//---------------------------------------------------------------------------
#include "stdafx.h"

#include <vcl.h>
#pragma hdrstop

#include "RightForm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"

#include "../xrEProps/ui_scale.hpp"

TfrmRight *frmRight;
//---------------------------------------------------------------------------
__fastcall TfrmRight::TfrmRight(TComponent* Owner)
	: TForm(Owner)
{
    scaleBy(this);
}
//---------------------------------------------------------------------------
