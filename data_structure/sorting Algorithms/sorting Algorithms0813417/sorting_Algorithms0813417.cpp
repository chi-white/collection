//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "sorting_Algorithms0813417.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm2 *Form2;
//---------------------------------------------------------------------------
__fastcall TForm2::TForm2(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
#define MAXNUMBER 10000000

int data[10000000] = {NULL};
int heap[10000000] = {NULL};
int temp[1000000] = {NULL};
int index[1000000] = {NULL};
int count[1000000] = {NULL};
int heapq = 0;
struct quick
{
	int left;
	int right;
};

struct stack
{
	quick* qnode;
	stack* next;
};
stack *top = NULL;

void swap(int i,int j)
{
	int temp;
	temp = data[i];
	data[i] = data[j];
	data[j] = temp;
}

void selectionsort(int data[],int n)
{
	int i,j,min,temp;
	for(i=0;i<n;i++)
	{
		min = i;
		for(j=i+1;j<n;j++)
			if(data[j]<data[min]) min = j;
		temp = data[i];
		data[i] = data[min];
		data[min] = temp;
	}
}

void insertionsort(int data[],int n)
{
	int target,i,j;
	for(i=1;i<n;i++)
	{
		target = data[i];
		j = i;
		while((j>0)&&(data[j-1]>target))
		{
			data[j] = data[j-1];
			j--;
		}
		data[j] = target;
	}
}

void bubblesort(int data[],int n)
{
	int i,j,temp;
	for(i=n-1;i>0;i--)
		for(j=1;j<=i;j++)
			if(data[j-1]>data[j])
			{
				temp = data[j-1];
				data[j-1] = data[j];
				data[j] = temp;
			}
}

void quicksort_re(int data[],int left,int right)//記得把第n項設成maxnumber
{
	int j,i,target;
	if(left<right)
	{
		i = left+1;
		j = right;
		target = data[left];
		do
		{
			while(i<=j&&data[i]<=target) i++;
			while(i<=j&&data[j]>=target) j--;
			if(i<j) swap(i,j);
		}while(i<j);
		if(j>left) swap(left,j);
		quicksort_re(data,left,j-1);
		quicksort_re(data,j+1,right);
    }
}

quick* pop()
{
	stack* old_top;
	quick* r;
	if(top==NULL) ShowMessage("Stack is empty!!");
	else
	{
		old_top = top;
		top = top->next;
		r = old_top->qnode;
		free(old_top);
	}
	return r;
}

void push(int left,int right)
{
	quick* r = new quick;
	r->right = right;
	r->left = left;
	stack* p = new stack;
	p->qnode = r;
	p->next = top;
	top = p;
}

void quicksort(int data[],int n)//記得把第n項設成maxnumber
{
	quick* r;
	int left=0;
	int right = n-1;
	int i,j,target;
	push(left,right);
	while(top!=NULL)
	{
		r = pop();
		target = data[r->left];
		i = (r->left)+1;
		j = r->right;
		do
		{
			while(i<=j&&data[i]<=target) i++;
			while(i<=j&&data[j]>=target) j--;
			if(i<j) swap(i,j);
		}while(i<j);
		if(j>r->left) swap(r->left,j);
		if(j+1<r->right) push(j+1,r->right);
		if(r->left<j-1) push(r->left,j-1);
	}
}

void insertheap(int x)
{
	int i;
	if(heapq==MAXNUMBER) ShowMessage("Heap is full!");
	else
	{
		heapq++;
		i = heapq;
		while((i>1) && (x>heap[i/2]))
		{
			heap[i] = heap[i/2];
			i /= 2;
		}
		heap[i] = x;
	}
}

int deleteheap()
{
	int x,i,j,temp;
	if(heapq==0) ShowMessage("Heap is empty!");
	else
	{
		x = heap[1];
		heap[1] = heap[heapq];
		heapq--;
		i = 1;
		while(i<=heapq/2)
		{
			if(heap[2*i]>heap[2*i+1]) j = 2*i;
			else j = 2*i+1;
			if(heap[i]>heap[j]) break;
			temp = heap[i];
			heap[i] = heap[j];
            heap[j] = temp;
			i = j;
		}
		return x;
    }
}

void heapsort(int data[],int n)
{
	int i;
	for(i=0;i<n;i++) insertheap(data[i]);
	for(i=n-1;i>=0;i--) data[i] = deleteheap();
}

void merge(int C[],int k,int A[],int i,int m,int B[],int j,int n)
{
	while((i<=m)&&(j<=n))
	{
		if(A[i] <= B[j]) C[k++] = A[i++];
		else C[k++] = B[j++];
	}
	while(i<=m) C[k++] = A[i++];
	while(j<=n) C[k++] = B[j++];
}

void mergesort_re(int data[],int left,int right)
{
	int m;
	if(left<right)
	{
		m = (left+right)/2;
		mergesort_re(data,left,m);
		mergesort_re(data,m+1,right);
		merge(data,left,data,left,m,data,m+1,right);
    }
}

int get_place(int x,int i)
{
	int j;
	for(j=1;j!=i;j++) x = x/10;
	x = x%10;
	return x;
}

int digits(int x)
{
	int i,j=0;
	for(i=1;;i*=10)
	{ 
		if(x<i) break;
		j++;
	}
	return j;
}

void radixsort(int data[],int n)
{
	int max = 0,i,j,radix,digit;
	for(i=1;i<n;i++)
		if(data[i]>max) max = data[i];
	radix = digits(max);

	for(i=1;i<=radix;i++)
	{
		for(j=0;j<10;j++) count[j] = 0;
		for(j=0;j<n;j++)//(j<n不是j<10)講義寫錯勒
		{ 
			digit = get_place(data[j],i);
			count[digit]++;
		}
		index[0] = 0;
		for(j=1;j<10;j++) index[j] = index[j-1]+count[j-1];
		for(j=0;j<n;j++)
		{
			digit = get_place(data[j],i);
			temp[index[digit]++] = data[j];
		}
		for(j=0;j<n;j++) data[j] = temp[j];
	}
}

void random(int n,int range)
{
	int i;
	for(i=0;i<n;i++) data[i] = rand()%range;
}

void __fastcall TForm2::Button1Click(TObject *Sender)//count
{
	int times = StrToInt(Edit1->Text);
	int N = StrToInt(Edit2->Text);
	int range = StrToInt(Edit3->Text);
	int i,j,k;
	clock_t t_begin,t_end;
	if(CheckBox1->Checked)//selection sort
	{
		
		Memo1->Lines->Add("SlectionSort :");
		for(i=1;i<=times;i++)
		{	
			t_begin = clock();
			random(N*i,range);
			selectionsort(data,N*i);
			t_end = clock();
			Form2->Memo1->Lines->Add("N="+IntToStr(N*i)+" : CPU time(sec)"+FloatToStr((float)(t_end-t_begin)/CLOCKS_PER_SEC));
            if(CheckBox10->Checked)
			{
				Memo2->Lines->Add("SlectionSort (N ="+IntToStr(N*i)+") : ");
				for(int j=0;j<N*i;j++)
					Memo2->Lines->Add(data[j]);
			}
		}
	}
	if(CheckBox2->Checked)//InsertionSort
	{
		Memo1->Lines->Add("InsertionSort :");
		for(i=1;i<=times;i++)
		{	
			t_begin = clock();
			random(N*i,range);
			insertionsort(data,N*i);
			t_end = clock();
			Form2->Memo1->Lines->Add("N="+IntToStr(N*i)+" : CPU time(sec)"+FloatToStr((float)(t_end-t_begin)/CLOCKS_PER_SEC));
            if(CheckBox10->Checked)
			{
				Memo2->Lines->Add("InsertionSort (N ="+IntToStr(N*i)+") : ");
				for(int j=0;j<N*i;j++)
					Memo2->Lines->Add(data[j]);
			}
		}
	}
	if(CheckBox3->Checked)//BubbleSort
	{
		Memo1->Lines->Add("BubbleSort :");
		for(i=1;i<=times;i++)
		{	
			t_begin = clock();
			random(N*i,range);
			bubblesort(data,N*i);
			t_end = clock();
			Form2->Memo1->Lines->Add("N="+IntToStr(N*i)+" : CPU time(sec)"+FloatToStr((float)(t_end-t_begin)/CLOCKS_PER_SEC));
            if(CheckBox10->Checked)
			{
				Memo2->Lines->Add("BubbleSort (N ="+IntToStr(N*i)+") : ");
				for(int j=0;j<N*i;j++)
					Memo2->Lines->Add(data[j]);
			}
		}
	}
	if(CheckBox4->Checked)//QuickSort
	{
		Memo1->Lines->Add("QuickSort : ");
		for(i=1;i<=times;i++)
		{	
			t_begin = clock();
			random(N*i,range);
			data[N*i] = MAXNUMBER;
			quicksort(data,N*i);
			t_end = clock();
			Form2->Memo1->Lines->Add("N="+IntToStr(N*i)+" : CPU time(sec)"+FloatToStr((float)(t_end-t_begin)/CLOCKS_PER_SEC));
			if(CheckBox10->Checked)
			{
				Memo2->Lines->Add("QuickSort(N ="+IntToStr(N*i)+") : ");
				for(int j=0;j<N*i;j++)
					Memo2->Lines->Add(data[j]);
			}
		}
	}
	
	if(CheckBox5->Checked)//QuickSort_re
	{
		Memo1->Lines->Add("QuickSort(recursive version) : ");
		for(i=1;i<=times;i++)
		{
			t_begin = clock();
			random(N*i,range);
			data[N*i] = MAXNUMBER;
			quicksort_re(data,0,N*i-1);
			t_end = clock();
			Form2->Memo1->Lines->Add("N="+IntToStr(N*i)+" : CPU time(sec)"+FloatToStr((float)(t_end-t_begin)/CLOCKS_PER_SEC));
			if(CheckBox10->Checked)
			{
				Memo2->Lines->Add("QuickSort(recursive version) (N ="+IntToStr(N*i)+") : ");
				for(int j=0;j<N*i;j++)
					Memo2->Lines->Add(data[j]);
			}
		}
	}

	if(CheckBox6->Checked)
	{
		Memo1->Lines->Add("MergeSort(recursive version) : ");
		for(i=1;i<=times;i++)
		{
			t_begin = clock();
			random(N*i,range);
			mergesort_re(data,0,(N*i)-1);
			t_end = clock();
			Form2->Memo1->Lines->Add("N="+IntToStr(N*i)+" : CPU time(sec)"+FloatToStr((float)(t_end-t_begin)/CLOCKS_PER_SEC));
			if(CheckBox10->Checked)
			{
				Memo2->Lines->Add("MergeSort(recursive version) (N ="+IntToStr(N*i)+") : ");
				for(int j=0;j<N*i;j++)
					Memo2->Lines->Add(data[j]);
			}
		}
	}
	if(CheckBox7->Checked)//merge非遞迴
	{
		Memo1->Lines->Add("MergeSort : ");
		for(i=1;i<=times;i++)
		{
			t_begin = clock();
			random(N*i,range);
			int len = 2;
			while(len<=i*N)//要加等號!!(講義寫錯)
			{
				for(j=0;j<i*N;j+=len) merge(data,j,data,j,j+len/2-1,data,j+len/2,j+len-1);
				len *= 2;
			}
			t_end = clock();
			Form2->Memo1->Lines->Add("N="+IntToStr(N*i)+" : CPU time(sec)"+FloatToStr((float)(t_end-t_begin)/CLOCKS_PER_SEC));
			if(CheckBox10->Checked)
			{
				Memo2->Lines->Add("MergeSort (N ="+IntToStr(N*i)+") : ");
				for(int j=0;j<N*i;j++)
					Memo2->Lines->Add(data[j]);
			}
		}
	}
	if(CheckBox8->Checked)
	{
		Memo1->Lines->Add("HeapSort : ");
		for(i=1;i<=times;i++)
		{
			t_begin = clock();
			random(N*i,range);
			heapsort(data,N*i);
			t_end = clock();
			Form2->Memo1->Lines->Add("N="+IntToStr(N*i)+" : CPU time(sec)"+FloatToStr((float)(t_end-t_begin)/CLOCKS_PER_SEC));
            if(CheckBox10->Checked)
			{
				Memo2->Lines->Add("HeapSort (N ="+IntToStr(N*i)+") : ");
				for(int j=0;j<N*i;j++)
					Memo2->Lines->Add(data[j]);
			}
		}
	}

	if(CheckBox9->Checked)
	{
		Memo1->Lines->Add("Radix Sort : ");
		for(i=1;i<=times;i++)
		{
			t_begin = clock();
			random(N*i,range);
			radixsort(data,N*i);
			t_end = clock();
			Form2->Memo1->Lines->Add("N="+IntToStr(N*i)+" : CPU time(sec)"+FloatToStr((float)(t_end-t_begin)/CLOCKS_PER_SEC));
			if(CheckBox10->Checked)
			{
				Memo2->Lines->Add("Radix Sort (N ="+IntToStr(N*i)+") : ");
				for(int j=0;j<N*i;j++)
					Memo2->Lines->Add(data[j]);
			}
		}
	}
}


//---------------------------------------------------------------------------



