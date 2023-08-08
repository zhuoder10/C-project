#pragma once
#include<iostream>
using namespace std;
#include<string>

class worker {
public:

	virtual void showInfo() = 0;//显示信息

	virtual string getDept() = 0;//获取部门信息

	int id;
	string name;
	int deptId;

};
