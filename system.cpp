#include"system.h"
#include<iostream>
#include<fstream>
using namespace std;

bool ask()
{
	cout << "输入“r”返回" << endl;
	char ans;
	cin >> ans;
	while (ans != 'r')
	{
		ask();
		return true;
	}
	return true;
}

Database::Database()
{}

Database::~Database()
{}

void Database::addmem()
{
	system("cls");
	int com;
	cout << "要添加那种人员？:" << endl;
	cout << "1.教师 2.研究员 3.行政人员 4.教师兼行政人员 0.返回" << endl;
	cout << "请输入要添加的人员前的数字：" << endl;
	cin >> com;
	if (com == 0)
	{
		return;
	}
	cout << "请输入要添加的人员编号：" << endl;
	string num;
	cin >> num;
	for (vector<People*>::iterator it = datalist.begin(); it != datalist.end(); it++)
	{
		if ((*it)->getnum() == num)
		{
			cout << "编号重复！" << endl;
			if (ask())
			{
				return;
			}
		}
	}
	cout << "请输入人员姓名:" << endl;
	string name;
	cin >> name;
	cout << "请输入年龄:" << endl;
	int age;
	cin >> age;
	cout << "请输入人员性别 male/female?:" << endl;
	Gender sex;
	string tmp;
	cin >> tmp;
	if (tmp == "male")
	{
		sex = (Gender)male;
	}
	else
		sex = (Gender)female;
	if (com == 1)
	{
		cout << "请输入所属部门:" << endl;
		string department;
		cin >> department;
		cout << "请输入现专业:" << endl;
		string subject;
		cin >> subject;
		cout << "请输入职称:" << endl;
		string profession;
		cin >> profession;
		Teacher* t=new Teacher(num, name, age, sex, 1, department, subject, profession);
		datalist.push_back(t);
	}
	else if (com == 2)
	{
		cout << "请输入所属实验室:" << endl;
		string labtory;
		cin >> labtory;
		cout << "请输入职称:" << endl;
		string profession;
		cin >> profession;
		Graduate* g=new Graduate(num, name, age, sex, 2, labtory, profession);
		datalist.push_back(g);
	}
	else if (com == 3)
	{
		cout << "请输入政治面貌:" << endl;
		string status;
		cin >> status;
		cout << "请输入职称:" << endl;
		string prof;
		cin >> prof;
		Administrator* A=new Administrator(num, name, age, sex, 3, status, prof);
		datalist.push_back(A);
	}
	else if (com == 4)
	{
		cout << "请输入所属部门:" << endl;
		string department;
		cin >> department;
		cout << "请输入现专业:" << endl;
		string subject;
		cin >> subject;
		cout << "请输入政治面貌:" << endl;
		string status;
		cin >> status;
		cout << "请输入职称:" << endl;
		string prof;
		cin >> prof;
		TA* ta=new TA(num, name, age, sex, 4, department, subject, status, prof);
		datalist.push_back(ta);
	}
	cout << "添加成功" << endl;
	if (ask())
	{
		return;
	}
}

vector<People*>::iterator Database::searchmem()
{
	system("cls");
	cout << "请输入要查询的人员编号：(不需要请输入N)" << endl;
	string num;
	cin >> num;
	cout << "请输入人员姓名：(不需要请输入N)" << endl;
	string name;
	cin >> name;
	vector<People*>::iterator it;
	if (num == "N" && name == "N")
	{
		cout << "编号和姓名不能都为‘N’" << endl;
		return datalist.end();
	}
	for (it = datalist.begin(); it != datalist.end(); it++)
	{
		if ((num == "N" || (*it)->getnum() == num) && (name == "N" || (*it)->getname() == name))
		{
			cout << "查找成功：" << endl;
			(*it)->show();
			break;
		}
	}
	if (it == datalist.end())
	{
		cout << "不存在此人员" << endl;
	}
	if (ask())
	{
		return it;
	}
}

