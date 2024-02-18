// $Header: $
// Copyright (c) CODE Consulting and Development, s.r.o., Plzen. All rights reserved.

//
// Find all latest examples here : https://opclabs.doc-that.com/files/onlinedocs/OPCLabs-OpcStudio/Latest/examples.html .

unit _UAApplicationManifest;

interface

type
  InstanceOwnStorePath = class
    class procedure PlatformSpecific;
  end;

  ApplicationName = class
    class procedure Main;
  end;

implementation
uses
  ComObj,
  MessagePump,
  OpcLabs_BaseLib_TLB,
  OpcLabs_EasyOpcUA_TLB,
  OpcLabs_EasyOpcUAComponents_TLB,
  System.SysUtils;

{$I _UAApplicationManifest/InstanceOwnStorePath.PlatformSpecific.inc}
{$I _UAApplicationManifest/ApplicationName.Main.inc}

end.
