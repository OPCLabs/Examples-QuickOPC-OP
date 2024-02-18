// $Header: $
// Copyright (c) CODE Consulting and Development, s.r.o., Plzen. All rights reserved.

//
// Find all latest examples here : https://opclabs.doc-that.com/files/onlinedocs/OPCLabs-OpcStudio/Latest/examples.html .

unit _EasyAEClient;

interface

type
  PullNotification = class
    class procedure Main;
  end;

type
  SubscribeEvents = class
    class procedure Main;
  end;

implementation
uses
  IdGlobal,
  MessagePump,
  OpcLabs_EasyOpcClassic_TLB,
  OpcLabs_EasyOpcClassicComponents_TLB,
  OpcLabs_EasyOpcClassicCore_TLB,
  System.SysUtils,
  Variants,
  WinApi.ActiveX;

{$I _EasyAEClient/PullNotification.Main.inc}
{$I _EasyAEClient/SubscribeEvents.Main.inc}

end.
