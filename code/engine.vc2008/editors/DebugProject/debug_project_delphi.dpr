program debug_project_delphi;

uses
  Vcl.Forms,
  test_delphi_unit in 'test_delphi_unit.pas' {Form3};

{$R *.res}

begin
  Application.Initialize;
  Application.MainFormOnTaskbar := True;
  Application.CreateForm(TForm3, Form3);
  Application.Run;
end.
