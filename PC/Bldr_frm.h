//---------------------------------------------------------------------------

#ifndef Bldr_frmH
#define Bldr_frmH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Dialogs.hpp>
//---------------------------------------------------------------------------
class TBldr : public TForm
{
__published:	// IDE-managed Components
        TMemo *MTest;
        TLabel *LPort;
        TComboBox *CBCom;
        TOpenDialog *OpenHex;
        TButton *BHEX;
        TButton *BProg;
        TButton *Bini;
        TButton *BStop;
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall CBComChange(TObject *Sender);
        void __fastcall CBComDropDown(TObject *Sender);
        void __fastcall BHEXClick(TObject *Sender);
        void __fastcall BProgClick(TObject *Sender);
        void __fastcall BiniClick(TObject *Sender);
        void __fastcall BStopClick(TObject *Sender);
private:	// User declarations
        HANDLE Port;

public:		// User declarations
        __fastcall TBldr(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TBldr *Bldr;
//---------------------------------------------------------------------------
#endif
