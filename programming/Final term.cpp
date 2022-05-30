#include <iostream> 
#include <fstream>
#include <string.h>
#include <conio.h>
#include <time.h>
#include <stdlib.h>
using namespace std;

struct order
{
	int uid;
	int meal;
	int drink;
	int drinksize; 
};

struct customer
{
	char name[21];
	char account[17];
	char password[11];
	int loginno;
	int XAXBwin;
	int XAXBlose;
	int sudokuwin;
	int sudokulose;
};
/*------------------------------------------
Tools
--------------------------------------------*/
void anykey();
/*------------------------------------------
Account Management
--------------------------------------------*/
void inputAccount(char display[],char a[]);
void inputPassword(char display[],char a[]);
int LoadMember(customer m[]); //Read memberlist from txt file
void SaveMember(customer m[],int mn);
/*------------------------------------------
Order Functions
--------------------------------------------*/
void OrderMain(int uid,order orderlist[]);
int ordermealUI(int choice);
void mealPrintUI(int choice);
int orderdrinkUI(int choice);
void drinkPrintUI(int choice);
int orderdrinksizeUI(int choice);
void drinksizePrintUI(int choice);
int LoadOrder(order o[]);
int internalLoadOrder(order o[]);
//-------------------------------------------
void OrderView(int uid,order orderlist[]);
int MCcontrol(int mno,int on);
void internalUI(order orderlist[],int mno,int on);
/*------------------------------------------
XAXB Functions
--------------------------------------------*/
void XAXBMain(customer members[],int uid);
int XAXBcheck(int n);
int XAXB(int g,int a);
int XAXBinput();
/*------------------------------------------
MainUI
--------------------------------------------*/
int Login(customer m[],int* pmn);
int MainUI(int choice,int uid,customer members[]);
void PrintUI(int choice,int uid,customer members[]);
/*------------------------------------------
sudoku
--------------------------------------------*/
void sudokumain(customer members[],int uid);
void sudokuPrint(int Q[][9], int A[][9], int h, int w);
void sudokuread(int Q[][9]);
int sudokuCheck(int T[][9][10],int r, int c);
void sudokuUpdate(int T[][9][10],int r, int c,int a);
void sudokuSolve(int Q[][9],int A[][9]);
void sudokuPlay(int Q[][9],int A[][9]);
int sudokuCorrect(int q[][9],int a[][9]);
/*------------------------------------------
chatroom
--------------------------------------------*/
void chatroommain(customer members[],int uid);
/*------------------------------------------
��K�X
--------------------------------------------*/
int xpassword(customer m[],int uid);

int main()
{

	customer members[100];
	srand(time(NULL));
	order orderlist[1000];
	int memberno,uid,choice=1;
	memberno = LoadMember(members);
	uid = Login(members,&memberno);
	if(uid==1)
	{
		int mno,on,i;
		system("cls");
		on=LoadOrder(orderlist);
		mno=internalLoadOrder(orderlist);
		while(mno!=on)
		{
			system("cls");
			internalUI(orderlist,mno,on);
			mno=MCcontrol(mno,on);
		}
		if(mno==on)
		{
			cout<<"�q��w�����B�z����"<<endl;
			cout<<endl<<endl<< "Press any key to continue~~";
			anykey(); 
		}
		ofstream fout;
		fout.open("orderlist.txt");
		fout << on << endl;
		fout << mno<<endl;
		for(i=0;i<on;i++)
		{
			fout << orderlist[i].uid << endl;
			fout << orderlist[i].meal << endl;
			fout << orderlist[i].drink << endl;
			fout << orderlist[i].drinksize << endl;
		}
		fout.close();
		return 0;
	} 
	do
	{
		choice = MainUI(choice,uid,members);
		switch(choice)
		{
			case 1:
				OrderMain(uid,orderlist);
				//save current mealno,orderno,orderlist[0..orderno-1] to a file
				break;
			case 2:
				//Load current mealno,orderno,orderlist[0..orderno-1] from a file
				OrderView(uid,orderlist);
				break;
			case 3:
				xpassword(members,uid);
				break;
			case 4:
				chatroommain(members,uid);
				break;
			case 5:
				sudokumain(members,uid);
				break;
			case 6:
				XAXBMain(members,uid);
				break;
			default:
				break;
		}
		/*system("cls");
		cout << "�ﶵ" << choice << endl;
		cout << "Press any key to continue~~";
		anykey();*/
	}while(choice!=0);
	SaveMember(members,memberno);
	return 0;
}

