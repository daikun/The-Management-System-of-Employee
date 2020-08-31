#include"example.h"
#include"worker.h"

int main()
{
	WorkerManager Manage_System;
	int choice = 0;
	while (true)
	{
		Manage_System.Show_Menu();
		cout << "请输入功能选项:" ;
		cin >> choice;
		switch (choice)
		{
		case 0:  //0、退出管理系统
		{
			Manage_System.exitSystem();
			exit(0);
			break;
		}
		case 1:  //1、增加职工信息
		{
			Manage_System.Add_Emp();
			system("cls");
			break;
		}
		case 2:  //2、显示职工信息
		{
			Manage_System.Show_Emp();
			system("pause");
			system("cls");
			break;
		}
		case 3:  //3、删除离职职工
		{
			Manage_System.Del_Emp();
			system("pause");
			system("cls");
			break;
		}
		case 4:  //4、修改职工信息
		{
			Manage_System.Mod_Emp();
			system("pause");
			system("cls");
			break;
		}
		case 5:  //5、查找职工信息
		{
			Manage_System.Find_Emp();
			system("pause");
			system("cls");
			break;
		}
		case 6:  //6、按照编号排名
		{
			Manage_System.Sort_Emp();
			system("pause");
			system("cls");
			break;
		}
		case 7:  //7、清除所有文档
		{
			Manage_System.Clean_File();
			system("pause");
			system("cls");
			break;
		}
		default:
		{
			system("pause");
			system("cls");
			break;
		}
		}
	}

	system("pause");
	return 0;
}