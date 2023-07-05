object fraPortal: TfraPortal
  Left = 129
  Top = 69
  Width = 225
  Height = 290
  VertScrollBar.ButtonSize = 11
  VertScrollBar.Range = 257
  VertScrollBar.Smooth = True
  VertScrollBar.Style = ssFlat
  VertScrollBar.Visible = False
  Align = alClient
  BorderStyle = bsNone
  Color = 10528425
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clBlack
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = True
  Scaled = False
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object paCommands: TPanel
    Left = 0
    Top = 0
    Width = 225
    Height = 290
    Align = alTop
    ParentColor = True
    TabOrder = 0
    object ebInvertOrient: TExtBtn
      Left = 1
      Top = 21
      Width = 223
      Height = 15
      Align = alTop
      BevelShow = False
      HotTrack = True
      HotColor = 15790320
      Caption = 'Invert Orientation'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBlack
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
      OnClick = ebInvertOrientClick
      ExplicitTop = 14
      ExplicitWidth = 215
    end
    object ebComputeAllPortals: TExtBtn
      Left = 1
      Top = 36
      Width = 223
      Height = 15
      Align = alTop
      BevelShow = False
      HotTrack = True
      HotColor = 15790320
      Caption = 'Compute All Portals'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBlack
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
      OnClick = ebComputeAllPortalsClick
      ExplicitTop = 29
      ExplicitWidth = 215
    end
    object ebComputeSelPortals: TExtBtn
      Left = 1
      Top = 51
      Width = 223
      Height = 15
      Align = alTop
      BevelShow = False
      HotTrack = True
      HotColor = 15790320
      Caption = 'Compute Sel. Portals'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBlack
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
      OnClick = ebComputeClick
      ExplicitTop = 44
      ExplicitWidth = 215
    end
    object ExtBtn1: TExtBtn
      Left = 1
      Top = 66
      Width = 223
      Height = 15
      Align = alTop
      BevelShow = False
      HotTrack = True
      HotColor = 15790320
      Caption = 'Remove Similar'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBlack
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
      OnClick = ExtBtn1Click
      ExplicitTop = 59
      ExplicitWidth = 215
    end
    object Panel1: TPanel
      Left = 1
      Top = 1
      Width = 223
      Height = 20
      Align = alTop
      Caption = 'HeaderPanel'
      ShowCaption = False
      TabOrder = 0
      object APHeadLabel1: TLabel
        Left = 1
        Top = 1
        Width = 47
        Height = 13
        Align = alClient
        Alignment = taCenter
        Caption = 'Command'
        Color = clGray
        ParentColor = False
      end
      object ExtBtn2: TExtBtn
        Left = 211
        Top = 1
        Width = 11
        Height = 18
        Align = alRight
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        Glyph.Data = {
          DE000000424DDE00000000000000360000002800000007000000070000000100
          180000000000A8000000120B0000120B00000000000000000000FFFFFFFFFFFF
          FFFFFFFFFFFFFFFFFFFFFFFFFFFFFF000000FFFFFFFFFFFFFFFFFFFFFFFFFFFF
          FFFFFFFFFFFFFF000000FFFFFFFFFFFFFFFFFF000000FFFFFFFFFFFFFFFFFF00
          0000FFFFFFFFFFFF000000000000000000FFFFFFFFFFFF000000FFFFFF000000
          000000000000000000000000FFFFFF0000000000000000000000000000000000
          00000000000000000000FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF00
          0000}
        ParentFont = False
        OnClick = PanelMinClick
        ExplicitLeft = 185
        ExplicitTop = 2
        ExplicitHeight = 11
      end
    end
  end
  object fsStorage: TFormStorage
    IniSection = 'FramePortal'
    Options = []
    Version = 1
    StoredProps.Strings = (
      'paCommands.Height'
      'paCommands.Tag')
    StoredValues = <>
  end
end
