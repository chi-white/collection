object Form2: TForm2
  Left = 0
  Top = 0
  Caption = 'Singly_Linked_List by 0813417'#30333#27138#31098' 2020/11/28'
  ClientHeight = 527
  ClientWidth = 854
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
  object PageControl1: TPageControl
    Left = 0
    Top = 0
    Width = 854
    Height = 257
    ActivePage = TabSheet1
    Align = alTop
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clBlack
    Font.Height = -16
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 0
    object TabSheet1: TTabSheet
      Caption = 'Singly Linked List'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBlack
      Font.Height = -13
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
      object Panel1: TPanel
        Left = 24
        Top = 24
        Width = 241
        Height = 193
        Color = clInactiveCaption
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'Tahoma'
        Font.Style = []
        ParentBackground = False
        ParentFont = False
        ParentShowHint = False
        ShowHint = False
        TabOrder = 0
        object Label1: TLabel
          Left = 16
          Top = 2
          Width = 49
          Height = 19
          Caption = 'Insert'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clMaroon
          Font.Height = -16
          Font.Name = 'Tahoma'
          Font.Style = [fsBold]
          ParentFont = False
        end
        object Label4: TLabel
          Left = 16
          Top = 48
          Width = 71
          Height = 16
          Caption = 'element = '
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -13
          Font.Name = 'Tahoma'
          Font.Style = [fsBold]
          ParentFont = False
        end
        object Edit1: TEdit
          Left = 93
          Top = 47
          Width = 121
          Height = 21
          TabOrder = 0
          Text = '10'
        end
        object Button1: TButton
          Left = 40
          Top = 99
          Width = 145
          Height = 25
          BiDiMode = bdLeftToRight
          Caption = 'Insert after front'
          ParentBiDiMode = False
          TabOrder = 1
          OnClick = Button1Click
        end
        object Button3: TButton
          Left = 40
          Top = 130
          Width = 145
          Height = 25
          Caption = 'Insert rear'
          TabOrder = 2
          OnClick = Button3Click
        end
        object Button20: TButton
          Left = 40
          Top = 161
          Width = 145
          Height = 25
          Caption = 'Reverse the list'
          TabOrder = 3
          OnClick = Button20Click
        end
      end
      object Panel2: TPanel
        Left = 304
        Top = 24
        Width = 241
        Height = 193
        Color = clInactiveCaption
        ParentBackground = False
        TabOrder = 1
        object Label2: TLabel
          Left = 16
          Top = 0
          Width = 48
          Height = 19
          Caption = 'Seach'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clMaroon
          Font.Height = -16
          Font.Name = 'Tahoma'
          Font.Style = [fsBold]
          ParentFont = False
        end
        object Label5: TLabel
          Left = 14
          Top = 44
          Width = 62
          Height = 16
          Caption = 'Target = '
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -13
          Font.Name = 'Tahoma'
          Font.Style = [fsBold]
          ParentFont = False
        end
        object Edit2: TEdit
          Left = 82
          Top = 43
          Width = 119
          Height = 24
          TabOrder = 0
          Text = '10'
        end
        object Button4: TButton
          Left = 56
          Top = 99
          Width = 121
          Height = 25
          Caption = 'Insert target front'
          TabOrder = 1
          OnClick = Button4Click
        end
        object Button5: TButton
          Left = 55
          Top = 130
          Width = 122
          Height = 25
          Caption = 'Insert target back'
          TabOrder = 2
          OnClick = Button5Click
        end
        object Button8: TButton
          Left = 56
          Top = 161
          Width = 121
          Height = 25
          Caption = 'Delete target'
          TabOrder = 3
          OnClick = Button8Click
        end
        object Button15: TButton
          Left = 56
          Top = 68
          Width = 121
          Height = 25
          Caption = 'Find'
          TabOrder = 4
          OnClick = Button15Click
        end
      end
      object Panel3: TPanel
        Left = 584
        Top = 27
        Width = 241
        Height = 193
        Color = clInactiveCaption
        ParentBackground = False
        TabOrder = 2
        object Label7: TLabel
          Left = 22
          Top = 28
          Width = 27
          Height = 16
          Caption = 'N = '
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -13
          Font.Name = 'Tahoma'
          Font.Style = [fsBold]
          ParentFont = False
        end
        object Label8: TLabel
          Left = 6
          Top = 58
          Width = 60
          Height = 16
          Caption = 'Range = '
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -13
          Font.Name = 'Tahoma'
          Font.Style = [fsBold]
          ParentFont = False
        end
        object Label3: TLabel
          Left = 16
          Top = 0
          Width = 67
          Height = 19
          Caption = 'Random'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clMaroon
          Font.Height = -16
          Font.Name = 'Tahoma'
          Font.Style = [fsBold]
          ParentFont = False
        end
        object Edit4: TEdit
          Left = 72
          Top = 25
          Width = 105
          Height = 24
          TabOrder = 0
          Text = '10'
        end
        object Edit5: TEdit
          Left = 72
          Top = 55
          Width = 105
          Height = 24
          TabOrder = 1
          Text = '100'
        end
        object Button7: TButton
          Left = 42
          Top = 152
          Width = 167
          Height = 25
          Caption = 'Clear all'
          TabOrder = 2
          OnClick = Button7Click
        end
        object Button6: TButton
          Left = 42
          Top = 121
          Width = 167
          Height = 25
          Caption = 'Insert random (after rear)'
          TabOrder = 3
          OnClick = Button6Click
        end
        object Button17: TButton
          Left = 40
          Top = 88
          Width = 169
          Height = 25
          Caption = 'Insert random (after front)'
          TabOrder = 4
          OnClick = Button17Click
        end
      end
    end
    object TabSheet2: TTabSheet
      Caption = 'Double Linked List'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBlack
      Font.Height = -13
      Font.Name = 'Tahoma'
      Font.Style = [fsBold]
      ImageIndex = 1
      ParentFont = False
      object Panel4: TPanel
        Left = 32
        Top = 24
        Width = 241
        Height = 196
        Color = clInactiveCaption
        ParentBackground = False
        ParentShowHint = False
        ShowHint = False
        TabOrder = 0
        object Label6: TLabel
          Left = 11
          Top = 44
          Width = 71
          Height = 16
          Caption = 'element = '
        end
        object Label11: TLabel
          Left = 11
          Top = 8
          Width = 49
          Height = 19
          Caption = 'Insert'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clMaroon
          Font.Height = -16
          Font.Name = 'Tahoma'
          Font.Style = [fsBold]
          ParentFont = False
        end
        object Button2: TButton
          Left = 48
          Top = 118
          Width = 137
          Height = 25
          Caption = 'Insert rear'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -13
          Font.Name = 'Tahoma'
          Font.Style = []
          ParentFont = False
          TabOrder = 0
          OnClick = Button2Click
        end
        object Button9: TButton
          Left = 48
          Top = 87
          Width = 137
          Height = 25
          Caption = 'Insert after front'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -13
          Font.Name = 'Tahoma'
          Font.Style = []
          ParentFont = False
          TabOrder = 1
          OnClick = Button9Click
        end
        object Edit3: TEdit
          Left = 80
          Top = 41
          Width = 121
          Height = 24
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -13
          Font.Name = 'Tahoma'
          Font.Style = []
          ParentFont = False
          TabOrder = 2
          Text = '10'
        end
        object Button19: TButton
          Left = 48
          Top = 149
          Width = 137
          Height = 25
          Caption = 'Reverse the list'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -13
          Font.Name = 'Tahoma'
          Font.Style = []
          ParentFont = False
          TabOrder = 3
          OnClick = Button19Click
        end
      end
      object Panel5: TPanel
        Left = 304
        Top = 24
        Width = 241
        Height = 196
        Color = clInactiveCaption
        ParentBackground = False
        TabOrder = 1
        object Label9: TLabel
          Left = 24
          Top = 44
          Width = 61
          Height = 16
          Caption = 'target = '
        end
        object Label12: TLabel
          Left = 16
          Top = 8
          Width = 48
          Height = 19
          Caption = 'Seach'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clMaroon
          Font.Height = -16
          Font.Name = 'Tahoma'
          Font.Style = [fsBold]
          ParentFont = False
        end
        object Edit6: TEdit
          Left = 91
          Top = 41
          Width = 121
          Height = 24
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -13
          Font.Name = 'Tahoma'
          Font.Style = []
          ParentFont = False
          TabOrder = 0
          Text = '10'
        end
        object Button10: TButton
          Left = 56
          Top = 71
          Width = 121
          Height = 25
          Caption = 'Find'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -13
          Font.Name = 'Tahoma'
          Font.Style = []
          ParentFont = False
          TabOrder = 1
          OnClick = Button10Click
        end
        object Button11: TButton
          Left = 56
          Top = 102
          Width = 121
          Height = 25
          Caption = 'Insert target front'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -13
          Font.Name = 'Tahoma'
          Font.Style = []
          ParentFont = False
          TabOrder = 2
          OnClick = Button11Click
        end
        object Button12: TButton
          Left = 56
          Top = 133
          Width = 121
          Height = 25
          Caption = 'Insert target back'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -13
          Font.Name = 'Tahoma'
          Font.Style = []
          ParentFont = False
          TabOrder = 3
          OnClick = Button12Click
        end
        object Button13: TButton
          Left = 56
          Top = 164
          Width = 121
          Height = 25
          Caption = 'Delete target'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -13
          Font.Name = 'Tahoma'
          Font.Style = []
          ParentFont = False
          TabOrder = 4
          OnClick = Button13Click
        end
      end
      object Panel6: TPanel
        Left = 568
        Top = 24
        Width = 241
        Height = 196
        Color = clInactiveCaption
        ParentBackground = False
        TabOrder = 2
        object Label10: TLabel
          Left = 32
          Top = 33
          Width = 27
          Height = 16
          Caption = 'N = '
        end
        object Label13: TLabel
          Left = 8
          Top = 8
          Width = 67
          Height = 19
          Caption = 'Random'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clMaroon
          Font.Height = -16
          Font.Name = 'Tahoma'
          Font.Style = [fsBold]
          ParentFont = False
        end
        object Label14: TLabel
          Left = 14
          Top = 60
          Width = 60
          Height = 16
          Caption = 'Range = '
        end
        object Edit7: TEdit
          Left = 81
          Top = 30
          Width = 121
          Height = 24
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -13
          Font.Name = 'Tahoma'
          Font.Style = []
          ParentFont = False
          TabOrder = 0
          Text = '10'
        end
        object Button14: TButton
          Left = 32
          Top = 102
          Width = 177
          Height = 25
          Caption = 'Insert random (after front)'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -13
          Font.Name = 'Tahoma'
          Font.Style = []
          ParentFont = False
          TabOrder = 1
          OnClick = Button14Click
        end
        object Button16: TButton
          Left = 32
          Top = 133
          Width = 177
          Height = 25
          Caption = 'Insert random (after rear)'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -13
          Font.Name = 'Tahoma'
          Font.Style = []
          ParentFont = False
          TabOrder = 2
          OnClick = Button16Click
        end
        object Edit8: TEdit
          Left = 80
          Top = 60
          Width = 121
          Height = 24
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -13
          Font.Name = 'Tahoma'
          Font.Style = []
          ParentFont = False
          TabOrder = 3
          Text = '100'
        end
        object Button18: TButton
          Left = 32
          Top = 164
          Width = 177
          Height = 25
          Caption = 'Clear all'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -13
          Font.Name = 'Tahoma'
          Font.Style = []
          ParentFont = False
          TabOrder = 4
          OnClick = Button18Click
        end
      end
    end
  end
  object PageControl2: TPageControl
    Left = 0
    Top = 257
    Width = 854
    Height = 270
    ActivePage = TabSheet3
    Align = alClient
    ParentShowHint = False
    ShowHint = False
    Style = tsFlatButtons
    TabOrder = 1
    ExplicitTop = 256
    object TabSheet3: TTabSheet
      Caption = 'Singly Memo'
      object Memo1: TMemo
        Left = 0
        Top = -25
        Width = 846
        Height = 264
        Align = alBottom
        Color = clInactiveCaption
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -16
        Font.Name = 'Tahoma'
        Font.Style = [fsBold]
        Lines.Strings = (
          'Memo1')
        ParentFont = False
        ScrollBars = ssVertical
        TabOrder = 0
      end
    end
    object TabSheet4: TTabSheet
      Caption = 'Double Memo'
      ImageIndex = 1
      object Memo2: TMemo
        Left = 0
        Top = 0
        Width = 846
        Height = 239
        Align = alClient
        Color = clInactiveCaption
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -16
        Font.Name = 'Tahoma'
        Font.Style = [fsBold]
        Lines.Strings = (
          'Memo2')
        ParentFont = False
        ScrollBars = ssVertical
        TabOrder = 0
      end
    end
  end
end
