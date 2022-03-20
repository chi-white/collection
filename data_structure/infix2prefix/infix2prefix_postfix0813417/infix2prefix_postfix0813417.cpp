//---------------------------------------------------------------------------

#include <vcl.h>
#include <string.h> 
#pragma hdrstop

#include "infix2prefix_postfix0813417.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm2 *Form2;
int top1;
int top2;
char stack1[100];
char stack2[100];
AnsiString strarray[100];//存放前序轉換結果的陣列，因為char array無法勝任:(
//---------------------------------------------------------------------------
__fastcall TForm2::TForm2(TComponent* Owner)
	: TForm(Owner)
{
}
int parsing(AnsiString e,char token[])
{
	int n = e.Length();
	for(int i=0;i<n;i++)
		token[i] = e[i+1];//AnsiString從1開始
	return n;
}
void push1(char a)//push到operator陣列 
{
	stack1[++top1] = a;	
}
void push2(char a)//push到轉換後陣列
{
	if(a!='(' && a!=')')
		stack2[++top2] = a;	
}
char pop()//必定從stack1 pop出
{
	char a = stack1[top1];
	stack1[top1--] = NULL;
	return a; 
}
int p(char a)//外部優先權
{
	if(a=='(')
		return 9;
	else if(a=='^')
		return 8;
   else if(a=='*'||a=='/'||a=='%')
		return 7;
	else if(a=='+'||a=='-')
		return 6;
	else if(a=='&&')
		return 2;
	else if(a=='||')
		return 1;
   else //#
		return 0;	
}
int q(char a)//內部優先權
{
	if(a=='(')
		return 0;
	else if(a=='^')
		return 8;
   else if(a=='*'||a=='/'||a=='%')
		return 7;
	else if(a=='+'||a=='-')
		return 6;
	else if(a=='&&')
		return 2;
	else if(a=='||')
		return 1;
   else //#
		return 0;
}
bool operator_(char a)//是operator回傳true，不是回傳false
{
	if(a=='('||a=='^'||a=='*'||a=='/'||a=='%'||a=='+'||a=='-'||a=='&&'||a=='||'||a==')')
		return True;
	else
		return False;
}

bool operator_str(AnsiString a)//是operator回傳true，不是回傳false
{
	if(a=='('||a=='^'||a=='*'||a=='/'||a=='%'||a=='+'||a=='-'||a=='&&'||a=='||'||a==')')
		return True;
	else
		return False;
}
AnsiString get_prefix(AnsiString x)
{
	AnsiString a,b,c;
	b = strarray[top2];
	a = strarray[top2-1];
	c = x+a+b;
	top2 = top2-2;
	return c;
}
void push_str(AnsiString a)
{
	if(a!='(' && a!=')')
		strarray[++top2] = a;
}

AnsiString pop_str()
{
	AnsiString a = strarray[top1--];
	strarray[top1--] = " ";
	return a;
}

//---------------------------------------------------------------------------

