// $Header: $
// Copyright (c) CODE Consulting and Development, s.r.o., Plzen. All rights reserved.

//#region Example
// This example shows how to let the user browse for an OPC "Classic" server.
//
// Find all latest examples here : https://opclabs.doc-that.com/files/onlinedocs/OPCLabs-OpcStudio/Latest/examples.html .

class procedure ShowDialog.Main;
var
  ServerDialog: OpcLabs_EasyOpcForms_TLB._OpcServerDialog;
begin
  // Instantiate the dialog object
  ServerDialog := CoOpcServerDialog.Create;

  ServerDialog.ShowDialog(nil);

  // Display results
  WriteLn(ServerDialog.ServerElement.ToString);
end;
//#endregion Example
