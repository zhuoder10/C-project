#pragma once
#include<iostream>
#include<vector>
#include"student.h"
#include"teacher.h"
using namespace std;
#include"identity.h"
#include<algorithm>
#include"computerRoom.h"

class Manager :public identity {
public:

	Manager();

	Manager(string name, string pwd);

	virtual void openMenu();

	void addPerson();//添加账号

	void showPerson();//查看账号

	void showComputer();//查看机房信息

	void clearFile();//清空预约记录 

	void initVector();//初始化容器

	bool checkRepeat(int id, int type);//判断有没有重复

	vector<Student> vStu;//存学生的
	vector<Teacher> tStu;//村老师的容器
	vector<computerRoom> vCom;//存储机房的信息
};