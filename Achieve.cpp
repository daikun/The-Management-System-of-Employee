#include"example.h"
#include"worker.h"

int main()
{
	WorkerManager Manage_System;
	int choice = 0;
	while (true)
	{
		Manage_System.Show_Menu();
		cout << "�����빦��ѡ��:" ;
		cin >> choice;
		switch (choice)
		{
		case 0:  //0���˳�����ϵͳ
		{
			Manage_System.exitSystem();
			exit(0);
			break;
		}
		case 1:  //1������ְ����Ϣ
		{
			Manage_System.Add_Emp();
			system("cls");
			break;
		}
		case 2:  //2����ʾְ����Ϣ
		{
			Manage_System.Show_Emp();
			system("pause");
			system("cls");
			break;
		}
		case 3:  //3��ɾ����ְְ��
		{
			Manage_System.Del_Emp();
			system("pause");
			system("cls");
			break;
		}
		case 4:  //4���޸�ְ����Ϣ
		{
			Manage_System.Mod_Emp();
			system("pause");
			system("cls");
			break;
		}
		case 5:  //5������ְ����Ϣ
		{
			Manage_System.Find_Emp();
			system("pause");
			system("cls");
			break;
		}
		case 6:  //6�����ձ������
		{
			Manage_System.Sort_Emp();
			system("pause");
			system("cls");
			break;
		}
		case 7:  //7����������ĵ�
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