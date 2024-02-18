// $Header: $
// Copyright (c) CODE Consulting and Development, s.r.o., Plzen. All rights reserved.

//
// Find all latest examples here : https://opclabs.doc-that.com/files/onlinedocs/OPCLabs-OpcStudio/Latest/examples.html .

unit _UADataDialog;

interface

type
  ShowDialog = class
    class procedure Main;
  end;

implementation
uses
  System_Windows_Forms_TLB,
  OpcLabs_BaseLibForms_TLB,
  OpcLabs_EasyOpcForms_TLB,
  OpcLabs_EasyOpcUA_TLB,
  System.SysUtils,
  Variants,
  WinApi.ActiveX;

{$I _UADataDialog/ShowDialog.Main.inc}

end.
