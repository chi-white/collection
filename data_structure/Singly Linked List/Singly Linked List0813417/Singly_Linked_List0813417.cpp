//---------------------------------------------------------------------------

#include <vcl.h>
#include <stdlib.h>
#include <time.h>
#pragma hdrstop

#include "Singly_Linked_List0813417.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm2 *Form2;
//---------------------------------------------------------------------------
struct node//singly
{
	int data;
	struct node* next;
};

struct node2//bouble
{
	int data;
	node2* right;
	node2* left;
};

 node* first = new node; //singly初始的空節點
 node* last = first; //singly指向最後的節點
 node2* first2 = new node2;//double初始的空節點
 node2* last2 = first2;//double指向最後的節點

__fastcall TForm2::TForm2(TComponent* Owner)
	: TForm(Owner)
{
	first->data = NULL;//初始所有初始結點
	first->next = NULL;
	first2->data = NULL;
	first2->right = NULL;
	first2->left = NULL;
}

void print(node* head)
{
	String out = "";
	node* p = head->next;
	while(p!=NULL)
	{
		out += "-->"+IntToStr(p->data);
		p = p->next;
	}
	Form2->Memo1->Lines->Add(out);
}

void print2(node2* head)
{
	String out = "";
	node2* p = head->right;
	while(p!=NULL)
	{
		out += "-->"+IntToStr(p->data);
		p = p->right;
	}
	Form2->Memo2->Lines->Add(out);
}