void Database::dispmem()
{
	system("cls");
	if (datalist.empty())
	{
		cout << "列表为空" << endl;
		if (ask())
		{
			return;
		}
	}
	for (vector<People*>::iterator it = datalist.begin(); it != datalist.end(); it++)
	{
		(*it)->show();
	}
	if (ask())
	{
		return;
	}
}

void Database::edit(int type, int comm, vector<People*>::iterator it)
{
	int m = type * 10 + comm;;
	switch (comm)
	{
	case 1:
	{
		cout << "请输入新的编号：";
		string num;
		cin >> num;
		for (vector<People*>::iterator iter = datalist.begin(); iter != datalist.end(); iter++)
		{
			if ((*iter)->getnum() == num)
			{
				cout << "编号重复！" << endl;
				return;
			}
		}
		(*it)->setnum(num);
		break;
	}
	case 2:
	{
		cout << "请输入新的姓名：";
		string name;
		cin >> name;
		(*it)->setname(name);
		break;
	}
	case 3:
	{
		cout << "请输入新的年龄：";
		int age;
		cin >> age;
		(*it)->setage(age);
		break;
	}
	case 4:
	{
		cout << "请输入新的性别 male/female：";
		Gender sex;
		string tmp;
		cin >> tmp;
		if (tmp == "male")
		{
			sex = (Gender)male;
		}
		else
			sex = (Gender)female;
		(*it)->setsex(sex);
		break;
	}
	}
	switch (m)
	{
	case 15:
	{
		cout << "请输入新的部门：";
		string dep;
		cin >> dep;
		(*it)->setdep(dep);
		break;
	}
	case 16:
	{
		cout << "请输入新的专业：";
		string sub;
		cin >> sub;
		(*it)->setsub(sub);
		break;
	}
	case 17:
	{
		cout << "请输入新的职称：";
		string prof;
		cin >> prof;
		(*it)->setprof(prof);
		break;
	}
	case 25:
	{
		cout << "请输入新的实验室名称：";
		string lab;
		cin >> lab;
		(*it)->setlab(lab);
		break;
	}
	case 26:
	{
		cout << "请输入新的职称：";
		string prof;
		cin >> prof;
		(*it)->setprof(prof);
		break;
	}
	case 35:
	{
		cout << "请输入新的政治面貌：";
		string status;
		cin >> status;
		(*it)->setstatus(status);
		break;
	}
	case 36:
	{
		cout << "请输入新的职称：";
		string prof;
		cin >> prof;
		(*it)->setprof(prof);
		break;
	}
	case 45:
	{
		cout << "请输入新的部门：";
		string dep;
		cin >> dep;
		(*it)->setdep(dep);
		break;
	}
	case 46:
	{
		cout << "请输入新的专业：";
		string sub;
		cin >> sub;
		(*it)->setsub(sub);
		break;
	}
	case 47:
	{
		cout << "请输入新的政治面貌：";
		string status;
		cin >> status;
		(*it)->setstatus(status);
		break;
	}
	case 48:
	{
		cout << "请输入新的职称：";
		string prof;
		cin >> prof;
		(*it)->setprof(prof);
		break;
	}
	}
}

void Database::editmem()
{
	system("cls");
	cout << "进行要修改人员信息的查询，" << endl;
	vector<People*>::iterator it = searchmem();
	if (it != datalist.end())
	{
		int comm, n;
		n = (*it)->gettype();
		cout << "要修改的信息对应编号：1.编号 2.姓名 3.年龄 4.性别 ";
		switch (n)
		{
		case 1:
			cout << "5.部门 6.专业 7.职称 0.返回" << endl;
			break;
		case 2:
			cout << "5.所属实验室 6.职称 0.返回" << endl;
			break;
		case 3:
			cout << "5.政治面貌 6.职称 0.返回" << endl;
			break;
		case 4:
			cout << "5.部门 6.专业 7.政治面貌 8.职称 0.返回" << endl;
			break;
		}
		cout << "请输入要修改的信息：";
		cin >> comm;
		while (comm != 0)
		{
			edit(n, comm, it);
			cout << "要修改的信息对应编号：1.编号 2.姓名 3.年龄 4.性别 ";
			switch (n)
			{
			case 1:
				cout << "5.部门 6.专业 7.职称 0.返回" << endl;
				break;
			case 2:
				cout << "5.所属实验室 6.职称 0.返回" << endl;
				break;
			case 3:
				cout << "5.政治面貌 6.职称 0.返回" << endl;
				break;
			case 4:
				cout << "5.部门 6.专业 7.政治面貌 8.职称 0.返回" << endl;
				break;
			}
			cout << "请输入要修改的信息：";
			cin >> comm;
		}
		return;
	}
	else
	{
		return;
	}
}

