object Form2: TForm2
  Left = 743
  Top = 0
  Caption = '0813417'#30333#27138#31098' shortest path 1/1'
  ClientHeight = 532
  ClientWidth = 821
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  Position = poDesigned
  PixelsPerInch = 96
  TextHeight = 13
  object Panel1: TPanel
    Left = 0
    Top = 0
    Width = 225
    Height = 532
    Align = alLeft
    TabOrder = 0
    object Label1: TLabel
      Left = 69
      Top = 24
      Width = 91
      Height = 16
      Caption = 'Shortest path'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Tahoma'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object Label2: TLabel
      Left = 69
      Top = 64
      Width = 21
      Height = 13
      Caption = 'N = '
    end
    object Label3: TLabel
      Left = 18
      Top = 104
      Width = 72
      Height = 13
      Caption = 'range(w(e)) = '
    end
    object Label4: TLabel
      Left = 40
      Top = 147
      Width = 50
      Height = 13
      Caption = 'if(w(e)) > '
    end
    object Label5: TLabel
      Left = 54
      Top = 192
      Width = 36
      Height = 13
      Caption = 'w(e) = '
    end
    object Label6: TLabel
      Left = 28
      Top = 236
      Width = 62
      Height = 13
      Caption = 'Souce no. = '
    end
    object Label7: TLabel
      Left = 40
      Top = 344
      Width = 144
      Height = 16
      Caption = 'Short path Algorithms'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Tahoma'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object Button1: TButton
      Left = 28
      Top = 305
      Width = 166
      Height = 25
      Caption = 'Generate G'
      TabOrder = 0
      OnClick = Button1Click
    end
    object Button2: TButton
      Left = 28
      Top = 374
      Width = 167
      Height = 25
      Caption = 'Single Source All Destination'
      TabOrder = 1
      OnClick = Button2Click
    end
    object Button3: TButton
      Left = 28
      Top = 429
      Width = 167
      Height = 25
      Caption = 'All pairs'
      TabOrder = 2
      OnClick = Button3Click
    end
    object Edit1: TEdit
      Left = 96
      Top = 61
      Width = 98
      Height = 21
      TabOrder = 3
      Text = '4'
    end
    object Edit3: TEdit
      Left = 96
      Top = 144
      Width = 98
      Height = 21
      TabOrder = 4
      Text = '60'
    end
    object Edit4: TEdit
      Left = 96
      Top = 189
      Width = 98
      Height = 21
      TabOrder = 5
      Text = '999'
    end
    object Edit5: TEdit
      Left = 96
      Top = 233
      Width = 98
      Height = 21
      TabOrder = 6
      Text = '0'
    end
    object Edit2: TEdit
      Left = 96
      Top = 101
      Width = 98
      Height = 21
      TabOrder = 7
      Text = '100'
    end
    object Button4: TButton
      Left = 28
      Top = 480
      Width = 167
      Height = 25
      Caption = 'Transitive closure '
      TabOrder = 8
      OnClick = Button4Click
    end
    object CheckBox1: TCheckBox
      Left = 69
      Top = 269
      Width = 97
      Height = 17
      Caption = 'symmetry'
      TabOrder = 9
    end
  end
  object PageControl1: TPageControl
    Left = 225
    Top = 0
    Width = 596
    Height = 532
    ActivePage = TabSheet1
    Align = alClient
    TabOrder = 1
    object TabSheet1: TTabSheet
      Caption = 'tracing'
      object Memo1: TMemo
        Left = 0
        Top = 0
        Width = 588
        Height = 504
        Align = alClient
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -13
        Font.Name = 'Tahoma'
        Font.Style = [fsBold]
        Lines.Strings = (
          'Memo1')
        ParentFont = False
        ScrollBars = ssBoth
        TabOrder = 0
      end
    end
    object TabSheet2: TTabSheet
      Caption = 'distance map'
      ImageIndex = 1
      object StringGrid1: TStringGrid
        Left = 0
        Top = 0
        Width = 588
        Height = 504
        Align = alClient
        TabOrder = 0
      end
    end
    object TabSheet3: TTabSheet
      Caption = 'process'
      ImageIndex = 2
      object StringGrid2: TStringGrid
        Left = 0
        Top = 0
        Width = 588
        Height = 504
        Align = alClient
        TabOrder = 0
      end
    end
    object TabSheet4: TTabSheet
      Caption = 'All pairs '
      ImageIndex = 3
      object StringGrid3: TStringGrid
        Left = 0
        Top = 0
        Width = 588
        Height = 504
        Align = alClient
        TabOrder = 0
      end
    end
    object TabSheet5: TTabSheet
      Caption = 'Transitive closure'
      ImageIndex = 4
      object StringGrid4: TStringGrid
        Left = 0
        Top = 0
        Width = 588
        Height = 504
        Align = alClient
        TabOrder = 0
      end
    end
  end
end
