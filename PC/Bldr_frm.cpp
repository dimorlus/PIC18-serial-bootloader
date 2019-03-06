//---------------------------------------------------------------------------
#include <windows.h>
#include <stdlib.h>
#include <stdio.h>
#include <vcl.h>
#include <IniFiles.hpp>
#pragma hdrstop

#include "sys_utils.h"
#include "StrUtils.h"
#include "Serial.h"

#include "Bldr_serv.h"

#include "Bldr_frm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TBldr *Bldr;
//---------------------------------------------------------------------------
__fastcall TBldr::TBldr(TComponent* Owner)
        : TForm(Owner)
{
 HexFile = NULL;
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
void cb_fn(void *owner, const char *str)
{
 ((TBldr *)owner)->CBCom->Items->Add(str);
 Application->ProcessMessages();
 Sleep(0);
}
//---------------------------------------------------------------------------

void __fastcall TBldr::FormCreate(TObject *Sender)
{
  GetPortList(this, cb_fn);
  CBCom->Text = CBCom->Items->Strings[0];
  TIniFile *ini = new TIniFile(ChangeFileExt(Application->ExeName, ".ini"));
  CBCom->Text = ini->ReadString("UART", "PORT", "COM1");
  OpenHex->FileName = ini->ReadString("HEX", "FILE", "");
  Version = ini->ReadInteger("BLDR", "Version", 256);
  FlashWords = ini->ReadInteger("BLDR", "FlashWords", 8192);
  Offset = ini->ReadInteger("BLDR", "Offset", 0x500);
  RowSize = ROW_SIZE;
  RowSize = ini->ReadInteger("BLDR", "RowSize", RowSize);
  EEaddr = ini->ReadInteger("BLDR", "EEaddr", 0x310000);
  EEsize = ini->ReadInteger("BLDR", "EEsize", 0x100);
  CFGaddr = ini->ReadInteger("BLDR", "CFGaddr", 0x300000);
  CFGsize = ini->ReadInteger("BLDR", "CFGsize", 0x0c);
  UIDaddr = ini->ReadInteger("BLDR", "UIDaddr", 0x200000);
  UIDsize = ini->ReadInteger("BLDR", "UIDsize", 0x10);

  delete ini;
  CBComChange(Sender);
  ClearPort(Port);
  List = MTest->Lines;
}
//---------------------------------------------------------------------------

void __fastcall TBldr::FormClose(TObject *Sender, TCloseAction &Action)
{
  TIniFile *ini = new TIniFile(ChangeFileExt(Application->ExeName, ".ini"));
  if (Port != INVALID_HANDLE_VALUE)
   {
    ini->WriteString("UART", "PORT", CBCom->Text);
    lprintf(MTest->Lines, "Close COM port\n");
    CloseComPort(Port);
    //Log("Close COM port");
   }
  ini->WriteString("HEX", "FILE", OpenHex->FileName);
  ini->WriteInteger("BLDR", "Version", Version);
  ini->WriteInteger("BLDR", "FlashWords", FlashWords);
  ini->WriteInteger("BLDR", "Offset", Offset);
  ini->WriteInteger("BLDR", "RowSize", RowSize);
  ini->WriteInteger("BLDR", "EEaddr", EEaddr);
  ini->WriteInteger("BLDR", "EEsize", EEsize);
  ini->WriteInteger("BLDR", "CFGaddr", CFGaddr);
  ini->WriteInteger("BLDR", "CFGsize", CFGsize);
  ini->WriteInteger("BLDR", "UIDaddr", UIDaddr);
  ini->WriteInteger("BLDR", "UIDsize", UIDsize);

  delete ini;
}
//---------------------------------------------------------------------------

void __fastcall TBldr::CBComChange(TObject *Sender)
{
  int port_num;
  CloseComPort(Port);
  sscanf(CBCom->Text.c_str(), "COM%d", &port_num);
  Port = OpenComPort(port_num, 9600, 8, 'N', 1);
  if (Port != INVALID_HANDLE_VALUE)
   {
    lprintf(MTest->Lines,"Open COM%d@9600, 8, N, 1 Ok\n", port_num);
   }
}
//---------------------------------------------------------------------------

void __fastcall TBldr::CBComDropDown(TObject *Sender)
{
 CBCom->Items->Clear();
 GetPortList(this, cb_fn);
 CBCom->Text = CBCom->Items->Strings[0];
}
//---------------------------------------------------------------------------


void __fastcall TBldr::BHEXClick(TObject *Sender)
{
 OpenHex->InitialDir = "";//ExtractFileDir(IniFile);
 OpenHex->Filter = "Hex File (*.hex)|*.hex|";
 //OpenDialog->FileName = EeFile;
 OpenHex->Title = "Open HEX file";
 if (OpenHex->Execute())
  {
  }
}
//---------------------------------------------------------------------------

void __fastcall TBldr::BProgClick(TObject *Sender)
{
 BProg->Enabled = false;
 BStop->Enabled = true;
 MTest->Lines->Clear();
 lprintf(MTest->Lines, "Open %s ... ", OpenHex->FileName.c_str());
 HexFile = fopen(OpenHex->FileName.c_str(), "r");
 if (HexFile) lprintf(MTest->Lines, "Ok\n");
 else lprintf(MTest->Lines, "Fail\n");
 lprintf(MTest->Lines, "\n");

 prog_states(Port, true);
  while(prog_states(Port, false) == 0)
   {
    idle();
    Application->ProcessMessages();
    if (!BStop->Enabled) break;
   }

 if (HexFile)
  {
   lprintf(MTest->Lines, "Close HEX\n");
   fclose(HexFile);
   HexFile = NULL;
  }
 BProg->Enabled = true;
 BStop->Enabled = false;
}
//---------------------------------------------------------------------------

void __fastcall TBldr::BiniClick(TObject *Sender)
{
 AnsiString IniFile = ChangeFileExt(Application->ExeName, ".ini");
 AnsiString AStr = "notepad.exe \"" + IniFile + "\"";
 int res = WinExec(AStr.c_str(), SW_SHOWNORMAL);
 if (res < 32) MessageDlg("Error on attempt to execute " + IniFile,
                             mtError, TMsgDlgButtons() << mbOK, 0);
}
//---------------------------------------------------------------------------

void __fastcall TBldr::BStopClick(TObject *Sender)
{
 BStop->Enabled = false;        
}
//---------------------------------------------------------------------------

