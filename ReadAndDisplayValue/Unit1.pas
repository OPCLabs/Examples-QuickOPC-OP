// $Header: $
// Copyright (c) CODE Consulting and Development, s.r.o., Plzen. All rights reserved.

//
// Find all latest examples here : https://opclabs.doc-that.com/files/onlinedocs/OPCLabs-OpcStudio/Latest/examples.html .

unit Unit1;

interface

uses
  Windows, Messages, SysUtils, Variants, Classes, Graphics, Controls, Forms,
  Dialogs, StdCtrls,
  OpcLabs_EasyOpcClassic_TLB,
  OpcLabs_EasyOpcClassicComponents_TLB;

type
  TForm1 = class(TForm)
    Edit1: TEdit;
    procedure FormCreate(Sender: TObject);
  private
    { Private declarations }
  public
    { Public declarations }
  end;

var
  Form1: TForm1;

implementation

{$R *.dfm}

procedure TForm1.FormCreate(Sender: TObject);
var
  EasyDAClient: _EasyDAClient;
begin
  { Create EasyOPC-DA component }
  EasyDAClient := CoEasyDAClient.Create;

  { Read item value and display it }
  Edit1.Text := EasyDAClient.ReadItemValue('', 'OPCLabs.KitServer.2',
    'Demo.Single');
end;

end.
