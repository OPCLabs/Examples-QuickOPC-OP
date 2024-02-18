// $Header: $
// Copyright (c) CODE Consulting and Development, s.r.o., Plzen. All rights reserved.

//
// Find all latest examples here : https://opclabs.doc-that.com/files/onlinedocs/OPCLabs-OpcStudio/Latest/examples.html .

unit _UANodeId;

interface

type
  _Construction = class
    class procedure Main;
  end;


implementation
uses
  ComObj,
  Generics.Collections,
  IdGlobal,
  MessagePump,
  mscorlib_TLB,
  OpcLabs_BaseLib_TLB,
  OpcLabs_BaseLibForms_TLB,
  OpcLabs_EasyOpcUA_TLB,
  OpcLabs_EasyOpcUAComponents_TLB,
  System.DateUtils,
  System.SysUtils,
  Variants,
  WinApi.ActiveX,
  Windows;

{$I _UANodeId/_Construction.Main.inc}

end.
