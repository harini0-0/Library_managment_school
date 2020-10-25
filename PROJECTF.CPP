#include<iostream.h>
#include<conio.h>
#include<graphics.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<process.h>
#include<iomanip.h>
#include<fstream.h>
void intro();
void modify();
void search();
void issuebk();
void dstudent();
void mstud();
void mbook();
void memp();
void mfine();
void sstudent();
void sbook();
void semployee();
void sfines();
void sintro();
float calcfine();
struct date
{
   int mm,dd,yy ;
}d1,d2,d3;

class dclass
{
   int grade;
   char sec,teacher[25];
   public:
   void inpt()
   {
      cout<<"Enter the class grade, section and teacher in-charge"<<endl;
      cin>>grade>>sec;
      gets(teacher);
   }
   void oupt()
   {
      cout<<grade<<sec<<setw(20)<<teacher<<endl;
   }
}cl,c;
class dstudent //for us to enter details of students,not display student record
{
    int rgno,roll,grade;
    char na[30],sec;
  public:
     void enter()
      {
	 cout<<"Enter regis no, roll no,name,grade,sec"<<endl;
	 cin>>rgno>>roll;
	 gets(na);
	 cin>>grade>>sec;
      }
     void display()
     {
	 cout<<rgno<<setw(10)<<roll<<setw(20)<<na<<setw(10)<<grade<<setw(10)<<" "<<sec<<endl;
     }
     int retrgno()
     {
     return(rgno);
     }
     char* retna()
     {
     return(na);
     }
}st,s;
class demployee1
{
    int ecode;
    char design[50],gen, ename[50];
    float sal;
    public:
    void inpt()
    {
      cout<<"Enter employ code,name,designation,salary and gender"<<endl;
      cin>>ecode;
      gets(ename);
      gets(design);
      cin>>sal;
      cin>>gen;
      cout<<endl;
    }
    void oupt()
    {
      cout<<ecode<<setw(10)<<ename<<setw(20)<<design<<setw(16);
      cout<<sal<<setw(6)<<" "<<gen<<endl;
    }
   int retecode()
   {
   return(ecode);
   }
}em,e;

class dbook
{
    int bcode,qty;
    char bname[25],aname[25],genre[25];
  public:

     void inpt()
      {
	 cout<<"Enter code,name,author,genre,qty";
	  cin>>bcode;
	 gets(bname);
	 gets(aname);
	 gets(genre);
	 cin>>qty;
      }
      void oupt()
      {
	       cout<<bcode<<setw(20)<<bname<<setw(20)<<aname<<setw(15)<<genre<<setw(10)<<qty<<endl;//setw(5);
	       /*if(ino==0)
	       cout<<"issued"<<endl;
	       else
	       cout<<"-"<<endl;   */
      }
     int retbcode()
     {
	return(bcode);
     }
     char* retna()
     {
     return(bname);
     }
}bk,b;

class dissues
{
     int bno,sno;
     char bna[25],sna[30];
     date d4,d5; //return date d5
   public:
       int inpt()
       {
	 int c;
	 cout<<"Enter the book code = ";
	 cin>>bno;
	 cout<<"Enter student grno = ";
	 cin>>sno;
	 date1();
	 date2();
	 c=assign();
	 return(c);
      }

