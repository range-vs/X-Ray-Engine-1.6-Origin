﻿// CodeGear C++Builder
// Copyright (c) 1995, 2022 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'frmHdrStp.pas' rev: 35.00 (Windows)

#ifndef FrmhdrstpHPP
#define FrmhdrstpHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>
#include <SysInit.hpp>
#include <Winapi.Windows.hpp>
#include <Winapi.Messages.hpp>
#include <System.SysUtils.hpp>
#include <System.Classes.hpp>
#include <Vcl.Graphics.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.Dialogs.hpp>
#include <ElHeader.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <ElACtrls.hpp>
#include <ElBtnCtl.hpp>
#include <ElPopBtn.hpp>
#include <ElXPThemedControl.hpp>
#include <ElCLabel.hpp>
#include <ElLabel.hpp>
#include <ElListBox.hpp>
#include <System.UITypes.hpp>

//-- user supplied -----------------------------------------------------------

namespace Frmhdrstp
{
//-- forward type declarations -----------------------------------------------
class DELPHICLASS TfrmHeaderSetup;
//-- type declarations -------------------------------------------------------
class PASCALIMPLEMENTATION TfrmHeaderSetup : public Vcl::Forms::TForm
{
	typedef Vcl::Forms::TForm inherited;
	
__published:
	Vcl::Extctrls::TPanel* pnlSections;
	Ellistbox::TElListBox* lbxAvailable;
	Ellistbox::TElListBox* lbxVisible;
	Ellabel::TElLabel* lblAvailable;
	Ellabel::TElLabel* lblVisible;
	Elpopbtn::TElPopupButton* btnAdd;
	Elpopbtn::TElPopupButton* btnDelete;
	Elpopbtn::TElPopupButton* btnUp;
	Elpopbtn::TElPopupButton* btnDown;
	Elpopbtn::TElPopupButton* btnOk;
	Elpopbtn::TElPopupButton* btnCancel;
	void __fastcall FormShow(System::TObject* Sender);
	void __fastcall lbxVisibleEnter(System::TObject* Sender);
	void __fastcall lbxAvailableEnter(System::TObject* Sender);
	void __fastcall btnAddClick(System::TObject* Sender);
	void __fastcall btnDeleteClick(System::TObject* Sender);
	void __fastcall btnUpClick(System::TObject* Sender);
	void __fastcall btnDownClick(System::TObject* Sender);
	void __fastcall lbxVisibleMouseDown(System::TObject* Sender, System::Uitypes::TMouseButton Button, System::Classes::TShiftState Shift, int X, int Y);
	void __fastcall lbxVisibleDragOver(System::TObject* Sender, System::TObject* Source, int X, int Y, System::Uitypes::TDragState State, bool &Accept);
	void __fastcall lbxVisibleDragDrop(System::TObject* Sender, System::TObject* Source, int X, int Y);
	void __fastcall lbxAvailableDragOver(System::TObject* Sender, System::TObject* Source, int X, int Y, System::Uitypes::TDragState State, bool &Accept);
	void __fastcall lbxAvailableMouseDown(System::TObject* Sender, System::Uitypes::TMouseButton Button, System::Classes::TShiftState Shift, int X, int Y);
	void __fastcall lbxAvailableDragDrop(System::TObject* Sender, System::TObject* Source, int X, int Y);
	
private:
	void __fastcall UpdateButtons();
	
public:
	void __fastcall LoadHeaderSections(Elheader::TElHeaderSections* ASections);
	void __fastcall SaveHeaderSections(Elheader::TElHeaderSections* ASections);
public:
	/* TCustomForm.Create */ inline __fastcall virtual TfrmHeaderSetup(System::Classes::TComponent* AOwner) : Vcl::Forms::TForm(AOwner) { }
	/* TCustomForm.CreateNew */ inline __fastcall virtual TfrmHeaderSetup(System::Classes::TComponent* AOwner, int Dummy) : Vcl::Forms::TForm(AOwner, Dummy) { }
	/* TCustomForm.Destroy */ inline __fastcall virtual ~TfrmHeaderSetup() { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TfrmHeaderSetup(HWND ParentWindow) : Vcl::Forms::TForm(ParentWindow) { }
	
};


//-- var, const, procedure ---------------------------------------------------
}	/* namespace Frmhdrstp */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_FRMHDRSTP)
using namespace Frmhdrstp;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// FrmhdrstpHPP