void __fastcall TForm2::Button2Click(TObject *Sender)
{
	top1 = -1;
	top2 = -1;
	AnsiString e = Edit1->Text;
	char token[100] = {NULL};//infix原始串列
	int n = parsing(e,token);
	int i;
	char x;
	char s;
	for(int i=0;i<100;i++)
		stack1[i] = {NULL};//存放運算子operator
	for(int i=0;i<100;i++)
		strarray[i] = " ";////存放改變後結果
	push1('#');
	if(CheckBox1->Checked)
		Form2->Memo1->Lines->Add("Infix=>Prefix");	
	for(i=0;i<n;i++)
	{
		s = token[i];
		if(CheckBox1->Checked)//
		{
			Form2->Memo1->Lines->Add("------------------------------");
			Form2->Memo1->Lines->Add("operand array:");
			Form2->Memo1->Lines->Add(stack1);
			Form2->Memo1->Lines->Add("operand and operator array:");
			Form2->Memo1->Lines->Add(strarray[4]);
			Form2->Memo1->Lines->Add(strarray[3]);
			Form2->Memo1->Lines->Add(strarray[2]);
			Form2->Memo1->Lines->Add(strarray[1]);
			Form2->Memo1->Lines->Add(strarray[0]);
		}
		if(operator_(s)) //如果是運算子operand
		{
			if(s==')')//右括號特例情況
			{
				while(stack1[top1]!='(')
				{
					x = pop();
					push_str(get_prefix(x));  
					if(CheckBox1->Checked)//
					{
						Form2->Memo1->Lines->Add("------------------------------");
						Form2->Memo1->Lines->Add("operand array:");
						Form2->Memo1->Lines->Add(stack1);
						Form2->Memo1->Lines->Add("operand and operator array:");
						Form2->Memo1->Lines->Add(strarray[4]);
						Form2->Memo1->Lines->Add(strarray[3]);
						Form2->Memo1->Lines->Add(strarray[2]);
						Form2->Memo1->Lines->Add(strarray[1]);
						Form2->Memo1->Lines->Add(strarray[0]);
					}
				}
				pop();//pop出左括號
			}
			else//其他運算子符號
			{
				while(p(s)<=q(stack1[top1]))
				{
					x = pop();
					push_str(get_prefix(x));
					if(CheckBox1->Checked)//
					{
						Form2->Memo1->Lines->Add("------------------------------");
						Form2->Memo1->Lines->Add("operand array:");
						Form2->Memo1->Lines->Add(stack1);
						Form2->Memo1->Lines->Add("operand and operator array:");
						Form2->Memo1->Lines->Add(strarray[4]);
						Form2->Memo1->Lines->Add(strarray[3]);
						Form2->Memo1->Lines->Add(strarray[2]);
						Form2->Memo1->Lines->Add(strarray[1]);
						Form2->Memo1->Lines->Add(strarray[0]);
					}
				}
				push1(s);
				if(CheckBox1->Checked)
				{
					Form2->Memo1->Lines->Add("------------------------------");
					Form2->Memo1->Lines->Add("operand array:");
					Form2->Memo1->Lines->Add(stack1);
					Form2->Memo1->Lines->Add("operand and operator array:");
					Form2->Memo1->Lines->Add(strarray[4]);
					Form2->Memo1->Lines->Add(strarray[3]);
					Form2->Memo1->Lines->Add(strarray[2]);
					Form2->Memo1->Lines->Add(strarray[1]);
					Form2->Memo1->Lines->Add(strarray[0]);
				}
			}
		}
		else//運算元operator
			push_str(s);                                                                   //push str
	}
	while(stack1[top1]!='#')
	{
		x = pop();
		push_str(get_prefix(x));
		if(CheckBox1->Checked) //
		{
			Form2->Memo1->Lines->Add("------------------------------");
			Form2->Memo1->Lines->Add("operand array:");
			Form2->Memo1->Lines->Add(stack1);
			Form2->Memo1->Lines->Add("operand and operator array:");
			Form2->Memo1->Lines->Add(strarray[4]);
			Form2->Memo1->Lines->Add(strarray[3]);
			Form2->Memo1->Lines->Add(strarray[2]);
			Form2->Memo1->Lines->Add(strarray[1]);
			Form2->Memo1->Lines->Add(strarray[0]);
		}
	}
	Edit3->Text = strarray[0];//最後全部會在第0個空間裡
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Button1Click(TObject *Sender)//中序轉後續法
{
	top1 = -1;
	top2 = -1;
	AnsiString e = Edit1->Text;
	char token[100] = {NULL};//infix原始串列
	int n = parsing(e,token);
	int i;
	char x;
	char s;
	for(int i=0;i<100;i++)
		stack1[i] = {NULL};//存放運算子operator
	for(int i=0;i<100;i++)
		stack2[i] = {NULL};////存放改變後結果
	push1('#');
	if(CheckBox1->Checked)
		Form2->Memo1->Lines->Add("Infix=>Postfix");
	for(i=0;i<n;i++)
	{
		s = token[i];
		if(CheckBox1->Checked)//
		{
			Form2->Memo1->Lines->Add("------------------------------");
			Form2->Memo1->Lines->Add("operand array:");
			Form2->Memo1->Lines->Add(stack1);
			Form2->Memo1->Lines->Add("operand and operator array:");
			Form2->Memo1->Lines->Add(stack2);
		}
		if(operator_(s)) //如果是運算子operand
		{
			if(s==')')//右括號特例情況
			{
				while(stack1[top1]!='(')
				{
					x = pop();
					push2(x);   
					if(CheckBox1->Checked)//
					{
						Form2->Memo1->Lines->Add("------------------------------");
						Form2->Memo1->Lines->Add("operand array:");
						Form2->Memo1->Lines->Add(stack1);
						Form2->Memo1->Lines->Add("operand and operator array:");
						Form2->Memo1->Lines->Add(stack2);
					}
				}
				pop();//pop出左括號
			}
			else//其他運算子符號
			{
				while(p(s)<=q(stack1[top1]))
				{
					x = pop();
					push2(x);
					if(CheckBox1->Checked)//
					{
						Form2->Memo1->Lines->Add("------------------------------");
						Form2->Memo1->Lines->Add("operand array:");
						Form2->Memo1->Lines->Add(stack1);
						Form2->Memo1->Lines->Add("operand and operator array:");
						Form2->Memo1->Lines->Add(stack2);
					}
				}
				push1(s);
				if(CheckBox1->Checked)//
				{
					Form2->Memo1->Lines->Add("------------------------------");
					Form2->Memo1->Lines->Add("operand array:");
					Form2->Memo1->Lines->Add(stack1);
					Form2->Memo1->Lines->Add("operand and operator array:");
					Form2->Memo1->Lines->Add(stack2);
				}
			}
		}
		else//運算元operator
			push2(s);
	}
	while(stack1[top1]!='#')
	{
		x = pop();
		push2(x);
		if(CheckBox1->Checked)//
		{
			Form2->Memo1->Lines->Add("------------------------------");
			Form2->Memo1->Lines->Add("operand array:");
			Form2->Memo1->Lines->Add(stack1);
			Form2->Memo1->Lines->Add("operand and operator array:");
			Form2->Memo1->Lines->Add(stack2);
		}
	}
	Edit2->Text = stack2;
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Button3Click(TObject *Sender)
{
	Form2->Memo1->Lines->Clear();	
}
//---------------------------------------------------------------------------


void __fastcall TForm2::Button4Click(TObject *Sender)
{
	top2 = -1;
	AnsiString e = Edit4->Text;
	char token[100] = {NULL};//infix原始串列
	int n = parsing(e,token);
	int i;
	AnsiString y,x,s;
	for(int i=0;i<100;i++)
		strarray[i] = " ";////存放改變後結果
	push_str('#');
	for(i=0;i<n;i++)
	{
		s = token[i];
		Form2->Memo1->Lines->Add(s);
	
		if (operator_str(s))//是符號
		{
			push_str(s);
		}
		else//是數字
		{
		   while(!operator_str(strarray[top2]))
		   {
			   y = pop_str();
			   x = pop_str();
			   s = y+s+x;
		   }
		   push_str(s);
		} 
	}
	Edit5->Text =  strarray[2];
}
//---------------------------------------------------------------------------
