#include<iostream>
#include<string>
#include<fstream>
#include <bits/stdc++.h>
using namespace std;

class Admin{

  string username="bilal";
  string password = "123";

public:
  Admin(){}
  ~Admin() {}

  string getUserName()
  {
      return username;
  }
  string getPassword()
  {
      return password;
  }

  void CreateTeacher()
  {
      ofstream outf("distributerLogin.txt", ios::app);
      string name;
      string user;
      string pass;

      cout<<"Enter Name:\t";
      cin>>name;
      cout<<"\nEnter UserName:\t";
      cin>>user;
      cout<<"\nEnter Password:\t";
      cin>>pass;

      outf<<name << " " <<user << " " <<pass << endl;
      outf.close();
  }

  void Createcustomer()
  {
      ofstream outf("customerLogin.txt", ios::app);
      string name;
      string user;
      string pass;

      cout<<"Enter Name:\t";
      cin>>name;
      cout<<"\nEnter Roll Number:\t";
      cin>>user;
      cout<<"\nEnter Password:\t";
      cin>>pass;

      outf<<name << " " <<user << " " <<pass << endl;
      outf.close();

      char *a=new char[50];
      int j=0;
      j=user.length();
      for(int i=0;i<j;i++)
      {
          a[i]=user[i];

      }
      a[j]='\0';
      strcat(a,"_customerid.txt");
      ofstream outf2(a);
      outf2.close();





  }


};
