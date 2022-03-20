//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "hanoi0813417.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"

int i = 1;//�ΨӬ����B�J��
int j = 1;//�ΨӬ����B�J��
TForm2 *Form2;
//---------------------------------------------------------------------------
__fastcall TForm2::TForm2(TComponent* Owner)
	: TForm(Owner)
{
}

void hanoi(int n,char start,char temporary,char destination)//(start, temporary, destination)
{
	if(n==1)//���j�����I�A�C���ǤJ�Ȭ�1���ɭԪ�����L�l�q�_�I������I(���ݭn���~��)
	{
		Form2->Memo1->Lines->Add("step  "+IntToStr(i)+" :  Move  the  top  desk  from  tower  "+start+" to  tower  "+ destination);
		i++;
	}
	else//�Ҧ������ҬۦP�A�Y�Q��n�ӽL�l������I�W�A�h�n��m-1�ӽL�l����ȮɬW(��m-1�ӽL�l������I�W(���n�Өӻ����ȮɬW)�A�h�n��n-2�ӽL�l����ȮɬW(���n�Өӻ������I�W))
	{
		hanoi(n-1,start,destination,temporary);//��m-1�ӽL�l����ȮɬW
		hanoi(1,start,temporary,destination);//��n�ӽL�l������I�W
		hanoi(n-1,temporary,start,destination);//��m-1�ӽL�l������I�W
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
	Form2->Memo2->Lines->Add(space+"<"+IntToStr(n)+"> try moving the top "+IntToStr(n)+"desks from tower "+start+ "to tower "+destination);//�C���I�shanoi_tracing�ɡA���K�L�X�L������
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
	if(n<=0)//����ƾڤp�󵥩�0
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