  void date1()
 {
  cout<<"Enter the date of issue ";
  cin>>d4.dd;
  cin>>d4.mm;
  cin>>d4.yy;
 }
  void date2()
 {
  if(d4.dd<=15 && d4.mm!=2)
  {
  d5.dd=d4.dd+15;
  d5.mm=d4.mm;
  d5.yy=d4.yy;
  }
  else
  if(d4.dd>15 && d4.mm!=12 && d4.mm!=2)
  {
     d5.yy=d4.yy;
    if(d4.mm==4||d4.mm==6||d4.mm==9||d4.mm==11)
    {
     d5.mm=d4.mm+1;
     d5.dd=d4.dd-15;
    }
    if(d4.mm==1||d4.mm==3||d4.mm==5||d4.mm==7||d4.mm==8||d4.mm==10)
    {
     if(d4.dd!=16)
     {
	d5.mm=d4.mm+1;
	d5.dd=d4.dd-16;
     }
     else
     {
	d5.mm=d4.mm;
	d5.dd=31;
     }
    }
  }
  else
  if(d4.mm==12)
  {
   if(d4.dd>16)
   {
     d5.mm=1;
     d5.dd=d4.dd-16;
     d5.yy=d4.yy+1;
   }
   else
   {
     d5.mm=d4.mm;
     d5.dd=31;
     d5.yy=d4.yy;
   }
  }
  else
  if(d4.mm==2)
  {
   d5.yy=d4.yy;
   if(d4.dd<14)
   {
   d5.mm=2;
   d5.dd=d4.dd+15;
   }
   else
   {
   d5.mm=d4.mm+1;
   d5.dd=d4.dd-13;
   }
  }
 }
 int assign()
 {
   ifstream f5,f6;int f=0;
   f5.open("student.dat",ios::binary);
   f6.open("book.dat",ios::binary);
   while(f5.read((char*)&st,sizeof(st)))
   {
   if(st.retrgno()==sno)
   {
     strcpy(sna,st.retna());
     f=1;
     break;
   }
   }
   while(f6.read((char*)&bk,sizeof(bk)))
   {
      if(f==1)
      {
	 if(bk.retbcode()==bno)
	 {
	     getche();
	     strcpy(bna,bk.retna());
	     break;
	  }
       }
    }
   f5.close();
   f6.close();
   return(f);
 }
 float calculate(date d6) //d6 is today's date and d5 is original returning date  and d4 is issued date
 {
 int day=0,m,y;
 float x;
 m=d5.mm;
 y=d5.yy;
 while(y<d6.yy)
 {
 day+=365;
 y++;
 }
 if(y==d6.yy)
 {
 while(m<d6.mm)
 {
  if(m==1||m==3||m==5||m==7||m==8||m==10||m==12)
  {
  day+=31;
  }
  else
  if(m==2)
  day+=28;
  else
  {
  day+=30;
  }
  m++;
 }
 if(m==d6.mm)
 {
 day+=(d6.dd-d5.dd);
 }
 }
 x=day*0.5;
 return(x);
 }
 void display()
 {
  cout<<sno<<setw(22)<<sna<<setw(10)<<bno<<setw(20)<<bna<<setw(10);
  cout<<d5.dd<<"-"<<d5.mm<<"-"<<d5.yy<<endl;

 }
 int retbno()
 {
      return(bno);
 }
 int retsno()
 {
     return(sno);
 }
}i,is;
//----------------------------------------------------------------------------------------------------
//function of the project
//-----------------------------------------------------------------------------------------------------

void demployee()
{
   clrscr();
   demployee1 ee;
   ifstream f2;
   f2.open("employ.dat",ios::binary);
   cout<<"--------------------------------------------------------------------------------";
   cout<<"code"<<setw(10)<<"name"<<setw(19)<<"deisgnation"<<setw(17)<<"salary"<<setw(10)<<"gender"<<endl;
   cout<<"________________________________________________________________________________";
   while(f2.read((char*)&ee,sizeof(ee)))
   {
      ee.oupt();
   }
   f2.close();
   getch();
}

void dclass()
{
    clrscr();
    int n;
    ifstream f2;
    f2.open("class.dat",ios::binary);
    cout<<"---------------------------"<<endl;
    cout<<"class"<<setw(17)<<"teacher"<<endl;
    cout<<"---------------------------"<<endl;
    while(f2.read((char*)&cl,sizeof(cl)))
    cl.oupt();
    f2.close();
    getch();
}

void dstudent()
{
   clrscr();
   ifstream f2;
   cout<<"Regis No"<<setw(10)<<"Roll no"<<setw(10)<<"Name"<<setw(17)<<"Grade"<<setw(12)<<"Section"<<endl;
   f2.open("student.dat",ios::binary);
   while(f2.read((char*)&st,sizeof(st)))
   {
      st.display();
   }
   f2.close();
   getch();
}

void dbook()
{
 clrscr();
 ifstream f2;
 cout<<"code"<<setw(17)<<"name"<<setw(20)<<"author"<<setw(15)<<"genre"<<setw(10)<<"quantity"<<endl;
 f2.open("book.dat",ios::binary);
 while(f2.read((char*)&bk,sizeof(bk)))
  {
   bk.oupt();
  }
 f2.close();
 getch();
}
void dissue()
{
 clrscr();
 ifstream f2;
 cout<<"-------------------------------------------------------------------------------"<<endl;
 cout<<"stud grno"<<setw(16)<<"stud name"<<setw(10)<<"bookcode"<<setw(20)<<"bookname"<<setw(18)<<"return date"<<endl;
 cout<<"_______________________________________________________________________________"<<endl;
 f2.open("issues.dat",ios::binary);
 while(f2.read((char*)&i,sizeof(i)))
  {
   i.display();
  }
 f2.close();
 getch();
}

