//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "shortest_path0813417.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm2 *Form2;
int D[100] = {NULL};//�x�su��U�I���Ȯɳ̬q�Z��
int C[100] = {NULL};//�����Ȯɳ̵u���|���W�@���I
bool found[100] = {false};//�x�s�w�ѨM��node
int w[100][100] = {NULL};//�Z���x�},�q�Y������|�Q����
int A[100][100] = {NULL};//���j�ʳ��M�����I���̪�Z�����x�s�x�}
//---------------------------------------------------------------------------
__fastcall TForm2::TForm2(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------

int min()//found number that is mini and unfound
{
	int n = StrToInt(Form2->Edit1->Text);
	int mini_index = 0;
	int mini = 1000; //�e����index�Mvalue�d�V
	int i;
	for(i=0;i<n;i++)
		if(!found[i] && D[i]<mini)
		{	mini_index = i;
			mini = D[mini_index];
		}
	return mini_index;
}

bool all_found()//���Ҧ����`�I��solved
{
	int n = StrToInt(Form2->Edit1->Text);
	for(int i=0;i<n;i++)
		if(!found[i])
			return true;//�٦�false�h�j��true�A�ϩI�s���~��]�j��
	return false;//�Y�ˬd���Ҧ����������Ҭ�true�A�h�^��false�ϱo�I�s�̰���j��
}

void Shortestpath(int u,int v)
{
	int a = v;
	String path = IntToStr(v);
	while(C[v]!=u)
	{   path = IntToStr(C[v])+"--["+IntToStr(w[C[v]][v])+"]-->"+path;
		v = C[v];
	}
	path = "From "+IntToStr(u)+" to "+IntToStr(a)+" : "+IntToStr(u)+"--["+IntToStr(w[u][v])+"]-->"+path;
	Form2->Memo1->Lines->Add(path);
}

int short_path()
{
	int all_D[100][100] = {NULL};//�ΨӦs��C�@���s�᪺D
	int a = 0;//�ΨӬ����ĴX�Ӱj��
	int n = StrToInt(Form2->Edit1->Text);
	int u = StrToInt(Form2->Edit5->Text);//�_�I
	for(int i=0;i<100;i++)//�~���W��SSAD���|
		for(int j=0;j<100;j++)
			Form2->StringGrid2->Cells[i][j] = "";
	for(int i=0;i<n;i++)
	{   D[i] = w[u][i];
		C[i] = u;
	}
	found[u] = true;
	for(int i=0;i<n;i++)
		all_D[i][a]	= D[i];
	a++;//�i�J�j�餧�e�����l���A�s�i�h
	while(all_found())//����all found is false
	{	int k = min();//find the min number except number has been found
		found[k] = true;
		for(int j=0;j<n;j++)//��s���D
		{   if(!found[j] && D[j]> D[k]+w[k][j])
			{   D[j] = D[k]+w[k][j];   
				C[j] = k;
			}
		}
		for(int i=0;i<n;i++)
			all_D[i][a]	= D[i];
		a++;
	}
	Form2->StringGrid2->RowCount = n+1;
	Form2->StringGrid2->ColCount = a+1;
	for(int i=1;i<=n;i++)//���W
		Form2->StringGrid2->Cells[0][i] = IntToStr(i-1);  //stringgrid �O�����C (���O���C���)
	for(int j=1;j<=a;j++)//�j�馸��
	{   if(j==a) Form2->StringGrid2->Cells[j][0] = "C[v]";
		else Form2->StringGrid2->Cells[j][0] = IntToStr(j-1);
	}
	for(int j=0;j<a;j++)//��Jall_D����
		for(int i=0;i<n;i++)
			Form2->StringGrid2->Cells[j+1][i+1] = all_D[i][j];	
			
	for(int j=1;j<=n;j++)//��̨ܳθ��|���e�@���I
		Form2->StringGrid2->Cells[a][j] = IntToStr(C[j-1]);
}

void __fastcall TForm2::Button1Click(TObject *Sender)//generate G
{
	int u = StrToInt(Edit5->Text);
	int n = StrToInt(Edit1->Text);
	int range = StrToInt(Edit2->Text);
	int limit = StrToInt(Edit3->Text);
	int bigger = StrToInt(Edit4->Text);
	for(int i=0;i<n;i++)//���s�Z���x�}
		for(int j=0;j<n;j++)
			w[i][j] = NULL;
	for(int i=0;i<n;i++)//���ssolved�аO
			found[i] = false;
	for(int i=0;i<n;i++)//�H���ͦ��Z���x�}
	{   for(int j=0;j<n;j++)
		{   w[i][j] = (rand()%(range+1))+1;//+1�קK�Z�����s
			if(w[i][j]>limit) w[i][j] = bigger;
			if(CheckBox1->Checked)//��ٿﶵ
				if(w[j][i]>0) w[i][j] = w[j][i];//�O���q�D���@�P�ʡAA��B�O18�hB��A�]�n�O18����O40
		}
		w[i][i] = 0;//�]��999�άO0���S���v�T
	}
	StringGrid1->RowCount = n+1;
	StringGrid1->ColCount = n+1;
	for (int j=1; j<=n; j++)//��ܦa�I�N��	
	{   StringGrid1->Cells[0][j] = IntToStr(j-1);
		StringGrid1->Cells[j][0] = IntToStr(j-1);
	}
	for (int i=0;i<n; i++)
	   for (int j=0; j<n; j++)
		   StringGrid1->Cells[i+1][j+1] = IntToStr(w[i][j]);
}
//---------------------------------------------------------------------------

void __fastcall TForm2::Button2Click(TObject *Sender)//Single Source to All Destination
{
	int n = StrToInt(Edit1->Text);
	int u = StrToInt(Edit5->Text);
	short_path();
	for(int v=0;v<n;v++)
	{   if(v!=u)
			Shortestpath(u,v);
    }
	Memo1->Lines->Add("-----------------------------------------------");	
	for(int i=0;i<100;i++)//���s
	{	D[i] = NULL;
		C[i] = NULL;
		found[i] = false;
	}
}
void __fastcall TForm2::Button3Click(TObject *Sender)//all pairs
{
	int n = StrToInt(Edit1->Text);
	Form2->StringGrid3->RowCount = n+1;
	Form2->StringGrid3->ColCount = n+1;
	int i = 0;
	int j = 0;
	int k = 0;
	for (int j=1; j<=n; j++)//��ܦa�I�N��	
	{   StringGrid3->Cells[0][j] = IntToStr(j-1);
		StringGrid3->Cells[j][0] = IntToStr(j-1);
	}
	for(i=0;i<n;i++)//���sA�x�}
		for(j=0;j<n;j++)
			A[i][j] = NULL; 
	for(i=0;i<n;i++)//A inverse(��l���A)
		for(j=0;j<n;j++)
			A[i][j] = w[i][j];
	for(k=0;k<n;k++)
		for(i=0;i<n;i++)
			for(j=0;j<n;j++)
				if(A[i][j]>A[i][k]+A[k][j])
					A[i][j] = A[i][k]+A[k][j];
	for (i=0;i<n; i++)
	   for (j=0; j<n; j++)
		   StringGrid3->Cells[i+1][j+1] = IntToStr(A[i][j]);
				
}
//---------------------------------------------------------------------------

void __fastcall TForm2::Button4Click(TObject *Sender)//transitive closure
{
	int bigger = StrToInt(Edit4->Text);
	int n = StrToInt(Edit1->Text);
	Form2->StringGrid4->RowCount = n+1;
	Form2->StringGrid4->ColCount = n+1;
	for (int j=1; j<=n; j++)//��ܦa�I�N��	
	{   StringGrid4->Cells[0][j] = IntToStr(j-1);
		StringGrid4->Cells[j][0] = IntToStr(j-1);
	}
	for (int i=0;i<n; i++)
	   for (int j=0; j<n; j++)
	   {   if(A[i][j]==bigger)
			   StringGrid4->Cells[i+1][j+1] = 0;	   
		   else
			   StringGrid4->Cells[i+1][j+1] = 1;	
	   }
}
//---------------------------------------------------------------------------
