// $Header: $
// Copyright (c) CODE Consulting and Development, s.r.o., Plzen. All rights reserved.

//#region Example
// This example shows how to unsubscribe from changes of just some monitored
// items.
//
// Find all latest examples here : https://opclabs.doc-that.com/files/onlinedocs/OPCLabs-OpcStudio/Latest/examples.html .

type
  TClientEventHandlers128 = class
    procedure OnDataChangeNotification(
      ASender: TObject;
      sender: OleVariant;
      const eventArgs: _EasyUADataChangeNotificationEventArgs);
  end;

procedure TClientEventHandlers128.OnDataChangeNotification(
  ASender: TObject;
  sender: OleVariant;
  const eventArgs: _EasyUADataChangeNotificationEventArgs);
begin
  // Display the data
  if eventArgs.Succeeded then
  	WriteLn(eventArgs.Arguments.NodeDescriptor.ToString, ': ',
      eventArgs.AttributeData.ToString)
  else
  	WriteLn(eventArgs.Arguments.NodeDescriptor.ToString, ' *** Failure: ',
      eventArgs.ErrorMessageBrief);
end;

class procedure UnsubscribeMultipleMonitoredItems.Some;
var
  Arguments: OleVariant;
  Client: TEasyUAClient;
  ClientEventHandlers: TClientEventHandlers128;
  Handle: Cardinal;
  HandleArray: OleVariant;
  HandleSafeArray: PSafeArray;
  I: Cardinal;
  MonitoredItemArguments1, MonitoredItemArguments2, MonitoredItemArguments3:
    _EasyUAMonitoredItemArguments;
  MonitoringParameters: _UAMonitoringParameters;
  SelectedHandles: OleVariant;
begin
  // Instantiate the client object and hook events
  Client := TEasyUAClient.Create(nil);
  ClientEventHandlers := TClientEventHandlers128.Create;
  Client.OnDataChangeNotification := ClientEventHandlers.OnDataChangeNotification;

  WriteLn;
  WriteLn('Subscribing...');
  MonitoringParameters := CoUAMonitoringParameters.Create;
  MonitoringParameters.SamplingInterval := 1000;
  MonitoredItemArguments1 := CoEasyUAMonitoredItemArguments.Create;
  MonitoredItemArguments1.EndpointDescriptor.UrlString := 
    //'http://opcua.demo-this.com:51211/UA/SampleServer';
    //'https://opcua.demo-this.com:51212/UA/SampleServer/';
    'opc.tcp://opcua.demo-this.com:51210/UA/SampleServer';
  MonitoredItemArguments1.NodeDescriptor.NodeId.ExpandedText := 'nsu=http://test.org/UA/Data/ ;i=10845';
  MonitoredItemArguments1.MonitoringParameters := MonitoringParameters;
  MonitoredItemArguments2 := CoEasyUAMonitoredItemArguments.Create;
  MonitoredItemArguments2.EndpointDescriptor.UrlString := 
    //'http://opcua.demo-this.com:51211/UA/SampleServer';
    //'https://opcua.demo-this.com:51212/UA/SampleServer/';
    'opc.tcp://opcua.demo-this.com:51210/UA/SampleServer';
  MonitoredItemArguments2.NodeDescriptor.NodeId.ExpandedText := 'nsu=http://test.org/UA/Data/ ;i=10853';
  MonitoredItemArguments2.MonitoringParameters := MonitoringParameters;
  MonitoredItemArguments3 := CoEasyUAMonitoredItemArguments.Create;
  MonitoredItemArguments3.EndpointDescriptor.UrlString := 
    //'http://opcua.demo-this.com:51211/UA/SampleServer';
    //'https://opcua.demo-this.com:51212/UA/SampleServer/';
    'opc.tcp://opcua.demo-this.com:51210/UA/SampleServer';
  MonitoredItemArguments3.NodeDescriptor.NodeId.ExpandedText := 'nsu=http://test.org/UA/Data/ ;i=10855';
  MonitoredItemArguments3.MonitoringParameters := MonitoringParameters;
  Arguments := VarArrayCreate([0, 2], varVariant);
  Arguments[0] := MonitoredItemArguments1;
  Arguments[1] := MonitoredItemArguments2;
  Arguments[2] := MonitoredItemArguments3;

  HandleSafeArray := Client.SubscribeMultipleMonitoredItems(Arguments);
  TVarData(HandleArray).VType := varArray or varVariant;
  TVarData(HandleArray).VArray := PVarArray(HandleSafeArray);

  for I := VarArrayLowBound(HandleArray, 1) to VarArrayHighBound(HandleArray, 1) do
  begin
      Handle := Cardinal(HandleArray[I]);
      WriteLn('HandleArray[', I, ']: ', Handle);
  end;

  WriteLn;
  WriteLn('Processing monitored item changed events for 10 seconds...');
  PumpSleep(10*1000);

  WriteLn;
  WriteLn('Unsubscribing from 2 monitored items...');
  SelectedHandles := VarArrayCreate([0, 1], varVariant);
  // We will unsubscribe from the first and third monitored item we have
  // previously subscribed to.
  SelectedHandles[0] := HandleArray[0];
  SelectedHandles[1] := HandleArray[2];
  Client.UnsubscribeMultipleMonitoredItems(SelectedHandles);

  WriteLn;
  WriteLn('Processing monitored item changed events for 10 seconds...');
  PumpSleep(10*1000);

  WriteLn;
  WriteLn('Unsubscribing from all remaining monitored items...');
  Client.UnsubscribeAllMonitoredItems;

  WriteLn;
  WriteLn('Waiting for 5 seconds...');
  Sleep(5*1000);

  WriteLn;
  WriteLn('Finished.');
  VarClear(HandleArray);
  VarClear(Arguments);
  FreeAndNil(Client);
  FreeAndNil(ClientEventHandlers);
end;
//#endregion Example