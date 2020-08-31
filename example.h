#ifndef __Message_Mangement__
#define __Message_Mangement__

#include<iostream>
#include<string>
#include<fstream>
#include"worker.h"
#define FILEPATH ".\\empFile.txt"

using namespace std;

class WorkerManager
{
public:
	WorkerManager();
	~WorkerManager();
	void Show_Menu();
	void exitSystem();
	void Add_Emp();
	void save();
	int get_EmpNum();//读取文件中有多少人
	void init_Emp();//将初始文档中的数据读取到列表中
	void Show_Emp();//显示职工功能
	void Del_Emp();
	int Is_Emp_Exit(int id);//输入ID号，寻找员工的位置
	void Mod_Emp();
	void Find_Emp();
	void Sort_Emp();//根据员工编号排序
	void Clean_File();

	int m_EmployNum;
	Worker** m_EmpArray;
	bool m_FileIsEmpty;

private:

};



#endif
