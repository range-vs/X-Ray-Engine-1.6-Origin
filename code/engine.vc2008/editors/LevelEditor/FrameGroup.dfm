object fraGroup: TfraGroup
  Left = 505
  Top = 307
  VertScrollBar.Visible = False
  Align = alClient
  BorderStyle = bsNone
  ClientHeight = 615
  ClientWidth = 213
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
    Width = 213
    Height = 18
    Align = alTop
    ParentColor = True
    TabOrder = 0
    object ExtBtn2: TExtBtn
      Left = 1
      Top = 1
      Width = 211
      Height = 17
      Align = alTop
      Caption = 'Commands'
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
      ExplicitLeft = 2
      ExplicitTop = 0
      ExplicitWidth = 209
    end
    object ebUngroup: TExtBtn
      Left = 2
      Top = 32
      Width = 107
      Height = 15
      Align = alNone
      AllowAllUp = True
      BevelShow = False
      HotTrack = True
      HotColor = 15790320
      Caption = 'Ungroup'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBlack
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
      OnClick = ebUngroupClick
    end
    object ebGroup: TExtBtn
      Left = 2
      Top = 16
      Width = 107
      Height = 15
      Align = alNone
      AllowAllUp = True
      BevelShow = False
      HotTrack = True
      HotColor = 15790320
      Caption = 'Group'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBlack
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
      OnClick = ebMakeGroupClick
    end
    object ebSaveSelected: TExtBtn
      Left = 116
      Top = 33
      Width = 94
      Height = 15
      Align = alNone
      AllowAllUp = True
      BevelShow = False
      HotTrack = True
      HotColor = 15790320
      Caption = 'Save As...'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBlack
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
      OnClick = ebSaveSelectedClick
    end
    object ebMakeThumbnail: TExtBtn
      Left = 116
      Top = 18
      Width = 95
      Height = 15
      Align = alNone
      AllowAllUp = True
      BevelShow = False
      HotTrack = True
      HotColor = 15790320
      Caption = 'Make Thumbnail'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBlack
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
      OnClick = ebMakeThumbnailClick
    end
  end
  object paCurrentObject: TPanel
    Left = 0
    Top = 18
    Width = 213
    Height = 51
    Align = alTop
    Color = 10528425
    TabOrder = 1
    object APHeadLabel2: TLabel
      Left = 1
      Top = 1
      Width = 211
      Height = 13
      Align = alTop
      Alignment = taCenter
      Caption = 'Current Object'
      Color = clGray
      ParentColor = False
      ExplicitWidth = 68
    end
    object ebSelect: TExtBtn
      Left = 7
      Top = 16
      Width = 94
      Height = 15
      Align = alNone
      BevelShow = False
      HotTrack = True
      HotColor = 15790320
      Caption = 'Select...'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBlack
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
      OnClick = ebSelectClick
    end
    object MxLabel1: TMxLabel
      Left = 4
      Top = 32
      Width = 36
      Height = 13
      Caption = 'Curent:'
      ShadowColor = clGray
      ShadowSize = 0
      ShadowPos = spRightBottom
    end
    object lbCurrent: TMxLabel
      Left = 42
      Top = 32
      Width = 172
      Height = 13
      AutoSize = False
      Caption = '<empty>'
      ShadowColor = 15000804
      ShadowPos = spRightBottom
    end
    object ebReloadRefs: TExtBtn
      Left = 109
      Top = 16
      Width = 102
      Height = 15
      Align = alNone
      AllowAllUp = True
      BevelShow = False
      HotTrack = True
      HotColor = 15790320
      Caption = 'Reload Refs'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBlack
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
      OnClick = ebReloadRefsClick
    end
  end
  object Panel2: TPanel
    Left = 0
    Top = 154
    Width = 213
    Height = 51
    Align = alTop
    Color = 10528425
    TabOrder = 2
    ExplicitTop = 115
    object Label1: TLabel
      Left = 1
      Top = 1
      Width = 211
      Height = 13
      Align = alTop
      Alignment = taCenter
      Caption = 'Pivot Alignment'
      Color = clGray
      ParentColor = False
      ExplicitWidth = 73
    end
    object ebCenterToGroup: TExtBtn
      Left = 2
      Top = 16
      Width = 215
      Height = 15
      Align = alNone
      AllowAllUp = True
      BevelShow = False
      HotTrack = True
      HotColor = 15790320
      Caption = 'Center To Group'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBlack
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
      OnClick = ebCenterToGroupClick
    end
    object ebAlignToObject: TExtBtn
      Left = 2
      Top = 32
      Width = 215
      Height = 15
      Align = alNone
      AllowAllUp = True
      BevelShow = False
      HotTrack = True
      HotColor = 15790320
      Caption = 'Align To Object...'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBlack
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
      OnClick = ebAlignToObjectClick
    end
  end
  object paSelectObject: TPanel
    Left = 0
    Top = 69
    Width = 213
    Height = 85
    Align = alTop
    Color = 10528425
    TabOrder = 3
    object Bevel3: TBevel
      Left = 154
      Top = 59
      Width = 45
      Height = 16
    end
    object Label2: TLabel
      Left = 7
      Top = 22
      Width = 66
      Height = 27
      Caption = 'Select by Current:'
      WordWrap = True
    end
    object ExtBtn1: TExtBtn
      Left = 97
      Top = 27
      Width = 27
      Height = 14
      Align = alNone
      BevelShow = False
      HotTrack = True
      Caption = '+'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBlack
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
      OnClick = ExtBtn1Click
    end
    object ExtBtn3: TExtBtn
      Left = 130
      Top = 27
      Width = 27
      Height = 14
      Align = alNone
      BevelShow = False
      HotTrack = True
      Caption = '-'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBlack
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
      OnClick = ExtBtn3Click
    end
    object ExtBtn6: TExtBtn
      Left = 97
      Top = 60
      Width = 27
      Height = 14
      Align = alNone
      BevelShow = False
      HotTrack = True
      Caption = '=%'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBlack
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
      OnClick = ExtBtn6Click
    end
    object Label4: TLabel
      Left = 201
      Top = 61
      Width = 8
      Height = 13
      Caption = '%'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBlack
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object ExtBtn7: TExtBtn
      Left = 126
      Top = 60
      Width = 27
      Height = 14
      Align = alNone
      BevelShow = False
      HotTrack = True
      Caption = '+%'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBlack
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
      OnClick = ExtBtn7Click
    end
    object Label6: TLabel
      Left = 7
      Top = 50
      Width = 84
      Height = 29
      Caption = 'Select by Selected:'
      WordWrap = True
    end
    object seSelPercent: TMultiObjSpinEdit
      Left = 155
      Top = 61
      Width = 43
      Height = 13
      LWSensitivity = 1.000000000000000000
      ButtonKind = bkLightWave
      MaxValue = 100.000000000000000000
      MinValue = 1.000000000000000000
      Value = 100.000000000000000000
      AutoSize = False
      BorderStyle = bsNone
      Color = 12698049
      TabOrder = 0
      OnKeyPress = seSelPercentKeyPress
    end
    object Panel1: TPanel
      Left = 1
      Top = 1
      Width = 211
      Height = 20
      Align = alTop
      Caption = 'HeaderPanel'
      ShowCaption = False
      TabOrder = 1
      object APHeadLabel3: TLabel
        Left = 1
        Top = 1
        Width = 198
        Height = 18
        Align = alClient
        Alignment = taCenter
        Caption = 'Reference Select'
        Color = clGray
        ParentColor = False
        ExplicitWidth = 83
        ExplicitHeight = 13
      end
      object ExtBtn5: TExtBtn
        Left = 199
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
        ExplicitLeft = 200
        ExplicitTop = 2
        ExplicitHeight = 11
      end
    end
  end
  object pmGroupCommands: TMxPopupMenu
    Alignment = paCenter
    AutoPopup = False
    TrackButton = tbLeftButton
    MarginStartColor = 10921638
    MarginEndColor = 2763306
    BKColor = 10528425
    SelColor = clBlack
    SelFontColor = 10526880
    SepHColor = 1644825
    SepLColor = 13158600
    LeftMargin = 10
    Style = msOwnerDraw
    Left = 11
    Top = 199
    object N17: TMenuItem
      Caption = 'Group'
      OnClick = ebMakeGroupClick
    end
    object Ungroup1: TMenuItem
      Caption = 'Ungroup'
      OnClick = ebUngroupClick
    end
    object N1: TMenuItem
      Caption = '-'
    end
    object MakeThumbnail1: TMenuItem
      Caption = 'Make Thumbnail'
      OnClick = ebMakeThumbnailClick
    end
    object N2: TMenuItem
      Caption = '-'
    end
    object SaveAs1: TMenuItem
      Caption = 'Save As...'
      OnClick = ebSaveSelectedClick
    end
  end
end
