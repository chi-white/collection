object Form2: TForm2
  Left = 0
  Top = 0
  Caption = 'Form2'
  ClientHeight = 655
  ClientWidth = 1303
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
    Width = 217
    Height = 655
    Align = alLeft
    TabOrder = 0
    object Button1: TButton
      Left = 38
      Top = 369
      Width = 141
      Height = 42
      Caption = 'Loading maze'
      TabOrder = 0
      OnClick = Button1Click
    end
    object Button3: TButton
      Left = 38
      Top = 321
      Width = 141
      Height = 42
      Caption = 'generate maze'
      TabOrder = 1
      OnClick = Button3Click
    end
    object Panel3: TPanel
      Left = 16
      Top = 26
      Width = 161
      Height = 113
      BorderStyle = bsSingle
      TabOrder = 2
      object Label2: TLabel
        Left = 4
        Top = 43
        Width = 46
        Height = 13
        Caption = 'weight = '
      end
      object Label3: TLabel
        Left = 10
        Top = 83
        Width = 40
        Height = 13
        Caption = 'width = '
      end
      object Label4: TLabel
        Left = 34
        Top = 10
        Width = 46
        Height = 13
        Caption = 'Maze size'
      end
      object Label10: TLabel
        Left = 86
        Top = 10
        Width = 42
        Height = 13
        Caption = '(3~~30)'
      end
      object Edit1: TEdit
        Left = 56
        Top = 40
        Width = 61
        Height = 21
        TabOrder = 0
        Text = '25'
      end
      object Edit2: TEdit
        Left = 56
        Top = 80
        Width = 61
        Height = 21
        TabOrder = 1
        Text = '25'
      end
    end
    object Panel4: TPanel
      Left = 16
      Top = 135
      Width = 161
      Height = 180
      BorderStyle = bsSingle
      TabOrder = 3
      object Label5: TLabel
        Left = 5
        Top = 40
        Width = 75
        Height = 13
        Caption = 'start_weight = '
      end
      object Label6: TLabel
        Left = 16
        Top = 144
        Width = 64
        Height = 13
        Caption = 'end_width = '
      end
      object Label7: TLabel
        Left = 34
        Top = 8
        Width = 73
        Height = 13
        Caption = 'Start-End point'
      end
      object Label8: TLabel
        Left = 11
        Top = 72
        Width = 69
        Height = 13
        Caption = 'start_width = '
      end
      object Label9: TLabel
        Left = 10
        Top = 112
        Width = 70
        Height = 13
        Caption = 'end_weight = '
      end
      object Edit3: TEdit
        Left = 86
        Top = 36
        Width = 52
        Height = 21
        TabOrder = 0
        Text = '2'
      end
      object Edit4: TEdit
        Left = 86
        Top = 144
        Width = 52
        Height = 21
        TabOrder = 1
        Text = '24'
      end
      object Edit5: TEdit
        Left = 86
        Top = 63
        Width = 52
        Height = 21
        TabOrder = 2
        Text = '0'
      end
      object Edit6: TEdit
        Left = 86
        Top = 109
        Width = 52
        Height = 21
        TabOrder = 3
        Text = '23'
      end
    end
  end
  object PageControl1: TPageControl
    Left = 217
    Top = 0
    Width = 1086
    Height = 655
    ActivePage = TabSheet2
    Align = alClient
    TabOrder = 1
    object TabSheet1: TTabSheet
      Caption = 'data tracing'
      object Memo1: TMemo
        Left = 16
        Top = 15
        Width = 761
        Height = 594
        Lines.Strings = (
          'Memo1')
        ScrollBars = ssBoth
        TabOrder = 0
      end
    end
    object TabSheet2: TTabSheet
      Caption = 'Grud'
      ImageIndex = 1
      object StringGrid1: TStringGrid
        Left = 3
        Top = 0
        Width = 1079
        Height = 624
        TabOrder = 0
        OnDrawCell = color
      end
    end
  end
  object Panel2: TPanel
    Left = 16
    Top = 432
    Width = 161
    Height = 161
    BorderStyle = bsSingle
    TabOrder = 2
    object Label1: TLabel
      Left = 14
      Top = 89
      Width = 39
      Height = 13
      Caption = 'speed : '
    end
    object Button2: TButton
      Left = 14
      Top = 23
      Width = 111
      Height = 42
      Caption = 'Find a tour'
      TabOrder = 0
      OnClick = Button2Click
    end
    object TrackBar1: TTrackBar
      Left = 14
      Top = 108
      Width = 111
      Height = 45
      TabOrder = 1
    end
  end
  object OpenDialog1: TOpenDialog
    Left = 176
    Top = 8
  end
end
