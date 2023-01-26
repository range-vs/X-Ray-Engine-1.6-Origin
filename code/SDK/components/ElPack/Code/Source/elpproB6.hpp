// CodeGear C++Builder
// Copyright (c) 1995, 2022 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'elpproB6.dpk' rev: 35.00 (Windows)

#ifndef Elpprob6HPP
#define Elpprob6HPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// (rtl)
#include <SysInit.hpp>
#include <ElShellCtl.hpp>
#include <ElPrinter.hpp>
#include <ElPrinterPreview.hpp>
#include <ElTreePrinter.hpp>
#include <System.Types.hpp>	// (rtl)
#include <System.UITypes.hpp>	// (rtl)
#include <Winapi.Windows.hpp>	// (rtl)
#include <Winapi.Messages.hpp>	// (rtl)
#include <Winapi.MultiMon.hpp>	// (rtl)
#include <System.SysConst.hpp>	// (rtl)
#include <Winapi.ImageHlp.hpp>	// (rtl)
#include <Winapi.SHFolder.hpp>	// (rtl)
#include <Winapi.PsAPI.hpp>	// (rtl)
#include <System.RTLConsts.hpp>	// (rtl)
#include <System.Character.hpp>	// (rtl)
#include <System.Internal.ExcUtils.hpp>	// (rtl)
#include <System.SysUtils.hpp>	// (rtl)
#include <System.VarUtils.hpp>	// (rtl)
#include <System.Variants.hpp>	// (rtl)
#include <Winapi.ActiveX.hpp>	// (rtl)
#include <System.TypInfo.hpp>	// (rtl)
#include <System.Hash.hpp>	// (rtl)
#include <System.Math.hpp>	// (rtl)
#include <System.Generics.Defaults.hpp>	// (rtl)
#include <System.Generics.Collections.hpp>	// (rtl)
#include <System.Rtti.hpp>	// (rtl)
#include <System.TimeSpan.hpp>	// (rtl)
#include <System.Diagnostics.hpp>	// (rtl)
#include <System.Classes.hpp>	// (rtl)
#include <Winapi.Wincodec.hpp>	// (rtl)
#include <Winapi.CommCtrl.hpp>	// (rtl)
#include <Winapi.Qos.hpp>	// (rtl)
#include <Winapi.Winsock2.hpp>	// (rtl)
#include <Winapi.IpExport.hpp>	// (rtl)
#include <Winapi.ShellAPI.hpp>	// (rtl)
#include <Winapi.RegStr.hpp>	// (rtl)
#include <Winapi.WinInet.hpp>	// (rtl)
#include <Winapi.UrlMon.hpp>	// (rtl)
#include <Winapi.ObjectArray.hpp>	// (rtl)
#include <Winapi.StructuredQueryCondition.hpp>	// (rtl)
#include <Winapi.PropSys.hpp>	// (rtl)
#include <Winapi.MSXMLIntf.hpp>	// (rtl)
#include <Winapi.ShlObj.hpp>	// (rtl)
#include <Winapi.KnownFolders.hpp>	// (rtl)
#include <System.Masks.hpp>	// (rtl)
#include <System.StrUtils.hpp>	// (rtl)
#include <System.DateUtils.hpp>	// (rtl)
#include <System.IOUtils.hpp>	// (rtl)
#include <System.IniFiles.hpp>	// (rtl)
#include <System.Win.Registry.hpp>	// (rtl)
#include <System.UIConsts.hpp>	// (rtl)
#include <Vcl.Consts.hpp>	// (vcl)
#include <Vcl.Graphics.hpp>	// (vcl)
#include <System.Contnrs.hpp>	// (rtl)
#include <System.ImageList.hpp>	// (rtl)
#include <System.Messaging.hpp>	// (rtl)
#include <System.Actions.hpp>	// (rtl)
#include <Winapi.Imm.hpp>	// (rtl)
#include <Vcl.ActnList.hpp>	// (vcl)
#include <System.HelpIntfs.hpp>	// (rtl)
#include <System.SyncObjs.hpp>	// (rtl)
#include <Winapi.UxTheme.hpp>	// (rtl)
#include <Winapi.Dwmapi.hpp>	// (rtl)
#include <System.Win.Crtl.hpp>	// (rtl)
#include <System.ZLib.hpp>	// (rtl)
#include <Vcl.GraphUtil.hpp>	// (vcl)
#include <Vcl.StdCtrls.hpp>	// (vcl)
#include <System.MaskUtils.hpp>	// (rtl)
#include <Vcl.Clipbrd.hpp>	// (vcl)
#include <Vcl.Mask.hpp>	// (vcl)
#include <Winapi.CommDlg.hpp>	// (rtl)
#include <Winapi.WinSpool.hpp>	// (rtl)
#include <Vcl.Printers.hpp>	// (vcl)
#include <Winapi.RichEdit.hpp>	// (rtl)
#include <Vcl.ToolWin.hpp>	// (vcl)
#include <Vcl.ListActns.hpp>	// (vcl)
#include <Vcl.ComStrs.hpp>	// (vcl)
#include <Vcl.StdActns.hpp>	// (vcl)
#include <Vcl.ComCtrls.hpp>	// (vcl)
#include <System.WideStrUtils.hpp>	// (rtl)
#include <Winapi.Dlgs.hpp>	// (rtl)
#include <Vcl.Dialogs.hpp>	// (vcl)
#include <Vcl.ExtCtrls.hpp>	// (vcl)
#include <Vcl.Themes.hpp>	// (vcl)
#include <System.AnsiStrings.hpp>	// (rtl)
#include <System.Win.ComConst.hpp>	// (rtl)
#include <System.Win.ComObj.hpp>	// (rtl)
#include <System.Win.Taskbar.hpp>	// (rtl)
#include <System.Win.TaskbarCore.hpp>	// (rtl)
#include <Winapi.ShellScaling.hpp>	// (rtl)
#include <Winapi.FlatSB.hpp>	// (rtl)
#include <Vcl.Forms.hpp>	// (vcl)
#include <Vcl.ImgList.hpp>	// (vcl)
#include <Vcl.Menus.hpp>	// (vcl)
#include <Winapi.TpcShrd.hpp>	// (rtl)
#include <Winapi.MsCTF.hpp>	// (rtl)
#include <Winapi.MsInkAut.hpp>	// (rtl)
#include <Winapi.PenInputPanel.hpp>	// (rtl)
#include <Vcl.Controls.hpp>	// (vcl)
#include <Winapi.MMSystem.hpp>	// (rtl)
#include <ElStrUtils.hpp>	// (elpackB6)
#include <ElTools.hpp>	// (elpackB6)
#include <ElContBase.hpp>	// (elpackB6)
#include <ElList.hpp>	// (elpackB6)
#include <ElHook.hpp>	// (elpackB6)
#include <ElArray.hpp>	// (elpackB6)
#include <ElUnicodeStrings.hpp>	// (elpackB6)
#include <ElVCLUtils.hpp>	// (elpackB6)
#include <ElTmSchema.hpp>	// (elpackB6)
#include <ElUxTheme.hpp>	// (elpackB6)
#include <ElExtBkgnd.hpp>	// (elpackB6)
#include <ElImgFrm.hpp>	// (elpackB6)
#include <ElACtrls.hpp>	// (elpackB6)
#include <ElStack.hpp>	// (elpackB6)
#include <ElXPThemedControl.hpp>	// (elpackB6)
#include <HTMLRender.hpp>	// (elpackB6)
#include <ElHintWnd.hpp>	// (elpackB6)
#include <ElScrollBar.hpp>	// (elpackB6)
#include <ElEdits.hpp>	// (elpackB6)
#include <Vcl.Buttons.hpp>	// (vcl)
#include <ElRegUtils.hpp>	// (elpackB6)
#include <ElObjList.hpp>	// (elpackB6)
#include <ElIni.hpp>	// (elpackB6)
#include <ElBtnCtl.hpp>	// (elpackB6)
#include <ElHandPt.hpp>	// (elpackB6)
#include <ElSndMap.hpp>	// (elpackB6)
#include <ElColor.hpp>	// (elpackB6)
#include <ElMenus.hpp>	// (elpackB6)
#include <ElPopBtn.hpp>	// (elpackB6)
#include <ElCLabel.hpp>	// (elpackB6)
#include <ElLabel.hpp>	// (elpackB6)
#include <ElListBox.hpp>	// (elpackB6)
#include <frmHdrStp.hpp>	// (elpackB6)
#include <ElHeader.hpp>	// (elpackB6)
#include <ElCBFmts.hpp>	// (elpackB6)
#include <ElDragDrop.hpp>	// (elpackB6)
#include <ElTree.hpp>	// (elpackB6)
#include <ElTreeStdEditors.hpp>	// (elpackB6)
#include <ElStrToken.hpp>	// (elpackB6)
#include <ElShellUtils.hpp>	// (elpackB6)
#include <ElPanel.hpp>	// (elpackB6)
#include <ElMTree.hpp>	// (elpackB6)
#include <ElPropTools.hpp>	// (elpackB6)
#include <ElFrmPers.hpp>	// (elpackB6)
#include <ElCombos.hpp>	// (elpackB6)
#include <frmTbrStp.hpp>	// (elpackB6)
#include <ElToolbar.hpp>	// (elpackB6)
#include <ElStatBar.hpp>	// (elpackB6)
#include <ElSpinBtn.hpp>	// (elpackB6)
#include <ElSpin.hpp>	// (elpackB6)
#include <ElScrollBox.hpp>	// (elpackB6)
// PRG_EXT: .bpl
// BPI_DIR: ..\..\..\..\..\bins\Win64\Debug
// OBJ_DIR: ..\..\..\..\..\libraries\Win64\Debug
// OBJ_EXT: .o

//-- user supplied -----------------------------------------------------------

namespace Elpprob6
{
//-- forward type declarations -----------------------------------------------
//-- type declarations -------------------------------------------------------
//-- var, const, procedure ---------------------------------------------------
}	/* namespace Elpprob6 */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_ELPPROB6)
using namespace Elpprob6;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// Elpprob6HPP
