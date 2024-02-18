// $Header: $
// Copyright (c) CODE Consulting and Development, s.r.o., Plzen. All rights reserved.

//#region Example
// Parses a relative OPC-UA browse path and displays its elements.
//
// Find all latest examples here : https://opclabs.doc-that.com/files/onlinedocs/OPCLabs-OpcStudio/Latest/examples.html .

class procedure ParseRelative.Main;
var
  BrowsePathElement: _UABrowsePathElement;
  BrowsePathElements: _UABrowsePathElementCollection;
  BrowsePathParser: OpcLabs_EasyOpcUA_TLB._UABrowsePathParser;
  Count: Cardinal;
  Element: OleVariant;
  ElementEnumerator: IEnumVariant;
begin
  BrowsePathParser := CoUABrowsePathParser.Create;

  try
    BrowsePathElements := BrowsePathParser.ParseRelative('/Data.Dynamic.Scalar.CycleComplete');
  except
    on E: EOleException do
    begin
      WriteLn(Format('*** Failure: %s', [E.GetBaseException.Message]));
      Exit;
    end;
  end;

  // Display results
  ElementEnumerator := BrowsePathElements.GetEnumerator;
  while (ElementEnumerator.Next(1, Element, Count) = S_OK) do
  begin
    BrowsePathElement := IUnknown(Element) as _UABrowsePathElement;
    WriteLn(BrowsePathElement.ToString);
  end;

  // Example output:
  // /Data
  // .Dynamic
  // .Scalar
  // .CycleComplete

end;
//#endregion Example
