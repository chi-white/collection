object Form2: TForm2
  Left = 0
  Top = 0
  Caption = 'infix2prefix_postfix081417'#30333#27138#31098
  ClientHeight = 549
  ClientWidth = 817
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object Memo1: TMemo
    Left = 0
    Top = 243
    Width = 817
    Height = 306
    Align = alBottom
    Lines.Strings = (
      'Memo1')
    ScrollBars = ssVertical
    TabOrder = 0
    ExplicitTop = 240
    ExplicitWidth = 409
  end
  object CheckBox1: TCheckBox
    Left = 124
    Top = 192
    Width = 97
    Height = 17
    Caption = 'tracing '
    TabOrder = 1
  end
  object PageControl1: TPageControl
    Left = 0
    Top = 0
    Width = 817
    Height = 169
    ActivePage = TabSheet1
    Align = alTop
    TabOrder = 2
    object TabSheet1: TTabSheet
      Caption = 'Infix'
      object Label1: TLabel
        Left = 161
        Top = 19
        Width = 36
        Height = 13
        Caption = 'Infix = '
      end
      object Button1: TButton
        Left = 120
        Top = 56
        Width = 106
        Height = 25
        Caption = 'Infix=>Postfix'
        TabOrder = 0
        OnClick = Button1Click
      end
      object Button2: TButton
        Left = 120
        Top = 105
        Width = 106
        Height = 25
        Caption = 'Infix=>Prefix'
        TabOrder = 1
        OnClick = Button2Click
      end
      object Edit1: TEdit
        Left = 256
        Top = 16
        Width = 217
        Height = 21
        TabOrder = 2
        Text = 'A/B-(C+D)*E+A*C'
      end
      object Edit2: TEdit
        Left = 256
        Top = 58
        Width = 217
        Height = 21
        TabOrder = 3
      end
      object Edit3: TEdit
        Left = 256
        Top = 105
        Width = 217
        Height = 21
        TabOrder = 4
      end
    end
    object TabSheet2: TTabSheet
      Caption = 'Prefix'
      ImageIndex = 1
      ExplicitLeft = 0
      ExplicitTop = 28
      object Label2: TLabel
        Left = 160
        Top = 16
        Width = 42
        Height = 13
        Caption = 'Prefix = '
      end
      object Edit4: TEdit
        Left = 256
        Top = 16
        Width = 225
        Height = 21
        TabOrder = 0
        Text = '+-/AB*+CDE*AC'
      end
      object Button4: TButton
        Left = 124
        Top = 80
        Width = 106
        Height = 25
        Caption = 'Prefix=>Postfix'
        TabOrder = 1
        OnClick = Button4Click
      end
      object Edit5: TEdit
        Left = 256
        Top = 82
        Width = 225
        Height = 21
        TabOrder = 2
      end
    end
  end
  object Button3: TButton
    Left = 240
    Top = 188
    Width = 137
    Height = 25
    Caption = 'Clear Memo'
    TabOrder = 3
    OnClick = Button3Click
  end
end
