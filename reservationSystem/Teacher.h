#pragma once
#include<iostream>
using namespace std;
#include"identity.h"
#include"globalFile.h"
#include"orderFile.h"
#include<vector>

class Teacher :public identity {
public:
	Teacher();

	Teacher(int empId,string name,string pwd);

	virtual void openMenu();

	void showOrder();//��ʾԤԼ

	void validOrder();//���ԤԼ


	int empId;
	string name;
	string pwd;
};