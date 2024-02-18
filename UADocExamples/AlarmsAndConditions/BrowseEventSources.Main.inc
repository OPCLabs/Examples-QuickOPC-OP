// $Header: $
// Copyright (c) CODE Consulting and Development, s.r.o., Plzen. All rights reserved.

//#region Example
// This example shows how to browse objects under the "Objects" node and display event sources.
//
// Find all latest examples here : https://opclabs.doc-that.com/files/onlinedocs/OPCLabs-OpcStudio/Latest/examples.html .

class procedure BrowseEventSources.Main;
var
  ObjectNodeId: _UANodeId;
begin
  ObjectNodeId := CoUANodeId.Create;
  ObjectNodeId.StandardName := 'Objects';
  try
    BrowseFrom(ObjectNodeId);
  except
    on E: EOleException do
    begin
      WriteLn(Format('*** Failure: %s', [E.GetBaseException.Message]));
      Exit;
    end;
  end;
end;

class procedure BrowseEventSources.BrowseFrom(NodeId: _UANodeId);
var
  Client: OpcLabs_EasyOpcUA_TLB._EasyUAClient;
  Count: Cardinal;
  Element: OleVariant;
  EndpointDescriptor: string;
  EventSourceNodeElement: _UANodeElement;
  EventSourceNodeElementEnumerator: IEnumVariant;
  EventSourceNodeElements: _UANodeElementCollection;
  ObjectNodeElement: _UANodeElement;
  ObjectNodeElementEnumerator: IEnumVariant;
  ObjectNodeElements: _UANodeElementCollection;
begin
  EndpointDescriptor := 'opc.tcp://opcua.demo-this.com:62544/Quickstarts/AlarmConditionServer';

  WriteLn;
  WriteLn;
  WriteLn('Parent node: ', NodeId.ToString);

  // Instantiate the client object
  Client := CoEasyUAClient.Create;

  // Obtain event sources
  EventSourceNodeElements := Client.BrowseEventSources(EndpointDescriptor, NodeId.ExpandedText);

  // Display event sources
  if EventSourceNodeElements.Count <> 0 then
  begin
    WriteLn;
    WriteLn('Event sources:');
    EventSourceNodeElementEnumerator := EventSourceNodeElements.GetEnumerator;
    while (EventSourceNodeElementEnumerator.Next(1, Element, Count) = S_OK) do
    begin
      EventSourceNodeElement := IUnknown(Element) as _UANodeElement;
      WriteLn(EventSourceNodeElement.ToString);
    end;
  end;

  // Obtain objects
  ObjectNodeElements := Client.BrowseObjects(EndpointDescriptor, NodeId.ExpandedText);

  // Recurse
  ObjectNodeElementEnumerator := ObjectNodeElements.GetEnumerator;
  while (ObjectNodeElementEnumerator.Next(1, Element, Count) = S_OK) do
  begin
    ObjectNodeElement := IUnknown(Element) as _UANodeElement;
    BrowseFrom(ObjectNodeElement.NodeId);
  end;
end;

//#endregion Example
