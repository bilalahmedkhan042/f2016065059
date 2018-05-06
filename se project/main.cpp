#include <iostream>
#include<stdlib.h>
#include"Admin.cpp"
#include"distributer.cpp"
#include"customer.cpp"

using namespace std;

void AdminFlow()
{
    Admin a;
    bool flag = true;
    while(flag)
    {
        string user , pass;
        cout<<"Enter UserName:\t";
        cin >> user;
        cout<<"Enter Password:\t";
        cin >> pass;

        if(user == a.getUserName() && pass == a.getPassword())
        {
            int adminMenu= 0;
            bool flag1 = true;
            while(flag1)
            {
                cout<<"1. Create distributer login\n2. Create customer Login\n3. Logout";
                cin>>adminMenu;
                switch(adminMenu)
                {
                case 1:
                    a.CreateTeacher();
                    break;
                case 2:
                    a.Createcustomer();
                    break;
                case 3:
                    flag1 = false;
                    break;
                }
            }

            flag = false;
        }
        else
        {
            cout<<"\n\nWrong User or Password Input.\n\n";
        }
    }
}

distributer VerifyTeacherLogin(string user , string pass)
{
    ifstream inf("distributerLogin.txt");
    distributer t , t1;

    if(!inf.is_open())
    {
        cout<<"File distributerLogin.txt doesn't exists.";
    }
    else
    {
        while(!inf.eof())
        {

            string n;
            inf >> n;
            t.setName(n);
            inf >> n;
            t.setUser(n);
            inf >> n;
            t.setPass(n);

            if(t.getUser() == user && t.getPass() == pass)
            {
                return t;
            }
        }
        return t1;
    }
    return t1;
}
customer VerifystudentLogin(string id , string pass)
{
    ifstream inf("StudentLogin.txt");
    customer s , s1;

    if(!inf.is_open())
    {
        cout<<"File StudentLogin.txt doesn't exists.";
    }
    else
    {
        while(!inf.eof())
        {

            string n;
            inf >> n;
            s.setname(n);
            inf >> n;
            s.setid(n);
            inf >> n;
            s.setpass(n);

            if(s.getid() == id && s.getpass() == pass)
            {
                return s;
            }
        }
        return s1;
    }
    return s1;
}
void TeacherFlow()
{
    distributer t;
    bool flag = true;
    while(flag)
    {
        string user , pass;
        cout<<"Enter UserName:\t";
        cin >> user;
        cout<<"Enter Password:\t";
        cin >> pass;

        t = VerifyTeacherLogin(user , pass);
        if(t.getName() != "" && t.getUser() != "" && t.getPass() != "")
        {
            int teacherMenu= 0;
            bool flag1 = true;
            while(flag1)
            {
                cout<<"1. Create film\n2. Delete film\n3. Upload Audio\n4. Upload subtitles\n5. View films\n6. Logout";
                cin>>teacherMenu;
                switch(teacherMenu)
                {
                case 1:
                    t.createfilm();
                    break;
                case 2:
                    t.deleteCourse();
                    break;
                case 3:
                   // t.uploadAssignment();
                    break;
                case 4:
                    t.uploadLecture();
                    break;
                case 5:
                    t.viewCourses();
                    break;
                case 6:
                    flag1 = false;
                    break;
                }
            }
            flag = false;
        }
        else
        {
            cout<<"\n\nWrong User or Password Input.\n\n";
        }
    }
}
void studentflow()
{
    customer s;
    bool flag = true;
    while(flag)
    {
        string id , pass;
        cout<<"Enter UserName:\t";
        cin >> id;
        cout<<"Enter Password:\t";
        cin >> pass;

        s = VerifystudentLogin(id , pass);
        if(s.getname() != "" && s.getid() != "" && s.getpass() != "")
        {
            int studentMenu= 0;
            bool flag1 = true;
            while(flag1)
            {
                cout<<"1. watch movie Course\n2. dislike movie \n3.  View movies\n4. download subtitles\n5. Submit Assignment\n6.Logout";
                cin>>studentMenu;
                switch(studentMenu)
                {
                case 1:
                    s.watchedmovies();
                    break;
                case 2:
                    s.UnEnroll();
                    break;
                case 3:
                    s.SVeiwcourses();
                    break;
                case 4:
                    s.Viewlecture();
                    break;
                case 5:
                    s.ViewAssignment();
                    break;
                 case 6:
                    s.UploadAssigment();
                    break;
                case 7:
                    flag1 = false;
                    break;
                }
            }
            flag = false;
        }
        else
        {
            cout<<"\n\nWrong User or Password Input.\n\n";
        }
    }
}
int main()
{
    int loginID;
    while(true)
    {
        system("CLS");
        cout<<"1. Admin Login\n2. Distributer Login\n3. customer Login\n\nEnter :\t";
        cin >> loginID;

        switch (loginID)
        {
        case 1:
            AdminFlow();
            break;
        case 2:
            TeacherFlow();
            break;
        case 3:
            studentflow();
        }

    }




    return 0;
}
