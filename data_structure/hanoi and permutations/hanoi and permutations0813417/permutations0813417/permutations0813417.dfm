object Form2: TForm2
  Left = 0
  Top = 0
  Caption = 'permutations by '#30333#27138#31098' 2020/10/2 Ver. 0.3'
  ClientHeight = 504
  ClientWidth = 710
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object Splitter1: TSplitter
    Left = 201
    Top = 0
    Height = 504
    ExplicitLeft = 192
    ExplicitTop = 408
    ExplicitHeight = 100
  end
  object Panel1: TPanel
    Left = 0
    Top = 0
    Width = 201
    Height = 504
    Align = alLeft
    TabOrder = 0
    object Label1: TLabel
      Left = 28
      Top = 72
      Width = 19
      Height = 13
      Caption = 'k = '
    end
    object Label2: TLabel
      Left = 28
      Top = 123
      Width = 20
      Height = 13
      Caption = 'n = '
    end
    object Label3: TLabel
      Left = 114
      Top = 155
      Width = 63
      Height = 13
      Caption = '(k<=n<=26)'
    end
    object Edit1: TEdit
      Left = 69
      Top = 69
      Width = 92
      Height = 21
      TabOrder = 0
      Text = '0'
    end
    object Edit2: TEdit
      Left = 69
      Top = 120
      Width = 92
      Height = 21
      TabOrder = 1
      Text = '3'
    end
    object Button1: TButton
      Left = 16
      Top = 192
      Width = 145
      Height = 57
      Caption = 'Permutations'
      TabOrder = 2
      OnClick = Button1Click
    end
    object CheckBox1: TCheckBox
      Left = 28
      Top = 296
      Width = 129
      Height = 17
      Caption = 'Tracing permutations'
      Checked = True
      State = cbChecked
      TabOrder = 3
    end
  end
  object PageControl1: TPageControl
    Left = 204
    Top = 0
    Width = 506
    Height = 504
    ActivePage = TabSheet1
    Align = alClient
    TabOrder = 1
    object TabSheet1: TTabSheet
      Caption = 'permutations'
      object Memo1: TMemo
        Left = 25
        Top = 24
        Width = 448
        Height = 417
        Lines.Strings = (
          'Memo1')
        ScrollBars = ssVertical
        TabOrder = 0
      end
    end
    object TabSheet2: TTabSheet
      Caption = 'tracing permutations'
      ImageIndex = 1
      ExplicitLeft = 0
      ExplicitTop = 0
      ExplicitWidth = 0
      ExplicitHeight = 0
      object Memo2: TMemo
        Left = 24
        Top = 24
        Width = 449
        Height = 417
        Lines.Strings = (
          'Memo2')
        ScrollBars = ssBoth
        TabOrder = 0
      end
    end
  end
end
