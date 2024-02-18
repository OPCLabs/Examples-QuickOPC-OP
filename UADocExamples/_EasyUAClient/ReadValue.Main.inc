// $Header: $
// Copyright (c) CODE Consulting and Development, s.r.o., Plzen. All rights reserved.

//#region Example
// This example shows how to read value of a single node, and display it.
//
// Find all latest examples here : https://opclabs.doc-that.com/files/onlinedocs/OPCLabs-OpcStudio/Latest/examples.html .

class procedure ReadValue.Main;
var
  Client: OpcLabs_EasyOpcUA_TLB._EasyUAClient;
  Value: OleVariant;
begin
  // Instantiate the client object
  Client := CoEasyUAClient.Create;

  // Obtain value of a node
  try
    Value := Client.ReadValue(
      //'http://opcua.demo-this.com:51211/UA/SampleServer',
      //'https://opcua.demo-this.com:51212/UA/SampleServer/',
      'opc.tcp://opcua.demo-this.com:51210/UA/SampleServer',
      'nsu=http://test.org/UA/Data/ ;i=10853');
  except
    on E: EOleException do
    begin
      WriteLn(Format('*** Failure: %s', [E.GetBaseException.Message]));
      Exit;
    end;
  end;

  // Display results
  WriteLn('value: ', Value);
end;
//#endregion Example
