object frmOneColor: TfrmOneColor
  Left = 234
  Top = 763
  Align = alTop
  BorderIcons = []
  BorderStyle = bsNone
  ClientHeight = 57
  ClientWidth = 143
  Color = 10528425
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  KeyPreview = True
  OldCreateOrder = False
  Position = poScreenCenter
  Scaled = False
  OnClose = FormClose
  PixelsPerInch = 96
  TextHeight = 13
  object Bevel1: TBevel
    Left = 0
    Top = 0
    Width = 143
    Height = 57
  end
  object Bevel2: TBevel
    Left = 1
    Top = 1
    Width = 141
    Height = 55
    Style = bsRaised
  end
  object mcColor: TMultiObjColor
    Left = 3
    Top = 15
    Width = 23
    Height = 39
    Shape = stRoundRect
    OnMouseDown = mcColorMouseDown
  end
  object ebMultiRemove: TExtBtn
    Left = 3
    Top = 2
    Width = 23
    Height = 13
    Align = alNone
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clBlack
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    Glyph.Data = {
      56010000424D560100000000000036000000280000000A000000090000000100
      18000000000020010000120B0000120B00000000000000000000C8D0D4C8D0D4
      C8D0D4C8D0D4C8D0D4C8D0D4C8D0D4C8D0D4C8D0D4C8D0D40000C8D0D4000000
      000000C8D0D4C8D0D4C8D0D4C8D0D4000000000000C8D0D40000C8D0D4C8D0D4
      000000000000C8D0D4C8D0D4000000000000C8D0D4C8D0D40000C8D0D4C8D0D4
      C8D0D4000000000000000000000000C8D0D4C8D0D4C8D0D40000C8D0D4C8D0D4
      C8D0D4C8D0D4000000000000C8D0D4C8D0D4C8D0D4C8D0D40000C8D0D4C8D0D4
      C8D0D4000000000000000000000000C8D0D4C8D0D4C8D0D40000C8D0D4C8D0D4
      000000000000C8D0D4C8D0D4000000000000C8D0D4C8D0D40000C8D0D4000000
      000000C8D0D4C8D0D4C8D0D4C8D0D4000000000000C8D0D40000C8D0D4C8D0D4
      C8D0D4C8D0D4C8D0D4C8D0D4C8D0D4C8D0D4C8D0D4C8D0D40000}
    ParentFont = False
    Spacing = 0
    OnClick = ebMultiRemoveClick
  end
  object tvDOList: TElTree
    Left = 27
    Top = 2
    Width = 113
    Height = 52
    Cursor = crDefault
    Hint = ''
    LeftPosition = 0
    DragCursor = crDrag
    AlwaysKeepSelection = False
    AutoExpand = True
    DockOrientation = doNoOrient
    DefaultSectionWidth = 120
    BorderStyle = bsNone
    BorderSides = [ebsLeft, ebsRight, ebsTop, ebsBottom]
    DragAllowed = True
    DrawFocusRect = False
    ExplorerEditMode = False
    Flat = True
    FocusedSelectColor = 10526880
    FocusedSelectTextColor = clBlack
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clBlack
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    FullRowSelect = False
    HeaderHeight = 19
    HeaderHotTrack = False
    HeaderSections.Data = {
      F4FFFFFF07000000B004020000000000FFFFFFFF000001010100420078000000
      000000001027000000010000BC55640E0000000000006E000000000000000100
      000000000000000000010000000000003B005F0045004400490054004F005200
      3B005F004C004500560045004C005F0045004400490054004F0052003B004400
      00003B0042006100730065003B00000000004200010000000001000000000000
      000000000000B004020000000000FFFFFFFF0000010101004200780000000000
      000010270000000100005C598B0D0100000000006E0000000000000001000000
      00000000000000010000000000003B005F0045004400490054004F0052003B00
      5F004C004500560045004C005F0045004400490054004F0052003B0044000000
      3B0042006100730065003B000000000042000100000000010000000000000000
      00000000B004020000000000FFFFFFFF00000101010042007800000000000000
      10270000000100000CC9BA0C0200000000006E00000000000000010000000000
      0000000000010000000000003B005F0045004400490054004F0052003B005F00
      4C004500560045004C005F0045004400490054004F0052003B00440000003B00
      42006100730065003B0000000000420001000000000100000000000000000000
      0000B004020000000000FFFFFFFF000001010100420078000000000000001027
      000000010000A0727F0D0300000000006E000000000000000100000000000000
      000000010000000000003B005F0045004400490054004F0052003B005F004C00
      4500560045004C005F0045004400490054004F0052003B00440000003B004200
      6100730065003B00000000004200010000000001000000000000000000000000
      B004020000000000FFFFFFFF0000010101004200780000000000000010270000
      000100008C58E70E0400000000006E0000000000000001000000000000000000
      00010000000000003B005F0045004400490054004F0052003B005F004C004500
      560045004C005F0045004400490054004F0052003B00440000003B0042006100
      730065003B00000000004200010000000001000000000000000000000000B004
      020000000000FFFFFFFF00000101010042007800000000000000102700000001
      0000CC78BD0C0500000000006E00000000000000010000000000000000000001
      0000000000003B005F0045004400490054004F0052003B005F004C0045005600
      45004C005F0045004400490054004F0052003B00440000003B00420061007300
      65003B00000000004200010000000001000000000000000000000000B0040200
      00000000FFFFFFFF000001010100420078000000000000001027000000010000
      9C6D900C0600000000006E000000000000000100000000000000000000010000
      000000003B005F0045004400490054004F0052003B005F004C00450056004500
      4C005F0045004400490054004F0052003B00440000003B004200610073006500
      3B00000000004200010000000001000000000000000000000000}
    HeaderFont.Charset = DEFAULT_CHARSET
    HeaderFont.Color = clBlack
    HeaderFont.Height = -11
    HeaderFont.Name = 'MS Sans Serif'
    HeaderFont.Style = []
    HorizontalLines = True
    HorzDivLinesColor = 7368816
    HorzScrollBarStyles.ShowTrackHint = False
    HorzScrollBarStyles.Width = 17
    HorzScrollBarStyles.ButtonSize = 14
    HorzScrollBarStyles.UseSystemMetrics = False
    HorzScrollBarStyles.UseXPThemes = False
    IgnoreEnabled = False
    IncrementalSearch = False
    ItemIndent = 9
    KeepSelectionWithinLevel = False
    LineBorderActiveColor = clBlack
    LineBorderInactiveColor = clBlack
    LineHeight = 16
    LinesColor = clBtnShadow
    MultiSelect = False
    OwnerDrawMask = '~~@~~'
    ParentFont = False
    PlusMinusTransparent = True
    ScrollbarOpposite = False
    ScrollTracking = True
    ShowButtons = False
    ShowLeafButton = False
    ShowLines = False
    ShowRootButtons = False
    StoragePath = '\Tree'
    TabOrder = 0
    TabStop = True
    Tracking = False
    TrackColor = clBlack
    VertScrollBarStyles.ShowTrackHint = True
    VertScrollBarStyles.Width = 17
    VertScrollBarStyles.ButtonSize = 14
    VertScrollBarStyles.UseSystemMetrics = False
    VertScrollBarStyles.UseXPThemes = False
    VirtualityLevel = vlNone
    UseXPThemes = False
    TextColor = clBtnText
    BkColor = clGray
    OnItemFocused = tvDOListItemFocused
    LinkStyle = [fsUnderline]
    OnDragDrop = tvDOListDragDrop
    OnDragOver = tvDOListDragOver
    OnStartDrag = tvDOListStartDrag
  end
end
