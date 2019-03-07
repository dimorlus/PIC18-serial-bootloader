//---------------------------------------------------------------------------
#include <windows.h>
#include <stdlib.h>
#include <stdio.h>
#include <vcl.h>
#include <IniFiles.hpp>
#pragma hdrstop

#include "Serial.h"

#include "Bldr_serv.h"
//---------------------------------------------------------------------------

#pragma argsused

AnsiString ComPort;
AnsiString HexFileName;
HANDLE Port;

void LoadIni(char *exeName)
{
  TIniFile *ini = new TIniFile(ChangeFileExt(exeName, ".ini"));
  ComPort = ini->ReadString("UART", "PORT", "COM1");
  HexFileName = ini->ReadString("HEX", "FILE", "");
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
}

void SaveIni(char *exeName, char *HexName)
{
  TIniFile *ini = new TIniFile(ChangeFileExt(exeName, ".ini"));
  ini->WriteString("HEX", "FILE", HexName);
  delete ini;

}

int main(int argc, char* argv[])
{
 int port_num;
 LoadIni(argv[0]);

 sscanf(ComPort.c_str(), "COM%d", &port_num);
 Port = OpenComPort(port_num, 9600, 8, 'N', 1);
 if (Port != INVALID_HANDLE_VALUE)
  {
   printf("Open COM%d@9600, 8, N, 1 Ok\n\r", port_num);
   if (argc>1 && argv[1])
    {
     printf("Open %s ... ", argv[1]);
     HexFile = fopen(argv[1], "r");
     if (HexFile)
      {
       printf("Ok\n\r");
       SaveIni(argv[0], argv[1]);
      }
     else
      {
       printf("Fail.\n\r");
       printf("Open %s ... ", HexFileName.c_str());
       HexFile = fopen(HexFileName.c_str(), "r");
      }
     if (HexFile) printf("Ok\n\r");
     else printf("Fail.\n\r");
    }
   else
    {
     printf("Open %s ... ", HexFileName.c_str());
     HexFile = fopen(HexFileName.c_str(), "r");
     if (HexFile) printf("Ok\n\r");
     else printf("Fail.\n\r");
    }

   if (HexFile)
    {
     prog_states(Port, true);
     while(prog_states(Port, false) == 0) idle();
     printf("Close HEX\n\r");
     fclose(HexFile);
    }
   CloseComPort(Port);
  }
 else printf("Failed open port %d\n\r", port_num);
 return 0;
}
//---------------------------------------------------------------------------
