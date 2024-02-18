// $Header: $
// Copyright (c) CODE Consulting and Development, s.r.o., Plzen. All rights reserved.

//
// Find all latest examples here : https://opclabs.doc-that.com/files/onlinedocs/OPCLabs-OpcStudio/Latest/examples.html .

unit _EasyUAClient2;

interface

type
  ReadValue = class
  public
    class procedure Main(); static;
end;

type
  SubscribeDataChange = class
  public
    class procedure Main(); static;
end;

type
  WriteValue = class
  public
    class procedure Main(); static;
end;

implementation
uses
  ActiveX,
  ComObj,
  MessagePump,
  mscorlib_TLB,
  OpcLabs_BaseLib_TLB,
  OpcLabs_EasyOpcUA_TLB,
  OpcLabs_EasyOpcUAComponents_TLB,
  System.SysUtils;

{$I _EasyUAClient.ReadValue.Main.inc}
{$I _EasyUAClient.SubscribeDataChange.Main.inc}
{$I _EasyUAClient.WriteValue.Main.inc}

end.
