#include<iostream.h>
#include<conio.h>
#include<string.h>
#include<fstream.h>
#include<stdio.h>

int sum=0;

class log
{public:
	char username[20], pswd[20];

	void getdata()
	       {int i;
	       char a;
	       cin>>username;
	       for(i=0; ; )
	       {a=getch();
	       if((a>='a'&&a<='z')||(a>='A'&&a<='Z')||(a>='0' &&a<='9'))
			{pswd[i]=a;
			 ++i;
			 cout<<"*";
			 }
	       if(a=='\r')
			{pswd[i]='\0';
			break;
			}
		}
		}
	void putdata()
	       {cout<<username<<pswd;
	       }
};

class resort
{int rno, cost, days;
char name[10], type[10];
long id;
public:
	void getdata()
	{cout<<"\nEnter Room no, Name, ID, Type and Days"<<endl;
	cin>>rno>>name>>id>>type>>days;
	}

	void putdata()
	{cout<<"\nDetails are:"<<endl;
	cout<<"Room no: "<<rno<<endl;
	cout<<"Name: "<<name<<endl;
	cout<<"ID: "<<id<<endl;
	cout<<"Type: "<<type<<endl;
	cout<<"Days: "<<days<<endl;
	}

	int getrno()
	{return (rno);
	}

	int getdays()
	{return(days);
	}

	char* gettype()
	{return(type);
	}

	long getid()
	{return(id);
	}

	char* getname()
	{return(name);
	}
};

void checkin();
void checkout();
void checkoutrno();
void checkoutname();
void display();
void dispall();
void dispname();
void disprno();
void dispid();
void change();
void changerno();
void changedet();
void totearn();

void checkin()
{fstream fin;
fin.open("resort.dat", ios::app);
resort r;
int n, i;
cout<<"\nEnter no of guests"<<endl;
cin>>n;
for (i=0; i<n; i++)
	{r.getdata();
	fin.write((char*)&r, sizeof(r));
	}
fin.close();
}

void checkout()
{int ch;
do
{cout<<"\nMenu: "<<endl;
cout<<"1. Checkout by room no "<<endl;
cout<<"2. checkout by name "<<endl;
cout<<"3. Exit"<<endl;
cout<<"\nChoose your option"<<endl;
cin>>ch;
switch(ch)
	{case 1: checkoutrno();
		break;
	case 2: checkoutname();
		break;
	}
}while (ch<=2);
}

void display()
{int ch;
do
{cout<<"\nMenu:"<<endl;
cout<<"1. Display all"<<endl;
cout<<"2. Display by name"<<endl;
cout<<"3. Display by room no"<<endl;
cout<<"4. Display by ID"<<endl;
cout<<"5. Exit"<<endl;
cout<<"\nChoose your option"<<endl;
cin>>ch;
switch(ch)
	{case 1: dispall();
		break;
	case 2: dispname();
		break;
	case 3: disprno();
		break;
	case 4: dispid();
		break;
	}
}while(ch<=4);
}

void dispall()
{fstream fdisp("resort.dat", ios::in);
resort r;
while (fdisp.read((char*)&r, sizeof(r)))
	{r.putdata();
	cout<<endl;
	}
fdisp.close();
}

void dispname()
{fstream fdisp("resort.dat", ios::in);
resort r;
char nm[10];
cout<<"\nEnter the name to be searched"<<endl;
cin>>nm;
while(fdisp.read((char*)&r, sizeof(r)))
	if(strcmpi(r.getname(),nm)==0)
		r.putdata();
fdisp.close();
}

void disprno()
{fstream fdisp ("resort.dat", ios::in);
resort r;
int no;
cout<<"\nEnter room no to be searched"<<endl;
cin>>no;
while(fdisp.read((char*)&r, sizeof(r)))
	if(no==r.getrno())
		r.putdata();
fdisp.close();
}

void dispid()
{fstream fdisp ("resort.dat", ios::in);
resort r;
long no;
cout<<"\nEnter ID to be searched"<<endl;
cin>>no;
while(fdisp.read((char*)&r, sizeof(r)))
	if(no==r.getid())
		r.putdata();
fdisp.close();
}

void checkoutrno()
{int ch;
ifstream fin ("resort.dat");
ofstream fout("temp.dat");
resort r;
int no;
cout<<"\nEnter room no to check out"<<endl;
cin>>no;
while(fin.read((char*)&r, sizeof(r)))
	if(no==r.getrno())
		{if(strcmpi(r.gettype(),"standard")==0)
			{cout<<"\nAmt= "<<r.getdays()*1000<<endl;
			sum=sum+(r.getdays()*1000);
			}
		else
		       {cout<<"\nAmt= "<<r.getdays()*1500<<endl;
		       sum=sum+(r.getdays()*1500);
			}
		do
			{cout<<"\nPaid?"<<endl;
			cout<<"1. Yes"<<endl;
			cout<<"2. No"<<endl;
			cout<<"3. Transaction done"<<endl;
			cout<<"\nEnter your option"<<endl;
			cin>>ch;
			switch(ch)
				{case 1: {cout<<"\nChecked out"<<endl;
					while(fin.read((char*)&r, sizeof(r)))
						if(no!=r.getrno())
							fout.write((char*)&r, sizeof(r));
					fin.close();
					fout.close();
					remove ("resort.dat");
					rename("temp.dat","resort.dat");
					}
					break;
				case 2: cout<<"\nPlease complete payment"<<endl;
					break;
				}
			}while(ch<=2);
			}
	else
		cout<<"\nNo such room"<<endl;
}

