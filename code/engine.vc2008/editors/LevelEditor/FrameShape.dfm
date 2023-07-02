object fraShape: TfraShape
  Left = 844
  Top = 116
  VertScrollBar.Visible = False
  Align = alClient
  BorderStyle = bsNone
  ClientHeight = 290
  ClientWidth = 217
  Color = 10528425
  Constraints.MinWidth = 206
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clBlack
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  Scaled = False
  PixelsPerInch = 96
  TextHeight = 13
  object paAppend: TPanel
    Left = 0
    Top = 0
    Width = 217
    Height = 60
    Align = alTop
    ParentColor = True
    TabOrder = 0
    object ebTypeSphere: TExtBtn
      Left = 2
      Top = 21
      Width = 215
      Height = 15
      Align = alNone
      BevelShow = False
      HotTrack = True
      HotColor = 15790320
      GroupIndex = 1
      Down = True
      Caption = 'Sphere'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBlack
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object ebTypeBox: TExtBtn
      Left = 2
      Top = 36
      Width = 215
      Height = 15
      Align = alNone
      BevelShow = False
      HotTrack = True
      HotColor = 15790320
      GroupIndex = 1
      Caption = 'Box'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBlack
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object Panel2: TPanel
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
        Caption = 'Append'
        Color = clGray
        ParentColor = False
        ExplicitWidth = 37
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
        ExplicitLeft = 204
        ExplicitTop = 2
        ExplicitHeight = 11
      end
    end
  end
  object paEdit: TPanel
    Left = 0
    Top = 60
    Width = 217
    Height = 60
    Align = alTop
    ParentColor = True
    TabOrder = 1
    object ebAttachShape: TExtBtn
      Left = 2
      Top = 21
      Width = 215
      Height = 14
      Align = alNone
      AllowAllUp = True
      BevelShow = False
      HotTrack = True
      HotColor = 15790320
      GroupIndex = 1
      Caption = 'Attach Shape...'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBlack
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
      OnClick = ebAttachShapeClick
    end
    object ebDetachAllShapes: TExtBtn
      Left = 2
      Top = 35
      Width = 215
      Height = 14
      Align = alNone
      BevelShow = False
      HotTrack = True
      HotColor = 15790320
      Caption = 'Detach All'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBlack
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
      OnClick = ebDetachAllShapesClick
    end
    object Panel3: TPanel
      Left = 1
      Top = 1
      Width = 215
      Height = 20
      Align = alTop
      Caption = 'HeaderPanel'
      ShowCaption = False
      TabOrder = 0
      ExplicitTop = 14
      object ExtBtn3: TExtBtn
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
        ExplicitLeft = 204
        ExplicitTop = 2
        ExplicitHeight = 11
      end
      object Label1: TLabel
        Left = 1
        Top = 1
        Width = 202
        Height = 18
        Align = alClient
        Alignment = taCenter
        Caption = 'Edit'
        Color = clGray
        ParentColor = False
        ExplicitTop = 5
      end
    end
  end
  object Panel1: TPanel
    Left = 0
    Top = 224
    Width = 217
    Height = 66
    Align = alBottom
    BorderStyle = bsSingle
    Color = 10528425
    TabOrder = 2
    object ebEditLevelBoundMode: TExtBtn
      Left = -2
      Top = 9
      Width = 215
      Height = 14
      Align = alNone
      AllowAllUp = True
      BevelShow = False
      HotTrack = True
      HotColor = 15790320
      GroupIndex = 1
      Caption = 'Edit Level Bound'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBlack
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
      OnClick = ebEditLevelBoundModeClick
    end
    object ebRecalcLB: TExtBtn
      Left = -2
      Top = 33
      Width = 215
      Height = 14
      Align = alNone
      BevelShow = False
      HotTrack = True
      HotColor = 15790320
      Caption = 'Recalc'
      Enabled = False
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBlack
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
      OnClick = ebRecalcLBClick
    end
  end
  object fsStorage: TFormStorage
    IniSection = 'FrameShape'
    Options = []
    Version = 4
    StoredProps.Strings = (
      'paAppend.Tag'
      'paAppend.Height'
      'paEdit.Tag'
      'paEdit.Height')
    StoredValues = <>
  end
end
