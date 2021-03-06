//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "magic_square0813417.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"

TForm2 *Form2;
//---------------------------------------------------------------------------
__fastcall TForm2::TForm2(TComponent* Owner)
	: TForm(Owner)
{
}

void swap(int **square,int a,int b,int n)
{
	int temp;
	temp = square[a][b];
	square[a][b] = square[n-1-a][n-1-b];
	square[n-1-a][n-1-b] = temp;
}

void self_check(int** square,int n)//檢查每一行列總和是否相同
{
	int sum = 0;
	int i,j;
	for(i=0;i<n;i++)//每一列的和
	{
		sum = 0;
		for(j=0;j<n;j++)
		{
			sum += square[i][j];
			if(j==n-1)
			{
					Form2->StringGrid1->Cells[n+1][i] = IntToStr(sum);
			}
		}
	}
	for(j=0;j<n;j++) //每一行的和
	{
		sum = 0;
		for(i=0;i<n;i++)
		{
			sum += square[i][j];
			if(i==n-1)
			{
					Form2->StringGrid1->Cells[j][n+1] = IntToStr(sum);
			}
		}
	}
	sum = 0;//左上右下的對角線和
	for(i=0;i<n;i++)
	{
		sum += square[i][i];
	}
	Form2->StringGrid1->Cells[n][n] = IntToStr(sum);
		
	sum = 0;//右上左下的對角線和
	for(i=0;i<n;i++)
			sum += square[i][n-1-i];
	Form2->StringGrid1->Cells[n+1][n+1] = IntToStr(sum);
}

void square_print(int ** square,int n)
{
	Form2->StringGrid1->RowCount = n+2;
	Form2->StringGrid1->ColCount = n+2;
	for (int i=0; i<n+3; i++)
		for (int j=0; j<n+3; j++)
			Form2->StringGrid1->Cells[j][i] = " ";//清空StringGrid先前的畫面
	for (int i=0; i<n; i++)
		for (int j=0; j<n; j++)
			Form2->StringGrid1->Cells[j][i] = IntToStr(square[i][j]);
		self_check(square,n);
}

void up_left(int n)
{
	int **square;
	int r = 0;
	int c = (n-1)/2;
	square = new int*[n];
	for(int i=0;i<n;i++)
		square[i] = new int[n];
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			square[i][j] = 0; //不知道原本的位址存放的是甚麼所以先全部歸成0
	square[r][c] = 1;
	for(int i=1;i<n*n;i++)
	{
		r -= 1;
		c -= 1;
		if(r<0)
			r = n-1;
		if(c<0)
			c = n-1;
		if(square[r][c]!=0)
		{
			r++;
			c++;
			if(r>n-1)
				r = 0;
			if(c>n-1)
				c = 0;
			r++;
		}
		square[r][c] = i+1;
	}
	square_print(square,n);
	self_check(square,n);
	for (int i = 0; i < n; i++)
		delete [] square[i];
	delete [] square;
}

void up_right(int n)
{
	int **square;
	int r = 0;
	int c = (n-1)/2;
	square = new int*[n];
	for(int i=0;i<n;i++)
		square[i] = new int[n];
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			square[i][j] = 0;
	square[r][c] = 1;
	for(int i=1;i<n*n;i++)
	{
		r -= 1;
		c += 1;
		if(r<0)
			r = n-1;
		if(c>n-1)
			c = 0;
		if(square[r][c]!=0)
		{
			r++;
			c--;
			if(r>n-1)
				r = 0;
			if(c<0)
				c = n-1;
			r++;
		}
		square[r][c] = i+1;
	}
	square_print(square,n);
	for (int i = 0; i < n; i++)
		delete [] square[i];
	delete [] square;
}

void botton_left(int n)
{
	int **square;
	int r = n-1;
	int c = (n-1)/2;
	square = new int*[n];
	for(int i=0;i<n;i++)
		square[i] = new int[n];
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			square[i][j] = 0;
	square[r][c] = 1;
	for(int i=1;i<n*n;i++)
	{
		r++;
		c--;
		if(r>n-1)
			r = 0;
		if(c<0)
			c = n-1;
		if(square[r][c]!=0)
		{
			r--;
			c++;
			if(r<0)//
				r = n-1;
			if(c>n-1)
				c = 0;
			r--;
		}
		square[r][c] = i+1;
	}
	square_print(square,n);
	for (int i = 0; i < n; i++)
		delete [] square[i];
	delete [] square;
}

void botton_right(int n)
{
	int **square;
	int r = n-1;
	int c = (n-1)/2;
	square = new int*[n];
	for(int i=0;i<n;i++)
		square[i] = new int[n];
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			square[i][j] = 0;
	square[r][c] = 1;
	for(int i=1;i<n*n;i++)
	{
		r++;
		c++;
		if(r>n-1)
			r = 0;
		if(c>n-1)
			c = 0;
		if(square[r][c]!=0)
		{
			r--;
			c--;
			if(r<0)
				r = n-1;
			if(c<0)
				c = n-1;
			r--;
		}
		square[r][c] = i+1;
	}
	square_print(square,n);
	for (int i = 0; i < n; i++)
		delete [] square[i];
	delete [] square;
}

void four_times(int n)
{
	int bound;
	int count = 1;
	bound = n/2;
	int **square;
	square = new int*[n];
	for(int i=0;i<n;i++)
		square[i] = new int[n];
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
		{
			square[i][j] = count;
			count++;
		}

	for(int i=0;i<bound;i++)//左上正方形右斜對角線
		swap(square,i,i,n);
	for(int i=0;i<bound;i++)//右上正方形左斜對角線
		swap(square,i,n-1-i,n);
	if((n/4)%2==0)//大於4會有副對角線
	{
		for(int i=0;i<bound;i++)//左上正方形左斜對角線
			swap(square,i,bound-1-i,n);
		for(int i=0;i<bound;i++)//右上正方形右斜對角線
			swap(square,i,bound+i,n);
	}
    square_print(square,n);
    for (int i = 0; i < n; i++)
		delete [] square[i];
	delete [] square;
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Button1Click(TObject *Sender)
{
	int n = StrToInt(Edit1->Text);
	if(n<1)
		n = -n;//若為負數自動轉換為正數
	if(n%2==1)
	{
		if(RadioButton1->Checked)
			up_left(n);
		if(RadioButton2->Checked)
			up_right(n);
		if(RadioButton3->Checked)
			botton_left(n);
		if(RadioButton4->Checked)
			botton_right(n);
	}
	else if(n%4==0)
	{
		four_times(n);
	}
}
