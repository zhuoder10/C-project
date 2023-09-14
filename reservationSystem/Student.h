#pragma once
#include<iostream>
using namespace std;
#include"identity.h"
#include<fstream>
#include"globalFile.h"
#include"computerRoom.h"
#include<vector>
#include"orderFile.h"

class Student :public identity {
public:
	Student();

	Student(int id,string name,string pwd);

	virtual void openMenu();//菜单界面

	//申请预约
	void applyOrder();

	//查看自身预约
	void showMyOrder();

	//查看所有预约
	void showAllOrder();

	//取消所有预约
	void cancelOrder();

	int id;
	string name;
	string pwd;
	vector<computerRoom> vCom;
};