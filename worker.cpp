#include "worker.h"

//**********Start:Employer类成员函数**********
Employee::Employee(int id, string name, int dId)
{
	this->m_ID = id;
	this->m_Name = name;
	this->m_DeptId = dId;
}

void Employee::showInfo() {
	cout << "员工编号：" << this->m_ID << endl;
	cout << "员工姓名：" << this->m_Name << endl;
	cout << "员工岗位：" << this->m_DeptId << endl;
}

string Employee::getDeptName() {
	return string("员工");
}
//**********End:Employer类成员函数**********


//**********Start:Manager类成员函数**********
Manager::Manager(int id, string name, int dId)
{
	this->m_ID = id;
	this->m_Name = name;
	this->m_DeptId = dId;
}

void Manager::showInfo() {
	cout << "员工编号：" << this->m_ID << endl;
	cout << "员工姓名：" << this->m_Name << endl;
	cout << "员工岗位：" << this->m_DeptId << endl;
}

string Manager::getDeptName() {
	return string("经理");
}
//**********End:Manager类成员函数**********


//**********Start:Boss类成员函数**********
Boss::Boss(int id, string name, int dId)
{
	this->m_ID = id;
	this->m_Name = name;
	this->m_DeptId = dId;
}

void Boss::showInfo() {
	cout << "员工编号：" << this->m_ID << endl;
	cout << "员工姓名：" << this->m_Name << endl;
	cout << "员工岗位：" << this->m_DeptId << endl;
}

string Boss::getDeptName() {
	return string("老板");
}
//**********End:Boss类成员函数**********


