//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "permutations0813417.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"

int count = 0;

TForm2 *Form2;
//---------------------------------------------------------------------------
__fastcall TForm2::TForm2(TComponent* Owner)
	: TForm(Owner)
{
}

void swap(char list[],int k,int i)//交換function
{
	wchar_t temp;
	temp = list[k];
	list[k] = list[i];
	list[i] = temp;
}

void permutations(char list[],int k,int n)
{
	int i;
	if(k==n-1)
	{
		String a = list;
		a = a.SubString(0,n);
		Form2->Memo1->Lines->Add(a+"["+IntToStr(count++)+"]");
	}
	else
	{
		for(i=k;i<n;i++)//選定一個字元當頭頭
		{
			swap(list,k,i);//依序和其後的字元交換
			permutations(list,k+1,n);//產生遞迴，決定下一個位置的頭頭是誰
			swap(list,k,i);//歸位
		}
	}
}

void permutations_tracing(char list[],int k,int n)
{
	int i,j;
	String space ="    ";
	for(j=0;j<k;j++)
	{
		space += "    ";
	}//用來調整tracing的格式
	if(k==n-1)
	{
		String a = list;
		a = a.SubString(0,n);
		Form2->Memo2->Lines->Add(space+"==>(k,n)=("+IntToStr(k)+","+IntToStr(n)+")!	k==n-1	print!");
		Form2->Memo2->Lines->Add(a+"["+IntToStr(count++)+"]");
	}
	else
	{
		for(i=k;i<n;i++)
		{
			swap(list,k,i);
			String b = list;//listswap後才轉換成字元，不然會轉換到未swap的字串
			b = b.SubString(0,n);
			Form2->Memo2->Lines->Add(space+"> i="+IntToStr(i)+"	(k,n)=("+IntToStr(k)+","+IntToStr(n)+"),	swap[k,x]=["+IntToStr(k)+","+IntToStr(i)+"],	list[ ]="+b);
			permutations_tracing(list,k+1,n);
			swap(list,k,i);
			String c = list;
			c = c.SubString(0,n);
			Form2->Memo2->Lines->Add(space+"< i="+IntToStr(i)+"	(k,n)=("+IntToStr(k)+","+IntToStr(n)+"),	swap[k,x]=["+IntToStr(k)+","+IntToStr(i)+"],	list[ ]="+c);
		}
	}
}

//---------------------------------------------------------------------------

void __fastcall TForm2::Button1Click(TObject *Sender)
{
	int k,n,i;
	char list[26] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
	/*String input;
	input = Edit2->Text;
	n = input.Length();
	wchar_t list[n];
	for(i=0;i<n;i++)
	{
		list[i] = input[i];
	}*/
	k = StrToInt(Edit1->Text);
	n = StrToInt(Edit2->Text);
	if(k>26||n>26)//超過26個字元防呆
		Form2->Memo1->Lines->Add("YOUR NUMBER OVER26!!!");
	else
	{
		permutations(list,k,n);
		Form2->Memo1->Lines->Add("---------------------------------------------------");
		count = 0;
		if(CheckBox1->Checked)
		{
			Form2->Memo2->Lines->Add("Go==>(k,n)=("+IntToStr(k)+","+IntToStr(n)+")");
			permutations_tracing(list,k,n);
			Form2->Memo2->Lines->Add("--------------------------------------------------------------------------------------------------------");
			count = 0;
		}
    }
}
//---------------------------------------------------------------------------