void Database::delmem()
{
	system("cls");
	if (datalist.empty())
	{
		cout << "记录为空！" << endl;
		if (ask())
		{
			return;
		}
	}
	cout << "请输入要删除的人员编号:（不需要则输入“N”）" << endl;
	string num;
	cin >> num;
	cout << "请输入要删除的人员姓名：（不需要则输入“N”）" << endl;
	string name;
	cin >> name;
	vector<People*>::iterator it;
	if (num == "N" && name == "N")
	{
		cout << "编号和姓名不能都为‘N’" << endl;
		return;
	}
	for (it = datalist.begin(); it != datalist.end(); it++)
	{
		if ((num == "N" || num == (*it)->getnum()) && (name == "N" || (*it)->getname() == name))
		{
			delete (*it);
			datalist.erase(it);
			cout << "删除成功" << endl;
			if (ask())
			{
				return;
			}
		}
	}
	if (it == datalist.end())
	{
		cout << "不存在此人员" << endl;
		if (ask())
		{
			return;
		}
	}
}


void Database::stastic()
{
	system("cls");
	cout << "人员总数：" << People::pepnum << endl;
	cout << "其中男性员工" << People::malenum << "人，女性员工" << People::femalenum << "人。" << endl;
	cout << "教师" << Teacher::teachernum << "人，研究员" << Graduate::granum <<"人，"<< endl;
	cout << "行政人员" << Administrator::adminnum << "人，教师兼行政人员" << TA::TAnum << "人。" << endl;
	cout << "请输入要统计的参数：" << endl;
	cout << "(1.姓名 2.年龄 3.所属部门 4.专业 5.所属实验室 6.政治面貌 7.职称)" << endl;
	int comm;
	cin >> comm;
	cout << "请输入参数：";
	int parai;
	string para;
	if (comm == 2)
	{
		cin >> parai;
	}
	else
	{
		cin >> para;
	}
	vector<People*>::iterator it = datalist.begin();
	int sum=0;
	if (comm == 1)
	{
		for (; it != datalist.end(); it++)
		{
			if ((*it)->getname() == para)
			{
				sum++;
			}
		}
	}
	else if (comm == 2)
	{
		for (; it != datalist.end(); it++)
		{
			if ((*it)->getage() == parai)
			{
				sum++;
			}
		}
	}
	else if (comm == 3)
	{
		for (; it != datalist.end(); it++)
		{
			if ((*it)->getdep() == para)
			{
				sum++;
			}
		}
	}
	else if (comm == 4)
	{
		for (; it != datalist.end(); it++)
		{
			if ((*it)->getsub() == para)
			{
				sum++;
			}
		}
	}
	else if (comm == 5)
	{
		for (; it != datalist.end(); it++)
		{
			if ((*it)->getlab() == para)
			{
				sum++;
			}
		}
	}
	else if (comm == 6)
	{
		for (; it != datalist.end(); it++)
		{
			if ((*it)->getstatus() == para)
			{
				sum++;
			}
		}
	}
	else if (comm == 7)
	{
		for (; it != datalist.end(); it++)
		{
			if ((*it)->getprof() == para)
			{
				sum++;
			}
		}
	}
	cout << "参数相同的人员共有:" << sum << "人" << endl;
	if (ask())
	{
		return;
	}
}

