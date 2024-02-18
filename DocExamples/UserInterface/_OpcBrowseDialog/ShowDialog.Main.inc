// $Header: $
// Copyright (c) CODE Consulting and Development, s.r.o., Plzen. All rights reserved.

//#region Example
// This example shows how to let the user browse for an OPC Data Access node.
//
// Find all latest examples here : https://opclabs.doc-that.com/files/onlinedocs/OPCLabs-OpcStudio/Latest/examples.html .

class procedure ShowDialog.Main;
var
  BrowseDialog: OpcLabs_EasyOpcForms_TLB._OpcBrowseDialog;
begin
  // Instantiate the dialog object
  BrowseDialog := CoOpcBrowseDialog.Create;

  BrowseDialog.ShowDialog(nil);

  // Display results
  WriteLn(BrowseDialog.Outputs.CurrentNodeElement.DANodeElement.ToString);
end;
//#endregion Example
