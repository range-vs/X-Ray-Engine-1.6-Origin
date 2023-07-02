object fraLight: TfraLight
  Left = 521
  Top = 407
  VertScrollBar.Visible = False
  Align = alClient
  BorderStyle = bsNone
  ClientHeight = 115
  ClientWidth = 217
  Color = 10528425
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clBlack
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = True
  Scaled = False
  PixelsPerInch = 96
  TextHeight = 13
  object paCommands: TPanel
    Left = 0
    Top = 0
    Width = 217
    Height = 55
    Align = alTop
    ParentColor = True
    TabOrder = 0
    object ebUseSelInD3D: TExtBtn
      Left = 2
      Top = 22
      Width = 105
      Height = 15
      Align = alNone
      AllowAllUp = True
      BevelShow = False
      HotTrack = True
      HotColor = 15790320
      Caption = 'Enable Sel'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBlack
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
      OnClick = ebUseSelInD3DClick
    end
    object ebUnuseSelInD3D: TExtBtn
      Left = 2
      Top = 37
      Width = 105
      Height = 15
      Align = alNone
      AllowAllUp = True
      BevelShow = False
      HotTrack = True
      HotColor = 15790320
      Caption = 'Disable Sel'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBlack
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
      OnClick = ebUnuseSelInD3DClick
    end
    object ebUseAllInD3D: TExtBtn
      Left = 110
      Top = 22
      Width = 105
      Height = 15
      Align = alNone
      AllowAllUp = True
      BevelShow = False
      HotTrack = True
      HotColor = 15790320
      Caption = 'Enable All'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBlack
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
      OnClick = ebUseAllInD3DClick
    end
    object ebUnuseAllInD3D: TExtBtn
      Left = 110
      Top = 37
      Width = 105
      Height = 15
      Align = alNone
      AllowAllUp = True
      BevelShow = False
      HotTrack = True
      HotColor = 15790320
      Caption = 'Disable All'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBlack
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
      OnClick = ebUnuseAllInD3DClick
    end
    object Panel1: TPanel
      Left = 1
      Top = 1
      Width = 215
      Height = 20
      Align = alTop
      Caption = 'HeaderPanel'
      ShowCaption = False
      TabOrder = 0
      object APHeadLabel1: TLabel
        Left = 1
        Top = 1
        Width = 202
        Height = 18
        Align = alClient
        Alignment = taCenter
        Caption = 'Affect in D3D'
        Color = clGray
        ParentColor = False
        ExplicitWidth = 64
        ExplicitHeight = 13
      end
      object ExtBtn2: TExtBtn
        Left = 203
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
        OnClick = PaneMinClick
        ExplicitLeft = 185
        ExplicitTop = 2
        ExplicitHeight = 11
      end
    end
  end
end