void PrintUI(int choice,int uid,customer members[])
{
	system("cls");
	cout<<"�o�O�z��"<<members[uid].loginno<<"���n�J�t��"<<endl; 
	char left[7],right[7];
	int i;
	for(i=0;i<7;i++)
	{
		left[i] = ' ';
		right[i] = ' ';
	}
	left[choice]='[';
	right[choice]=']';
	cout << "                                  "<< left[1] << "1" << right[1] << " Order" << endl;
	cout << "                                  "<< left[2] << "2" << right[2] << " �d�q��" << endl;
	cout << "                                  "<< left[3] << "3" << right[3] << " �ק�|�����" << endl;
	cout << "                                  "<< left[4] << "4" << right[4] << " ��ѫ�" << endl;
	cout << "                                  "<< left[5] << "5" << right[5] << " �ƿW�C��" << endl;
	cout << "                                  "<< left[6] << "6" << right[6] << " �q�Ʀr" << endl;
	cout << "                                  "<< left[0] << "0" << right[0] << " ���}�t��" << endl;
}

int MainUI(int choice,int uid,customer members[])
{
	char c,c1;
	do
	{
		PrintUI(choice,uid,members);
		c = getch();
		if(c==-32)
		{
			c1 = getch();
			if(c1==72)
				choice = (choice+6)%7;
			if(c1==80)
				choice = (choice+1)%7;
			if(c1==77)
				c=13;
		}
		if(c>='0'&&c<='6')
			choice = c-'0';
		if(c==0)
			c1 = getch();
	}while(c!=13);
	return choice;
}

void sudokumain(customer members[],int uid)
{
	int Q[9][9],A[9][9],A2[9][9];
	int correctness,success,fail;
	cout<<"�z�w�g���D��L"<<members[uid].sudokuwin<<"���M���L"<<members[uid].sudokulose<<"���o"<<endl; 
	anykey();
	sudokuread(Q);
	sudokuPlay(Q,A); 
	sudokuSolve(Q,A2);
	correctness = sudokuCorrect(A,A2);
	if(correctness==1)
		{
			cout << "Good Job!!!!!!!" << endl;
			members[uid].sudokuwin++;
		} 
	else
		{
			cout << "Stupid ><" << endl;
			members[uid].sudokulose++;
		}	
	anykey();
}

int sudokuCorrect(int q[][9],int a[][9])
{
	int r,c,open=1;
	for(r=0;r<9;r++)
		for(c=0;c<9;c++)
			{
				if(q[r][c]!=a[r][c])
				open=0;
			}
	return open;
}

void sudokuSolve(int Q[][9],int A[][9])
{
	int T[9][9][10];
	int r,c,a,i,j;
	for(r=0;r<9;r++)
		for(c=0;c<9;c++)
			for(a=1;a<=9;a++)
				T[r][c][a]=1;
	for(r=0;r<9;r++)
	{
		for(c=0;c<9;c++)
		{
			a = Q[r][c];
			A[r][c]=a;
			if(a>0)
				sudokuUpdate(T,r,c,a);
		}
	}
	int flag=1;
	while(flag==1)
	{
		flag = 0;
		for(r=0;r<9;r++)
		{
			for(c=0;c<9;c++)
			{
				if(A[r][c]==0)
				{
					a=sudokuCheck(T,r,c);
					if(a>0)
					{
						A[r][c]=a;
						sudokuUpdate(T,r,c,a);
						flag = 1;
					}
				}
			}
		}
	}
} 

