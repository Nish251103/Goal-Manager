#include<fstream>
#include<curses.h>
#include<string.h>
#include<stdio.h>
#include<iostream>

using namespace std;

class train
{
int id,tno,pno,price,cart;
char name[30],dest[30];
public:
int getid()
{
return id;
}
void info()
{
cout<<"\nEnter the data";
cin>>id>>name>>tno>>price>>pno>>cart>>dest;
}
void display()
{
cout<<"\n ID is :"<<id;
cout<<"\n Name is :"<<name;
cout<<"\n Ticket no is :"<<tno;
cout<<"\n Ticket price :"<<price;
cout<<"\n Plateform no is :"<<pno;
cout<<"\n Train cart no :"<<cart;
cout<<"\n Destination is :"<<dest;
cout<<"\n";
}

};
int main()
{
erase();
int idd;
char ch;
int choice;
train t;
do{
cout<<"\n\nenter the choice";
cout<<"\n 1.create the file";
cout<<"\n 2.read the file";
cout<<"\n 3.edit the file";
cout<<"\n 4.exit";
cin>>choice;
switch(choice)
{
case 1:
{
	ofstream fout;
	fout.open("train.dat",ios::binary|ios::out);
	do
	{
	t.info();
	fout.write((char *)&t,sizeof(t));
	cout<<"do you want to continue(y/n)";
	cin>>ch;
	}while(ch=='y');
	fout.close();
	cout<<"\nfile created";
	break;
}
case 2:
{
	ifstream fin;
	fin.open("train.dat",ios::binary);
	fin.seekg(0);
	while(fin.read((char *)&t,sizeof(t)))
	{
	t.display();
	}
	fin.close();
	break;
}
case 3:
{
	int flag=0;
	fstream f;
	cout<<"enter the id to be modified";
	cin>>idd;
	f.open("train.dat",ios::binary|ios::out|ios::in);
	f.seekg(0);
	while(f.read((char *)&t,sizeof(t)))
	{
	 if(idd==t.getid())
	 {
	  flag=1;
	  t.display();
	  cout<<"\n enter the data to be edit:";
	  f.seekp((-1)*sizeof(t),ios::cur);
	  t.info();
	  f.write((char *)&t,sizeof(t));
	  break;
	 }
	}
	if(flag==0)
	{
	cout<<"\n record not found";
	}
	f.close();
       /*	do
	{
	t.info();
	fout1.write((char *)&t,sizeof(t));
	cout<<"\n do you want to continue(y/n) :";
	cin>>ch;
	}while(ch=='y');
	fout1.close();
	cout<<"file created";*/
	break;
}
case 4:
{
	cout<<"exit";
	break;
}
}
}
while(choice!=4);

}