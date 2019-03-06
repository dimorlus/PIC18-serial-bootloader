object Bldr: TBldr
  Left = 343
  Top = 121
  Width = 543
  Height = 390
  Caption = 'PIC18 serial bootloader'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -13
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  OnClose = FormClose
  OnCreate = FormCreate
  DesignSize = (
    535
    357)
  PixelsPerInch = 120
  TextHeight = 16
  object LPort: TLabel
    Left = 14
    Top = 12
    Width = 27
    Height = 16
    Caption = 'Port:'
  end
  object MTest: TMemo
    Left = 0
    Top = 107
    Width = 538
    Height = 253
    TabStop = False
    Anchors = [akLeft, akTop, akRight, akBottom]
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clWindowText
    Font.Height = -12
    Font.Name = 'Courier'
    Font.Style = []
    ParentFont = False
    ScrollBars = ssVertical
    TabOrder = 0
  end
  object CBCom: TComboBox
    Left = 50
    Top = 8
    Width = 85
    Height = 24
    Hint = 'Select COM port'
    ItemHeight = 16
    ParentShowHint = False
    ShowHint = True
    TabOrder = 1
    OnChange = CBComChange
    OnDropDown = CBComDropDown
  end
  object BHEX: TButton
    Left = 20
    Top = 60
    Width = 57
    Height = 25
    Caption = '&HEX'
    TabOrder = 2
    OnClick = BHEXClick
  end
  object BProg: TButton
    Left = 88
    Top = 60
    Width = 57
    Height = 25
    Caption = '&Prog'
    TabOrder = 3
    OnClick = BProgClick
  end
  object Bini: TButton
    Left = 458
    Top = 8
    Width = 41
    Height = 25
    Anchors = [akTop, akRight]
    Caption = '.ini'
    TabOrder = 4
    OnClick = BiniClick
  end
  object BStop: TButton
    Left = 156
    Top = 60
    Width = 57
    Height = 25
    Caption = '&Stop'
    Enabled = False
    TabOrder = 5
    OnClick = BStopClick
  end
  object OpenHex: TOpenDialog
    Left = 256
    Top = 20
  end
end