int sudokuCheck(int T[][9][10],int r, int c)
{
	int i,count = 0;
	for(i=1;i<=9;i++)
		count += T[r][c][i];
	if(count==1)
	{
		for(i=1;i<=9;i++)
			if(T[r][c][i]==1)
				return i;
	}
	else
		return 0;
}

void sudokuUpdate(int T[][9][10],int r, int c,int a)
{
	int i,j;
	for(i=1;i<=9;i++)
		T[r][c][i]=0;
	for(i=0;i<9;i++)
		T[r][i][a]=0;
	for(i=0;i<9;i++)
		T[i][c][a]=0;
	for(i=r/3*3;i<=r/3*3+2;i++)
		for(j=c/3*3;j<=c/3*3+2;j++)
			T[i][j][a] = 0;
	T[r][c][a]=1;
}

void sudokuread(int Q[][9])
{
	int y,x,t;
	ifstream fin;
	t=rand()%2;
	if(t==0)
		fin.open("Q1.txt");
	else
		fin.open("Q2.txt");	
	for(y=0;y<9;y++)
		for(x=0;x<9;x++)
			fin >> Q[y][x];
	fin.close();
}

void sudokuPlay(int Q[][9],int A[][9])
{
	int h=0,w=0;
	int r,c;
	for(r=0;r<9;r++)
		for(c=0;c<9;c++)
			A[r][c]=Q[r][c];
	char x1,x2;
	do
	{
		sudokuPrint(Q,A,h,w);
		x1 = getch();
		if(x1==-32)
		{
			x2 = getch();
			if(x2==72)
				h = (h + 8)%9;//up
			if(x2==80)
				h = (h + 1)%9;//down
			if(x2==75)
				w = (w + 8)%9;//left
			if(x2==77)
				w = (w + 1)%9;//right
		}
		if(x1>='0'&&x1<='9'&&Q[h][w]==0)
		{
			A[h][w]=x1-'0';
		}
	}while(x1!=13);
}

void sudokuPrint(int Q[][9], int A[][9], int h, int w)
{
	char left[9][9];
	char right[9][9];
	int r,c;
	system("cls");
	for(r=0;r<9;r++)
	{
		for(c=0;c<9;c++)
		{
			left[r][c]=' ';
			right[r][c]=' ';
		}
	}
	if(Q[h][w]==0)
	{
		left[h][w] = '[';
		right[h][w] = ']';
	}
	else
	{
		left[h][w] = '<';
		right[h][w] = '>';
	}
	for(r=0;r<9;r++)
	{
		for(c=0;c<9;c++)
		{
			if(A[r][c]>0)
				cout << left[r][c] << A[r][c] << right[r][c];
			else
				cout << left[r][c] << " " << right[r][c];
			if(c==2||c==5)
				cout <<"|";
		}
		cout << endl;
		if(r==2||r==5)
			cout << "-----------------------------"<<endl;
	}
}


void XAXBMain(customer members[],int uid)
{
	int ans,guess,AB;
	srand(time(NULL));
	int human_ans;
	int com_guess;
	int P[10000];
	int i,AB1,AB2;
	int round=0;
	system("cls");
	cout<<"�z�w�gĹ�L"<<members[uid].XAXBwin<<"���M��L"<<members[uid].XAXBlose<<"���o"<<endl; 
	cout<<"�п�J�A���D��"<<endl;
	cin>>human_ans; //�H������ 
		cout<<"�}�l�q�o"<<endl;
	do
	{
		ans = rand()%10000;
	}while(XAXBcheck(ans)==0);//�q������ 
	
	for(i=0;i<10000;i++)
	{
		if(XAXBcheck(i)==1)
			P[i] = 1;
		else
			P[i] = 0;
	}				//�q���ˬd���� 
	do
	{
		for(i=0;i<10000;i++)
			if(P[i]==1)
				break;
		com_guess = i;//�q���_�l���� 
		cout<<"�п�J�A������"<<endl; 
		cin>>guess;
		AB = XAXB(guess,ans); 
		cout << AB/10 << "A" << AB%10 << "B" << endl;//�H�q������ 
		cout << "computer guess:" << com_guess <<endl;
		AB1 = XAXB(com_guess,human_ans);
		cout << AB1/10 << "A" << AB1%10 << "B" << endl;//�q�������� 
		for(i=0;i<10000;i++)
		{
			if(P[i]==1)
			{
				AB2 = XAXB(com_guess,i);
				if(AB2!=AB1)
					P[i] = 0;
			}
		}
		round++;
	}while(AB1!=40&&AB!=40);
	if(AB1==40)
	{
		cout<<"�q���b"<<round<<"�^�XĹ�F"<<endl;
		members[uid].XAXBlose++;
	}
	if(AB==40)
	{
		cout<<"�H���b"<<round<<"�^�XĹ�F"<<endl;
		members[uid].XAXBwin++;
	}
	cout<<"�q�����׬O:"<<ans<<endl;
	cout << "�I���N���~���L�欰";
	anykey();
}