void displaydetails()
{
   clrscr();
   cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
   cout<<"                          DISPLAY DETAILS"<<endl;
   cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
   int c;
   cout<<"1.Book Details"<<endl;
   cout<<"2.Student Records"<<endl;
   cout<<"3.Issues"<<endl;
   cout<<"4.Employee Records"<<endl;
   cout<<"5.Class List"<<endl;
   cout<<"6.Return to main menu"<<endl;
   cout<<"Enter your choice"<<endl;
   cin>>c;
   switch(c)
   {
     case 1: dbook();
	     displaydetails();
	     break;

      case 2: dstudent();
	      displaydetails();
	      break;

      case 3: dissue();
	      displaydetails();
	      break;

      case 4: demployee();
	      displaydetails();
	      break;

      case 5: dclass();
	      displaydetails();
	      break;

      case 6: intro();
	      break;
   }
}
void add()
{
    clrscr();
    int ch;
    fstream f1;
    cout<<"------------------------------------------------------------------------"<<endl;
    cout<<"                                       ADD DETAILS                      "<<endl;
    cout<<"------------------------------------------------------------------------"<<endl;
    cout<<"1.Student Details"<<endl;
    cout<<"2.Book Details"<<endl;
    cout<<"3.Employee Details"<<endl;
    cout<<"4.Class Details"<<endl;
    cout<<"5.Return To Modify menu"<<endl;
    cout<<"Enter your choice"<<endl;
    cin>>ch;
    switch(ch)
    {
       case 1: f1.open("student.dat",ios::binary|ios::app);
	       s.enter();
	       f1.write((char*)&s,sizeof(s));
	       f1.close();
	       dstudent();
	       add();
	       break;

       case 2: f1.open("book.dat",ios::binary|ios::app);
	       b.inpt();
	       f1.write((char*)&b,sizeof(b));
	       f1.close();
	       dbook();
	       add();
	       break;

       case 3: f1.open("employ.dat",ios::binary|ios::app);
	       e.inpt();
	       f1.write((char*)&e,sizeof(e));
	       f1.close();
	       demployee();
	       add();
	       break;

       case 4: f1.open("class.dat",ios::binary|ios::app);
	       c.inpt();
	       f1.write((char*)&c,sizeof(c));
	       f1.close();
	       dclass();
	       add();
	       break;

       case 5: modify();
	       break;

}

}


