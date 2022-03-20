//---------------------------------------------------------------------------
#include <stdlib.h>
#include <time.h>
#include <vcl.h>
#pragma hdrstop
#include "stdio.h"
#include "mouse_in_maze0813417.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"

#define maxsize 900
struct offset//�ܶq��struct
{
	int dx,dy;
};
struct imformation//�s�J����struct
{
	int x,y;
	int dir; //N0 NE1 E2 SE3 S4 SW5 W6 NW7
};
int maze[30][30];
int mark[30][30];
int m,n;//�s���g�c�j�p
int top  = -1;
int weight;
int width;
int start_width;
int start_weight;
int end_weight;
int end_width;
struct offset move[8];
struct imformation stack[maxsize];//�ŧistack,�s�J���񪺰��|
void refresh_in(int j,int i);
void refresh_out(int j,int i);
void initial_offset();
void push(struct imformation step);
struct imformation pop();
struct imformation die_road();
void walking();
void loading();
void refresh_in(int j,int i);
void refresh_out(int j,int i);
void refresh_final(int j,int i);
void grid_colordeal();

TForm2 *Form2;
//---------------------------------------------------------------------------
__fastcall TForm2::TForm2(TComponent* Owner)
	: TForm(Owner)
{
}
void initial_offset()//��l��offset
{
	move[0].dy = -1;
	move[0].dx = 0;
	move[1].dy = -1;
	move[1].dx = 1;
	move[2].dy = 0;
	move[2].dx = 1;
	move[3].dy = 1;
	move[3].dx = 1;
	move[4].dy = 1;
	move[4].dx = 0;
	move[5].dy = 1;
	move[5].dx = -1;
	move[6].dy = 0;
	move[6].dx = -1;
	move[7].dy = -1;
	move[7].dx = -1;
}

void push(struct imformation step)
{
	Form2->Memo1->Lines->Add("push : ("+IntToStr(step.y)+","+IntToStr(step.x)+","+IntToStr(step.dir)+")");
	stack[++top].x = step.x;
	stack[top].y = step.y;
	stack[top].dir = step.dir;
	refresh_in(step.x,step.y);
}

struct imformation pop()
{
	Form2->Memo1->Lines->Add("pop : ("+IntToStr(stack[top].y)+","+IntToStr(stack[top].x)+","+IntToStr(stack[top].dir)+")");
	refresh_out(stack[top].x,stack[top].y);
	return stack[top--];
}

struct imformation die_road()//�L���i�������A
{
	int d,u,v;
	struct imformation step;
	step = pop();
	do
	{
		d = 0;
		while(d<8)//�q�K�Ӥ�V�h����
		{

			u = step.y+move[d].dy;
			v = step.x+move[d].dx;
			if((!maze[u][v])&&(!mark[u][v]))//����@����즳��L�i�檺��l
			{
				top++;
				return step;
			}
			else
				d++;
		}
		if(d>=8)//�L��L�i���l
			step = pop();
	}while(top>=0);
	return step;   //only for back to start point
}

