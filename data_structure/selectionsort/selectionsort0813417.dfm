object Form2: TForm2
  Left = 0
  Top = 0
  Caption = 'selectionsort vs bubblesort by '#30333#27138#31098' 2020/9/22 Ver. 0.3'
  ClientHeight = 535
  ClientWidth = 866
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
    Left = 26
    Top = 35
    Width = 21
    Height = 13
    Caption = 'N = '
  end
  object Label2: TLabel
    Left = 8
    Top = 96
    Width = 42
    Height = 13
    Caption = 'range = '
  end
  object Label3: TLabel
    Left = 672
    Top = 96
    Width = 44
    Height = 13
    Caption = 'target = '
  end
  object Edit1: TEdit
    Left = 72
    Top = 32
    Width = 121
    Height = 21
    TabOrder = 0
    Text = '1000'
  end
  object Button1: TButton
    Left = 8
    Top = 160
    Width = 185
    Height = 25
    Caption = 'generate ramdon number'
    TabOrder = 1
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 232
    Top = 160
    Width = 185
    Height = 25
    Caption = 'selection sort'
    TabOrder = 2
    OnClick = Button2Click
  end
  object Button3: TButton
    Left = 450
    Top = 160
    Width = 185
    Height = 25
    Caption = 'bubble sort'
    TabOrder = 3
    OnClick = Button3Click
  end
  object Button4: TButton
    Left = 672
    Top = 160
    Width = 185
    Height = 25
    Caption = 'binary search'
    TabOrder = 4
    OnClick = Button4Click
  end
  object Memo1: TMemo
    Left = 8
    Top = 232
    Width = 185
    Height = 233
    Lines.Strings = (
      'Memo1')
    ScrollBars = ssVertical
    TabOrder = 5
  end
  object Memo2: TMemo
    Left = 232
    Top = 232
    Width = 185
    Height = 233
    Lines.Strings = (
      'Memo2')
    ScrollBars = ssVertical
    TabOrder = 6
  end
  object Memo3: TMemo
    Left = 450
    Top = 232
    Width = 185
    Height = 233
    Lines.Strings = (
      'Memo3')
    ScrollBars = ssVertical
    TabOrder = 7
  end
  object Memo4: TMemo
    Left = 672
    Top = 232
    Width = 185
    Height = 233
    Lines.Strings = (
      'Memo4')
    ScrollBars = ssVertical
    TabOrder = 8
  end
  object Edit2: TEdit
    Left = 72
    Top = 93
    Width = 121
    Height = 21
    TabOrder = 9
    Text = '1000'
  end
  object Edit3: TEdit
    Left = 722
    Top = 93
    Width = 121
    Height = 21
    TabOrder = 10
    Text = '991'
  end
  object CheckBox1: TCheckBox
    Left = 288
    Top = 34
    Width = 97
    Height = 17
    Caption = 'CheckBox1'
    Checked = True
    State = cbChecked
    TabOrder = 11
  end
  object CheckBox2: TCheckBox
    Left = 288
    Top = 95
    Width = 97
    Height = 17
    Caption = 'CheckBox2'
    Checked = True
    State = cbChecked
    TabOrder = 12
  end
end
