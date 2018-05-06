#include<iostream>
#include<string>
#include<fstream>
#include"Course.cpp"
#include <bits/stdc++.h>

using namespace std;

class distributer
{
    string name;
    string user;
    string pass;

public:
    distributer()
    {
        name = "";
        user = "";
        pass = "";
    }
    ~distributer(){}
    void setName(string n)
    {
        name = n;
    }
    string getName()
    {
        return name;
    }
    void setUser(string n)
    {
        user = n;
    }
    string getUser()
    {
        return user;
    }
    void setPass(string n)
    {
        pass = n;
    }
    string getPass()
    {
        return pass;
    }


    void createfilm()
    {
        char *cName = new char[50];
        cout<<"Enter Course Name:\t";
        cin >> cName;


        int len = user.length();
        char *n = new char[len];
        for(int i=0;i<len ; i++)
        {
            n[i] = user[i];
        }
        n[len] = '\0';

        //Writing in List of Courses in Courses.txt
        ofstream outf1("film.txt" , ios::app);
        outf1 << cName << " " << name << " " << user <<endl;

        strcat(cName, "_");
        strcat(cName , n);

        char *cAName = new char[50] , *cLName = new char[50];
        strcpy(cAName, cName);
        strcpy(cLName, cName);

        strcat(cAName, "_audio.txt");
        strcat(cLName, "_subtitles.txt");

        //Creating course file
        strcat(cName , ".txt");
        ofstream outf( cName );
        ofstream outf2(cAName);
        ofstream outf3(cLName);

        outf.close();
        outf1.close();
        outf2.close();
        outf3.close();

    }

    void getCreatedCourses(film c1[])
    {
        film c;
        //Course c1[10];

        ifstream inf("film.txt");
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
                c.setfilmName(n);
                inf >> n;
                c.setdistributerName(n);
                inf >> n;
                c.setdistributerUserName(n);

                if(c.getdistrubuterName() == name && c.getdistributerUserName() == user)
                {
                    c1[i] = c;
                    i++;
                }
            }
        }
        inf.close();
    }

    void deleteCourse()
    {
        film c[10];
        getCreatedCourses(c);
        int j=1;

        if(c[0].getfilmName() == "")
        {
            cout << "No course created yet." << endl;
        }
        else
        {
            for(int i=0;i<10;i++)
            {
                if(c[i].getfilmName() == "")
                {
                    break;
                }
                else
                {
                    cout << j << ". " << c[i].getfilmName() << endl;
                    j++;
                }
            }

            int choice;
            cout << "Enter which course you want to delete:\t";
            cin >> choice;

            ifstream inf("film.txt");
            ofstream outf("film1.txt");

            while(!inf.eof())
            {
                film c2;
                string n;
                inf >> n;
                c2.setfilmName(n);
                inf >> n;
                c2.setdistributerName(n);
                inf >> n;
                c2.setdistributerUserName(n);

                if(c[choice-1].getfilmName().compare(c2.getfilmName()) == 0
                     && c[choice-1].getdistrubuterName().compare(c2.getdistrubuterName()) == 0
                     && c[choice-1].getdistributerUserName().compare(c2.getdistributerUserName()) == 0)
                {
                    //do nothing

                    char *fn = new char[50];
                    string s = c2.getfilmName();
                    int len = s.length();

                    for(int i=0;i<len;i++)
                    {
                        fn[i] = s[i];
                    }
                    fn[len] = '\0';
                    strcat(fn, "_");
                    s = c2.getdistributerUserName();
                    len = s.length();
                    int len1 = strlen(fn);

                    for(int i=0;i<len;i++)
                    {
                        fn[len1+i] = s[i];
                    }
                    fn[len1 + len] = '\0';

                    char *fnA = new char[50] , *fnL = new char[50];
                    strcpy(fnA , fn);
                    strcpy(fnL , fn);

                    strcat(fn, ".txt");
                    remove(fn);

                    strcat(fnA, "_audio.txt");
                    remove(fnA);
                    strcat(fnL, "_subtitles.txt");
                    remove(fnL);
                }
                else
                {
                    outf << c2.getfilmName() << " " << c2.getdistrubuterName() << " " << c2.getdistributerUserName() << endl;
                }

            }
            inf.close();
            outf.close();
            remove("film.txt");
            rename("film1.txt" , "film.txt");
        }
    }

    void uploadfilm()
    {
        film c[10];
        getCreatedCourses(c);
        int j=1;

        if(c[0].getfilmName() == "")
        {
            cout << "No course created yet." << endl;
        }
        else
        {
            for(int i=0;i<10;i++)
            {
                if(c[i].getfilmName() == "")
                {
                    break;
                }
                else
                {
                    cout << j << ". " << c[i].getfilmName() << endl;
                    j++;
                }
            }

            int choice;
            cout << "Enter which course Assignment you want to upload:\t";
            cin >> choice;

            char *fn = new char[50];
            string s = c[choice-1].getfilmName();
            int len = s.length();

            for(int i=0;i<len;i++)
            {
                fn[i] = s[i];
            }
            fn[len] = '\0';
            strcat(fn, "_");
            s = c[choice-1].getdistributerUserName();
            len = s.length();
            int len1 = strlen(fn);

            for(int i=0;i<len;i++)
            {
                fn[len1+i] = s[i];
            }
            fn[len1 + len] = '\0';
            strcat(fn, "_audio.txt");

            ofstream outf(fn , ios :: app);

            string assName;
            cout<<"Enter Name of Audio you want to upload: ";
            cin>>assName;
            cout<<endl;

            outf<<assName<<endl;

        }

    }

    void uploadLecture()
    {
        film c[10];
        getCreatedCourses(c);
        int j=1;

        if(c[0].getfilmName() == "")
        {
            cout << "No course created yet." << endl;
        }
        else
        {
            for(int i=0;i<10;i++)
            {
                if(c[i].getfilmName() == "")
                {
                    break;
                }
                else
                {
                    cout << j << ". " << c[i].getfilmName() << endl;
                    j++;
                }
            }

            int choice;
            cout << "Enter which course Lecture you want to upload:\t";
            cin >> choice;

            char *fn = new char[50];
            string s = c[choice-1].getfilmName();
            int len = s.length();

            for(int i=0;i<len;i++)
            {
                fn[i] = s[i];
            }
            fn[len] = '\0';
            strcat(fn, "_");
            s = c[choice-1].getdistributerUserName();
            len = s.length();
            int len1 = strlen(fn);

            for(int i=0;i<len;i++)
            {
                fn[len1+i] = s[i];
            }
            fn[len1 + len] = '\0';
            strcat(fn, "_audio.txt");

            ofstream outf(fn , ios :: app);

            string audioname;
            cout<<"Enter Name of Lecture you want to upload: ";
            cin>>audioname;
            cout<<endl;

            outf<<audioname<<endl;
        }
    }

    void viewCourses()
    {
        film c[10];
        getCreatedCourses(c);
        int j=1;

        if(c[0].getfilmName() == "")
        {
            cout << "No course created yet." << endl;
        }
        else
        {
            for(int i=0;i<10;i++)
            {
                if(c[i].getfilmName() == "")
                {
                    break;
                }
                else
                {
                    cout << j << ". " << c[i].getfilmName() << endl;
                    j++;
                }
            }
        }
    }

    void markSubmission()
    {

    }


};
