#include"example.h"

//**********Start:WorkerManager类构造函数**********
WorkerManager::WorkerManager() {
	ifstream ifs;
	ifs.open(FILEPATH, ios::in);

	if (!ifs.is_open()) {
		cout << "文件打开失败" << endl;
		this->m_EmployNum = 0;
		this->m_EmpArray = NULL;
		this->m_FileIsEmpty = true;
		ifs.close();
	}

	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		cout << "文件存在，但为空文件" << endl;
		this->m_EmployNum = 0;
		this->m_EmpArray = NULL;
		this->m_FileIsEmpty = true;
		ifs.close();
	}

	//获取初始时文件中的员工数目
	this->m_EmployNum = this->get_EmpNum();
	//初始化员工列表
	this->init_Emp();
}
//**********End:WorkerManager类构造函数**********


//**********Start:WorkerManager类析构函数**********
WorkerManager::~WorkerManager() {
	if (this->m_EmpArray != NULL) {
		for (int i = 0; i < this->m_EmployNum; i++) {
			if (this->m_EmpArray[i] != NULL) {
				delete this->m_EmpArray[i];
			}
		}
		delete[] this->m_EmpArray;
		this->m_EmpArray = NULL;
		this->m_EmployNum = 0;
		this->m_FileIsEmpty = true;
		cout << "数据清空成功!" << endl;
	}
}
//**********End:WorkerManager类析构函数**********


//**********Start:显示菜单**********
void WorkerManager::Show_Menu()
{
	cout << "****************************************" << endl;
	cout << "********* 欢迎使用职工管理系统 *********" << endl;
	cout << "*********** 0、退出管理系统 ************" << endl;
	cout << "*********** 1、增加职工信息 ************" << endl;
	cout << "*********** 2、显示职工信息 ************" << endl;
	cout << "*********** 3、删除离职职工 ************" << endl;
	cout << "*********** 4、修改职工信息 ************" << endl;
	cout << "*********** 5、查找职工信息 ************" << endl;
	cout << "*********** 6、按照编号排名 ************" << endl;
	cout << "*********** 7、清除所有文档 ************" << endl;
	cout << "****************************************" << endl;
	cout << endl;
}
//**********End:显示菜单**********


//**********Start:退出菜单**********
void WorkerManager::exitSystem()
{
	cout << "欢迎下次使用!" << endl;
	system("pause");
}
//**********End:退出菜单**********


//**********Start:保存为TXT文档菜单**********
void WorkerManager::save() {
	ofstream ofs;
	ofs.open(FILEPATH, ios::out);

	for (int i = 0; i < this->m_EmployNum; i++)
	{
		ofs << this->m_EmpArray[i]->m_ID << " "
			<< this->m_EmpArray[i]->m_Name << " "
			<< this->m_EmpArray[i]->m_DeptId << endl;
	}

	ofs.close();
}
//**********End:保存为TXT文档菜单**********


//**********Start:添加职员功能菜单**********
void WorkerManager::Add_Emp()
{
	cout << "请输入添加的工人数目:";
	int addNum;
	cin >> addNum;
	if (addNum > 0)
	{
		//计算并开辟新的空间
		int newSize = this->m_EmployNum + addNum;
		Worker** newSpace = new Worker*[newSize];
		//将原空间的内容放入到新空间中
		if (this->m_EmpArray != NULL)
		{
			for (int i = 0; i < this->m_EmployNum; i++) {
				newSpace[i] = this->m_EmpArray[i];
			}
			this->m_FileIsEmpty = false;
		}

		//放入新的数据
		for (int i = 0; i < addNum; i++)
		{
			int id;
			string name;
			int dSelect;

			cout << "请输入第" << i + 1 << "个员工的编号" << endl;
			cin >> id;
			cout << "请输入第" << i + 1 << "个员工的姓名" << endl;
			cin >> name;
			cout << "请输入第" << i + 1 << "个员工的岗位" << endl;
			cout << "1：普通员工" << endl;
			cout << "2：经理" << endl;
			cout << "3：老板" << endl;
			cin >> dSelect;

			Worker* worker = NULL;
			switch (dSelect)
			{
			case 1:
			{
				worker = new Employee(id, name, dSelect);
				break;
			}
			case 2:
			{
				worker = new Manager(id, name, dSelect);
				break;
			}
			case 3:
			{
				worker = new Boss(id, name, dSelect);
				break;
			}
			default:
				cout << "输入错误" << endl;
			}

			newSpace[this->m_EmployNum + i] = worker;
		}
		//更新类中数据
		delete[] this->m_EmpArray;
		m_EmpArray = new Worker*[newSize];
		for (int i = 0; i < newSize; i++) {
			m_EmpArray[i] = newSpace[i];
		}

		//获取的是添加职工后的人员数目
		this->m_EmployNum = newSize;
		delete[] newSpace;
		cout << "信息添加成功" << endl;

		this->m_FileIsEmpty = false;
	}
	else {
		cout << "输入错误" << endl;
	}

	this->save();
	system("pause");
}
//**********End:添加职员功能菜单**********


