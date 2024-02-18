// $Header: $
// Copyright (c) CODE Consulting and Development, s.r.o., Plzen. All rights reserved.

//
// Find all latest examples here : https://opclabs.doc-that.com/files/onlinedocs/OPCLabs-OpcStudio/Latest/examples.html .

unit _ComputerBrowserDialog;

interface

type
  ShowDialog = class
    class procedure Main;
  end;

implementation
uses
  OpcLabs_BaseLibForms_TLB,
  System.SysUtils,
  Variants,
  WinApi.ActiveX;

{$I _ComputerBrowserDialog/ShowDialog.Main.inc}

end.
