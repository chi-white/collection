//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Binary_Search_Tree0813417.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm2 *Form2;
//---------------------------------------------------------------------------
struct BTN
{
	BTN* leftchild;
	BTN* rightchild;
	BTN* parent;
	int data;
};
BTN* empty;//在root之上的空白節點
BTN* root;
String out;
struct Qnode
{
	BTN* treenode;
	Qnode* next;
};
Qnode* front,*rear;
__fastcall TForm2::TForm2(TComponent* Owner)
	: TForm(Owner)
{
	empty = new BTN;
	empty->parent = NULL;//要當作向下指向root的指標
	empty->leftchild = NULL;
	empty->rightchild = NULL;
}
void preorder(BTN* node)//前序法
{
	if(node!=NULL)
	{
		out += "->"+IntToStr(node->data);
		preorder(node->leftchild);
		preorder(node->rightchild);
	}
}

void inorder(BTN* node)//中序法
{
	if(node!=NULL)
	{
		inorder(node->leftchild);
		out += "->"+IntToStr(node->data);
		inorder(node->rightchild);
	}
}

void postorder(BTN* node)//後序法
{
	if(node!=NULL)
	{
		postorder(node->leftchild);
		postorder(node->rightchild);
		out += "->"+IntToStr(node->data);
	}
}

void del(BTN* node)//刪除所有節點
{
	if(node!=NULL)
	{
		del(node->leftchild);
		del(node->rightchild);
		free(node);
    }
}
void insert(int element)
{
	BTN* add;
	add = new BTN;
	add->data = element;
	add->parent = NULL;
	add->rightchild = NULL;
	add->leftchild = NULL;
	if(empty->parent==NULL)//假借parent表示son
	{
		root = add;
		root->data = element;
		root->parent = empty;
		empty->parent = root;
	}
	else
	{
		BTN* p = root;
		while(true)
		{
			if(add->data < p->data)//若現有節點之data比較大
			{
				if(p->leftchild==NULL)
				{
					p->leftchild = add;
					add->parent = p;
					break;
				}
				else
					p = p->leftchild;
			}
			else
			{
				if(p->rightchild==NULL)
				{
					p->rightchild = add;
					add->parent = p;
					break;
				}
				else
					p = p->rightchild;
			}
		}
	}
	Form2->Memo1->Lines->Add("add : "+IntToStr(element));
}

BTN* InorderSucc(BTN* node)
{
	BTN* p = node;
	while(p->leftchild!=NULL)
		p = p->leftchild;
	return p;
}

BTN* DeleteBSTree(BTN* node,int x)
{
	BTN* temp;
	if(node==NULL) return node;
	else if(node->data>x) node->leftchild = DeleteBSTree(node->leftchild,x);
	else if(node->data<x) node->rightchild = DeleteBSTree(node->rightchild,x);
	else // x found in node
	{	if(node->leftchild==NULL||node->rightchild==NULL)
		{   temp = node->leftchild;
			if(temp==NULL) temp = node->rightchild;
			if(temp==NULL)//為子葉
			{   temp = node;
				node = NULL;
			}
			else *node = *temp; //為單子樹
			free(temp);
		}
		else//為雙子樹
		{   temp = InorderSucc(node->rightchild);
			node->data = temp->data;
			node->rightchild = DeleteBSTree(node->rightchild,temp->data);
		}
	}
	return node;
}

BTN* AddQueue(BTN* Tnode)
{
	Qnode* node = new Qnode;
	node->treenode = Tnode;
	node->next = NULL;
	if(front==NULL) front = node;
	else rear->next = node;
	rear = node;
}

BTN* DeleteQnode()
{
	BTN* Tnode;
	Qnode* old_front;
	if(rear==NULL) return NULL;
	else
	{
		Tnode = front->treenode;
		old_front = front;
		front = front->next;
		free(old_front);
		return Tnode;
    }
}

void LevelOrder(BTN* node)
{
	AddQueue(node);
	while(front!=NULL)
	{
		node = DeleteQnode() ;
		out += "->"+IntToStr(node->data);
		if(node->leftchild!=NULL) AddQueue(node->leftchild);
		if(node->rightchild!=NULL) AddQueue(node->rightchild);
	}
}

//---------------------------------------------------------------------------
void __fastcall TForm2::Button1Click(TObject *Sender)//insert BTN
{
	int element = StrToInt(Edit1->Text);
	insert(element);
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Button6Click(TObject *Sender)//sequence tree
{
	out = "";
	if(RadioButton1->Checked==true)//Preorder
	{
		preorder(root);
		Form2->Memo1->Lines->Add("Preorder sequence : "+out);
	}
	else if(RadioButton2->Checked==true)//Inorder
	{
		inorder(root);
		Form2->Memo1->Lines->Add("Inorder sequence : "+out);
	}
	else if(RadioButton3->Checked==true)//Postorder
	{
		postorder(root);
		Form2->Memo1->Lines->Add("Postorder sequence : "+out);
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Button3Click(TObject *Sender)//random insert
{
	int n = StrToInt(Edit2->Text);
	int range = StrToInt(Edit3->Text);
	for(int i=0;i<n;i++)
	{
	   int element = rand()%(range+1);
	   insert(element);
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Button2Click(TObject *Sender)//delete from BTN
{
	BTN* node;
	int x = StrToInt(Edit1->Text);
	node = DeleteBSTree(root,x);
	Form2->Memo1->Lines->Add("Delete :"+IntToStr(x));
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Button5Click(TObject *Sender)//clear tree
{
	del(root);
	empty->parent = NULL;
	out = "";
    root = NULL;
	Form2->Memo1->Lines->Add("Clear tree!");
}
//---------------------------------------------------------------------------

void __fastcall TForm2::Button7Click(TObject *Sender)//level-oder traversal
{
	out = "";
	LevelOrder(root);
	Form2->Memo1->Lines->Add("Level oder traversal:"+out);
}
//---------------------------------------------------------------------------

