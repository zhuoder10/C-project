#pragma once
#include<iostream>
using namespace std;
#include<string>
#include"worker.h"

class manager :public worker {
public:

	manager(int id, string name, int deptId);//构造函数

	void showInfo();//显示信息

	string getDept();//获取部门信息


};