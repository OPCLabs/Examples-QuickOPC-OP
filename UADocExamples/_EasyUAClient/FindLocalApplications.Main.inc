// $Header: $
// Copyright (c) CODE Consulting and Development, s.r.o., Plzen. All rights reserved.

//#region Example
// This example shows how to obtain application URLs of all OPC Unified Architecture servers, using specified discovery URI strings.
//
// Find all latest examples here : https://opclabs.doc-that.com/files/onlinedocs/OPCLabs-OpcStudio/Latest/examples.html .

class procedure FindLocalApplications.Main;
const
  UAApplicationTypes_Server = 1;
var
  Client: OpcLabs_EasyOpcUA_TLB._EasyUAClient;
  Count: Cardinal;
  Element: OleVariant;
  DiscoveryElement: _UADiscoveryElement;
  DiscoveryElementEnumerator: IEnumVariant;
  DiscoveryElements: _UADiscoveryElementCollection;
  DiscoveryUriStrings: OleVariant;
begin
  DiscoveryUriStrings := VarArrayCreate([0, 2], varVariant);
  DiscoveryUriStrings[0] := 'opc.tcp://opcua.demo-this.com:4840/UADiscovery';
  DiscoveryUriStrings[1] := 'http://opcua.demo-this.com/UADiscovery/Default.svc';
  DiscoveryUriStrings[2] := 'http://opcua.demo-this.com:52601/UADiscovery';

  // Instantiate the client object
  Client := CoEasyUAClient.Create;

  // Obtain collection of application elements
  try
    DiscoveryElements := Client.FindLocalApplications(DiscoveryUriStrings, UAApplicationTypes_Server);
  except
    on E: EOleException do
    begin
      WriteLn(Format('*** Failure: %s', [E.GetBaseException.Message]));
      Exit;
    end;
  end;

  // Display results
  DiscoveryElementEnumerator := DiscoveryElements.GetEnumerator;
  while (DiscoveryElementEnumerator.Next(1, Element, Count) = S_OK) do
  begin
    DiscoveryElement := IUnknown(Element) as _UADiscoveryElement;
    WriteLn(
      'DiscoveryElements["',
      DiscoveryElement.DiscoveryUriString,
      '".ApplicationUriString: ',
      DiscoveryElement.ApplicationUriString);
  end;

  VarClear(DiscoveryUriStrings);
end;
//#endregion Example
