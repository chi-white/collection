object Form2: TForm2
  Left = 0
  Top = 0
  Caption = 'Tower of Hanoi by '#30333#27138#31098'2020/9/24 Ver. 0.3'
  ClientHeight = 512
  ClientWidth = 611
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 32
    Top = 162
    Width = 86
    Height = 13
    Caption = 'Number of disks : '
  end
  object PageControl1: TPageControl
    Left = 169
    Top = 0
    Width = 442
    Height = 512
    ActivePage = TabSheet2
    Align = alClient
    TabOrder = 3
    object TabSheet1: TTabSheet
      Caption = 'All moves'
      object Memo1: TMemo
        Left = 0
        Top = 0
        Width = 434
        Height = 484
        Align = alClient
        Lines.Strings = (
          'Memo1')
        ScrollBars = ssVertical
        TabOrder = 0
      end
    end
    object TabSheet2: TTabSheet
      Caption = 'Tracing moves'
      ImageIndex = 1
      object Memo2: TMemo
        Left = 0
        Top = 0
        Width = 434
        Height = 484
        Align = alClient
        Lines.Strings = (
          'Memo2')
        ScrollBars = ssBoth
        TabOrder = 0
      end
    end
  end
  object Panel1: TPanel
    Left = 0
    Top = 0
    Width = 169
    Height = 512
    Align = alLeft
    TabOrder = 2
    object CheckBox1: TCheckBox
      Left = 56
      Top = 344
      Width = 97
      Height = 17
      Caption = 'tracing'
      Checked = True
      State = cbChecked
      TabOrder = 0
    end
  end
  object Edit1: TEdit
    Left = 8
    Top = 181
    Width = 137
    Height = 21
    TabOrder = 0
    Text = '3'
  end
  object Button1: TButton
    Left = 16
    Top = 261
    Width = 137
    Height = 49
    Caption = 'Tower of Hanoi'
    TabOrder = 1
    OnClick = Button1Click
  end
end
