//---------------------------------------------------------------------------

#ifndef SplashH
#define SplashH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
#include "MXCtrls.hpp"
#include <ExtCtrls.hpp>
#include <Graphics.hpp>
#include <jpeg.hpp>
#include "ExtBtn.hpp"
//---------------------------------------------------------------------------
class TfrmSplash : public TForm
{
__published:	// IDE-managed Components
    TImage *Image1;
	TMxLabel *lbStatus;
	TExtBtn *ExtBtn1;
private:	// User declarations
public:		// User declarations
    __fastcall TfrmSplash(TComponent* Owner);
    void SetStatus(LPSTR log){ if (log){ lbStatus->Caption = log; lbStatus->Repaint(); };}
};
//---------------------------------------------------------------------------
extern PACKAGE TfrmSplash *frmSplash;
//---------------------------------------------------------------------------
#endif
