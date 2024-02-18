// $Header: $
// Copyright (c) CODE Consulting and Development, s.r.o., Plzen. All rights reserved.

//#region Example
// Attempts to parse an absolute  OPC-UA browse path and displays its starting node and elements.
//
// Find all latest examples here : https://opclabs.doc-that.com/files/onlinedocs/OPCLabs-OpcStudio/Latest/examples.html .

class procedure TryParse.Main;
var
  BrowsePath: _UABrowsePath;
  BrowsePathElement: _UABrowsePathElement;
  BrowsePathParser: OpcLabs_EasyOpcUA_TLB._UABrowsePathParser;
  BrowsePathResult: OleVariant;
  Count: Cardinal;
  Element: OleVariant;
  ElementEnumerator: IEnumVariant;
  StringParsingError: _StringParsingError;
begin
  BrowsePathParser := CoUABrowsePathParser.Create;

  StringParsingError := BrowsePathParser.TryParse('[ObjectsFolder]/Data/Static/UserScalar', BrowsePathResult);

  // Display results
  if StringParsingError <> nil then
  begin
    WriteLn('*** Error: ', StringParsingError.ToString);
    Exit;
  end;

  BrowsePath := IUnknown(BrowsePathResult) as _UABrowsePath;
  WriteLn('StartingNodeId: ', BrowsePath.StartingNodeId.ToString);

  WriteLn('Elements:');
  ElementEnumerator := BrowsePath.Elements.GetEnumerator;
  while (ElementEnumerator.Next(1, Element, Count) = S_OK) do
  begin
    BrowsePathElement := IUnknown(Element) as _UABrowsePathElement;
    WriteLn(BrowsePathElement.ToString);
  end;

  // Example output:
  // StartingNodeId: ObjectsFolder
  // Elements:
  // /Data
  // /Static
  // /UserScalar

end;
//#endregion Example
