object fraSpawn: TfraSpawn
  Left = 494
  Top = 384
  VertScrollBar.Visible = False
  Align = alClient
  BorderStyle = bsNone
  ClientHeight = 282
  ClientWidth = 219
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
  object paCurrent: TPanel
    Left = 0
    Top = 118
    Width = 219
    Height = 164
    Align = alClient
    Constraints.MinHeight = 164
    ParentColor = True
    TabOrder = 0
    ExplicitTop = 109
    object APHeadLabel1: TLabel
      Left = 1
      Top = 1
      Width = 217
      Height = 13
      Align = alTop
      Alignment = taCenter
      Caption = 'Current Spawn'
      Color = clGray
      ParentColor = False
      ExplicitWidth = 70
    end
    object Bevel1: TBevel
      Left = 1
      Top = 14
      Width = 217
      Height = 1
      Align = alTop
      Shape = bsSpacer
      ExplicitWidth = 215
    end
    object paItems: TPanel
      Left = 1
      Top = 15
      Width = 217
      Height = 148
      Align = alClient
      BevelOuter = bvNone
      ParentColor = True
      TabOrder = 0
    end
  end
  object paCommands: TPanel
    Left = 0
    Top = 58
    Width = 219
    Height = 60
    Align = alTop
    ParentColor = True
    TabOrder = 1
    object ebAttachObject: TExtBtn
      Left = 2
      Top = 22
      Width = 215
      Height = 15
      Align = alNone
      AllowAllUp = True
      BevelShow = False
      HotTrack = True
      HotColor = 15790320
      GroupIndex = 1
      Caption = 'Attach Object...'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBlack
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
      OnClick = ebAttachObjectClick
    end
    object evDetachObject: TExtBtn
      Left = 2
      Top = 37
      Width = 215
      Height = 15
      Align = alNone
      BevelShow = False
      HotTrack = True
      HotColor = 15790320
      Caption = 'Detach Object'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBlack
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
      OnClick = evDetachObjectClick
    end
    object Panel2: TPanel
      Left = 1
      Top = 1
      Width = 217
      Height = 20
      Align = alTop
      Caption = 'HeaderPanel'
      ShowCaption = False
      TabOrder = 0
      ExplicitTop = 14
      object ExtBtn1: TExtBtn
        Left = 205
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
        ExplicitLeft = 211
        ExplicitTop = -3
      end
      object Label1: TLabel
        Left = 1
        Top = 1
        Width = 204
        Height = 18
        Align = alClient
        Alignment = taCenter
        Caption = 'Commands'
        Color = clGray
        ParentColor = False
        ExplicitWidth = 52
        ExplicitHeight = 13
      end
    end
  end
  object paSelectObject: TPanel
    Left = 0
    Top = 0
    Width = 219
    Height = 58
    Align = alTop
    Color = 10528425
    TabOrder = 2
    object ebSelectByRefs: TExtBtn
      Left = 97
      Top = 15
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
    object ebDeselectByRefs: TExtBtn
      Left = 126
      Top = 15
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
    object ebMultiSelectByRefMove: TExtBtn
      Left = 97
      Top = 29
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
      OnClick = ebMultiSelectByRefMoveClick
    end
    object Bevel2: TBevel
      Left = 154
      Top = 28
      Width = 45
      Height = 16
    end
    object Label2: TLabel
      Left = 201
      Top = 30
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
    object ebMultiSelectByRefAppend: TExtBtn
      Left = 126
      Top = 29
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
      OnClick = ebMultiSelectByRefAppendClick
    end
    object Label3: TLabel
      Left = 5
      Top = 43
      Width = 45
      Height = 13
      Caption = 'Selected:'
      WordWrap = True
    end
    object Label5: TLabel
      Left = 5
      Top = 16
      Width = 47
      Height = 26
      Caption = 'Select by Current:'
      WordWrap = True
    end
    object seSelPercent: TMultiObjSpinEdit
      Left = 155
      Top = 30
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
      Width = 217
      Height = 20
      Align = alTop
      Caption = 'HeaderPanel'
      ShowCaption = False
      TabOrder = 1
      ExplicitTop = 14
      object APHeadLabel3: TLabel
        Left = 1
        Top = 1
        Width = 204
        Height = 18
        Align = alClient
        Alignment = taCenter
        Caption = 'Reference Select'
        Color = clGray
        ParentColor = False
        ExplicitWidth = 83
        ExplicitHeight = 13
      end
      object ExtBtn3: TExtBtn
        Left = 205
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
  object fsStorage: TFormStorage
    IniSection = 'FrameRPoint'
    Options = []
    Version = 3
    StoredProps.Strings = (
      'paCurrent.Tag'
      'paCurrent.Height'
      'paCommands.Tag'
      'paCommands.Height')
    StoredValues = <>
    Left = 128
    Top = 184
  end
end