void del()
{
clrscr();
    int ch,n;ofstream f1;ifstream f2;
    cout<<"------------------------------------------------------------------------------"<<endl;
    cout<<"                                       REMOVE RECORDS                                         "<<endl;
    cout<<"-----------------------------------------------------------------------------"<<endl;
    cout<<"1.Student Details"<<endl;
    cout<<"2.Book Details"<<endl;
    cout<<"3.Employee Details"<<endl;
    cout<<"4.Return To Modify Function"<<endl;
    cout<<"5.Return to Main Menu"<<endl;
    cout<<"Enter your choice"<<endl;
    cin>>ch;
    clrscr();
    switch(ch)
    {
       case 1: cout<<"Enter Grno. to be deleted";
	       cin>>n;
	       //dstudent s;
	       f1.open("New.dat",ios::binary);
	       f2.open("STUDENT.dat",ios::binary);
	       while(f2.read((char*)&s,sizeof(s)))
	       {
		  if(s.retrgno()!=n)
		     f1.write((char*)&s,sizeof(s));
	       }
	       f1.close();
	       f2.close();
	       remove("STUDENT.dat");
	       rename("New.dat","STUDENT.dat");
	       dstudent();
	       del();
	       break;

       case 2: cout<<"Enter Book's code to be deleted";
	       cin>>n;
	       //dbook b;
	       f1.open("New.dat",ios::binary);
	       f2.open("book.dat",ios::binary);
	       while(f2.read((char*)&b,sizeof(b)))
	       {
		  if(b.retbcode()!=n)
		     f1.write((char*)&b,sizeof(b));
	       }
	       f1.close();
	       f2.close();
	       remove("book.dat");
	       rename("New.dat","book.dat");
	       dbook();
	       del();
	       break;

       case 3: cout<<"Enter Employ's code to be deleted";
	       cin>>n ;
	       //demployee e;
	       f1.open("New.dat",ios::binary);
	       f2.open("employ.dat",ios::binary);
	       while(f2.read((char*)&e,sizeof(e)))
	       {
		  if(e.retecode()!=n)
		     f1.write((char*)&e,sizeof(e));
	       }
	       f1.close();
	       f2.close();
	       remove("employ.dat");
	       rename("New.dat","employ.dat");
	       del();
	       break;

       case 4: modify();
	       break;

       case 5:intro();
	      break;
}
}
void mod()
{
    clrscr();
    int ch,n;
    ofstream f1;
    f1.open("new.dat",ios::binary);
    ifstream f2;
    cout<<"------------------------------------------------------------------------------"<<endl;
    cout<<"                                       MODIFY DETAILS                                         "<<endl;
    cout<<"-----------------------------------------------------------------------------"<<endl;
    cout<<"1.Student Details"<<endl;
    cout<<"2.Book Details"<<endl;
    cout<<"3.Employee Details"<<endl;
    cout<<"4.Return To Modify menu"<<endl;
    cout<<"5.Return to Main Menu"<<endl;
    cout<<"Enter your choice"<<endl;
    cin>>ch;
    clrscr();
    switch(ch)
    {
       case 1: cout<<"Enter Grno. to be modified";
	       cin>>n;
	       f2.open("student.dat",ios::binary);
	       while(f2.read((char*)&s,sizeof(s)))
	       {
		if(s.retrgno()==n)
		  {
		    s.enter();
		  }
		    f1.write((char*)&s,sizeof(s));
		}
		f1.close();
		f2.close();
		remove("student.dat");
		rename("new.dat","student.dat");
		cout<<"\n\n\t Record Updated";
		dstudent();
		mod();
		break;

       case 2: cout<<"Enter Bcode to modifiy";
	       cin>>n;
	       f2.open("book.dat",ios::binary);
	       while(f2.read((char*)&b,sizeof(b)))
	       {
		if(b.retbcode()==n)
		 {
		  b.inpt();
		 }
	       f1.write((char*)&b,sizeof(b));
	       }
	       f1.close();
	       f2.close();
	       remove("book.dat");
	       rename("new.dat","book.dat");
	       cout<<"\n\n\t Record Updated";
	       dbook();
	       mod();
	       break;

       case 3: cout<<"Enter Ecode to be modified";
	       cin>>n ;
	       f2.open("employ.dat",ios::binary);
	       while(f2.read((char*)&e,sizeof(e)))
	       {
	       if(e.retecode()==n)
		  {
		    e.inpt();
		  }
		   f1.write((char*)&e,sizeof(e));
	       }
	       f1.close();
	       f2.close();
	       remove("employ.dat");
	       rename("new.dat","employ.dat");
	       cout<<"\n\n\t Record Updated";
	       demployee();
	       mod();
	       break;

       case 4: modify();
	       break;

       case 5:intro();
	      break;
    }
}
void modify()
{
  clrscr();
  cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
  cout<<"                          MODIFY RECORDS"<<endl;
  cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
  cout<<"1.Enter Record details "<<endl;
  cout<<"2.Eliminate Records"<<endl;
  cout<<"3.Modify Records"<<endl;
  cout<<"4.Back to Main Menu"<<endl;
  cout<<"Enter your option"<<endl;
  int c;
  cin>>c;
  switch(c)
   {
    case 1 : add();
	     break;

    case 2 : del();
	     break;

    case 3 : mod();
	     break;

    case 4 : intro();
	     break;
   }
}

