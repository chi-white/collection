//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Polynomial0813417.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm2 *Form2;
struct term;
term* Newheader(int coef,int expo);
term *a_first,*a_last,*b_first,*b_last,*c_first,*c_last;
//---------------------------------------------------------------------------
__fastcall TForm2::TForm2(TComponent* Owner)
	: TForm(Owner)
{
	a_first = Newheader(0,-1);
	b_first = Newheader(0,-1);
	c_first = Newheader(0,-1);
	a_last = a_first;
	b_last = b_first;
	c_last = c_first;
}

struct term
{
	int coef;
	int expo;
	term* next;
};

term* Newheader(int coef,int expo)
{
	term* r = new term;
	r->coef = coef;
	r->expo = expo;
	r->next = r;
	return r;
}

term* Newterm(term* x)
{
	term* r = new term;
	r->coef = x->coef;
	r->expo = x->expo;
	return r;
}

void C()
{
	term *p,*q;
	p = a_first->next;
	q = b_first->next;
	while(p!=a_first||q!=b_first)
	{
		term* r;
		if(p->expo > q->expo)
		{
			r = Newterm(p);
			p = p->next;
		}
		else if(p->expo < q->expo)
		{
			r = Newterm(q);
			q = q->next;
		}
		else//expo?۵?
		{
			r = Newterm(p);
			r->coef += q->coef;
			p = p->next;
			q = q->next;
			if(r->coef == 0) continue;
		}
		c_last->next = r;
		c_last = r;
	}
	c_last->next = c_first;
}

String print(term* first)
{
	String out;
	term* r;
	r = first->next;
	while(r!=first)
	{
		if(r->coef>0)
		{
			if(r->expo==0)
				out += "+ "+IntToStr(r->coef)+" ";
			else if(r->expo==1)
				out += "+ "+IntToStr(r->coef)+"X ";
			else
				out += "+ "+IntToStr(r->coef)+"X^"+IntToStr(r->expo)+" ";
		}
		else//coef<0
		{
			if(r->expo==0)
				out += IntToStr(r->coef)+" ";
			else if(r->expo==1)
				out += IntToStr(r->coef)+"X ";
			else
				out += IntToStr(r->coef)+"X^"+IntToStr(r->expo)+" ";
		}
		r = r->next;
	}
	return out;
}

void clear(term* first)
{
	term* x;
	while(first->next!=first)
	{
		x = first->next;
		first->next = x->next;
		free(x);
    }
}

String random(int maxexpo,int coef_range,int zero_range,term* first,term* last)
{
	String out = "";
	int i,zerocount=0,coef;
	term* r;
	for(i=maxexpo+1;i>-1;i--)
	{
		coef = rand()%coef_range;
		if(coef==0) zerocount++;
		if(zerocount>zero_range)
			while(coef==0)
				coef = rand()%coef_range;
		if(coef==0)
			continue;
		else
		{
			r = Newheader(coef,i);
			last->next = r;
			last = r;
			last->next = first;
		}
	}
	out = print(first);
	return out;
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Button4Click(TObject *Sender)//C = A+B
{
	String outa = "",outb = "",outc="";
	C();
	outa = print(a_first);
	outa = "A : "+outa;
	outb = print(b_first);
	outb = "B : "+outb;
	outc = print(c_first);
	outc = "C : "+outc;
	Form2->Memo2->Lines->Add(outa);
	Form2->Memo2->Lines->Add(outb);
	Form2->Memo2->Lines->Add(outc);
	Form2->Memo2->Lines->Add("===============================");
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Button5Click(TObject *Sender)//clear
{
	clear(a_first);
	clear(b_first);
	clear(c_first);
	a_last = a_first;
	b_last = b_first;
	c_last = c_first;
    Form2->Memo1->Lines->Add("clear!");
    ShowMessage("Clear All Polynomial!");
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Button2Click(TObject *Sender)//Add to A ?ɭ??K?n?ۤv?`?N
{
	String out = "";
	int coef = StrToInt(Edit2->Text);
	int expo = StrToInt(Edit1->Text);
	term* r;
    r = Newheader(coef,expo);
	a_last->next = r;
	a_last = r;
	a_last->next = a_first;
	out = print(a_first);
	out = "A : "+out;
	Form2->Memo1->Lines->Add(out);
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Button1Click(TObject *Sender) ////Add to B ?ɭ??K?n?ۤv?`?N
{
	String out = "";
	int coef = StrToInt(Edit2->Text);
	int expo = StrToInt(Edit1->Text);
	term* r = new term;
	r->coef = coef;
	r->expo = expo;
	b_last->next = r;
	b_last = r;
	b_last->next = b_first;
	out = print(b_first);
	out = "B : "+out;
	Form2->Memo1->Lines->Add(out);
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Button3Click(TObject *Sender)//random generate
{
	int maxexpo = StrToInt(Edit3->Text);
	int coef_range = StrToInt(Edit4->Text);
	int zero_range = StrToInt(Edit5->Text);
	String outa,outb;
	outa = random(maxexpo,coef_range,zero_range,a_first,a_last);
	outb = random(maxexpo,coef_range,zero_range,b_first,b_last);
	outa = "A : "+outa;
	outb = "B : "+outb;
	Form2->Memo1->Lines->Add(outa);
	Form2->Memo1->Lines->Add(outb);
}
//---------------------------------------------------------------------------