int XAXBinput()
{
	int guess;
	do{
		cout << "Please guess:";
		cin >> guess;
		if(XAXBcheck(guess)==0)
			cout << "Type error!!!!!!" << endl;
	}while(XAXBcheck(guess)==0);
	return guess;
}

int XAXB(int g,int a)
{
	int A=0,B=0;
	int g1,g2,g3,g4,a1,a2,a3,a4;
	g1 = g/1000;
	g2 = g%1000/100;
	g3 = g%100/10;
	g4 = g%10;
	a1 = a/1000;
	a2 = a%1000/100;
	a3 = a%100/10;
	a4 = a%10;
	if(a1==g1)
		A++;
	if(a2==g2)
		A++;
	if(a3==g3)
		A++;
	if(a4==g4)
		A++;
	if(a1==g2||a1==g3||a1==g4)
		B++;
	if(a2==g1||a2==g3||a2==g4)
		B++;
	if(a3==g1||a3==g2||a3==g4)
		B++;
	if(a4==g1||a4==g2||a4==g3)
		B++;
	return A*10+B;
}

int XAXBcheck(int n)
{
	int a,b,c,d;
	if(n<0||n>=10000)
		return 0;
	a = n/1000;
	b = n%1000/100;
	c = n%100/10;
	d = n%10;
	if(a==b||a==c||a==d||b==c||b==d||c==d)
		return 0;
	return 1;
}

void OrderMain(int uid,order orderlist[])
{
	int choice=1,i,on,mno,c=0;
	int* pon;
	int* pmno;
	on=LoadOrder(orderlist);
	mno=internalLoadOrder(orderlist);
	pon=&on;
	pmno=&mno;
	/*orderlist[*pon].meal = ordermealUI(choice);
	choice=1;
	orderlist[*pon].drink = orderdrinkUI(choice);
	choice=1;
	orderlist[*pon].drinksize = orderdrinksizeUI(choice);*/
	//orderlist[*pon].uid = uid;
	do{
		orderlist[*pon].uid = uid;
		orderlist[*pon].meal = ordermealUI(choice);
		choice=1;
		orderlist[*pon].drink = orderdrinkUI(choice);
		choice=1;
		orderlist[*pon].drinksize = orderdrinksizeUI(choice);
		system("cls");
		switch(orderlist[*pon].meal)
		{
			case 1:
				cout<<"������"<<endl;
				break;
			case 2:
				cout<<"�j���J"<<endl;
				break;
			case 3:
				cout<<"���h���װ_�q��"<<endl;
				break;
			case 4:
				cout<<"������"<<endl;
				break;
			case 5:
				cout<<"����"<<endl;
				break;
			case 0:
				cout<<"���L��"<<endl;
				break;
		}
			switch(orderlist[*pon].drink)
		{
			case 1:
				cout<<"�i��"<<endl;
				break;
			case 2:
				cout<<"���"<<endl;
				break;
			case 3:
				cout<<"�f�c����"<<endl;
				break;
			case 4:
				cout<<"����"<<endl;
				break;
			case 5:
				cout<<"�ɦ̿@��"<<endl;
				break;
			case 0:
				cout<<"����"<<endl;
				break;
		}
			switch(orderlist[*pon].drinksize)
		{
			case 1:
				cout<<"���M"<<endl;
				break;
			case 2:
				cout<<"�j�M"<<endl;
				break;
			case 0:
				cout<<"�S�j�M"<<endl;
				break;
		}
		cout<<"Pause ENTER if you ensure your meal"<<endl; 
		c=getch();
		//cout<<c<<endl;
		//anykey();
	}while(c!=13);
	(*pon)++;
	//on=*pon;
	//mno=*pmno;
	ofstream fout;
	fout.open("orderlist.txt");
	fout << *pon << endl;
	fout << *pmno<<endl;
	for(i=0;i<*pon;i++)
	{
		fout << orderlist[i].uid << endl;
		fout << orderlist[i].meal << endl;
		fout << orderlist[i].drink << endl;
		fout << orderlist[i].drinksize << endl;
	}
	fout.close();
}

