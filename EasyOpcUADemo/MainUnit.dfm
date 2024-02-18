object MainForm: TMainForm
  Left = 0
  Top = 0
  Caption = 'MainForm'
  ClientHeight = 394
  ClientWidth = 772
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object HintLabel: TLabel
    Left = 2
    Top = 9
    Width = 353
    Height = 13
    Caption = 
      'Hint: Press the "Subscribe" button to see dynamically changing O' +
      'PC data.'
  end
  object Label7: TLabel
    Left = 9
    Top = 47
    Width = 52
    Height = 13
    Caption = 'Server &Uri:'
  end
  object Label8: TLabel
    Left = 18
    Top = 75
    Width = 42
    Height = 13
    Caption = 'Node &Id:'
  end
  object Label6: TLabel
    Left = 380
    Top = 117
    Width = 70
    Height = 13
    Caption = 'Value to write:'
  end
  object Label10: TLabel
    Left = 234
    Top = 150
    Width = 75
    Height = 13
    Caption = 'Monitored item:'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'Tahoma'
    Font.Style = [fsUnderline]
    ParentFont = False
  end
  object Label9: TLabel
    Left = 17
    Top = 174
    Width = 109
    Height = 13
    Caption = 'Sampling interval (ms):'
  end
  object Label1: TLabel
    Left = 417
    Top = 150
    Width = 30
    Height = 13
    Caption = 'Value:'
  end
  object Label3: TLabel
    Left = 414
    Top = 176
    Width = 35
    Height = 13
    Caption = 'Status:'
  end
  object Label5: TLabel
    Left = 360
    Top = 205
    Width = 89
    Height = 13
    Caption = 'Source timestamp:'
  end
  object Label2: TLabel
    Left = 363
    Top = 235
    Width = 88
    Height = 13
    Caption = 'Server timestamp:'
  end
  object Label4: TLabel
    Left = 2
    Top = 283
    Width = 51
    Height = 13
    Caption = 'Exception:'
  end
  object Panel1: TPanel
    Left = 5
    Top = 32
    Width = 754
    Height = 1
    BorderStyle = bsSingle
    Caption = 'Panel1'
    TabOrder = 0
  end
  object ServerUriEdit: TEdit
    Left = 72
    Top = 46
    Width = 328
    Height = 21
    TabOrder = 1
    Text = 'opc.tcp://opcua.demo-this.com:51210/UA/SampleServer'
  end
  object NodeIdEdit: TEdit
    Left = 72
    Top = 73
    Width = 328
    Height = 21
    TabOrder = 3
    Text = 'nsu=http://test.org/UA/Data/;i=10854'
  end
  object DiscoverServersButton: TButton
    Left = 406
    Top = 43
    Width = 112
    Height = 23
    Caption = '< Browse servers...'
    TabOrder = 2
    OnClick = DiscoverServersButtonClick
  end
  object BrowseDataButton: TButton
    Left = 406
    Top = 71
    Width = 112
    Height = 23
    Caption = '< Browse data...'
    TabOrder = 4
    OnClick = BrowseDataButtonClick
  end
  object ReadButton: TButton
    Left = 218
    Top = 112
    Width = 118
    Height = 23
    Caption = '&Read'
    TabOrder = 5
    OnClick = ReadButtonClick
  end
  object ValueToWriteEdit: TEdit
    Left = 460
    Top = 115
    Width = 176
    Height = 21
    TabOrder = 6
  end
  object WriteValueButton: TButton
    Left = 641
    Top = 113
    Width = 118
    Height = 23
    Caption = '&Write value'
    TabOrder = 7
    OnClick = WriteValueButtonClick
  end
  object SamplingIntervalSpinEdit: TSpinEdit
    Left = 132
    Top = 171
    Width = 80
    Height = 22
    Increment = 10
    MaxValue = 999999999
    MinValue = 1
    TabOrder = 8
    Value = 200
  end
  object SubscribeMonitoredItemButton: TButton
    Left = 218
    Top = 171
    Width = 118
    Height = 23
    Caption = 'Su&bscribe'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 9
    OnClick = SubscribeMonitoredItemButtonClick
  end
  object ChangeMonitoredItemSubscriptionButton: TButton
    Left = 218
    Top = 200
    Width = 118
    Height = 23
    Caption = 'C&hange subscription'
    TabOrder = 10
    OnClick = ChangeMonitoredItemSubscriptionButtonClick
  end
  object UnsubscribeMonitoredItemButton: TButton
    Left = 218
    Top = 229
    Width = 118
    Height = 23
    Caption = '&Unsubscribe'
    TabOrder = 11
    OnClick = UnsubscribeMonitoredItemButtonClick
  end
  object ValueEdit: TEdit
    Left = 460
    Top = 147
    Width = 176
    Height = 21
    Color = clBtnFace
    ReadOnly = True
    TabOrder = 12
  end
  object StatusEdit: TEdit
    Left = 460
    Top = 174
    Width = 176
    Height = 21
    Color = clBtnFace
    ReadOnly = True
    TabOrder = 13
  end
  object SourceTimestampEdit: TEdit
    Left = 460
    Top = 202
    Width = 176
    Height = 21
    Color = clBtnFace
    ReadOnly = True
    TabOrder = 14
  end
  object ServerTimestampEdit: TEdit
    Left = 460
    Top = 232
    Width = 176
    Height = 21
    Color = clBtnFace
    ReadOnly = True
    TabOrder = 15
  end
  object AboutButton: TButton
    Left = 685
    Top = 44
    Width = 75
    Height = 23
    Caption = '&About...'
    TabOrder = 16
    OnClick = AboutButtonClick
  end
  object CloseButton: TButton
    Left = 685
    Top = 70
    Width = 75
    Height = 23
    Caption = 'Close'
    TabOrder = 17
    OnClick = CloseButtonClick
  end
  object ExceptionMemo: TMemo
    Left = 5
    Top = 299
    Width = 755
    Height = 90
    Color = clBtnFace
    Lines.Strings = (
      '')
    ReadOnly = True
    ScrollBars = ssVertical
    TabOrder = 18
  end
end
