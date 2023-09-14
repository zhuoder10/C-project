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

	void showOrder();//œ‘ æ‘§‘º

	void validOrder();//…Û∫À‘§‘º


	int empId;
	string name;
	string pwd;
};