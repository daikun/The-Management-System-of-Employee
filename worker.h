#pragma once

#include<iostream>
#include<string>
#include<fstream>

using namespace std;

//**********Start:Worker类**********
class Worker
{
public:
	virtual void showInfo() = 0;
	virtual string getDeptName() = 0;

	int m_ID;
	string m_Name;
	int m_DeptId;
};
//**********End:Worker类**********


//**********Start:Employee类**********
class Employee :public Worker
{
public:
	Employee(int id, string name, int dId);
	virtual void showInfo();
	virtual string getDeptName();

};
//**********End:Employee类**********


//**********Start:Manager类**********
class Manager :public Worker
{
public:
	Manager(int id, string name, int dId);
	virtual void showInfo();
	virtual string getDeptName();

};
//**********End:Manager类**********


//**********Start:Boss类**********
class Boss :public Worker
{
public:
	Boss(int id, string name, int dId);
	virtual void showInfo();
	virtual string getDeptName();

};
//**********End:Boss类**********
