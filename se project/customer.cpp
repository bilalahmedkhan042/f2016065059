#include<iostream>
#include"StudentCourse.cpp"
#include<string>

#include <bits/stdc++.h>
#include<fstream>

using namespace std;
class customer
{
    string name;
    string id;
    string pass;
public:
    customer ()
    {
        name="";
        id="";
        pass="";
    }
    ~customer(){ }
    void setname(string n)
    {
        name=n;
    }
    string getname()
    {
        return name;
    }
    void setid(string r)
    {
        id = r;
    }
    string getid()
    {
        return id;
    }
    void setpass(string p)
    {
        pass = p;
    }
    string getpass()
    {
        return pass;
    }

    void getCreatedfilm(filmname c1[])
    {
        filmname c;
        //Course c1[10];

        ifstream inf("Course.txt");
        if(!inf.is_open())
        {
            cout<<"No course created yet to delete.";
        }
        else
        {
            int i=0;
            while(!inf.eof())
            {
                string n;
                inf >> n;
                c.setqfilmName(n);
                inf >> n;
                c.setqdistributerName(n);
                inf >> n;
                c.setqdistributerUserName(n);

                c1[i] = c;
                i++;
            }
        }
        inf.close();
    }

    int getTotalCoursesCreated()
    {
        filmname c;
        int i=0;

        ifstream inf("Course.txt");
        if(!inf.is_open())
        {
            cout<<"No course created yet to delete.";
        }
        else
        {
            while(!inf.eof())
            {
                string n;
                inf >> n;
                c.setqfilmName(n);
                inf >> n;
                c.setqdistributerName(n);
                inf >> n;
                c.setqdistributerUserName(n);

                i++;
            }
            //i--;
        }
        inf.close();
        return i;
    }

    void watchedmovies()
    {
        int numberOffilms = getTotalCoursesCreated();
        filmname c[numberOffilms];
        getCreatedfilm(c);
        int j=1;

        if(c[0].getqfilmName() == "")
        {
            cout << "No course created yet." << endl;
        }
        else
        {
            for(int i=0;i< numberOffilms;i++)
            {
                if(c[i].getqfilmName() == "")
                {
                    break;
                }
                else
                {
                    cout << j << ". " << c[i].getqfilmName() << "  " << c[i].getqdistributerUserName() <<endl;
                    j++;
                }
            }

            int choice;
            cout << "Enter which course you want to enroll:\t";
            cin >> choice;

            char *filmName = new char[50];
            char *fn = new char[50];
            string s = c[choice-1].getqfilmName();
            int len = s.length();

            for(int i=0;i<len;i++)
            {
                fn[i] = s[i];
            }
            fn[len] = '\0';

            strcpy(filmName , fn);

            strcat(fn, "_");
            s = c[choice-1].getqdistributerUserName();
            len = s.length();
            int len1 = strlen(fn);

            char *distributerUserName=new char[50];
            for(int i=0;i<len;i++)
            {
                distributerUserName[i] = s[i];
            }
            distributerUserName[len] = '\0';
            strcat(fn,distributerUserName);
            strcat(fn, ".txt");

            ofstream outf(fn , ios::app);

            outf << name << " " << id << endl;
            outf.close();

            string abc = c[choice-1].getqdistributerName();
            len = abc.length();
            char *distributerName=new char[50];
            for(int i=0;i<len;i++)
            {
                distributerName[i] = abc[i];
            }
            distributerName[len] = '\0';
            strcat(fn,distributerName);
            strcat(fn, ".txt");



              char *a=new char[50];
              int j=0;
              j=id.length();
              for(int i=0;i<j;i++)
              {
                  a[i]=id[i];

              }
              a[j]='\0';
              strcat(a,"_id.txt");
              ofstream outf2(a,ios::app);
              outf2<< filmName << " " << distributerName << " " << distributerUserName << endl;
              outf2.close();


            //delete fn;
        }
    }