void walking()
{
	struct imformation step;//�{�b��m!!!!
	int u;//�Y�N�n�e�����C�A������y
	int v;//�Y�N�n�e������A������x
	int d;//�n�h����V��
	String out;
	for(int a=0;a<10;a++)
		for(int b=0;b<10;b++)
			mark[a][b] = 0;
	step.y = start_weight;
	step.x = start_width;
	Form2->Memo1->Lines->Add("___________________________________processing steps___________________________________");
	do
	{
		d = 0;
		while(d<8)//�q�K�Ӥ�V�h����
		{
			u = step.y+move[d].dy;
			v = step.x+move[d].dx;
			if((!maze[u][v])&&(!mark[u][v]))  //���۸��F �A�[�J���U���I
			{
				step.dir = d;
				push(step);
				mark[step.y][step.x] = 1;
				step.y = u;
				step.x = v;
				if(u==end_weight&&v==end_width)//�p�G��F���I
				{
					mark[step.y][step.x] = 1;
					step.dir = 0;
					push(step);
					Form2->Memo1->Lines->Add("REACH DESTINATION!");
					Form2->Memo1->Lines->Add("___________________________________correcting steps___________________________________");
					for(int i=0;i<=top;i++)
					{
						Form2->Memo1->Lines->Add("("+IntToStr(stack[i].y)+","+IntToStr(+stack[i].x)+","+IntToStr(stack[i].dir)+") ->");
						refresh_final(stack[i].x,stack[i].y);
						maze[stack[i].y][stack[i].x] = 3;//for memo correcting map
					}
                    Form2->Memo1->Lines->Add("___________________________________correcting map___________________________________");
					for (int i=0;i<m;i++)//�L�X���T���|3�N�����T���|
					{
						out = "";
						for (int j=0; j<n; j++)
							out += "  "+IntToStr(maze[i][j]);
						Form2->Memo1->Lines->Add(out);
					}
					top = -1;//����j��
				}
				break;
			}
			else
				d++;
		}
		if(d==8)//�o�{�S�����i�H�����ɭ�
		{

			mark[step.y][step.x] = 1;//�аO���U���I�����L
			step = die_road(); //�i��h�^�ʧ@
		}
	}while(top>=0);
	if(mark[end_weight][end_width]==0)//�P�_�O�]���S�����ҥH���X���٬O�]���q���I�^�ӤF�ҥH���X��
		Form2->Memo1->Lines->Add("NO DESTINATION!");
}

void loading()
{
    FILE *fp;
	String out;
	int i, j;
	AnsiString infile;
	if(Form2->OpenDialog1->Execute())
	{
		infile = Form2->OpenDialog1->FileName;
		fp = fopen(infile.c_str(), "r+");
		fscanf(fp, "%d %d", &m, &n);
		Form2->Memo1->Lines->Add("(m, n)="+IntToStr(m)+", "+IntToStr(n));
		for (i=0; i<m; i++)
			for (j=0; j<n; j++)
				fscanf(fp, "%d", &maze[i][j]);
		fclose(fp);
		for (i=0; i<m; i++)
		{
			 out = "";
			 for (j=0; j<n; j++)
				out += "  "+IntToStr(maze[i][j]);
			 Form2->Memo1->Lines->Add(out);
		}
		Form2->StringGrid1->RowCount = m;
		Form2->StringGrid1->ColCount = n;
		for (i=0; i<m; i++)
			for (j=0; j<n; j++)
				Form2->StringGrid1->Cells[j][i] = maze[i][j];
		for(int i=0;i<weight;i++)
			if(maze[i][0]==0)
			{
				start_weight = i;
				start_width = 0;
			}
		for(int i=0;i<m;i++)
			if(maze[0][i]==0)
			{
				start_weight = 0;
				start_width = i;
			}
		for(int i=0;i<n;i++)
			if(maze[i][m-1]==0)
			{
				end_weight = i;
				end_width = m-1;
			}
		for(int i=0;i<m;i++)
			if(maze[n-1][i]==0)
			{
				end_weight = n-1;
				end_width = i;
			}
	}
	else
		Form2->Memo1->Lines->Add("Nothing happens.");
}

void refresh_in(int j,int i)//���L�����C��
{
	grid_colordeal();
	Sleep(Form2->TrackBar1->Position);//����t��
	Form2->StringGrid1->Cells[j][i] = 3;
	Form2->StringGrid1->Refresh();
}

void refresh_out(int j,int i)//�h�^�ܦ^�쥻���C��
{
	grid_colordeal();
	Sleep(Form2->TrackBar1->Position);//����t��
	Form2->StringGrid1->Cells[j][i] = 0;
	Form2->StringGrid1->Refresh();
}

void refresh_final(int j,int i)
{
	 grid_colordeal();
	Sleep(Form2->TrackBar1->Position);//����t��
	Form2->StringGrid1->Cells[j][i] = 4;
	Form2->StringGrid1->Refresh();
}

