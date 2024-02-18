// $Header: $
// Copyright (c) CODE Consulting and Development, s.r.o., Plzen. All rights reserved.

//
// Find all latest examples here : https://opclabs.doc-that.com/files/onlinedocs/OPCLabs-OpcStudio/Latest/examples.html .

unit _UABrowsePathParser;

interface

type
  Parse = class
    class procedure Main;
  end;

type
  ParseRelative = class
    class procedure Main;
  end;

type
  TryParse = class
    class procedure Main;
  end;

type
  TryParseRelative = class
    class procedure Main;
  end;


implementation
uses
  ComObj,
  Generics.Collections,
  IdGlobal,
  MessagePump,
  mscorlib_TLB,
  OpcLabs_BaseLib_TLB,
  OpcLabs_BaseLibForms_TLB,
  OpcLabs_EasyOpcUA_TLB,
  System.DateUtils,
  System.SysUtils,
  Variants,
  WinApi.ActiveX,
  Windows;

{$I _UABrowsePathParser/Parse.Main.inc}
{$I _UABrowsePathParser/ParseRelative.Main.inc}
{$I _UABrowsePathParser/TryParse.Main.inc}
{$I _UABrowsePathParser/TryParseRelative.Main.inc}

end.
