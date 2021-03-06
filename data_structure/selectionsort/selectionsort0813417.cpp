//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "selectionsort0813417.h"
#include<time.h>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"

int data[1000000];
int n;


TForm2 *Form2;
//---------------------------------------------------------------------------
__fastcall TForm2::TForm2(TComponent* Owner)
	: TForm(Owner)
{
}

void SelectSort(int data[],int n)
{
	int i;
	int j;
	int min;
	int temp;
	for(i=0;i<n;i++)
	{
		min = i;
		for(j=i+1;j<n;j++)
		{
			if(data[j]<data[min])
			min = j;
		}
		temp = data[i];
		data[i] = data[min];
		data[min] = temp;
	}
}

void BubbleSort(int data[],int n)
{
	int i;
	int current;
	int temp;
	int max = n-1;
	for(i=0;i<n;i++)
	{
		current = 0;
		while(current!=max)
		{
			if(data[current]>data[current+1])
			{
				temp = data[current];
				data[current] = data[current+1];
				data[current+1] = temp;
			}
			current++;
		}
		max--;
	}
}

void binarysearch(int data[],int n,int target)
{
	int left = 0;
	int right = n-1;
	int middle = (left+right)/2;
	while(left<right)
	{
		if(data[middle]>target)
			right = middle-1;
		else if(data[middle]==target)
		{
			Form2->Memo4->Lines->Add("Found in place"+IntToStr(middle));
			break;
		}
		else
			left = middle+1;
		middle = (left+right)/2;
	}
	if(left==right)
	{
		if(data[middle]==target)
			Form2->Memo4->Lines->Add("Found in place"+IntToStr(middle));
		else
			Form2->Memo4->Lines->Add("Number does not exist!");
	}
}

//---------------------------------------------------------------------------

void __fastcall TForm2::Button1Click(TObject *Sender)
{
     int i;
	int range = StrToInt(Edit2->Text);
	n = StrToInt(Edit1->Text);
	if(CheckBox1->Checked)
		for(i=0;i<n;i++)
		{
			data[i] = rand()%(range+1);
			Form2->Memo1->Lines->Add("data["+IntToStr(i)+"] = "+IntToStr(data[i]));
		}
}
//---------------------------------------------------------------------------

void __fastcall TForm2::Button2Click(TObject *Sender)
{
	clock_t t_begin, t_end;
	int i;
	t_begin = clock();
	SelectSort(data,n);
	t_end = clock();
	Form2->Memo2->Lines->Add("CPU time (sec) = "+FloatToStr((float)(t_end-t_begin)/CLOCKS_PER_SEC));
	if(CheckBox1->Checked)
		for(i=0;i<n;i++)
		{
			Form2->Memo2->Lines->Add("data["+IntToStr(i)+"] = "+IntToStr(data[i]));
		}
	if(CheckBox2->Checked)
	{
		for(i=0;i<n;i++)
		{
			if(data[i]>data[i+1])
			{
				Form2->Memo2->Lines->Add("Self Check: fail");
				break;
			}
		        if(i = n-1)
				Form2->Memo2->Lines->Add("Self Check: success");
		}
	}

}
//---------------------------------------------------------------------------

void __fastcall TForm2::Button3Click(TObject *Sender)
{
	clock_t t_begin, t_end;
	int i;
	t_begin = clock();
	BubbleSort(data,n);
	t_end = clock();
	Form2->Memo3->Lines->Add("CPU time (sec) = "+FloatToStr((float)(t_end-t_begin)/CLOCKS_PER_SEC));
	if(CheckBox1->Checked)
		for(i=0;i<n;i++)
		{
			Form2->Memo3->Lines->Add("data["+IntToStr(i)+"] = "+IntToStr(data[i]));
		}
	if(CheckBox2->Checked)
	{
		for(i=0;i<n;i++)
		{
			if(data[i]>data[i+1])
			{
				Form2->Memo3->Lines->Add("Self Check: fail");
				break;
			}
			if(i = n-1)
				Form2->Memo3->Lines->Add("Self Check: success");
		}
	}

}
//---------------------------------------------------------------------------

void __fastcall TForm2::Button4Click(TObject *Sender)
{
	int target = StrToInt(Edit3->Text);
	binarysearch(data,n,target);
}
//---------------------------------------------------------------------------


