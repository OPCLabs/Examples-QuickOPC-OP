// $Header: $
// Copyright (c) CODE Consulting and Development, s.r.o., Plzen. All rights reserved.

//
// Find all latest examples here : https://opclabs.doc-that.com/files/onlinedocs/OPCLabs-OpcStudio/Latest/examples.html .

unit _DataType;

interface

uses
  OpcLabs_BaseLib_TLB;

type
  Kind = class
  public
    class procedure Main(); static;
  private
    class procedure ProcessDataType(DataType: OpcLabs_BaseLib_TLB._DataType; MaximumDepth: Cardinal); static;
end;

implementation
uses
  ActiveX,
  ComObj,
  MessagePump,
  mscorlib_TLB,
  OpcLabs_EasyOpcUA_TLB,
  OpcLabs_EasyOpcUAComponents_TLB,
  System.SysUtils,
  Variants;

{$I _DataType.Kind.Main.inc}

end.
