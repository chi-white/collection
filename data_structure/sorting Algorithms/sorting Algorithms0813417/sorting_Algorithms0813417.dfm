object Form2: TForm2
  Left = 0
  Top = 0
  Caption = '0813417'#30333#27138#31098'sorting algorithms1/19'
  ClientHeight = 537
  ClientWidth = 895
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
    Width = 265
    Height = 537
    Align = alLeft
    TabOrder = 0
    object Label1: TLabel
      Left = 32
      Top = 46
      Width = 41
      Height = 13
      Caption = 'Times = '
    end
    object Label2: TLabel
      Left = 32
      Top = 88
      Width = 21
      Height = 13
      Caption = 'N = '
    end
    object Label3: TLabel
      Left = 31
      Top = 134
      Width = 42
      Height = 13
      Caption = 'range = '
    end
    object Label4: TLabel
      Left = 32
      Top = 16
      Width = 26
      Height = 13
      Caption = 'Input'
    end
    object Label5: TLabel
      Left = 32
      Top = 112
      Width = 148
      Height = 13
      Caption = '(uper limit N*times = 1000000)'
    end
    object Label6: TLabel
      Left = 32
      Top = 158
      Width = 115
      Height = 13
      Caption = '(max range = 1000000)'
    end
    object Edit1: TEdit
      Left = 88
      Top = 38
      Width = 129
      Height = 21
      TabOrder = 0
      Text = '3'
    end
    object Edit2: TEdit
      Left = 88
      Top = 85
      Width = 129
      Height = 21
      TabOrder = 1
      Text = '10'
    end
    object Edit3: TEdit
      Left = 88
      Top = 131
      Width = 129
      Height = 21
      TabOrder = 2
      Text = '100'
    end
    object CheckBox1: TCheckBox
      Left = 32
      Top = 208
      Width = 97
      Height = 17
      Caption = 'Selection sort'
      TabOrder = 3
    end
    object CheckBox2: TCheckBox
      Left = 32
      Top = 231
      Width = 97
      Height = 17
      Caption = 'Insertion sort '
      TabOrder = 4
    end
    object CheckBox3: TCheckBox
      Left = 32
      Top = 254
      Width = 97
      Height = 17
      Caption = 'Bubble sort'
      TabOrder = 5
    end
    object CheckBox4: TCheckBox
      Left = 32
      Top = 277
      Width = 201
      Height = 17
      Caption = 'Quick sort (non-recursive versions)'
      TabOrder = 6
    end
    object CheckBox5: TCheckBox
      Left = 32
      Top = 300
      Width = 201
      Height = 17
      Caption = 'Quick sort (recursive versions)'
      TabOrder = 7
    end
    object CheckBox6: TCheckBox
      Left = 32
      Top = 346
      Width = 185
      Height = 17
      Caption = ' Merge sort (recursive versions)'
      TabOrder = 8
    end
    object CheckBox7: TCheckBox
      Left = 32
      Top = 323
      Width = 201
      Height = 17
      Caption = 'Merge sort (non-recursive versions)'
      TabOrder = 9
    end
    object CheckBox8: TCheckBox
      Left = 32
      Top = 369
      Width = 97
      Height = 17
      Caption = 'Heap sort'
      TabOrder = 10
    end
    object Button1: TButton
      Left = 16
      Top = 463
      Width = 201
      Height = 41
      Caption = 'count'
      TabOrder = 11
      OnClick = Button1Click
    end
    object CheckBox9: TCheckBox
      Left = 32
      Top = 392
      Width = 169
      Height = 17
      Caption = 'Radix sort'
      TabOrder = 12
    end
    object CheckBox10: TCheckBox
      Left = 32
      Top = 440
      Width = 97
      Height = 17
      Caption = 'print result'
      TabOrder = 13
    end
  end
  object PageControl1: TPageControl
    Left = 265
    Top = 0
    Width = 630
    Height = 537
    ActivePage = TabSheet1
    Align = alClient
    TabOrder = 1
    object TabSheet1: TTabSheet
      Caption = 'CPU time'
      object Memo1: TMemo
        Left = 0
        Top = 0
        Width = 622
        Height = 509
        Align = alClient
        Lines.Strings = (
          'Memo1')
        ScrollBars = ssVertical
        TabOrder = 0
      end
    end
    object TabSheet2: TTabSheet
      Caption = 'sorting list'
      ImageIndex = 1
      ExplicitLeft = 0
      ExplicitTop = 0
      ExplicitWidth = 0
      ExplicitHeight = 0
      object Memo2: TMemo
        Left = 0
        Top = 0
        Width = 622
        Height = 509
        Align = alClient
        Lines.Strings = (
          'Memo2')
        ScrollBars = ssVertical
        TabOrder = 0
      end
    end
  end
end
