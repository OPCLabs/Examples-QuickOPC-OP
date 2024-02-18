// $Header: $
// Copyright (c) CODE Consulting and Development, s.r.o., Plzen. All rights reserved.

//#region Example
// This example shows how to let the user browse for an OPC-UA server endpoint.
//
// Find all latest examples here : https://opclabs.doc-that.com/files/onlinedocs/OPCLabs-OpcStudio/Latest/examples.html .

class procedure ShowDialog.Main;
var
  EndpointDialog: OpcLabs_EasyOpcForms_TLB._UAEndpointDialog;
  DialogResult: System_Windows_Forms_TLB.DialogResult;
begin
  // Instantiate the dialog object
  EndpointDialog := CoUAEndpointDialog.Create;

  EndpointDialog.DiscoveryHost := 'opcua.demo-this.com';

  DialogResult := EndpointDialog.ShowDialog(nil);
  WriteLn(DialogResult);

  if DialogResult <> DialogResult_OK then
    Exit;

  // Display results
  WriteLn(EndpointDialog.DiscoveryElement.ToString);
end;
//#endregion Example
