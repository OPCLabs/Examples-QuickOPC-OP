// $Header: $
// Copyright (c) CODE Consulting and Development, s.r.o., Plzen. All rights reserved.

//#region Example
// This example shows how to let the user browse for computers on the network.
//
// Find all latest examples here : https://opclabs.doc-that.com/files/onlinedocs/OPCLabs-OpcStudio/Latest/examples.html .

class procedure ShowDialog.Main;
var
  ComputerBrowserDialog: OpcLabs_BaseLibForms_TLB._ComputerBrowserDialog;
begin
  // Instantiate the dialog object
  ComputerBrowserDialog := CoComputerBrowserDialog.Create;

  ComputerBrowserDialog.ShowDialog(nil);
  WriteLn(ComputerBrowserDialog.SelectedName);
end;
//#endregion Example
