// $Header: $
// Copyright (c) CODE Consulting and Development, s.r.o., Plzen. All rights reserved.

//#region Example
// This example shows how to obtain data variables under the "Server" node
// in the address space.
//
// Find all latest examples here : https://opclabs.doc-that.com/files/onlinedocs/OPCLabs-OpcStudio/Latest/examples.html .

class procedure BrowseDataVariables.Main;
var
  Client: OpcLabs_EasyOpcUA_TLB._EasyUAClient;
  Count: Cardinal;
  Element: OleVariant;
  EndpointDescriptor: string;
  NodeElement: _UANodeElement;
  NodeElementEnumerator: IEnumVariant;
  NodeElements: _UANodeElementCollection;
  ServerNodeId: _UANodeId;
begin
  EndpointDescriptor := 
    //'http://opcua.demo-this.com:51211/UA/SampleServer';
    //'https://opcua.demo-this.com:51212/UA/SampleServer/';
    'opc.tcp://opcua.demo-this.com:51210/UA/SampleServer';

  // Instantiate the client object
  Client := CoEasyUAClient.Create;

  // Obtain variables under "Server" node
  ServerNodeId := CoUANodeId.Create;
  ServerNodeId.StandardName := 'Server';
  try
    NodeElements := Client.BrowseDataVariables(EndpointDescriptor, ServerNodeId.ExpandedText);
  except
    on E: EOleException do
    begin
      WriteLn(Format('*** Failure: %s', [E.GetBaseException.Message]));
      Exit;
    end;
  end;

  // Display results
  NodeElementEnumerator := NodeElements.GetEnumerator;
  while (NodeElementEnumerator.Next(1, Element, Count) = S_OK) do
  begin
    NodeElement := IUnknown(Element) as _UANodeElement;
    WriteLn;
    WriteLn('nodeElement.NodeId: ', NodeElement.NodeId.ToString);
    WriteLn('nodeElement.NodeId.ExpandedText: ', NodeElement.NodeId.ExpandedText);
    WriteLn('nodeElement.DisplayName: ', NodeElement.DisplayName);
  end;

  // Example output:
  //
  //nodeElement.NodeId: Server_ServerStatus
  //nodeElement.NodeId.ExpandedText: nsu=http://opcfoundation.org/UA/ ;i=2256
  //nodeElement.DisplayName: ServerStatus
end;
//#endregion Example
