//
// Find all latest examples here : https://opclabs.doc-that.com/files/onlinedocs/OPCLabs-OpcStudio/Latest/examples.html .

unit AlarmsAndEvents;

interface

type
AEExamplesMenu = class
public
  class procedure Main(); static;
end;

implementation
uses
  Console,
  _EasyAEClient;

class procedure AEExamplesMenu.Main();

var
  actionArray: TArray<TNamedAction>;
  cont: boolean;
begin
  actionArray := TArray<TNamedAction>.Create(
    TNamedAction.Create(@_EasyAEClient.PullNotification.Main, 'DocExamples.AlarmsAndEvents._EasyAEClient.PullNotification.Main'),
    TNamedAction.Create(@_EasyAEClient.SubscribeEvents.Main, 'DocExamples.AlarmsAndEvents._EasyAEClient.SubscribeEvents.Main')
  );
  repeat
    WriteLn;
    cont := ConsoleDialog.SelectAndPerformAction('Select action to perform', 'Return', actionArray);
    if cont then
    begin
      WriteLn('Press Enter to continue...');
      ReadLn;
    end;
  until not cont;
end;

end.
