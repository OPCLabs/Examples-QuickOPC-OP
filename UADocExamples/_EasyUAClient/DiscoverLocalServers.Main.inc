// $Header: $
// Copyright (c) CODE Consulting and Development, s.r.o., Plzen. All rights reserved.

//#region Example
// This example shows how to obtain application URLs of all OPC Unified Architecture servers on the specified host.
//
// Find all latest examples here : https://opclabs.doc-that.com/files/onlinedocs/OPCLabs-OpcStudio/Latest/examples.html .

class procedure DiscoverLocalServers.Main;
var
  Client: OpcLabs_EasyOpcUA_TLB._EasyUAClient;
  Count: Cardinal;
  Element: OleVariant;
  DiscoveryElement: _UADiscoveryElement;
  DiscoveryElementEnumerator: IEnumVariant;
  DiscoveryElements: _UADiscoveryElementCollection;
begin
  // Instantiate the client object
  Client := CoEasyUAClient.Create;

  // Obtain collection of server elements
  try
    DiscoveryElements := Client.DiscoverLocalServers('opcua.demo-this.com');
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
end;
//#endregion Example
