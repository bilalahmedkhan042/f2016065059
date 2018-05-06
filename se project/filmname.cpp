#include<iostream>
#include<string>

using namespace std;

class filmname{

    string qfilmName;
    string qdistributerName;
    string qdistributerUserName;
    string qcustomername;
    string qid;

public:

    void setqfilmName(string n)
    {
        qfilmName = n;
    }
    string getqfilmName()
    {
        return qfilmName;
    }

    void setqdistributerName(string n)
    {
        qdistributerName = n;
    }
    string getqdistributerName()
    {
        return qdistributerName;
    }

    void setqdistributerUserName(string n)
    {
        qdistributerUserName = n;
    }
    string getqdistributerUserName()
    {
        return qdistributerUserName;
    }
    void setqcustomername(string n)
    {
        qcustomername=n;
    }
    string getqcustomername()
    {
        return qid;
    }
    void setqcustomerid(string n)
    {
        qid=n;
    }
    string getqcustomerid()
    {
        return qid;
    }

    filmname()
    {
        qfilmName = "";
        qdistributerName = "";
        qdistributerUserName = "";
        qcustomername="";
        qid="";
    }
    ~filmname(){}

};

