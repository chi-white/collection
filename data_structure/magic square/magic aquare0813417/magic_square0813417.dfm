object Form2: TForm2
  Left = 0
  Top = 0
  Caption = 'Magic Square by '#30333#27138#31098' 2020/10/15'
  ClientHeight = 516
  ClientWidth = 884
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object Panel1: TPanel
    Left = 0
    Top = 0
    Width = 185
    Height = 516
    Align = alLeft
    TabOrder = 0
    object Label1: TLabel
      Left = 32
      Top = 129
      Width = 33
      Height = 19
      Caption = 'N = '
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
    end
    object Label2: TLabel
      Left = 46
      Top = 176
      Width = 86
      Height = 19
      Caption = '3<=N<=23'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
    end
    object Edit1: TEdit
      Left = 71
      Top = 127
      Width = 81
      Height = 27
      Font.Charset = ANSI_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = '@Adobe '#20223#23435' Std R'
      Font.Style = []
      ParentFont = False
      TabOrder = 0
      Text = '3'
    end
    object Button1: TButton
      Left = 32
      Top = 220
      Width = 121
      Height = 41
      Caption = 'magic square'
      Font.Charset = ANSI_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = '@Adobe '#20223#23435' Std R'
      Font.Style = []
      ParentFont = False
      TabOrder = 1
      OnClick = Button1Click
    end
    object GroupBox1: TGroupBox
      Left = 0
      Top = 296
      Width = 179
      Height = 97
      Caption = 'Moving Direction(for n=odd)'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 2
      object RadioButton1: TRadioButton
        Left = 3
        Top = 24
        Width = 81
        Height = 17
        Caption = 'Up-Left'
        Checked = True
        TabOrder = 0
        TabStop = True
      end
      object RadioButton3: TRadioButton
        Left = 3
        Top = 63
        Width = 81
        Height = 17
        Caption = 'Button-Left'
        TabOrder = 1
      end
      object RadioButton2: TRadioButton
        Left = 90
        Top = 24
        Width = 113
        Height = 17
        Caption = 'Up-Right'
        TabOrder = 2
      end
      object RadioButton4: TRadioButton
        Left = 90
        Top = 63
        Width = 113
        Height = 17
        Caption = 'Button-Right'
        TabOrder = 3
      end
    end
  end
  object PageControl1: TPageControl
    Left = 185
    Top = 0
    Width = 699
    Height = 516
    ActivePage = TabSheet1
    Align = alClient
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = '@Adobe '#20223#23435' Std R'
    Font.Style = []
    ParentFont = False
    TabOrder = 1
    object TabSheet1: TTabSheet
      Caption = 'Tabilar'
      object StringGrid1: TStringGrid
        Left = 0
        Top = 0
        Width = 691
        Height = 488
        Align = alClient
        Font.Charset = ANSI_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = '@Adobe '#20223#23435' Std R'
        Font.Style = []
        ParentFont = False
        TabOrder = 0
      end
    end
  end
end
