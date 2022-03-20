//---------------------------------------------------------------------------

#ifndef magic_square0813417H
#define magic_square0813417H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ComCtrls.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Grids.hpp>
//---------------------------------------------------------------------------
class TForm2 : public TForm
{
__published:	// IDE-managed Components
	TPanel *Panel1;
	TLabel *Label1;
	TEdit *Edit1;
	TLabel *Label2;
	TButton *Button1;
	TRadioButton *RadioButton1;
	TRadioButton *RadioButton2;
	TRadioButton *RadioButton3;
	TRadioButton *RadioButton4;
	TGroupBox *GroupBox1;
	TPageControl *PageControl1;
	TTabSheet *TabSheet1;
	TStringGrid *StringGrid1;
	void __fastcall Button1Click(TObject *Sender);


private:	// User declarations
public:		// User declarations
	__fastcall TForm2(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm2 *Form2;
//---------------------------------------------------------------------------
#endif
