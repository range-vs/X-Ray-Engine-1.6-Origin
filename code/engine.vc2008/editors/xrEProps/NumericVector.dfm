object frmNumericVector: TfrmNumericVector
  Left = 356
  Top = 798
  ActiveControl = seX
  BorderIcons = [biSystemMenu]
  BorderStyle = bsToolWindow
  Caption = 'Numeric'
  ClientHeight = 58
  ClientWidth = 171
  Color = 10528425
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  FormStyle = fsStayOnTop
  KeyPreview = True
  OldCreateOrder = False
  Position = poDefault
  Scaled = False
  OnKeyDown = FormKeyDown
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object RxLabel3: TLabel
    Left = 3
    Top = 3
    Width = 10
    Height = 13
    Caption = 'X:'
  end
  object RxLabel1: TLabel
    Left = 3
    Top = 21
    Width = 10
    Height = 13
    Caption = 'Y:'
  end
  object RxLabel2: TLabel
    Left = 3
    Top = 39
    Width = 10
    Height = 13
    Caption = 'Z:'
  end
  object Bevel1: TBevel
    Left = 14
    Top = 2
    Width = 99
    Height = 16
  end
  object Bevel2: TBevel
    Left = 14
    Top = 20
    Width = 99
    Height = 16
  end
  object Bevel3: TBevel
    Left = 14
    Top = 38
    Width = 99
    Height = 16
  end
  object paBottom: TPanel
    Left = 113
    Top = 0
    Width = 58
    Height = 58
    Align = alRight
    BevelOuter = bvNone
    Color = 10528425
    TabOrder = 0
    object ebOk: TExtBtn
      Left = 1
      Top = 21
      Width = 56
      Height = 17
      Align = alNone
      BevelShow = False
      BtnColor = 10528425
      Caption = 'Ok'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBlack
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
      Transparent = False
      FlatAlwaysEdge = True
      OnClick = ebOkClick
    end
    object ebCancel: TExtBtn
      Left = 1
      Top = 39
      Width = 56
      Height = 17
      Align = alNone
      BevelShow = False
      BtnColor = 10528425
      Caption = 'Cancel'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBlack
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
      Transparent = False
      FlatAlwaysEdge = True
      OnClick = ebCancelClick
    end
    object ebReset: TExtBtn
      Left = 1
      Top = 1
      Width = 56
      Height = 17
      Align = alNone
      BevelShow = False
      BtnColor = 10528425
      Caption = 'Reset'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBlack
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
      Transparent = False
      FlatAlwaysEdge = True
      OnClick = ebResetClick
    end
  end
  object seX: TMultiObjSpinEdit
    Left = 15
    Top = 4
    Width = 98
    Height = 13
    LWSensitivity = 0.1
    ButtonKind = bkLightWave
    Decimal = 3
    Increment = 0.001
    ValueType = vtFloat
    AutoSize = False
    BorderStyle = bsNone
    Color = 10526880
    TabOrder = 1
    OnChange = OnModified
  end
  object seY: TMultiObjSpinEdit
    Left = 15
    Top = 22
    Width = 98
    Height = 13
    LWSensitivity = 0.1
    ButtonKind = bkLightWave
    Decimal = 3
    Increment = 0.001
    ValueType = vtFloat
    AutoSize = False
    BorderStyle = bsNone
    Color = 10526880
    TabOrder = 2
    OnChange = OnModified
  end
  object seZ: TMultiObjSpinEdit
    Left = 15
    Top = 40
    Width = 98
    Height = 13
    LWSensitivity = 0.1
    ButtonKind = bkLightWave
    Decimal = 3
    Increment = 0.001
    ValueType = vtFloat
    AutoSize = False
    BorderStyle = bsNone
    Color = 10526880
    TabOrder = 3
    OnChange = OnModified
  end
end