int ordermealUI(int choice)
{
	char c,c1;
	do
	{
		mealPrintUI(choice);
		c = getch();
		if(c==-32)
		{
			c1 = getch();
			if(c1==72)
				choice = (choice+5)%6;
			if(c1==80)
				choice = (choice+1)%6;
			if(c1==77)
				c=13;
		}
		if(c>='1'&&c<='6')
			choice = c-'0';
		if(c==0)
			c1 = getch();
	}while(c!=13);
	return choice;
}

void mealPrintUI(int choice)
{
	system("cls");
	char left[6],right[6];
	int i;
	for(i=0;i<6;i++)
	{
		left[i] = ' ';
		right[i] = ' ';
	}
	left[choice]='[';
	right[choice]=']';
	cout << endl << endl << endl;
	cout << endl << endl ;
	cout << "                 "<<"�аݤ��ѷQ�Y����O??" << endl;	
	cout << "                 "<< left[1] << "������"<< right[1] << endl;
	cout << "                 "<< left[2] << " �j���J"  << right[2] <<  endl;
	cout << "                 "<< left[3] << " ���h���װ_�q��" << right[3]   << endl;
	cout << "                 "<< left[4] <<" ������"<< right[4] <<  endl;
	cout << "                 "<< left[5] << " ����" << right[5]   << endl;
	cout << "                 "<< left[0] << " ���L��"<< right[0] <<   endl;
}

int orderdrinkUI(int choice)
{
	char c,c1;
	do
	{
		drinkPrintUI(choice);
		c = getch();
		if(c==-32)
		{
			c1 = getch();
			if(c1==72)
				choice = (choice+5)%6;
			if(c1==80)
				choice = (choice+1)%6;
			if(c1==77)
				c=13;
		}
		if(c>='1'&&c<='6')
			choice = c-'0';
		if(c==0)
			c1 = getch();
	}while(c!=13);
	return choice;
}

void drinkPrintUI(int choice)
{
	system("cls");
	char left[6],right[6];
	int i;
	for(i=0;i<6;i++)
	{
		left[i] = ' ';
		right[i] = ' ';
	}
	left[choice]='[';
	right[choice]=']';
	cout << endl << endl << endl;
	cout << endl << endl ;
	cout << "                 "<<"���n�f�t���򶼮ƩO??" << endl;
	cout << "                 "<< left[1] << " �i��" << right[1]   << endl;
	cout << "                 "<< left[2] << " ���" << right[2]   << endl;
	cout << "                 "<< left[3] << " �f�c����"<< right[3]   << endl;
	cout << "                 "<< left[4] << " ����"<< right[4]   << endl;
	cout << "                 "<< left[5] << " �ɦ̿@��" << right[5]   << endl;
	cout << "                 "<< left[0] << " ����" << right[0]   << endl;
}

