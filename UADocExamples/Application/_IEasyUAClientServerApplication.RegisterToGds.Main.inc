// $Header: $
// Copyright (c) CODE Consulting and Development, s.r.o., Plzen. All rights reserved.

//#region Example
// Shows how to create an application registration in the GDS, assigning it a new application ID.
//
// Find all latest examples here : https://opclabs.doc-that.com/files/onlinedocs/OPCLabs-OpcStudio/Latest/examples.html .

class procedure RegisterToGds.Main;
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

  // Create an application registration in the GDS, assigning it a new application ID.
  try
    ApplicationId := Application.RegisterToGds(gdsEndpointDescriptor);
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
