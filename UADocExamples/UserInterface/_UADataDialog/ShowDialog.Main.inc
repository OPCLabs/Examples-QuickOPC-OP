// $Header: $
// Copyright (c) CODE Consulting and Development, s.r.o., Plzen. All rights reserved.

//#region Example
// This example shows how to let the user browse for an OPC-UA data node
// (a Data Variable or a Property).
//
// Find all latest examples here : https://opclabs.doc-that.com/files/onlinedocs/OPCLabs-OpcStudio/Latest/examples.html .

class procedure ShowDialog.Main;
var
  DataDialog: OpcLabs_EasyOpcForms_TLB._UADataDialog;
  DialogResult: System_Windows_Forms_TLB.DialogResult;
begin
  // Instantiate the dialog object
  DataDialog := CoUADataDialog.Create;

  DataDialog.EndpointDescriptor.UrlString := 
    //'http://opcua.demo-this.com:51211/UA/SampleServer';
    //'https://opcua.demo-this.com:51212/UA/SampleServer/';
    'opc.tcp://opcua.demo-this.com:51210/UA/SampleServer';
  DataDialog.UserPickEndpoint := True;

  DialogResult := DataDialog.ShowDialog(nil);
  WriteLn(DialogResult);

  if DialogResult <> DialogResult_OK then
    Exit;

  // Display results
  WriteLn('EndpointDescriptor: ', DataDialog.EndpointDescriptor.ToString);
  WriteLn('NodeElement: ', DataDialog.NodeElement.ToString);
end;
//#endregion Example