void semployee()
 {
  clrscr();
  ifstream f1;
  demployee1 ee;
  int s;
  char ch='n',o;
  cout<<"enter the employ code";
  cin>>s;
  f1.open("employ.dat",ios::binary);
  while(f1.read((char*)&ee,sizeof(ee)))
  {
    if(ee.retecode()==s)
    {
     cout<<"--------------------------------------------------------------------------------";
     cout<<"code"<<setw(10)<<"name"<<setw(19)<<"deisgnation"<<setw(17)<<"salary"<<setw(10)<<"gender"<<endl;
     cout<<"________________________________________________________________________________";
     ee.oupt();
     ch='y';
    }
  }
  f1.close();
  if(ch=='n')
  {
    cout<<"employ not found"<<endl;
    cout<<"retry searching employee?-y/n"<<endl;
    cin>>o;
    if(o=='y')
    {
      semployee();
    }
    else
    {
     search();
    }
  }
  else
  {
    cout<<endl;
    cout<<"retry searching employee?-y/n"<<endl;
    cin>>o;
    if(o=='y')
    {
      semployee();
    }
    else
    {
     search();
    }
  }
}
void sissues()
 {
    clrscr();
    ifstream f1;
    int s,found=0;
    char ch='n',o;
    cout<<"Enter the book code ";
    cin>>s;
    f1.open("issues.dat",ios::binary);
  while(f1.read((char*)&i,sizeof(i)))
  {
    if(i.retbno()==s)
    {
      if(found==0)
      {
      cout<<"-------------------------------------------------------------------------------"<<endl;
      cout<<"Stud grno"<<setw(16)<<"Stud name"<<setw(10)<<"Bookcode"<<setw(20)<<"Bookname"<<setw(18)<<"return date"<<endl;
      cout<<"_______________________________________________________________________________"<<endl;
      }
      i.display();
      found=1;
      ch='y';
    }
  }
  f1.close();
  if(ch=='n')
  {
    cout<<"info not found"<<endl;
    cout<<"Retry searching issue?-y/n"<<endl;
    cin>>o;
    if(o=='y')
    {
      sissues();
    }
    else
    {
     search();
    }
  }
  else
  {
    cout<<endl;
    cout<<"retry searching issue?-y/n"<<endl;
    cin>>o;
    if(o=='y')
    {
      sissues();
    }
    else
    {
     search();
    }
  }
}
void sbooks()
 {
    clrscr();
    ifstream f1;

    int s;
    char ch='n',o;
    cout<<"Enter the book code";
    cin>>s;
    f1.open("book.dat",ios::binary);
  while(f1.read((char*)&bk,sizeof(bk)))
  {
    if(bk.retbcode()==s)
    {
       cout<<"--------------------------------------------------------------------------------";
       cout<<"code"<<setw(17)<<"name"<<setw(20)<<"author"<<setw(15)<<"genre"<<setw(10)<<"quantity"<<endl;
       cout<<"--------------------------------------------------------------------------------"<<endl;
       bk.oupt();
       ch='y';
    }
  }
  f1.close();
  if(ch=='n')
  {
    cout<<"Book not found"<<endl;
    cout<<"Retry searching Book?-y/n"<<endl;
    cin>>o;
    if(o=='y')
    {
      sbooks();
    }
    else
    {
     search();
    }
  }
  else
  {
    cout<<endl;
    cout<<"retry searching book?-y/n"<<endl;
    cin>>o;
    if(o=='y')
    {
      sbooks();
    }
    else
    {
     search();
    }
  }
}

void sstudent()
 {
    clrscr();
    ifstream f1;

    int s;
    char ch='n',o;
    cout<<"Enter the Student Registration Number";
    cin>>s;
    f1.open("student.dat",ios::binary);
  while(f1.read((char*)&st,sizeof(st)))
  {
    if(st.retrgno()==s)
    {
       cout<<"--------------------------------------------------------------------------------";
       cout<<"GR No"<<setw(10)<<"Roll No."<<setw(8)<<"Name"<<setw(22)<<"Grade"<<setw(9)<<"    Section"<<endl;
       cout<<"--------------------------------------------------------------------------------"<<endl;
     st.display();
     ch='y';
    }
  }
  f1.close();
  if(ch=='n')
  {
    cout<<"Student not found"<<endl;
    cout<<"Retry searching student?-y/n"<<endl;
    cin>>o;
    if(o=='y')
    {
      sstudent();
    }
    else
    {
     search();
    }
  }
  else
  {
    cout<<endl;
    cout<<"retry searching student?-y/n"<<endl;
    cin>>o;
    if(o=='y')
    {
      sstudent();
    }
    else
    {
     search();
    }
  }
}


void search()
{
  clrscr();
  int x;
  cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
  cout<<"                              SEARCH RECORDS"<<endl;
  cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
  cout<<"1.Student Records"<<endl;
  cout<<"2.Book Records"<<endl;
  cout<<"3.Employee Records"<<endl;
  cout<<"4.issues"<<endl;
  cout<<"5.Return to main menu "<<endl;
  cout<<" Enter your option "<<endl;
  cin>>x;
   switch(x)
   {
     case 1: sstudent();
	     break;

     case 2: sbooks();
	     break;

     case 3: semployee();
	     break;

     case 4: sissues();
	     break;

     case 5: intro();
	     break;
   }
 }