int orderdrinksizeUI(int choice)
{
	char c,c1;
	do
	{
		drinksizePrintUI(choice);
		c = getch();
		if(c==-32)
		{
			c1 = getch();
			if(c1==72)
				choice = (choice+2)%3;
			if(c1==80)
				choice = (choice+1)%3;
			if(c1==77)
				c=13;
		}
		if(c>='1'&&c<='3')
			choice = c-'0';
		if(c==0)
			c1 = getch();
	}while(c!=13);
	return choice;
}

void drinksizePrintUI(int choice)
{
	system("cls");
	char left[3],right[3];
	int i;
	for(i=0;i<3;i++)
	{
		left[i] = ' ';
		right[i] = ' ';
	}
	left[choice]='[';
	right[choice]=']';
	cout << endl << endl << endl;
	cout << endl << endl ;
	cout << "                 "<<"���ƪ��j�p�O??" << endl;
	cout << "                 "<< left[1] << " ���M"  << right[1]  << endl;
	cout << "                 "<< left[2] << " �j�M" << right[2]  << endl;
	cout << "                 "<< left[0] << " �S�j�M" << right[0]   << endl;
}

void OrderView(int uid,order o[]) 
{
	int on;
	int i;
	on=LoadOrder(o);
	for(i=0;i<on;i++)
	{
		if(o[i].uid==uid)
		{
			switch(o[i].meal)
			{
				case 1:
					cout<< "������"<<endl;
					break;
				case 2:
					cout<<"�j���J"<<endl;
					break;
				case 3:
					cout<<"���h���װ_�q��"<<endl;
					break;
				case 4:
					cout<<"������"<<endl;
					break;
				case 5:
					cout<<"����"<<endl;
					break;
				case 0:
					cout<<"���L��"<<endl;
					break;
			}
			switch(o[i].drink)
			{
				case 1:
					cout<<"�i��"<<endl;
					break;
				case 2:
					cout<<"���"<<endl;
					break;
				case 3:
					cout<<"�f�c����"<<endl;
					break;
				case 4:
					cout<<"����"<<endl;
					break;
				case 5:
					cout<<"�ɦ̿@��"<<endl;
					break;
				case 0:
					cout<<"����"<<endl;
					break;
			}
			switch(o[i].drinksize)
			{
				case 1:
					cout<<"���M"<<endl;
					break;
				case 2:
					cout<<"�j�M"<<endl;
					break;
				case 0:
					cout<<"�S�j�M"<<endl;
					break;
			}
			cout << endl;
		}
	}
	cout << "Press any key to continue~~";
	anykey();
	
}

int LoadOrder(order o[])
{
	int mon,on,i;
	ifstream fin;
	fin.open("orderlist.txt");
	fin >> on;
	fin >> mon;
	for(i=0;i<on;i++)
	{
		fin >> o[i].uid;
		fin >> o[i].meal;
		fin >> o[i].drink;
		fin >> o[i].drinksize;
	}
	fin.close(); 
	return on;
}

int internalLoadOrder(order o[])
{
	int mno,on,i;
	ifstream fin;
	fin.open("orderlist.txt");
	fin >> on;
	fin >> mno;
	for(i=0;i<on;i++)
	{
		fin >> o[i].uid;
		fin >> o[i].meal;
		fin >> o[i].drink;
		fin >> o[i].drinksize;
	}
	fin.close(); 
	return mno;
}


void chatroommain(customer members[],int uid)
{
	ifstream fin;
	ofstream fout;
	int c=0;
	char buffer[100];
	char input[100];
	do
	{
		system("cls");
		fin.open("msg.txt");
		while(fin.getline(buffer,99))
		{
			cout << buffer << endl;
		}
		fin.close();
		cout << "Please input your words:";
		cin.getline(input,99);
		fout.open("msg.txt",ios::app);
		fout << members[uid].name<<" :" << input << endl;
		fout.close();
		cout<<"�Y�Q���}�Ы�Q"<<endl;
		c=getch();
	}while(c!=113);	
}

void anykey()
{
	char c = getch();
	if(c==0||c==-32)
		getch();
}

