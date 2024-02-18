// $Header: $
// Copyright (c) CODE Consulting and Development, s.r.o., Plzen. All rights reserved.

//#region Example
// Shows how to delete an application registration from the GDS.
//
// Find all latest examples here : https://opclabs.doc-that.com/files/onlinedocs/OPCLabs-OpcStudio/Latest/examples.html .

class procedure UnregisterFromGds.Main;
var
  Application: TEasyUAApplication;
  GdsEndpointDescriptor: _UAEndpointDescriptor;
begin
  // Define which GDS we will work with.
  GdsEndpointDescriptor := CoUAEndpointDescriptor.Create;
  GdsEndpointDescriptor.UrlString := 'opc.tcp://opcua.demo-this.com:58810/GlobalDiscoveryServer';
  GdsEndpointDescriptor.UserIdentity.UserNameTokenInfo.UserName := 'appadmin';
  GdsEndpointDescriptor.UserIdentity.UserNameTokenInfo.Password := 'demo';

  // Obtain the application interface.
  Application := TEasyUAApplication.Create(nil);

  // Display which application we are about to work with.
  WriteLn('Application URI string: ', Application.GetApplicationElement.ApplicationUriString);

  // Delete an application registration from the GDS.
  try
    Application.UnregisterFromGds(gdsEndpointDescriptor);
  except
    on E: EOleException do
    begin
      WriteLn(Format('*** Failure: %s', [E.GetBaseException.Message]));
    end;
  end;
end;
//#endregion Example
