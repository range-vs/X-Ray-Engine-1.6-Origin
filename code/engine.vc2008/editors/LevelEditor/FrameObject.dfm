object fraObject: TfraObject
  Left = 679
  Top = 503
  VertScrollBar.Visible = False
  Align = alClient
  AutoSize = True
  BorderStyle = bsNone
  ClientHeight = 372
  ClientWidth = 218
  Color = 10528425
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clBlack
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = True
  Scaled = False
  OnCreate = FormCreate
  OnDestroy = FormDestroy
  OnHide = FormHide
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object paSelectObject: TPanel
    Left = 0
    Top = 60
    Width = 218
    Height = 85
    Align = alTop
    Color = 10528425
    TabOrder = 0
    object Bevel3: TBevel
      Left = 153
      Top = 56
      Width = 45
      Height = 16
    end
    object Label1: TLabel
      Left = 7
      Top = 19
      Width = 47
      Height = 26
      Caption = 'Select by Current:'
      WordWrap = True
    end
    object ExtBtn1: TExtBtn
      Left = 97
      Top = 19
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
      OnClick = ebSelectByRefsClick
    end
    object ExtBtn3: TExtBtn
      Left = 126
      Top = 19
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
      OnClick = ebDeselectByRefsClick
    end
    object ExtBtn6: TExtBtn
      Left = 97
      Top = 50
      Width = 27
      Height = 30
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
      OnClick = ebMultiSelectByRefMoveClick
    end
    object Label4: TLabel
      Left = 204
      Top = 58
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
      Left = 122
      Top = 51
      Width = 27
      Height = 29
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
      OnClick = ebMultiSelectByRefAppendClick
    end
    object Label6: TLabel
      Left = 7
      Top = 50
      Width = 47
      Height = 26
      Caption = 'Select by Selected:'
      WordWrap = True
    end
    object seSelPercent: TMultiObjSpinEdit
      Left = 155
      Top = 57
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
    object Panel3: TPanel
      Left = 1
      Top = 1
      Width = 216
      Height = 20
      Align = alTop
      Caption = 'HeaderPanel'
      ShowCaption = False
      TabOrder = 1
      object APHeadLabel3: TLabel
        Left = 1
        Top = 1
        Width = 203
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
        OnClick = PaneMinClick
        ExplicitLeft = 205
        ExplicitTop = 4
        ExplicitHeight = 11
      end
    end
  end
  object paCommands: TPanel
    Left = 0
    Top = 0
    Width = 218
    Height = 60
    Align = alTop
    Color = 10528425
    TabOrder = 1
    ExplicitTop = -4
    object ebMultiAppend: TExtBtn
      Left = 2
      Top = 20
      Width = 215
      Height = 15
      Align = alNone
      BevelShow = False
      HotTrack = True
      HotColor = 15790320
      Caption = 'Multiple Append'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBlack
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      Margin = 13
      ParentFont = False
      OnClick = ebMultiAppendClick
    end
    object Bevel4: TBevel
      Left = 1
      Top = 41
      Width = 216
      Height = 1
      Shape = bsBottomLine
    end
    object ebRandomAppendMode: TExtBtn
      Left = 1
      Top = 41
      Width = 108
      Height = 17
      Align = alNone
      AllowAllUp = True
      BevelShow = False
      HotTrack = True
      HotColor = 15790320
      BtnColor = 10528425
      GroupIndex = 1
      Caption = 'Random Append'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBlack
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      Glyph.Data = {
        6E040000424D6E04000000000000360000002800000028000000090000000100
        18000000000038040000120B0000120B00000000000000000000FF00FF000000
        C4C4C4C4C4C4C4C4C4C4C4C4C4C4C4C4C4C4C4C4C4FF00FFFF00FF000000C4C4
        C4C4C4C4C4C4C4C4C4C4C4C4C4C4C4C4C4C4C4FF00FFFF00FF000000C4C4C4C4
        C4C4C4C4C4C4C4C4C4C4C4C4C4C4C4C4C4FF00FFFF00FFFF00FFFF00FFFF00FF
        FF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FF0000009999999999999999
        99999999999999999999C4C4C4FF00FFFF00FF00000099999999999999999999
        9999999999999999C4C4C4FF00FFFF00FF000000999999999999999999999999
        999999999999C4C4C4FF00FFC4C4C40000000000000000000000000000000000
        00000000FF00FFFF00FFFF00FF00000099999999999999999999999999999999
        9999C4C4C4FF00FFFF00FF000000999999999999999999999999999999999999
        C4C4C4FF00FFFF00FF000000999999999999999999999999999999999999C4C4
        C4FF00FFC4C4C4999999999999999999999999999999999999000000FF00FFFF
        00FFFF00FF000000999999999999999999999999999999999999C4C4C4FF00FF
        FF00FF000000999999999999999999999999999999999999C4C4C4FF00FFFF00
        FF000000999999999999999999999999999999999999C4C4C4FF00FFC4C4C499
        9999999999999999999999999999999999000000FF00FFFF00FFFF00FF000000
        999999999999999999999999999999999999C4C4C4FF00FFFF00FF0000009999
        99999999999999999999999999999999C4C4C4FF00FFFF00FF00000099999999
        9999999999999999999999999999C4C4C4FF00FFC4C4C4999999999999999999
        999999999999999999000000FF00FFFF00FFFF00FF0000009999999999999999
        99999999999999999999C4C4C4FF00FFFF00FF00000099999999999999999999
        9999999999999999C4C4C4FF00FFFF00FF000000999999999999999999999999
        999999999999C4C4C4FF00FFC4C4C49999999999999999999999999999999999
        99000000FF00FFFF00FFFF00FF00000099999999999999999999999999999999
        9999C4C4C4FF00FFFF00FF000000999999999999999999999999999999999999
        C4C4C4FF00FFFF00FF000000999999999999999999999999999999999999C4C4
        C4FF00FFC4C4C4999999999999999999999999999999999999000000FF00FFFF
        00FFFF00FF000000000000000000000000000000000000000000000000FF00FF
        FF00FF000000000000000000000000000000000000000000000000FF00FFFF00
        FF000000000000000000000000000000000000000000000000FF00FFC4C4C499
        9999999999999999999999999999999999000000FF00FFFF00FFFF00FFFF00FF
        FF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00
        FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF
        00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFC4C4C4C4C4C4C4C4C4C4C4C4
        C4C4C4C4C4C4C4C4C4C4C4C4FF00FFFF00FF}
      Margin = 3
      NumGlyphs = 4
      ParentFont = False
      Spacing = 3
      OnClick = ebRandomAppendModeClick
    end
    object ExtBtn8: TExtBtn
      Left = 107
      Top = 24
      Width = 107
      Height = 17
      Align = alNone
      BevelShow = False
      HotTrack = True
      HotColor = 15790320
      Caption = 'Random Props...'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBlack
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
      OnClick = ExtBtn8Click
    end
    object Panel2: TPanel
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
        Width = 203
        Height = 18
        Align = alClient
        Alignment = taCenter
        Caption = 'Commands'
        Color = clGray
        ParentColor = False
        ExplicitWidth = 52
        ExplicitHeight = 13
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
        OnClick = PaneMinClick
        ExplicitLeft = 205
        ExplicitTop = 6
        ExplicitHeight = 11
      end
    end
  end
  object paCurrentObject: TPanel
    Left = 0
    Top = 145
    Width = 218
    Height = 227
    Align = alClient
    Color = 10528425
    Constraints.MinHeight = 175
    TabOrder = 2
    OnResize = paCurrentObjectResize
    object APHeadLabel2: TLabel
      Left = 1
      Top = 38
      Width = 216
      Height = 13
      Align = alTop
      Alignment = taCenter
      Caption = 'Current Object'
      Color = clGray
      ParentColor = False
      ExplicitWidth = 68
    end
    object Bevel2: TBevel
      Left = 1
      Top = 37
      Width = 216
      Height = 1
      Align = alTop
      Shape = bsBottomLine
      ExplicitTop = 50
    end
    object paItems: TPanel
      Left = 1
      Top = 51
      Width = 216
      Height = 175
      Align = alClient
      AutoSize = True
      BevelOuter = bvNone
      ParentColor = True
      TabOrder = 0
    end
    object Panel1: TPanel
      Left = 1
      Top = 1
      Width = 216
      Height = 36
      Align = alTop
      BevelOuter = bvNone
      Caption = 'HeaderPanel'
      ParentColor = True
      ShowCaption = False
      TabOrder = 1
      object ExtBtn4: TExtBtn
        Left = 1
        Top = 6
        Width = 215
        Height = 15
        Align = alNone
        BevelShow = False
        HotTrack = True
        HotColor = 15790320
        Caption = 'Select ...'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        ParentFont = False
        OnClick = ExtBtn4Click
      end
      object ExtBtn9: TExtBtn
        Left = 1
        Top = 20
        Width = 215
        Height = 15
        Align = alNone
        BevelShow = False
        HotTrack = True
        HotColor = 15790320
        Caption = 'Refresh List'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        ParentFont = False
        OnClick = ExtBtn9Click
      end
    end
  end
  object fsStorage: TFormStorage
    IniSection = 'FrameObject'
    Options = []
    Version = 3
    StoredValues = <>
    Left = 144
    Top = 288
  end
end