void Database::save()
{
	system("cls");
	ofstream outfile("text.txt",ios::out);
	vector<People*>::iterator it = datalist.begin();
	for (; it != datalist.end(); it++) {
		if ((*it)->gettype() == 1)
		{

				outfile << (*it)->gettype() << endl;
				outfile << (*it)->getnum() << endl;
				outfile << (*it)->getname() << endl;
				outfile << (*it)->getage() << endl;
				outfile << (*it)->getsex() << endl;
				outfile << (*it)->getdep() << endl;
				outfile << (*it)->getsub() << endl;
				outfile << (*it)->getprof() << endl;
			
		}
		else if ((*it)->gettype() == 2)
		{
		
				outfile << (*it)->gettype() << endl;
				outfile << (*it)->getnum() << endl;
				outfile << (*it)->getname() << endl;
				outfile << (*it)->getage() << endl;
				outfile << (*it)->getsex() << endl;
				outfile << (*it)->getlab() << endl;
				outfile << (*it)->getprof() << endl;
			
		}
		else if ((*it)->gettype() == 3)
		{
			
				outfile << (*it)->gettype() << endl;
				outfile << (*it)->getnum() << endl;
				outfile << (*it)->getname() << endl;
				outfile << (*it)->getage() << endl;
				outfile << (*it)->getsex() << endl;
				outfile << (*it)->getstatus() << endl;
				outfile << (*it)->getprof() << endl;
			
		}
		else if ((*it)->gettype() == 4)
		{
			
				outfile << (*it)->gettype() << endl;
				outfile << (*it)->getnum() << endl;
				outfile << (*it)->getname() << endl;
				outfile << (*it)->getage() << endl;
				outfile << (*it)->getsex() << endl;
				outfile << (*it)->getdep() << endl;
				outfile << (*it)->getsub() << endl;
				outfile << (*it)->getstatus() << endl;
				outfile << (*it)->getprof() << endl;
		
		}
	}
	outfile.close();
	cout << "存储成功！" << endl;
	if (ask())
	{
		return;
	}
}

void Database::read()
{
	system("cls");
	ifstream infile("text.txt", ios::in);
	if (infile.is_open())
	{
		char com;
		cout << "是否清除当前数据？Y/N:" ;
		cin >> com;
		if (com == 'Y')
		{
			for (vector<People*>::iterator it = datalist.begin(); it != datalist.end(); it++)
			{
				delete (*it);
			}
			datalist.clear();
		}
		int type;
		while (infile >> type)
		{
			switch (type)
			{
			case 1:
			{
				string num,name,dep,sub,prof;
				int age,sex;
				infile >> num >> name >> age>>sex>>dep>>sub>>prof;
				Gender s;
				if (sex == 0)
				{
					s = male;
				}
				else
				{
					s = female;
				}
				Teacher* t = new Teacher(num, name, age, s, 1, dep, sub, prof);
				datalist.push_back(t);
				break;
			}
			case 2:
			{
				string num, name, lab, prof;
				int age, sex;
				infile >> num >> name >> age >> sex >>lab >> prof;
				Gender s;
				if (sex == 0)
				{
					s = male;
				}
				else
				{
					s = female;
				}
				Graduate* g=new Graduate(num, name, age, s, type, lab, prof);
				datalist.push_back(g);
				break;
			}
			case 3:
			{
				string num, name, status, prof;
				int age, sex;
				infile >> num >> name >> age >> sex >> status >> prof;
				Gender s;
				if (sex == 0)
				{
					s = male;
				}
				else
				{
					s = female;
				}
				Administrator* a=new Administrator(num, name, age, s, type, status, prof);
				datalist.push_back(a);
				break;
			}
			case 4:
			{
				string num, name, dep,sub,status, prof;
				int age, sex;
				infile >> num >> name >> age >> sex >> dep>>sub>>status >> prof;
				Gender s;
				if (sex == 0)
				{
					s = male;
				}
				else
				{
					s = female;
				}
				TA* ta=new TA(num, name, age, s, type, dep,sub,status, prof);
				datalist.push_back(ta);
				break;
			}
			}
		}
		cout << "读取成功" << endl;
		if (ask())
		{
			return;
		}
	}
	else
	{
		cout << "打开文件失败" << endl;
		if (ask())
		{
			return;
		}
	}
}