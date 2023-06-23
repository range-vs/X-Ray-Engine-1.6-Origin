object frmMain: TfrmMain
  Left = 426
  Top = 417
  VertScrollBar.Visible = False
  ClientHeight = 413
  ClientWidth = 754
  Color = clBtnFace
  Constraints.MinHeight = 446
  Constraints.MinWidth = 660
  DoubleBuffered = True
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  KeyPreview = True
  OldCreateOrder = False
  Position = poDefault
  Scaled = False
  OnClose = FormClose
  OnCloseQuery = FormCloseQuery
  OnCreate = FormCreate
  OnKeyDown = FormKeyDown
  OnResize = FormResize
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object paBottomBar: TPanel
    Left = 0
    Top = 396
    Width = 754
    Height = 17
    Align = alBottom
    BevelInner = bvLowered
    BevelOuter = bvNone
    TabOrder = 0
  end
  object paMain: TPanel
    Left = 0
    Top = 0
    Width = 516
    Height = 396
    Align = alClient
    BevelOuter = bvNone
    TabOrder = 1
    object paTopBar: TPanel
      Left = 0
      Top = 0
      Width = 516
      Height = 18
      Align = alTop
      BevelOuter = bvNone
      Color = 10528425
      DoubleBuffered = True
      FullRepaint = False
      ParentBackground = False
      ParentDoubleBuffered = False
      TabOrder = 0
    end
    object paRender: TPanel
      Left = 0
      Top = 18
      Width = 516
      Height = 378
      Align = alClient
      BevelOuter = bvNone
      Color = 4868682
      TabOrder = 1
      OnResize = paRenderResize
      object D3DWindow: TD3DWindow
        Left = 6
        Top = 6
        Width = 513
        Height = 371
        FocusedColor = 9502719
        UnfocusedColor = 9211020
        OnChangeFocus = D3DWindowChangeFocus
        BorderStyle = bsNone
        Color = 5592405
        TabOrder = 0
        OnKeyDown = D3DWindowKeyDown
        OnKeyPress = D3DWindowKeyPress
        OnKeyUp = D3DWindowKeyUp
        OnMouseDown = D3DWindowMouseDown
        OnMouseMove = D3DWindowMouseMove
        OnMouseUp = D3DWindowMouseUp
        OnResize = D3DWindowResize
        OnPaint = D3DWindowPaint
      end
    end
  end
  object paLeftBarMain: TPanel
    Left = 516
    Top = 0
    Width = 238
    Height = 396
    Align = alRight
    AutoSize = True
    Caption = 'paLeftBarMain'
    TabOrder = 2
    object paLeftBar: TCategoryPanelGroup
      Left = 1
      Top = 18
      Width = 236
      Height = 377
      VertScrollBar.Tracking = True
      VertScrollBar.Visible = False
      Align = alClient
      BevelInner = bvLowered
      BevelOuter = bvNone
      BiDiMode = bdLeftToRight
      DoubleBuffered = True
      Color = 10528425
      GradientBaseColor = 10528425
      HeaderFont.Charset = DEFAULT_CHARSET
      HeaderFont.Color = clWindowText
      HeaderFont.Height = -11
      HeaderFont.Name = 'Tahoma'
      HeaderFont.Style = []
      ParentBiDiMode = False
      ParentDoubleBuffered = False
      TabOrder = 0
      object paTools: TCategoryPanel
        Top = 0
        Height = 300
        Caption = 'Toolbar'
        FullRepaint = False
        ParentColor = True
        TabOrder = 0
        OnCollapse = paToolsCollapse
        OnExpand = paToolsExpand
        ExplicitLeft = -3
        ExplicitTop = 3
      end
    end
    object Panel1: TPanel
      Left = 1
      Top = 1
      Width = 236
      Height = 17
      Align = alTop
      Caption = 'Panel1'
      Color = 10528425
      ParentBackground = False
      ShowCaption = False
      TabOrder = 1
      object sbToolsMin: TExtBtn
        Left = 220
        Top = 1
        Width = 15
        Height = 15
        Align = alRight
        BtnColor = 10528425
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        Glyph.Data = {
          DE000000424DDE00000000000000360000002800000007000000070000000100
          180000000000A8000000120B0000120B00000000000000000000FFFFFFFFFFFF
          FFFFFFFFFFFFFFFFFF000000FFFFFF000000FFFFFFFFFFFFFFFFFFFFFFFF0000
          00000000FFFFFF000000FFFFFFFFFFFFFFFFFF000000000000000000FFFFFF00
          0000FFFFFFFFFFFF000000000000000000000000FFFFFF000000FFFFFFFFFFFF
          FFFFFF000000000000000000FFFFFF000000FFFFFFFFFFFFFFFFFFFFFFFF0000
          00000000FFFFFF000000FFFFFFFFFFFFFFFFFFFFFFFFFFFFFF000000FFFFFF00
          0000}
        ParentFont = False
        OnClick = sbToolsMinClick
        ExplicitLeft = 1
        ExplicitTop = 23
        ExplicitHeight = 212
      end
    end
  end
  object fsStorage: TFormStorage
    IniSection = 'Main Form'
    Options = [fpPosition]
    RegistryRoot = prLocalMachine
    Version = 1
    OnSavePlacement = fsStorageSavePlacement
    StoredProps.Strings = (
      'paLeftBar.Tag')
    StoredValues = <>
    Left = 193
    Top = 33
  end
  object tmRefresh: TTimer
    Enabled = False
    OnTimer = tmRefreshTimer
    Left = 129
    Top = 33
  end
end
