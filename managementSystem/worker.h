#pragma once
#include<iostream>
using namespace std;
#include<string>

class worker {
public:

	virtual void showInfo() = 0;//��ʾ��Ϣ

	virtual string getDept() = 0;//��ȡ������Ϣ

	int id;
	string name;
	int deptId;

};
