// $Header: $
// Copyright (c) CODE Consulting and Development, s.r.o., Plzen. All rights reserved.

//#region Example
// This example shows how to let the user browse for a host (computer) and
// an endpoint of an OPC-UA server residing on it.
//
// Find all latest examples here : https://opclabs.doc-that.com/files/onlinedocs/OPCLabs-OpcStudio/Latest/examples.html .

class procedure ShowDialog.Main;
var
  HostAndEndpointDialog: OpcLabs_EasyOpcForms_TLB._UAHostAndEndpointDialog;
  DialogResult: System_Windows_Forms_TLB.DialogResult;
  HostElement: OpcLabs_BaseLib_TLB.HostElement;
  DiscoveryElement: OpcLabs_EasyOpcUA_TLB.UADiscoveryElement;
begin
  // Instantiate the dialog object
  HostAndEndpointDialog := CoUAHostAndEndpointDialog.Create;

  HostAndEndpointDialog.EndpointDescriptor.Host := 'opcua.demo-this.com';

  DialogResult := HostAndEndpointDialog.ShowDialog(nil);
  WriteLn(DialogResult);

  if DialogResult <> DialogResult_OK then
    Exit;

  // Display results
  HostElement := HostAndEndpointDialog.HostElement;
  if HostElement <> nil then
    WriteLn('HostElement: ', HostElement.ToString);
  DiscoveryElement := HostAndEndpointDialog.DiscoveryElement;
  if DiscoveryElement <> nil then
    WriteLn('DiscoveryElement: ', DiscoveryElement.ToString);
end;
//#endregion Example