void checkoutname()
{int ch;
ifstream fin ("resort.dat");
ofstream fout("temp.dat");
resort r;
char nm[10];
cout<<"\nEnter name to check out with"<<endl;
cin>>nm;
while(fin.read((char*)&r, sizeof(r)))
	if(strcmpi(nm,r.getname())==0)
		{if(strcmpi(r.gettype(),"standard")==0)
			{cout<<"Amt= "<<r.getdays()*1000<<endl;
			sum=sum+(r.getdays()*1000);
			}
		else
			{cout<<"Amt= "<<r.getdays()*1500<<endl;
			sum=sum+(r.getdays()*1500);
			}
		do
		{cout<<"\nPaid?"<<endl;
		cout<<"1. Yes"<<endl;
		cout<<"2. No"<<endl;
		cout<<"3. Transaction done"<<endl;
		cout<<"\nEnter your option"<<endl;
		cin>>ch;
		switch(ch)
			{case 1: {cout<<"Checked out"<<endl;
				while(fin.read((char*)&r, sizeof(r)))
					if(strcmp(nm,r.getname())!=0)
						fout.write((char*)&r, sizeof(r));
				fin.close();
				fout.close();
				remove ("resort.dat");
				rename("temp.dat","resort.dat");
				}
				break;

			case 2: cout<<"\nPlease complete payment"<<endl;
				break;
			}
		}while(ch<=2);
		}
}

void change()
{int ch;
do
{cout<<"\nMenu:"<<endl;
cout<<"1. Change room no"<<endl;
cout<<"2. Change personal details"<<endl;
cout<<"3. Exit"<<endl;
cout<<"\nChoose your option"<<endl;
cin>>ch;
switch (ch)
	{case 1: changerno();
		break;
	case 2: changedet();
		break;
	}
}while (ch<=2);
}

void changerno()
{int pos, no;
resort r,s;
fstream fin("resort.dat", ios::in|ios::out);
cout<<"\nEnter room no to be changed"<<endl;
cin>>no;
while(fin.read((char*)&r, sizeof(r)))
	if(no==r.getrno())
		{r.putdata();
		pos=fin.tellg();
		fin.seekp(pos-sizeof(r), ios::beg);
		cout<<"\nEnter new room no with previous details"<<endl;
		s.getdata();
		fin.write((char*)&s, sizeof(s));
		}
fin.close();
}

void changedet()
{int pos;
char nm[10];
resort r,s;
fstream fin("resort.dat", ios::in|ios::out);
cout<<"\nEnter name to be changed"<<endl;
cin>>nm;
while(fin.read((char*)&r, sizeof(r)))
	if(strcmpi(nm,r.getname())==0)
		{r.putdata();
		pos=fin.tellg();
		fin.seekp(pos-sizeof(r), ios::beg);
		cout<<"\nEnter new details with previous room no"<<endl;
		s.getdata();
		fin.write((char*)&s, sizeof(s));
		}
fin.close();
}

void create()
{fstream fout ("login.dat", ios::out);
log l;
int ch;
cout<<"\nEnter username and password"<<endl;
l.getdata();
fout.write((char*)&l, sizeof(l));
do
{cout<<"\nMenu"<<endl;
cout<<"1. Check in"<<endl;
cout<<"2. Check out"<<endl;
cout<<"3. Display"<<endl;
cout<<"4. Change"<<endl;
cout<<"5. Total earnings"<<endl;
cout<<"6. Exit"<<endl;
cout<<"\nEnter your option"<<endl;
cin>>ch;
switch (ch)
	{case 1: checkin();
		break;
	case 2: checkout();
		break;
	case 3: display();
		break;
	case 4: change();
		break;
	case 5: totearn();
		break;
	}
}while(ch<=5);
fout.close();
}

void login()
{fstream fin ("login.dat",ios::in);
log l, c;
int ch;
cout<<"\nEnter username and password"<<endl;
c.getdata();
while(fin.read((char*)&l, sizeof(l)))
	if(strcmpi(l.username,c.username)==0&&strcmpi(l.pswd,c.pswd)==0)
		{do
		{cout<<"\nMenu"<<endl;
		cout<<"1. Check in"<<endl;
		cout<<"2. Check out"<<endl;
		cout<<"3. Display"<<endl;
		cout<<"4. Change"<<endl;
		cout<<"5. Total earnings"<<endl;
		cout<<"6. Exit"<<endl;
		cout<<"\nEnter your option"<<endl;
		cin>>ch;
		switch (ch)
			{case 1: checkin();
				break;
			case 2: checkout();
				break;
			case 3: display();
				break;
			case 4: change();
				break;
			case 5: totearn();
				break;
			}
		}while(ch<=5);
		}
	else
		cout<<"\nNo such account"<<endl;
fin.close();
}

void totearn()
{cout<<"\nTotal earning for the day is   "<<sum<<endl;
}

void main()
{clrscr();
int ch;
do{
	cout<<"\n \n \t \t \t Welcome to Alila Diwa Resort"<<endl;
	cout<<"\nMenu:"<<endl;
	cout<<"1. Login"<<endl;
	cout<<"2. Create account"<<endl;
	cout<<"3. Exit"<<endl;
	cout<<"\nChoose your option"<<endl;
	cin>>ch;
	switch (ch)
		{case 1: login();
			break;
		case 2: create();
			break;
		}
}while(ch<=2);
getch();
}