//**********Start:读取文件中的人数(文件中的职工数目)**********
int WorkerManager::get_EmpNum() {
	ifstream ifs;
	ifs.open(FILEPATH, ios::in);

	int num = 0;
	int id;
	string name;
	int did;

	while (ifs >> id && ifs >> name && ifs >> did) {
		num++;
	}
	ifs.close();
	return num;
}
//**********End:读取文件中的人数(文件中的职工数目)**********


//**********Start:将初始文档中的数据读取到列表中**********
void WorkerManager::init_Emp() {
	ifstream ifs;
	ifs.open(FILEPATH, ios::in);

	int id;
	string name;
	int dId;
	//要提前声明m_EmpArray开辟了多少个单位的内存。
	this->m_EmpArray = new Worker*[this->get_EmpNum()];

	int index = 0;
	while (ifs >> id && ifs >> name && ifs >> dId) {
		Worker* worker = NULL;
		if (dId == 1)
			worker = new Employee(id, name, dId);
		else if(dId == 2)
			worker = new Manager(id, name, dId);
		else 
			worker = new Boss(id, name, dId);

		this->m_EmpArray[index] = worker;
		index++;
	}
}
//**********End:将初始文档中的数据读取到列表中**********


//**********Start:显示职工名称**********
void WorkerManager::Show_Emp() {
	if (this->m_FileIsEmpty) {
		cout << "文件为空或不存在!" << endl;
	}
	else {
		for (int i = 0; i < this->m_EmployNum; i++) {
			cout << "****************************************" << endl;
			this->m_EmpArray[i]->showInfo();
		}
	}
}
//**********End:显示职工名称**********


//**********Start:寻找职工位置函数**********
int WorkerManager::Is_Emp_Exit(int id) 
{
	int index = -1;
	for (int i = 0; i < this->m_EmployNum; i++){
		if (this->m_EmpArray[i]->m_ID == id) {
			index = i;
		}
	}
	return index;
}
//**********End:寻找职工位置函数**********


//**********Start:删除职工名称**********
void WorkerManager::Del_Emp() {
	if (this->m_FileIsEmpty) {
		cout << "文件为空!" << endl;
		return;
	}

	int id;
	cout << "请输入想要删除的员工ID：" << endl;
	cin >> id;
	int index = this->Is_Emp_Exit(id);
	if (index != -1) {
		for (int i = index; i < this->m_EmployNum - 1; i++) {
			this->m_EmpArray[i] = this->m_EmpArray[i + 1];
		}
		this->m_EmployNum--;
		this->save();
		cout << "删除成功!" << endl;
	}
	else
		cout << "删除失败，未找到该职工" << endl;
}
//**********End:删除职工名称**********


