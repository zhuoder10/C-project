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

	virtual void openMenu();//�˵�����

	//����ԤԼ
	void applyOrder();

	//�鿴����ԤԼ
	void showMyOrder();

	//�鿴����ԤԼ
	void showAllOrder();

	//ȡ������ԤԼ
	void cancelOrder();

	int id;
	string name;
	string pwd;
	vector<computerRoom> vCom;
};