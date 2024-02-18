// $Header: $
// Copyright (c) CODE Consulting and Development, s.r.o., Plzen. All rights reserved.

//#region Example
// This example shows how to let the user browse for computers on the network.
//
// Find all latest examples here : https://opclabs.doc-that.com/files/onlinedocs/OPCLabs-OpcStudio/Latest/examples.html .

class procedure ShowDialog.Main;
var
  ComputerBrowserDialog: OpcLabs_BaseLibForms_TLB._ComputerBrowserDialog;
  DialogResult: System_Windows_Forms_TLB.DialogResult;
begin
  // Instantiate the dialog object
  ComputerBrowserDialog := CoComputerBrowserDialog.Create;

  DialogResult := ComputerBrowserDialog.ShowDialog(nil);
  WriteLn(DialogResult);

  if DialogResult <> DialogResult_OK then
    Exit;

  // Display results
  WriteLn(ComputerBrowserDialog.SelectedName);
end;
//#endregion Example
