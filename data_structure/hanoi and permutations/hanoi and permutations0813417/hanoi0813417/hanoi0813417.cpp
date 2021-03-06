//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "hanoi0813417.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"

int i = 1;//用來紀錄步驟數
int j = 1;//用來紀錄步驟數
TForm2 *Form2;
//---------------------------------------------------------------------------
__fastcall TForm2::TForm2(TComponent* Owner)
	: TForm(Owner)
{
}

void hanoi(int n,char start,char temporary,char destination)//(start, temporary, destination)
{
	if(n==1)//遞迴的終點，每當傳入值為1的時候直接把盤子從起點移到終點(不需要中繼站)
	{
		Form2->Memo1->Lines->Add("step  "+IntToStr(i)+" :  Move  the  top  desk  from  tower  "+start+" to  tower  "+ destination);
		i++;
	}
	else//所有概念皆相同，若想把n個盤子移到終點柱，則要把m-1個盤子移到暫時柱(把m-1個盤子移到終點柱(對第n個來說的暫時柱)，則要把n-2個盤子移到暫時柱(對第n個來說的終點柱))
	{
		hanoi(n-1,start,destination,temporary);//把m-1個盤子移到暫時柱
		hanoi(1,start,temporary,destination);//把n個盤子移到終點柱
		hanoi(n-1,temporary,start,destination);//把m-1個盤子移到終點柱
	}
}

void hanoi_tracing(int const_n,int n,char start,char temporary,char destination)
{
	int i;
	String space = "";
	for(i=0;i<(const_n-n);i++)
	{
		space += "	 ";
    }
	Form2->Memo2->Lines->Add(space+"<"+IntToStr(n)+"> try moving the top "+IntToStr(n)+"desks from tower "+start+ "to tower "+destination);//每次呼叫hanoi_tracing時，順便印出他的足跡
	if(n==1)
		{
			Form2->Memo2->Lines->Add("step  "+IntToStr(j)+"  :  Move  the  top  desk  from  tower  "+start+" to  tower  "+ destination);
			j++;
		}
		else
		{
			hanoi_tracing(const_n,n-1,start,destination,temporary);
			hanoi_tracing(const_n,1,start,temporary,destination);
			hanoi_tracing(const_n,n-1,temporary,start,destination);
		}
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Button1Click(TObject *Sender)
{
	int n = StrToInt(Edit1->Text);
	char a,b,c;
	a = 'A';
	b = 'B';
	c = 'C';
	if(n<=0)//防止數據小於等於0
	{
		Form2->Memo1->Lines->Add("you  have  to  send  value  >  0");
		if(CheckBox1->Checked)
			Form2->Memo2->Lines->Add("you  have  to  send  value  >  0");
	}
	else
	{
		hanoi(n,a,b,c);
		Form2->Memo1->Lines->Add("--------------"+IntToStr(i-1)+" steps in total for "+IntToStr(n)+"disks------------");
		if(CheckBox1->Checked)
		{
			hanoi_tracing(n,n,a,b,c);
			Form2->Memo2->Lines->Add("--------------"+IntToStr(j-1)+" steps in total for "+IntToStr(n)+"disks------------");
		}
	}
    i = 1;
	j = 1;
}
//---------------------------------------------------------------------------





