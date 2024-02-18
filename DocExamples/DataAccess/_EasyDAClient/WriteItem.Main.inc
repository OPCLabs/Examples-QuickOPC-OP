// $Header: $
// Copyright (c) CODE Consulting and Development, s.r.o., Plzen. All rights reserved.

//#region Example
// This example shows how to write a value, timestamp and quality into a single item.
//
// Find all latest examples here : https://opclabs.doc-that.com/files/onlinedocs/OPCLabs-OpcStudio/Latest/examples.html .

class procedure WriteItem.Main;
var
  Client: OpcLabs_EasyOpcClassic_TLB._EasyDAClient;
begin
  // Instantiate the client object
  Client := CoEasyDAClient.Create;

  try
    Client.WriteItem('', 'OPCLabs.KitServer.2', 'Simulation.Register_I4', 12345, EncodeDate(1980, 1, 1), DAQualities_GoodNonSpecific);
  except
    on E: EOleException do
    begin
      WriteLn(Format('*** Failure: %s', [E.GetBaseException.Message]));
      Exit;
    end;
  end;

end;
//#endregion Example