void issuebk()
{
 clrscr();
 int c=0;char ch='y';
 cout<<"*************************ISSUING BOOK***********************"<<endl<<endl;
 fstream f1;
 f1.open("issues.dat",ios::binary|ios::app);
 while(ch=='y')
  {
   c=i.inpt();
   if(c!=0)
   f1.write((char*)&i,sizeof(i));
   else
   cout<<"Invalid Grno"<<endl;
   cout<<"Do you want to issue one more book? -y/n";
   cin>>ch;
  }
 f1.close();
 clrscr();
 ifstream f2;
 f2.open("issues.dat",ios::binary);
 cout<<"-------------------------------------------------------------------------------"<<endl;
 cout<<"stud grno"<<setw(16)<<"stud name"<<setw(10)<<"bookcode"<<setw(20)<<"bookname"<<setw(18)<<"return date"<<endl;
 cout<<"_______________________________________________________________________________"<<endl;
 while(f2.read((char*)&i,sizeof(i)))
  {
   i.display();
  }
 f2.close();
 getch();
 intro();
}

void intro()//mainmenu
{
    clrscr();
    int ch,n,t;
    float fine;
    cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
    cout<<"                                   MAIN MENU "<<endl;
    cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
    cout<<"1.Issue a book"<<endl;
    cout<<"2.Display record details"<<endl;
    cout<<"3.Modify records"<<endl;
    cout<<"4.Search records details"<<endl;
    cout<<"5.deposit book"<<endl;
    cout<<"6.Exit"<<endl;
    cout<<"Enter your option:-";
    cin>>ch;
    switch(ch)
    {
     case 1:issuebk();
	    break;

     case 2:displaydetails();
	    break;

     case 3:modify();
	    break;

     case 4: search();
	     break;

     case 5:   clrscr();
	       date d6;
	       ofstream f1;ifstream f2;
	       cout<<"***************************BOOK DEPOSITING***************************"<<endl<<endl;
	       f1.open("new.dat",ios::binary);
	       cout<<"Enter book code and student grno"<<endl;
	       cin>>n>>t;
	       cout<<"Enter today's date"<<endl;
	       cin>>d6.dd>>d6.mm>>d6.yy;
	       f2.open("issues.dat",ios::binary);
	       while(f2.read((char*)&is,sizeof(is)))
	       {
		if(is.retbno()==n && is.retsno()==t)
		     fine=is.calculate(d6);
		else
		if(is.retbno()!=n||is.retsno()!=t)
		     f1.write((char*)&is,sizeof(is));
		}
		f1.close();
		f2.close();
		if(fine<0)
		fine=0;
		remove("issues.dat");
		rename("new.dat","issues.dat");
		cout<<"Fine to be paid :"<<fine<<"Dhs"<<endl;
		cout<<"***Book deposited***";
		getch();
		intro();

		break;


     case 6:exit(0);
    }

}
void check()
{
    clrscr();
    char c[]={"incorrect"};
    char f[10];
    cout<<"enter password"<<endl;
    for(int i=0;i<9;i++)
    {
	 f[i]=getch();
	 cout<<"*";
    }
    f[i]='\0';
    if( strcmp(c,f)==0)
	  intro();
    else
    {
      cout<<"password incorrect";
      getch();
      exit(0);
    }
}

void main()
{
   clrscr();
   int gd=DETECT,gm;
   initgraph(&gd,&gm,"C:\\TurboC3\\BGI");
   setbkcolor(BLUE);
   settextstyle(GOTHIC_FONT,HORIZ_DIR,4);
   outtextxy(0,25,"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
   outtextxy(80,60,"LIBRARY MANAGEMENT");
   outtextxy(0,90,"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
   outtextxy(0,130,"-----------------------------------------------");
   outtextxy(110,180,"COMPUTER PROJECT");
   outtextxy(0,190,"_______________________________________________");
   outtextxy(125,250,"DONE BY:");
   outtextxy(140,290,"->HARINI");
   outtextxy(140,330,"->PAARGAVI M  SELVAN");
   outtextxy(140,370,"->RAMA ALAMELU");
   outtextxy(140,410,"->SANIA EJAZ ");
   getche();
   closegraph();
   check();
}
