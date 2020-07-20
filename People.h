#ifndef _PEOPLE_H_
#define _PEOPLE_H_
#include <string>
using namespace std;

enum Gender
{
    male = 0,
    female
};

class People
{
private:
    string num;  //编号
    string name; //姓名
    int age;     //年龄
    Gender sex;  //性别
    int type;

public:
    static int pepnum;    //成员总数
    static int malenum;   //男
    static int femalenum; //女
    static int teachernum;
    static int granum;
    static int adminnum;
    static int TAnum;
    People() { ; };
    People(string, string, int, Gender, int);
    virtual ~People();
    void setnum(string);
    void setname(string);
    void setage(int);
    void setsex(Gender);
    string getname() const { return name; }
    string getnum() const { return num; }
    int getage() const { return age; }
    Gender getsex() const { return sex; }
    int gettype() const { return type; }
    virtual void setdep(string d) { ; };
    virtual void setsub(string s) { ; };
    virtual void setlab(string) { ; };
    virtual void setstatus(string) { ; };
    virtual void setprof(string p) { ; };
    virtual string getdep() const { return "0"; }
    virtual string getsub() const { return "0"; }
    virtual string getlab() const { return "0"; }
    virtual string getprof() const { return "0"; }
    virtual string getstatus() const { return "0"; }
    virtual void show() const = 0;
};

class Teacher : virtual public People
{
private:
    string dep;  //部门
    string sub;  //专业
    string prof; //职称
public:
    Teacher() { ; };
    Teacher(string, string, int, Gender, int, string, string, string);
    virtual ~Teacher();
    void setdep(string d);
    void setsub(string s);
    void setprof(string p);
    virtual string getdep() const { return dep; }
    virtual string getsub() const { return sub; }
    virtual string getprof() const { return prof; }
    void show() const;
};

class Graduate : virtual public People
{
private:
    string lab;  //所属实验室
    string prof; //职称

public:
    Graduate() { ; };
    Graduate(string, string, int, Gender, int, string, string);
    virtual ~Graduate();
    void setlab(string);
    void setprof(string);
    string getlab() const { return lab; }
    string getprof() const { return prof; }
    void show() const;
};

class Administrator : virtual public People
{
private:
    string status; //政治面貌
    string prof;   //职称

public:
    Administrator() { ; };
    Administrator(string, string, int, Gender, int, string, string);
    virtual ~Administrator();
    void setstatus(string);
    void setprof(string);
    string getstatus() const { return status; }
    string getprof() const { return prof; }
    void show() const;
};

class TA : public Teacher, public Administrator
{
private:
    string proff;

public:
    TA();
    TA(string, string, int, Gender, int, string, string, string, string);
    virtual ~TA();
    void setprof(string);
    string getprof() const { return proff; }
    void show() const;
};

#endif