object Form2: TForm2
  Left = 0
  Top = 0
  Caption = 'Polynomial 0813417'#30333#27138#31098'1/17'
  ClientHeight = 490
  ClientWidth = 798
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
    Width = 227
    Height = 490
    Align = alLeft
    TabOrder = 0
    object Label1: TLabel
      Left = 8
      Top = 96
      Width = 46
      Height = 13
      Caption = 'exponent'
    end
    object Label2: TLabel
      Left = 8
      Top = 56
      Width = 46
      Height = 13
      Caption = 'coifficient'
    end
    object Label3: TLabel
      Left = 58
      Top = 209
      Width = 72
      Height = 13
      Caption = 'random setting'
    end
    object Label4: TLabel
      Left = 22
      Top = 238
      Width = 47
      Height = 13
      Caption = 'max expo'
    end
    object Label5: TLabel
      Left = 8
      Top = 278
      Width = 76
      Height = 13
      Caption = 'coef range(+/-)'
    end
    object Label6: TLabel
      Left = 32
      Top = 320
      Width = 37
      Height = 13
      Caption = '0 range'
    end
    object Button1: TButton
      Left = 8
      Top = 170
      Width = 171
      Height = 25
      Caption = 'Add to B'
      TabOrder = 0
      OnClick = Button1Click
    end
    object Button2: TButton
      Left = 8
      Top = 131
      Width = 171
      Height = 25
      Caption = 'Add to A'
      TabOrder = 1
      OnClick = Button2Click
    end
    object Edit1: TEdit
      Left = 58
      Top = 93
      Width = 121
      Height = 21
      TabOrder = 2
      Text = '2'
    end
    object Edit2: TEdit
      Left = 58
      Top = 53
      Width = 121
      Height = 21
      TabOrder = 3
      Text = '3'
    end
    object Button3: TButton
      Left = 8
      Top = 360
      Width = 171
      Height = 25
      Caption = 'random generate A and B'
      TabOrder = 4
      OnClick = Button3Click
    end
    object Button4: TButton
      Left = 8
      Top = 407
      Width = 171
      Height = 25
      Caption = 'C = A + B'
      TabOrder = 5
      OnClick = Button4Click
    end
    object Button5: TButton
      Left = 8
      Top = 454
      Width = 171
      Height = 25
      Caption = 'clear'
      TabOrder = 6
      OnClick = Button5Click
    end
    object Edit3: TEdit
      Left = 90
      Top = 240
      Width = 121
      Height = 21
      TabOrder = 7
      Text = '6'
    end
    object Edit4: TEdit
      Left = 90
      Top = 275
      Width = 121
      Height = 21
      TabOrder = 8
      Text = '9'
    end
    object Edit5: TEdit
      Left = 90
      Top = 317
      Width = 121
      Height = 21
      TabOrder = 9
      Text = '3'
    end
  end
  object PageControl1: TPageControl
    Left = 227
    Top = 0
    Width = 571
    Height = 490
    ActivePage = TabSheet2
    Align = alClient
    TabOrder = 1
    object TabSheet1: TTabSheet
      Caption = 'Polynomial'
      object Memo1: TMemo
        Left = 0
        Top = 0
        Width = 563
        Height = 462
        Align = alClient
        Lines.Strings = (
          'Memo1')
        TabOrder = 0
      end
    end
    object TabSheet2: TTabSheet
      Caption = 'Addition'
      ImageIndex = 1
      object Memo2: TMemo
        Left = 0
        Top = 0
        Width = 563
        Height = 462
        Align = alClient
        Lines.Strings = (
          'Memo2')
        TabOrder = 0
      end
    end
  end
end