//---------------------------------------------------------------------------
void __fastcall TForm2::Button3Click(TObject *Sender)//insert rear插在最後面的節點的新節點
{
	int element = StrToInt(Edit1->Text);
	node* p = new node;
	p->data = element;
	p->next = NULL;
	last->next = p;
	last = last->next;
	print(first);
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Button8Click(TObject *Sender)//delete target 若找到目標節點，將其刪除
{
	node* p = first;
	node* q;
	int count = 0;
	int target = StrToInt(Edit2->Text);
	//找到target的前一個節點，
	for(;p->next!=last;p = p->next)//最多指到last前一個節點(且不進迴圈)
	{
		if(p->next->data==target)
		{
			count++;
			q = p->next;
			p->next = p->next->next;
			free(q);
			break;
		}
	}
	if(last->data==target&&count==0)//要刪除的節點為最後一個節點之個案,count==0很重要，沒他有可能會重複刪掉
	{                               //鏈結，last也會被提到前面，造成後面序列遺失
		count++;
		last = p;//若刪除之節點為最後之節點，則先把指向最後節點的指標往前移一個
		q = last->next;//q指向要被刪除之節點
		last->next = NULL;//新last斷絕和q的連結
		free(q);
	}
	if(count==0)
	{
		ShowMessage("the number does not exist!");
	}
	else
		print(first);
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Button1Click(TObject *Sender)//insert after front插在空白節點後面的新節點
{
	int element = StrToInt(Edit1->Text);
	node* p = new node;
	p->data = element;
	p->next = first->next;
	first->next = p;
	if(p->next==NULL)
		last = p;
	print(first);
}
//---------------------------------------------------------------------------

void __fastcall TForm2::Button5Click(TObject *Sender)//insert target after插一個節點在指定節點後面
{
	node* p = first;
	node* add = new node;//要加入的節點
	int element = StrToInt(Edit1->Text);
	int target = StrToInt(Edit2->Text);
	int count = 0;
	add->data = element;
	for(;p!=NULL;p = p->next)
	{
		if(p->data==target)
		{
			if(p==last)
				last = add;
			count++;
			add->next = p->next;
			p->next = add;
		}
	}
	if(count==0)
	{
		ShowMessage("the number does not exist!");
	}
	else
		print(first);
}
//---------------------------------------------------------------------------

void __fastcall TForm2::Button4Click(TObject *Sender)//Insert target front
{
	node* p = first;
	node* add = new node;//容易忘記:要new才會要到記憶體區塊，不然只是名稱而已
	int count = 0;
	int target = StrToInt(Edit2->Text);
	int element = StrToInt(Edit1->Text);
	add->data = element;
	add->next = NULL;
	for(;p!=last;p = p->next)
	{

		if(p->next->data==target)
		{
			count++;
			add->next = p->next;
			p->next = add;
			break;
		}
	}
	if(count==0)
	{
		ShowMessage("the number does not exist!");
	}
	else
		print(first);
}
//---------------------------------------------------------------------------

void __fastcall TForm2::Button6Click(TObject *Sender)//insert random from rear
{
	srand(time(NULL));
	int n = StrToInt(Edit4->Text);
	int range = StrToInt(Edit5->Text);
	for(int i=0;i<n;i++)
	{
        node* p = new node;
		p->data = rand()%(range+1);
		p->next = NULL;
		last->next = p;
		last = last->next;
	}
	print(first);
}
//---------------------------------------------------------------------------

void __fastcall TForm2::Button7Click(TObject *Sender)//clear all
{
	node* p;//引導前方的指標
	while(first->next!=NULL)
	{
		p = first->next;
		first->next = first->next->next;//要記得把first->next接回去，不然刪不掉
		free(p);
	}
	last = first;//last改回初始空白節點
	Form2->Memo1->Lines->Add("CLEAR!");
}
//---------------------------------------------------------------------------


void __fastcall TForm2::Button15Click(TObject *Sender)//find
{
	node* p = first;
	int count = 0;
	int target = StrToInt(Edit2->Text);
	while(p!=NULL)
	{
		if(p->data==target)
		{
			count++;
			ShowMessage("the number exist!");
			break;
		}
		p = p->next;
	}
	if(count==0)
	{
		ShowMessage("the number does not exist!");
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm2::Button17Click(TObject *Sender) //random insert after front
{
	srand(time(NULL));
	int n = StrToInt(Edit4->Text);
	int range = StrToInt(Edit5->Text);
	for(int i=0;i<n;i++)
	{
		node* p = new node;
		p->data = rand()%(range+1);
		p->next = first->next;
		first->next = p;
	}
	print(first);
}
//===============BOUBLE LINKED LIST========================//


void __fastcall TForm2::Button9Click(TObject *Sender)//insert front
{
	int element = StrToInt(Edit3->Text);
	node2* p = new node2;
	p->data = element;
	p->left = first2;
	p->right = first2->right;
	if(first2->right!=NULL)//若是等於NULL代表first2右邊沒東西，不用讓右者指向新增者
		first2->right->left = p;
	else//若是等於NULL代表first2右邊沒東西，不用讓右者指向新增者
		last2 = p;
	first2->right = p;
	print2(first2);
}
//---------------------------------------------------------------------------

void __fastcall TForm2::Button18Click(TObject *Sender)//clear all
{
	node2* p;//引導前方的指標
	while(first2->right!=NULL)
	{
		p = first2->right;
		first2->right = p->right;
		if(p->right!=NULL)
			p->right->left = first2;
		free(p);
	}
	last = first;//last改回初始空白節點
	Form2->Memo2->Lines->Add("CLEAR!");
}
//---------------------------------------------------------------------------


void __fastcall TForm2::Button2Click(TObject *Sender)//insert rear
{
    int element = StrToInt(Edit3->Text);
	node2* p = new node2;
	p->data = element;
	p->right = NULL;
	p->left = last2;
	last2->right = p;
	last2 = last2->right;
	print2(first2);
}
//---------------------------------------------------------------------------


void __fastcall TForm2::Button10Click(TObject *Sender)//find
{
	node2* p = first2;
	int count = 0;
	int target = StrToInt(Edit6->Text);
	while(p!=NULL)
	{
		if(p->data==target)
		{
			count++;
			ShowMessage("the number exist!");
			break;
		}
		p = p->right;
	}
	if(count==0)
	{
		ShowMessage("the number does not exist!");
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Button13Click(TObject *Sender)//delete target
{
	int count = 0;
    int target = StrToInt(Edit6->Text);
	node2* p = first2;
	for(;p!=NULL;p = p->right)
	{
		if(p->data==target)
		{
			count++;
			p->left->right = p->right;
			if(p->right!=NULL)
				p->right->left = p->left;
			else                            //要刪除的的節點為最後一個節點
				last2 = last2->left;
			free(p);
			break;
        }
	}
	if(count==0)
	{
		ShowMessage("the number does not exist!");
	}
	else
        print2(first2);
}

//---------------------------------------------------------------------------

void __fastcall TForm2::Button14Click(TObject *Sender)//Insert random (after front)
{
	srand(time(NULL));
	int n = StrToInt(Edit7->Text);
	int range = StrToInt(Edit8->Text);
	for(int i=0;i<n;i++)
	{
		node2* p = new node2;
		p->data = rand()%(range+1);
		p->left = first2;
		p->right = first2->right;
		if(first2->right!=NULL)
			first2->right->left = p;
		else								//若是等於NULL代表first2右邊沒東西，不用讓右者指向新增者
			last2 = p;
		first2->right = p;
	}
	print2(first2);
}
//---------------------------------------------------------------------------

void __fastcall TForm2::Button16Click(TObject *Sender)//Insert random (after rear)
{
	srand(time(NULL));
	int n = StrToInt(Edit7->Text);
	int range = StrToInt(Edit8->Text);
	for(int i=0;i<n;i++)
	{
		node2* p = new node2;
		p->data = rand()%(range+1);
		p->left = last2;
		p->right = NULL;
		last2->right = p;
        last2 = last2->right;
	}
	print2(first2);
}
//---------------------------------------------------------------------------

void __fastcall TForm2::Button11Click(TObject *Sender)//insert target front
{
	int element = StrToInt(Edit3->Text);
	int target = StrToInt(Edit6->Text);
	int count = 0;
	node2* add = new node2;
	add->data = element;
	node2* p = first2;
	for(;p!=NULL;p=p->right)
	{
		if(p->data==target)
		{
			count++;
			add->right = p;
			add->left = p->left;
			p->left->right = add;
			p->left = add;
            break;
		}
	}
	if(count==0)
		ShowMessage("the number does not exist!");
	else
		print2(first2);
}
//---------------------------------------------------------------------------


void __fastcall TForm2::Button12Click(TObject *Sender)//insert target back
{
	int element = StrToInt(Edit3->Text);
	int target = StrToInt(Edit6->Text);
	int count = 0;
	node2* add = new node2;
	add->data = element;
	node2* p = first2;
	for(;p!=NULL;p=p->right)
	{
		if(p->data==target)
		{
			count++;
			add->left = p;
			add->right = p->right;
			if(p->right!=NULL)
				p->right->left = add;
			else                       //當target為最後一節點的情況
			{
				p->right = add;
				last2 = last2->right;
            }
			p->right = add;
			break;
		}
	}
	if(count==0)
		ShowMessage("the number does not exist!");
	else
		print2(first2);
}
//---------------------------------------------------------------------------


void __fastcall TForm2::Button19Click(TObject *Sender)//reverse the list
{
	int stack[1000] = {NULL};
	int top = -1;
	node2* p = first2->right;
	for(;p!=NULL;p=p->right)
		stack[++top] = p->data;
	p = first2->right;
	for(;p!=NULL;p=p->right)
	{
		p->data = stack[top--];
	}
    print2(first2);
}
//---------------------------------------------------------------------------

void __fastcall TForm2::Button20Click(TObject *Sender)//singly的list reversed
{
    int stack[1000] = {NULL};
	int top = -1;
	node* p = first->next;
	for(;p!=NULL;p=p->next)
		stack[++top] = p->data;
	p = first->next;
	for(;p!=NULL;p=p->next)
	{
		p->data = stack[top--];
	}
	print(first);
}
//---------------------------------------------------------------------------

