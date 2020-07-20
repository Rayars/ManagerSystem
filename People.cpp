#include "People.h"
#include <iostream>
using namespace std;

int People::pepnum = 0;
int People::malenum = 0;
int People::femalenum = 0;

People::People(string num1, string name1, int age1, Gender sex1, int type1)
{
    num = num1;
    name = name1;
    age = age1;
    sex = sex1;
    type = type1;
    if (sex == 0)
    {
        malenum++;
    }
    else
    {
        femalenum++;
    }
    pepnum++;
}

People::~People()
{
    pepnum--;
    if (sex == 0)
    {
        malenum--;
    }
    else
    {
        femalenum--;
    }
}

void People::setnum(string num1)
{
    num = num1;
}
void People::setname(string name1)
{
    name = name1;
}
void People::setage(int age1)
{
    age = age1;
}
void People::setsex(Gender sex1)
{
    sex = sex1;
}

int Teacher::teachernum = 0;

Teacher::Teacher(string num1, string name1, int age1, Gender sex1, int type1, string dep1, string sub1, string prof1) : People(num1, name1, age1, sex1, type1)
{
    dep = dep1;
    sub = sub1;
    prof = prof1;
    teachernum++;
}

Teacher::~Teacher()
{
    teachernum--;
}

void Teacher::setdep(string d)
{
    dep = d;
}
void Teacher::setsub(string s)
{
    sub = s;
}
void Teacher::setprof(string p)
{
    prof = p;
}

void Teacher::show() const
{
    cout << "编号：" << getnum() << " 姓名：" << getname() << " 年龄：" << getage() << " 性别：";
    if (getsex() == 0)
    {
        cout << "male ";
    }
    else
        cout << "female";
    cout << " 部门：" << getdep() << " 专业：" << getsub() << " 职称：" << getprof() << endl;
}

int Graduate::granum = 0;

Graduate::Graduate(string num1, string name1, int age1, Gender sex1, int type1, string lab1, string prof1) : People(num1, name1, age1, sex1, type1)
{
    lab = lab1;
    prof = prof1;
    granum++;
}

Graduate::~Graduate()
{
    granum--;
}

void Graduate::setlab(string lab1)
{
    lab = lab1;
}
void Graduate::setprof(string p)
{
    prof = p;
}
void Graduate::show() const
{
    cout << "编号：" << getnum() << " 姓名：" << getname() << " 年龄：" << getage() << " 性别：";
    if (getsex() == 0)
    {
        cout << "male ";
    }
    else
        cout << "female";
    cout << " 所属实验室：" << getlab() << " 职称：" << getprof() << endl;
}

int Administrator::adminnum = 0;

Administrator::Administrator(string num1, string name1, int age1, Gender sex1, int type1, string status1, string prof1) : People(num1, name1, age1, sex1, type1)
{
    status = status1;
    prof = prof1;
    adminnum++;
}

Administrator::~Administrator()
{
    adminnum--;
}

void Administrator::setstatus(string s)
{
    status = s;
}
void Administrator::setprof(string p)
{
    prof = p;
}

void Administrator::show() const
{
    cout << "编号：" << getnum() << " 姓名：" << getname() << " 年龄：" << getage() << " 性别：";
    if (getsex() == 0)
    {
        cout << "male ";
    }
    else
        cout << "female";
    cout << " 政治面貌：" << getstatus() << " 职称：" << getprof() << endl;
}

int TA::TAnum = 0;

TA::TA(string num1, string name1, int age1, Gender sex1, int type1, string dep1, string sub1, string status1, string prof1) : People(num1, name1, age1, sex1, type1)
{
    setdep(dep1);
    setsub(sub1);
    setstatus(status1);
    proff = prof1;
    teachernum++;
    adminnum++;
    TAnum++;
}

TA::~TA()
{
    teachernum--;
    adminnum--;
    TAnum--;
}

void TA::setprof(string p)
{
    proff = p;
}

void TA::show() const
{
    cout << "编号：" << getnum() << " 姓名：" << getname() << " 年龄：" << getage() << " 性别：";
    if (getsex() == 0)
    {
        cout << "male ";
    }
    else
        cout << "female";
    cout << " 部门：" << getdep() << " 专业：" << getsub() << " 政治面貌：" << getstatus() << " 职称：" << getprof() << endl;
}