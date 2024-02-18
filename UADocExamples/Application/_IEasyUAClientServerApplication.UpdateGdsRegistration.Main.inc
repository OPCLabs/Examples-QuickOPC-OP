// $Header: $
// Copyright (c) CODE Consulting and Development, s.r.o., Plzen. All rights reserved.

//#region Example
// Shows how to update an application registration in the GDS, keeping its application ID if possible.
//
// Find all latest examples here : https://opclabs.doc-that.com/files/onlinedocs/OPCLabs-OpcStudio/Latest/examples.html .

class procedure UpdateGdsRegistration.Main;
var
  Application: TEasyUAApplication;
  ApplicationId: _UANodeId;
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

  // Update an application registration in the GDS, keeping its application ID if possible.
  try
    ApplicationId := Application.UpdateGdsRegistration(gdsEndpointDescriptor);
  except
    on E: EOleException do
    begin
      WriteLn(Format('*** Failure: %s', [E.GetBaseException.Message]));
    end;
  end;

  // Display results
  WriteLn('Application ID: ', ApplicationId.ToString);
end;
//#endregion Example