//**********Start:修改职工名称**********
void WorkerManager::Mod_Emp() {
	if (this->m_FileIsEmpty) {
		cout << "文件为空或不存在!" << endl;
		return;
	}
	int id;
	int index;
	cout << "请输入修改的员工的ID：";
	cin >> id;
	index = this->Is_Emp_Exit(id);
	for (int i = 0; i < this->m_EmployNum; i++) {
		if (this->m_EmpArray[i]->m_ID = id) {
			int choice;
			cout << "1:ID号   2、姓名   3、职位(1：职工  2：经理  3：老板)" << endl;
			cout << "****************************************" << endl;
			cout << "请输入想要修改的内容:";
			cin >> choice;
			switch (choice)
			{
			case 1:
			{
				int new_ID;
				cout << "****************************************" << endl;
				cout << "请输入新的ID号：";
				cin >> new_ID;
				this->m_EmpArray[index]->m_ID = new_ID;
				break;
			}
			case 2:
			{
				string new_Name;
				cout << "****************************************" << endl;
				cout << "请输入新的姓名：";
				cin >> new_Name;
				this->m_EmpArray[index]->m_Name = new_Name;
				break;
			}
			case 3:
			{
				int new_Job;
				cout << "****************************************" << endl;
				cout << "请输入新的职位：";
				cin >> new_Job;
				this->m_EmpArray[index]->m_DeptId = new_Job;
				break;
			}
			default:
				break;
			}
			cout << "修改成功!" << endl;
			break;
		}
	}
	this->save();
}
//**********End:修改职工名称**********


//**********Start:查找职工名称**********
void WorkerManager::Find_Emp() {
	if (this->m_FileIsEmpty) {
		cout << "文件为空或不存在!" << endl;
		return;
	}
	while (true)
	{
		int choice;
		cout << "请输入查找的依据（1、ID号  2、姓名）," << endl;
		cout << "若想强制退出此功能，请输入(3):";
		cin >> choice;
		if (choice == 1)
		{
			int new_ID;
			cout << "请输入要查找的ID号：";
			cin >> new_ID;
			for (int i = 0; i < this->m_EmployNum; i++)
			{
				if (this->m_EmpArray[i]->m_ID == new_ID)
				{
					cout << "查找到了目标员工，信息如下:" << endl;
					this->m_EmpArray[i]->showInfo();
					return;
				}
			}
			cout << "没有查询到相应的员工，请重新输入" << endl;
		}
		else if (choice == 2) {
			string new_name;
			cout << "请输入要查找的姓名：";
			cin >> new_name;
			for (int i = 0; i < this->m_EmployNum; i++)
			{
				if (this->m_EmpArray[i]->m_Name == new_name)
				{
					cout << "查找到了目标员工，信息如下:" << endl;
					this->m_EmpArray[i]->showInfo();
					return;
				}
			}
			cout << "没有查询到相应的员工，请重新输入" << endl;
		}
		else if (choice == 3)
			break;
		else
			cout << "功能选择错误，请重新选择" << endl;
	}
}
//**********End:查找职工名称**********


//**********Start:根据员工编号排序**********
void WorkerManager::Sort_Emp() {
	if (this->m_FileIsEmpty) {
		cout << "文件为空或不存在!" << endl;
		return;
	}
	cout << "请选择排序方式" << endl;
	cout << "1、升序" << "   " << "2、降序" << endl;
	int select;
	cin >> select;
	for (int i = 0; i < this->m_EmployNum - 1; i++)
	{
		int MinOrMax = i;
		for (int j = i; j < this->m_EmployNum; j++)
		{
			if (select == 1)
			{
				if (this->m_EmpArray[i]->m_ID > this->m_EmpArray[j]->m_ID)
					MinOrMax = j;
			}
			else
			{
				if (this->m_EmpArray[i]->m_ID < this->m_EmpArray[j]->m_ID)
					MinOrMax = j;
			}
		}
		if (MinOrMax != i) {
			Worker* temp = this->m_EmpArray[i];
			this->m_EmpArray[i] = this->m_EmpArray[MinOrMax];
			this->m_EmpArray[MinOrMax] = temp;
		}
	}
	save();
	return;
}

//**********End:根据员工编号排序**********


//**********Start:清空数据操作**********
void WorkerManager::Clean_File() {
	cout << "确认清空数据?" << endl;
	cout << "1、确认清空数据" << endl;
	cout << "2、不清空数据" << endl;
	int choice;
	cin >> choice;

	if (choice == 1)
	{
		for (int i = 0; i < this->m_EmployNum; i++) {
			if (this->m_EmpArray[i] != NULL) {
				delete this->m_EmpArray[i];
			}
		}
		delete[] this->m_EmpArray;
		this->m_EmpArray = NULL;
		this->m_EmployNum = 0;
		this->m_FileIsEmpty = true;
		this->save();
		cout << "数据清空成功!" << endl;
	}
	else if (choice == 2)
	{
		return;
	}
}
//**********End:清空数据操作**********

