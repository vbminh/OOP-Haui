#include <bits/stdc++.h>

using namespace std;

class FACULTY;
class STUDENT;

class PERSON
{
protected:
    char Name[20];
    char Birth[12];
    char Address[20];
public:
    void input();
    void output();
    PERSON();
};

class SCHOOL
{
    char Name[20];
    char Date[12];
    friend class FACULTY;
    friend class STUDENT;
    friend void Sua(STUDENT a);
};

class FACULTY
{
    char Name[20];
    char Date[12];
    SCHOOL x;
public:
    void input();
    void output();
    friend class STUDENT;
    friend void Sua(STUDENT a);
};

class STUDENT:private PERSON
{
    FACULTY y;
    char Class[5];
    float Score;
public:
    void input();
    void output();
    STUDENT();
    friend void Sua(STUDENT a);
};

void PERSON::input()
{
    cout << "Person Name: "; fflush(stdin); gets(Name);
    cout << "Person Birth: "; fflush(stdin); gets(Birth);
    cout << "Person Address: "; fflush(stdin); gets(Address);
}

void PERSON::output()
{
    cout << "Person Name: " << Name << endl;
    cout << "Person Birth: " << Birth << endl;
    cout << "Person Address: " << Address << endl;
}

void FACULTY::input()
{
    cout << "Faculty Name: "; fflush(stdin); gets(Name);
    cout << "Faculty Date: "; fflush(stdin); gets(Date);
    cout << "School Name: "; fflush(stdin); gets(x.Name);
    cout << "School Date: "; fflush(stdin); gets(x.Date);
}

void FACULTY::output()
{
    cout << "Faculty Name: " << Name << endl;
    cout << "Faculty Date: " << Date << endl;
    cout << "School Name: " << x.Name << endl;
    cout << "Scholl Date: " << x.Date << endl;
}

void STUDENT::input()
{
    y.input();
    PERSON::input();
    cout << "Class:"; fflush(stdin); gets(Class);
    cout << "Score: "; cin >> Score;
}

void STUDENT::output()
{
    PERSON::output();
    y.output();
    cout << "Class: " << Class << endl;
    cout << "Score: "<< Score << endl;
}

PERSON::PERSON()
{
    strcpy(Name,"");
    strcpy(Birth,"");
    strcpy(Address,"");
}

STUDENT::STUDENT():PERSON()
{
    strcpy(y.x.Name,"");
    strcpy(y.x.Date,"");
    strcpy(y.Name,"");
    strcpy(y.Date,"");
    strcpy(Class,"");
    Score = 0;
}

void Sua(STUDENT a)
{
    strcpy(a.y.x.Name,"DHCNHN");
    a.output();
}
int main()
{
    STUDENT a;
    a.input();
    cout <<  endl << "Thong tin sv vua nhap:" << endl;
    a.output();
    cout << endl << "-------Bonus 1-------" << endl;
    Sua(a);
    return 0;
}
