unit test_delphi_unit;

interface

uses
  Winapi.Windows, Winapi.Messages, System.SysUtils, System.Variants, System.Classes, Vcl.Graphics,
  Vcl.Controls, Vcl.Forms, Vcl.Dialogs, Vcl.StdCtrls, ShellApi,
  ElXPThemedControl, ElTree, MxMenus, Vcl.Menus ;

type
TTestProc = reference to procedure(btn: TButton; i: Integer);

  TForm3 = class(TForm)
    ElTree1: TElTree;
    Button1: TButton;
    Button2: TButton;
    procedure Button1Click(Sender: TObject);

    procedure KeyDownTest();
    function FindNewFocused(): boolean;
    procedure Iterate(IterateProc: TTestProc);
    procedure Button2Click(Sender: TObject);

  end;

var
  Form3: TForm3;

implementation

{$R *.dfm}


procedure TForm3.Button1Click(Sender: TObject);
begin
  KeyDownTest();    // -->  KeyDownTest
end;

procedure TForm3.KeyDownTest();
begin
  FindNewFocused();  // -->  FindNewFocused
end;

procedure TForm3.Button2Click(Sender: TObject);
var
  Menu: TPopupMenu;
  MenuMx: TMxPopupMenu;
  MenuItem: TMenuItem;
  i: Integer;
begin
//   Menu := TPopupMenu.Create(nil);
//   Menu.Alignment := TPopupAlignment.paLeft;
//   for i := 1 to 10 do
//   begin
//     MenuItem := TMenuItem.Create(nil);
//     MenuItem.Caption := 'Teeeeeeeeeeest...';
//     Menu.Items.Add(MenuItem);
//   end;
//   Menu.Popup(100, 100);
   MenuMx := TMxPopupMenu.Create(nil);
   MenuMx.Style := TMxMenuStyle.msOwnerDraw;
   //MenuMx.Alignment := TPopupAlignment.paRight;
   for i := 1 to 3 do
   begin
     MenuItem := TMenuItem.Create(nil);
     MenuItem.Caption := 'Teeeeeeeeeeest...';
     MenuMx.Items.Add(MenuItem);
   end;
   MenuMx.Popup(400, 100);
end;

function TForm3.FindNewFocused(): boolean;

var
  IntNextVis: TTestProc;

begin
  IntNextVis := procedure(btn: TButton; i: Integer)
    begin
      ShowMessage(btn.Caption);  // ----> ERROR: ACCESS VOILATION!
    end;
  Iterate(IntNextVis); // -->  Iterate
  Result := True;
end;

procedure TForm3.Iterate(IterateProc: TTestProc);

  procedure IntIterate(btn: TButton; i: Integer);
  begin
      if(i > 2) then
        Exit;       // --> break reqursive
      if(i = 2) then
        IterateProc(btn, i) // -->  FindNewFocused.IntNextVis
      else
        IntIterate(btn, i + 1); // -->  Iterate.IntIterate
  end;

var
  i: Integer;
begin
    i := 0;
    //ShowMessage(Button1.Caption); // ----> WORKING!
    IntIterate(Button1, i);  // -->  Iterate.IntIterate
end;
end.


// написать на стек с просьбой об испарвлени БЕЗ ВЫНЕСЕНИЯ ПРОЦЕДУРЫ В ГЛОБАЛЬНУЮ ОБЛАСТЬ ВИДИМОСТИ

