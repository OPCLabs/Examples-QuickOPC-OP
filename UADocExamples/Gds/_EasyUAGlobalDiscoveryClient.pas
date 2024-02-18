// $Header: $
// Copyright (c) CODE Consulting and Development, s.r.o., Plzen. All rights reserved.

//
// Find all latest examples here : https://opclabs.doc-that.com/files/onlinedocs/OPCLabs-OpcStudio/Latest/examples.html .

unit _EasyUAGlobalDiscoveryClient;

interface

type
  FindApplications = class
  public
    class procedure Main(); static;
end;

type
  QueryApplications = class
  public
    class procedure Main(); static;
end;

type
  QueryServers = class
  public
    class procedure Main(); static;
end;

type
  UnregisterApplication = class
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
  System.Generics.Collections,
  System.SysUtils,
  Variants;

{$I _EasyUAGlobalDiscoveryClient.FindApplications.Main.inc}
{$I _EasyUAGlobalDiscoveryClient.QueryApplications.Main.inc}
{$I _EasyUAGlobalDiscoveryClient.QueryServers.Main.inc}
{$I _EasyUAGlobalDiscoveryClient.UnregisterApplication.Main.inc}

end.