int Login(customer m[],int* pmn)
{
	char name[20];
	char account[17];
	char password[11];
	char password2[11];
	char display[100]="�b��: ";
	int id=-1,i;
	do
	{
		strcpy(display,"�Y�ݭn���U�s�b��,�п�Jregister\n");
		strcat(display,"�b��: ");
		inputAccount(display,account);
		if(strcmp(account,"register")==0)
		{
			strcpy(display,"�п�J�s�b��: ");
			inputAccount(display,account);
			for(i=0;i<*pmn;i++)
			{
				if(strcmp(m[i].account,account)==0)
					break;
			}
			if(i==*pmn)
			{	
				strcat(display,account);
				strcat(display,"\n");
				strcat(display,"�п�J�K�X: ");
				inputPassword(display,password);
				strcpy(display,"�п�J�s�b��: ");
				strcat(display,account);
				strcat(display,"\n");
				strcat(display,"�Э��s��J�K�X: ");
				inputPassword(display,password2);
				if(strcmp(password,password2)==0)
				{
					cout << endl << "�m�W:";
					cin.getline(name,20);
					strcpy(m[*pmn].name,name);
					strcpy(m[*pmn].account,account);
					strcpy(m[*pmn].password,password);
					m[*pmn].loginno = 1;
					id = *pmn;
					(*pmn)++;
				}
				else
				{
					cout << endl << "Password Incorrect!!!!"<<endl;
					cout << "Press any key to continue~~";
					anykey();
				}
			}
			else
			{
				cout << "���b���w�Q�ϥ�" << endl;
				cout << "Press any key to continue~~";
				anykey(); 
			}
			continue;
		}
		strcat(display,account);
		strcat(display,"\n");
		strcat(display,"�K�X: ");
		inputPassword(display,password);
		for(i=0;i<*pmn;i++)
		{
			if(strcmp(m[i].account,account)==0)
			{
				if(strcmp(m[i].password,password)==0)
				{
					id = i;
					m[i].loginno++;
				}
				else
				{
					cout << endl << "Password Incorrect!!!!"<<endl;
					cout << "Press any key to continue~~";
					anykey();
				}
				break;
			}
		}
		if(i==*pmn)
		{
			cout << endl << "Who are you?"<<endl;
			cout << "Press any key to continue~~";
			anykey();
		}
	}while(id==-1);
	return id;
}

void inputAccount(char display[],char a[])
{
	char c;
	int i,count = 0;
	do
	{
		system("cls");
		cout << display;
		for(i=0;i<count;i++)
			cout << a[i];
		c = getch();
		if((c>='a'&&c<='z')||(c>='A'&&c<='Z')||(c>='0'&&c<='9')||c=='_')
		{
			if(count==0)
			{
				if((c>='a'&&c<='z')||(c>='A'&&c<='Z'))
				{
					a[count] = c;
					count++;					
				}
			}
			else if(count==16)
			{
				a[15] = c;
			}
			else
			{
				a[count] = c;
				count++;
			}
		}
		if(c==8&&count>0)
			count--;
		if(c==-32||c==0)
			getch();
	}while(c!=13||count<4);
	a[count] = '\0';
}

void inputPassword(char display[],char a[])
{
	char c;
	int i,count = 0;
	do
	{
		system("cls");
		cout << display;
		for(i=0;i<count;i++)
			cout << "*";
		c = getch();
		if((c>='a'&&c<='z')||(c>='A'&&c<='Z')||(c>='0'&&c<='9')||c=='_')
		{
			if(count==10)
			{
				a[9] = c;
			}
			else
			{
				a[count] = c;
				count++;
			}
		}
		if(c==8&&count>0)
			count--;
		if(c==-32||c==0)
			getch();
	}while(c!=13||count<4);
	a[count] = '\0';
}

