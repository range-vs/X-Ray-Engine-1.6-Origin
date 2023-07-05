object fraFogVol: TfraFogVol
  Left = 533
  Top = 437
  Align = alClient
  BorderStyle = bsNone
  ClientHeight = 327
  ClientWidth = 218
  Color = 10528425
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
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
    Width = 218
    Height = 327
    Align = alTop
    Alignment = taLeftJustify
    ParentColor = True
    TabOrder = 0
    object ebGroup: TExtBtn
      Left = 2
      Top = 22
      Width = 107
      Height = 15
      Align = alNone
      AllowAllUp = True
      BevelShow = False
      HotTrack = True
      HotColor = 15790320
      Caption = 'Group Selected'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBlack
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
      OnClick = ebGroupClick
    end
    object ebUngroup: TExtBtn
      Left = 106
      Top = 22
      Width = 107
      Height = 15
      Align = alNone
      AllowAllUp = True
      BevelShow = False
      HotTrack = True
      HotColor = 15790320
      Caption = 'UnGroup Selected'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBlack
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
      OnClick = ebUngroupClick
    end
    object Panel1: TPanel
      Left = 1
      Top = 1
      Width = 216
      Height = 20
      Align = alTop
      Caption = 'HeaderPanel'
      ShowCaption = False
      TabOrder = 0
      object APHeadLabel1: TLabel
        Left = 1
        Top = 1
        Width = 52
        Height = 13
        Align = alClient
        Alignment = taCenter
        Caption = 'Commands'
        Color = clGray
        ParentColor = False
      end
      object ExtBtn2: TExtBtn
        Left = 204
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
        OnClick = ExtBtn2Click
        ExplicitLeft = 206
        ExplicitTop = -1
        ExplicitHeight = 11
      end
    end
  end
end
