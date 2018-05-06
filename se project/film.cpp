#include<iostream>
#include<string>

using namespace std;

class film{

    string filmName;
    string distrubuterName;
    string distrubuterUserName;


public:

    void setfilmName(string n)
    {
        filmName = n;
    }
    string getfilmName()
    {
        return filmName;
    }

    void setdistributerName(string n)
    {
        distrubuterName = n;
    }
    string getdistrubuterName()
    {
        return distrubuterName;
    }

    void setdistributerUserName(string n)
    {
        distrubuterUserName = n;
    }
    string getdistributerUserName()
    {
        return distrubuterUserName;
    }


    Course()
    {
        filmName = "";
        distrubuterName = "";
        distrubuterUserName = "";

    }
    ~film(){}

};