    int getTotalEnrolledCourses()
    {
        filmname c;
        int i=0;

        char *a=new char[50];
        int j=0;
        j=id.length();
        for(int i=0;i<j;i++)
        {
            a[i]=id[i];
        }
        a[j]='\0';
        strcat(a,"_id.txt");

        ifstream inf(a);
        if(!inf.is_open())
        {
            cout<<"No course created yet to delete. (GetTotalEnrolledCourses)";
        }
        else
        {
            while(!inf.eof())
            {
                string n;
                inf >> n;
                c.setqfilmName(n);
                inf >> n;
                c.setqdistributerName(n);
                inf >> n;
                c.setqdistributerUserName(n);

                i++;
            }
            //i--;
        }
        inf.close();
        return i;
    }

    void getEnrolledCourses(filmname c1[])
    {
        filmname c;

        char *a=new char[50];
        int j=0;
        j=id.length();
        for(int i=0;i<j;i++)
        {
            a[i]=id[i];
        }
        a[j]='\0';
        strcat(a,"_id.txt");

        ifstream inf(a);
        if(!inf.is_open())
        {
            cout<<"No course created yet to delete. (getEnrolledCourses)";
        }
        else
        {
            int i=0;
            while(!inf.eof())
            {
                string n;
                inf >> n;
                c.setqfilmName(n);
                inf >> n;
                c.setqdistributerName(n);
                inf >> n;
                c.setqdistributerUserName(n);

                c1[i] = c;
                i++;
            }
        }
        inf.close();
    }

    void UnEnroll()
    {
        char *a=new char[50];
        int l=0;
        l=id.length();
        for(int i=0;i<l;i++)
        {
            a[i]=id[i];
        }
        a[l]='\0';
        strcat(a,"_id.txt");

        int numberOfCourses = getTotalEnrolledCourses();
        filmname c[numberOfCourses];
        getEnrolledCourses(c);
        int j=1;

        if(c[0].getqfilmName() == "")
        {
            cout << "No course created yet.(UnEnroll)" << endl;
        }
        else
        {
            for(int i=0;i< numberOfCourses;i++)
            {
                if(c[i].getqfilmName() == "")
                {
                    break;
                }
                else
                {
                    cout << j << ". " << c[i].getqfilmName() << "  " << c[i].getqdistributerUserName() <<endl;
                    j++;
                }
            }

            int choice;
            cout << "Enter which course you want to enroll:\t";
            cin >> choice;

            char *a1 = new char[50];
            a1[0] = '1';
            strcat(a1 , a);

            ofstream outf(a1);
            char *courseFileName = new char[50];

            for(int k=0;k<numberOfCourses;k++)
            {
                if(k == choice-1)
                {
                    char *cName = new char[50];
                    string s = c[k].getqfilmName();
                    int length=s.length();
                    for(int i=0;i<length;i++)
                    {
                        cName[i]=s[i];
                    }
                    cName[length]='\0';


                    char *cTUser = new char[50];
                    string s1 = c[k].getqdistributerUserName();
                    int length1=s1.length();
                    for(int i=0;i<length1;i++)
                    {
                        cTUser[i]=s1[i];
                    }
                    cTUser[length1]='\0';

                    strcpy(courseFileName , cName);
                    strcat(courseFileName , "_");
                    strcat(courseFileName , cTUser);

                }
                else
                {
                    outf << c[k].getqfilmName() << " " << c[k].getqdistributerName() << " " << c[k].getqdistributerUserName() << endl;
                }
            }


            outf.close();
            remove(a);
            rename(a1 , a);

            char *courseFileName1 = new char[50];
            strcpy(courseFileName1 , courseFileName);
            strcat(courseFileName1 , "1.txt");
            strcat(courseFileName , ".txt");

            cout << courseFileName << endl;
            cout << courseFileName1 <<endl;

            ofstream outf1(courseFileName1);
            ifstream inf(courseFileName);

            if(!inf.is_open())
            {
                cout<<"No course to un-enroll"<<endl;
            }
            else
            {
                while(!inf.eof())
                {
                    string sName;
                    string sid;

                    inf >> sName;
                    inf >> sid;

                    if(sName.compare(name) == 0 && sid.compare(id) == 0)
                    {

                    }
                    else
                    {
                        outf1 << sName << " " << sid << endl;
                    }
                }
                inf.close();
                outf1.close();

                remove(courseFileName);
                rename(courseFileName1 , courseFileName);
            }

        }

    }
    void SVeiwcourses()
    {

    }
    void Viewlecture()
    {

    }
    void ViewAssignment()
    {

    }
    void UploadAssigment()
    {

    }
};