void grid_colordeal()
{
	Form2->StringGrid1->DefaultDrawing = false;
	Form2->StringGrid1->FixedCols = 0;
	Form2->StringGrid1->FixedRows = 0;
	for (int i=0; i<m; i++)
		Form2->StringGrid1->RowHeights[i] =20;
	for (int i=0; i<n; i++)
		Form2->StringGrid1->ColWidths[i] =20;
	Form2->StringGrid1->GridLineWidth = 3;
	Form2->StringGrid1->Refresh();
}

//---------------------------------------------------------------------------
void __fastcall TForm2::Button1Click(TObject *Sender)
{
	loading();
	grid_colordeal();
	top = -1;
}
//---------------------------------------------------------------------------
void __fastcall TForm2::color(TObject *Sender, int ACol, int ARow, TRect &Rect, TGridDrawState State)
{
	AnsiString text = StringGrid1->Cells[ACol][ARow];
	if (text =="0")
		Form2->StringGrid1->Canvas->Brush->Color = TColor RGB(228,211,216);
	else if(text =="1")
		Form2->StringGrid1->Canvas->Brush->Color = TColor RGB(174,63,46);
	else if(text=="2")
		Form2->StringGrid1->Canvas->Brush->Color = TColor RGB(174,28,46);
	else if(text=="3")//fresh_in
		Form2->StringGrid1->Canvas->Brush->Color = TColor RGB(5,175,218);
	else if(text=="4")//fresh_final
		Form2->StringGrid1->Canvas->Brush->Color = TColor RGB(0,175,0);
	Form2->StringGrid1->Canvas->FillRect(Rect);
}
//---------------------------------------------------------------------------


void __fastcall TForm2::Button2Click(TObject *Sender)        //walking
{
    top = -1;
	for(int i=0;i<m;i++)
		for(int j=0;j<n;j++)
			mark[i][j] = 0;//��l�Ƥw���L����a��
	initial_offset();
	walking();
}
//---------------------------------------------------------------------------



void __fastcall TForm2::Button3Click(TObject *Sender)
{
	int i,j;
	weight = StrToInt(Edit1->Text);
	width = StrToInt(Edit2->Text);
	m = width;
	n = weight;
	start_width = StrToInt(Edit5->Text);
	start_weight = StrToInt(Edit3->Text);
	end_weight = StrToInt(Edit6->Text);
	end_width = StrToInt(Edit4->Text);
	Form2->StringGrid1->RowCount = width;
	Form2->StringGrid1->ColCount = weight;
	grid_colordeal();
     int z;
	int number = m*n/5;
    int y[4] = {1,0,-1,0};
	int x[4] = {0,1,0,-1};
	int xx = rand()%(width-2)+1;
	int yy = rand()%(weight-2)+1;
	for(i=0;i<weight;i++)
		for(j=0;j<width;j++)
			maze[i][j] = 0;

	for(j=0;j<width;j++)
	{
		maze[0][j] = 2;
		maze[weight-1][j] = 2;
	}
	for(i=0;i<weight;i++)
	{
		maze[i][0] = 2;
		maze[i][width-1] = 2;
	}

	for(i=0;i<number;i++)//�����H��������
	{
		xx = rand()%(width-2)+1;
		yy = rand()%(weight-2)+1;
		if(xx%2==1)
			xx += 1;
		if(yy%2==1)
			yy += 1;
		z = 0;
		if(maze[yy][xx]==0)
		{
			while(maze[xx][yy]!=2&&z<3)
			{
				maze[yy][xx] = 1;
				j=rand()%4;
				yy = yy+y[j];
				xx = xx+x[j];
				z++;
			}
        }
	}
	maze[start_weight][start_width] = 0;
	maze[end_weight][end_width] = 0;
	for (i=0; i<weight; i++)
		for (j=0; j<width; j++)
			Form2->StringGrid1->Cells[j][i] = maze[i][j];
    String out;
    for (int i=0;i<m;i++)//�L�X���T���|3�N�����T���|
	{
		out = "";
		for (int j=0; j<n; j++)
			out += "  "+IntToStr(maze[i][j]);
		Form2->Memo1->Lines->Add(out);
	}

}
//---------------------------------------------------------------------------



