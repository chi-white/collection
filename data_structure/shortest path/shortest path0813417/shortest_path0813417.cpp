//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "shortest_path0813417.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm2 *Form2;
int D[100] = {NULL};//儲存u到各點的暫時最段距離
int C[100] = {NULL};//紀錄暫時最短路徑的上一個點
bool found[100] = {false};//儲存已解決的node
int w[100][100] = {NULL};//距離矩陣,從頭到尾不會被改變
int A[100][100] = {NULL};//遞迴封閉和任兩點的最近距離的儲存矩陣
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
	int mini = 1000; //容易把index和value搞混
	int i;
	for(i=0;i<n;i++)
		if(!found[i] && D[i]<mini)
		{	mini_index = i;
			mini = D[mini_index];
		}
	return mini_index;
}

bool all_found()//當所有的節點都solved
{
	int n = StrToInt(Form2->Edit1->Text);
	for(int i=0;i<n;i++)
		if(!found[i])
			return true;//還有false則迴傳true，使呼叫者繼續跑迴圈
	return false;//若檢查完所有的元素內皆為true，則回傳false使得呼叫者停止迴圈
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
	int all_D[100][100] = {NULL};//用來存放每一行更新後的D
	int a = 0;//用來紀錄第幾個迴圈
	int n = StrToInt(Form2->Edit1->Text);
	int u = StrToInt(Form2->Edit5->Text);//起點
	for(int i=0;i<100;i++)//洗掉上個SSAD路徑
		for(int j=0;j<100;j++)
			Form2->StringGrid2->Cells[i][j] = "";
	for(int i=0;i<n;i++)
	{   D[i] = w[u][i];
		C[i] = u;
	}
	found[u] = true;
	for(int i=0;i<n;i++)
		all_D[i][a]	= D[i];
	a++;//進入迴圈之前先把初始狀態存進去
	while(all_found())//做到all found is false
	{	int k = min();//find the min number except number has been found
		found[k] = true;
		for(int j=0;j<n;j++)//更新單行D
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
	for(int i=1;i<=n;i++)//站名
		Form2->StringGrid2->Cells[0][i] = IntToStr(i-1);  //stringgrid 是先行後列 (不是先列後行)
	for(int j=1;j<=a;j++)//迴圈次數
	{   if(j==a) Form2->StringGrid2->Cells[j][0] = "C[v]";
		else Form2->StringGrid2->Cells[j][0] = IntToStr(j-1);
	}
	for(int j=0;j<a;j++)//填入all_D的值
		for(int i=0;i<n;i++)
			Form2->StringGrid2->Cells[j+1][i+1] = all_D[i][j];	
			
	for(int j=1;j<=n;j++)//顯示最佳路徑的前一個點
		Form2->StringGrid2->Cells[a][j] = IntToStr(C[j-1]);
}

void __fastcall TForm2::Button1Click(TObject *Sender)//generate G
{
	int u = StrToInt(Edit5->Text);
	int n = StrToInt(Edit1->Text);
	int range = StrToInt(Edit2->Text);
	int limit = StrToInt(Edit3->Text);
	int bigger = StrToInt(Edit4->Text);
	for(int i=0;i<n;i++)//重製距離矩陣
		for(int j=0;j<n;j++)
			w[i][j] = NULL;
	for(int i=0;i<n;i++)//重製solved標記
			found[i] = false;
	for(int i=0;i<n;i++)//隨機生成距離矩陣
	{   for(int j=0;j<n;j++)
		{   w[i][j] = (rand()%(range+1))+1;//+1避免距離為零
			if(w[i][j]>limit) w[i][j] = bigger;
			if(CheckBox1->Checked)//對稱選項
				if(w[j][i]>0) w[i][j] = w[j][i];//保持通道的一致性，A到B是18則B到A也要是18不能是40
		}
		w[i][i] = 0;//設成999或是0都沒有影響
	}
	StringGrid1->RowCount = n+1;
	StringGrid1->ColCount = n+1;
	for (int j=1; j<=n; j++)//顯示地點代號	
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
	for(int i=0;i<100;i++)//重製
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
	for (int j=1; j<=n; j++)//顯示地點代號	
	{   StringGrid3->Cells[0][j] = IntToStr(j-1);
		StringGrid3->Cells[j][0] = IntToStr(j-1);
	}
	for(i=0;i<n;i++)//重製A矩陣
		for(j=0;j<n;j++)
			A[i][j] = NULL; 
	for(i=0;i<n;i++)//A inverse(初始狀態)
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
	for (int j=1; j<=n; j++)//顯示地點代號	
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

