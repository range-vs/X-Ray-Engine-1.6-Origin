unit test_delphi_unit;

interface

uses
  Winapi.Windows, Winapi.Messages, System.SysUtils, System.Variants, System.Classes, Vcl.Graphics,
  Vcl.Controls, Vcl.Forms, Vcl.Dialogs, Vcl.StdCtrls, ShellApi,
  ElXPThemedControl, ElTree, MxMenus, Vcl.Menus, ExtBtn, Vcl.ExtCtrls, multi_edit,
  ElScrollBar, ElTreeStdEditors;

type
TTestProc = reference to procedure(btn: TButton; i: Integer);

  TForm3 = class(TForm)
    Panel1: TPanel;
    ExtBtn1: TExtBtn;
    ExtBtn2: TExtBtn;
    MultiObjSpinEdit1: TMultiObjSpinEdit;
    ElTree1: TElTree;
    tvProperties: TElTree;
    procedure FormCreate(Sender: TObject);
    procedure tvPropertiesItemDraw(Sender: TObject; Item: TElTreeItem;
      Surface: TCanvas; R: TRect; SectionIndex: Integer);
    

  end;

var
  Form3: TForm3;

implementation

{$R *.dfm}


procedure TForm3.FormCreate(Sender: TObject);
var
  btn: TExtBtn;
  Loc: TRect;

begin
  btn := TExtBtn.Create(nil);
  SetRect(Loc, 0, 0, ClientWidth - 15 - 2, ClientHeight + 1);
  SendMessage(Handle, EM_SETRECTNP, 0, LPARAM(@Loc));  // Longint
  tvProperties.Refresh;
 
end;

procedure TForm3.tvPropertiesItemDraw(Sender: TObject; Item: TElTreeItem;
  Surface: TCanvas; R: TRect; SectionIndex: Integer);
var
   l: Int64;
begin
   l := Item.Tag;
end;

end.
