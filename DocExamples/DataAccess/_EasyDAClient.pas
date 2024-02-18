// $Header: $
// Copyright (c) CODE Consulting and Development, s.r.o., Plzen. All rights reserved.

//
// Find all latest examples here : https://opclabs.doc-that.com/files/onlinedocs/OPCLabs-OpcStudio/Latest/examples.html .

unit _EasyDAClient;

interface

type
  BrowseNodes = class
    class procedure Main;
  end;

type
  BrowseProperties = class
    class procedure Main;
  end;

type
  GetMultiplePropertyValues = class
    class procedure Main;
  end;

type
  PullItemChanged = class
    class procedure Main;
    class procedure MultipleItems;
  end;

type
  ReadItem = class
    class procedure Main;
  end;

type
  ReadItemValue = class
    class procedure Main;
  end;

type
  ReadMultipleItems = class
    class procedure Main;
  end;

type
  ReadMultipleItemValues = class
    class procedure Main;
  end;

type
  SubscribeItem = class
    class procedure Main;
  end;

type
  SubscribeMultipleItems = class
    class procedure Main;
  end;

type
  WriteItem = class
    class procedure Main;
  end;

type
  WriteItemValue = class
    class procedure Main;
  end;

type
  WriteMultipleItems = class
    class procedure Main;
  end;

type
  WriteMultipleItemValues = class
    class procedure Main;
  end;

implementation
uses
  ComObj,
  IdGlobal,
  MessagePump,
  OpcLabs_BaseLib_TLB,
  OpcLabs_EasyOpcClassic_TLB,
  OpcLabs_EasyOpcClassicComponents_TLB,
  OpcLabs_EasyOpcClassicCore_TLB,
  System.SysUtils,
  Variants,
  WinApi.ActiveX;

{$I _EasyDAClient/BrowseNodes.Main.inc}
{$I _EasyDAClient/BrowseProperties.Main.inc}
{$I _EasyDAClient/GetMultiplePropertyValues.Main.inc}
{$I _EasyDAClient/PullItemChanged.Main.inc}
{$I _EasyDAClient/PullItemChanged.MultipleItems.inc}
{$I _EasyDAClient/ReadItem.Main.inc}
{$I _EasyDAClient/ReadItemValue.Main.inc}
{$I _EasyDAClient/ReadMultipleItems.Main.inc}
{$I _EasyDAClient/ReadMultipleItemValues.Main.inc}
{$I _EasyDAClient/SubscribeItem.Main.inc}
{$I _EasyDAClient/SubscribeMultipleItems.Main.inc}
{$I _EasyDAClient/WriteItem.Main.inc}
{$I _EasyDAClient/WriteItemValue.Main.inc}
{$I _EasyDAClient/WriteMultipleItems.Main.inc}
{$I _EasyDAClient/WriteMultipleItemValues.Main.inc}

end.
