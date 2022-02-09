//---------------------------------------------------------------------------

#ifndef mouse_in_maze0813417H
#define mouse_in_maze0813417H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ComCtrls.hpp>
#include <Vcl.Dialogs.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Grids.hpp>
//---------------------------------------------------------------------------
class TForm2 : public TForm
{
__published:	// IDE-managed Components
	TPanel *Panel1;
	TPageControl *PageControl1;
	TTabSheet *TabSheet1;
	TTabSheet *TabSheet2;
	TMemo *Memo1;
	TStringGrid *StringGrid1;
	TOpenDialog *OpenDialog1;
	TButton *Button1;
	TTrackBar *TrackBar1;
	TLabel *Label1;
	TButton *Button2;
	TPanel *Panel2;
	TButton *Button3;
	TPanel *Panel3;
	TEdit *Edit1;
	TEdit *Edit2;
	TLabel *Label2;
	TLabel *Label3;
	TLabel *Label4;
	TPanel *Panel4;
	TLabel *Label5;
	TEdit *Edit3;
	TLabel *Label6;
	TEdit *Edit4;
	TLabel *Label7;
	TLabel *Label8;
	TEdit *Edit5;
	TEdit *Edit6;
	TLabel *Label9;
	TLabel *Label10;
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall color(TObject *Sender, int ACol, int ARow, TRect &Rect, TGridDrawState State);
	void __fastcall Button2Click(TObject *Sender);
	void __fastcall Button3Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TForm2(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm2 *Form2;
//---------------------------------------------------------------------------
#endif