int LoadMember(customer m[])
{
	int no,i;
	char buf[100];
	ifstream fin;
	fin.open("memberlist.txt");
	fin >> no;
	fin.getline(buf,20);
	for(i=0;i<no;i++)
	{
		fin.getline(buf,20);
		strcpy(m[i].name,buf);
		fin >> buf;
		strcpy(m[i].account,buf);
		fin >> buf;
		strcpy(m[i].password,buf);
		fin >> m[i].loginno;
		fin>>m[i].XAXBwin;
		fin>>m[i].XAXBlose;
		fin>>m[i].sudokuwin;
		fin>>m[i].sudokulose;
		fin.getline(buf,20);
	}
	fin.close(); 
	return no;
}

void SaveMember(customer m[],int mn)
{
	int i;
	ofstream fout;
	fout.open("memberlist.txt");
	fout << mn << endl;
	for(i=0;i<mn;i++)
	{
		fout << m[i].name << endl;
		fout << m[i].account << endl;
		fout << m[i].password << endl;
		fout << m[i].loginno << endl;
		fout << m[i].XAXBwin << endl;
		fout << m[i].XAXBlose << endl;
		fout << m[i].sudokuwin << endl;
		fout << m[i].sudokulose << endl;
	}
	fout.close();
}

int xpassword(customer m[],int uid)
{
	char password[11];
	char password2[11];
	char password3[11];
	char display[100]=""; 
	char display2[100]="";
	char display3[100]="";
	char display4[100]="";

	strcat(display,"�п�J�K�X�G"); 
	inputPassword(display,password);
	if(strcmp(m[uid].password,password)==0)
	{
		strcat(display2,"�ЦA��J�K�X�G"); 
		inputPassword(display2,password);
		if(strcmp(m[uid].password,password)==0)
		{
			strcat(display3,"�п�J�s�K�X�G");
			inputPassword(display3,password2);
			strcat(display4,"�ЦA��J�s�K�X�G");
			inputPassword(display4,password3);
			if(strcmp(password2,password3)==0)
			{
				strcpy(m[uid].password,password3);
				system("cls");
				cout<<"�K�X�w��s����"<<endl;
				cout << "Press any key to continue~~";
				anykey();
				return 0;		 
			}
		}
	}
	system("cls");
	cout<<"�K�X�����T"<<endl<<"�K�X��異��"<<endl<<endl; 
	cout << "Press any key to continue~~";
	anykey();
	return 1;
}

int MCcontrol(int mno,int on)
{
	char i,c,c1;
	c=getch();
	i=mno;
	do
	{
		if(c==-32)
		{
			c1 = getch();
			if(c1==77)
			{
				if(i<on)
				{
					i+=1;
					return i;
				}
				else
				{
					cout<<"�q��w�����B�z����"<<endl; 
					return i;
				}
			}		
			if(c1==75)
			{
				if(i>0)
				{
					cout<<"�o�O�Ĥ@���q��"<<endl;
					i-=1;
					return i;
				}
				else
					return i;
			}
			else
				getch ();
		}
		else
			getch();
	}while(true);
}

void internalUI(order o[],int mno,int on)
{
	int i;
	i=mno;
	system("cls");
	switch(o[i].meal)
	{
		case 1:
			cout<<"������"<<endl;
			break;
		case 2:
			cout<<"�j���J"<<endl;
			break;
		case 3:
			cout<<"���h���װ_�q��"<<endl;
			break;
		case 4:
			cout<<"������"<<endl;
			break;
		case 5:
			cout<<"����"<<endl;
			break;
		case 0:
			cout<<"���L��"<<endl;
			break;
	}
	switch(o[i].drink)
	{
		case 1:
			cout<<"�i��"<<endl;
			break;
		case 2:
			cout<<"���"<<endl;
			break;
		case 3:
			cout<<"�f�c����"<<endl;
			break;
		case 4:
			cout<<"����"<<endl;
			break;
		case 5:
			cout<<"�ɦ̿@��"<<endl;
			break;
		case 0:
			cout<<"����"<<endl;
			break;
	}
	switch(o[i].drinksize)
	{
		case 1:
			cout<<"���M"<<endl;
			break;
		case 2:
			cout<<"�j�M"<<endl;
			break;
		case 0:
			cout<<"�S�j�M"<<endl;
			break;
	}
}

