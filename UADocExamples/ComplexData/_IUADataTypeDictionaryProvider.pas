// $Header: $
// Copyright (c) CODE Consulting and Development, s.r.o., Plzen. All rights reserved.

//
// Find all latest examples here : https://opclabs.doc-that.com/files/onlinedocs/OPCLabs-OpcStudio/Latest/examples.html .

unit _IUADataTypeDictionaryProvider;

interface

type
  ResolveDataTypeDescriptorFromDataTypeEncodingId = class
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
  System.SysUtils,
  Variants;

{$I _IUADataTypeDictionaryProvider.ResolveDataTypeDescriptorFromDataTypeEncodingId.Main.inc}

end.
