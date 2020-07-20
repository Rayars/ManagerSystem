#include"system.h"
#include<iostream>
using namespace std;

void dispalyMenu(bool n)
{
	system("cls");
	cout << "*****************************************************************************" << endl << endl;
	cout << "                         欢迎使用高校信息管理系统            " << endl << endl;
	cout << "*****************************************************************************" << endl << endl;
	cout << "                           请选择要执行的功能：" << endl;
	cout << "                           1).添加成员" << endl;
	cout << "                           2).查询成员信息" << endl;
	cout << "                           3).显示成员信息" << endl;
	cout << "                           4).编辑成员信息" << endl;
	cout << "                           5).删除成员" << endl;
	cout << "                           6).统计信息" << endl;
	cout << "                           7).保存" << endl;
	cout << "                           8).读取记录" << endl;
	cout << "                           0).退出" << endl
		<< endl
		<< endl;
	if (n == 1)
	{
		cout << "请输入指令：";
	}
	else
	{
		cout << "指令错误，请重新输入：";
	}
}

void run()
{
	dispalyMenu(1);
	int n;
	Database DATA;
	while ((n = getchar()) != '0')
	{
		n -= 48;
		switch (n)
		{
		case 0:
			return;//退出
		case 1:
			DATA.addmem();
			break; //添加
		case 2:
			DATA.searchmem();
			break; //查询
		case 3:
			DATA.dispmem();
			break; //显示
		case 4:
			DATA.editmem();
			break; //编辑
		case 5:
			DATA.delmem();
			break; //删除
		case 6:
			DATA.stastic();
			break; //统计
		case 7:
			DATA.save();
			break; //保存
		case 8:
			DATA.read();
			break; //读取
		default:
			dispalyMenu(0);
			continue; //显示操作指南
		}
		dispalyMenu(1);
	}
}

int main()
{
	run();
	return 0;
}