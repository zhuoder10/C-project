#pragma once
#include<iostream>
using namespace std;
#include<string>
#include"worker.h"

class manager :public worker {
public:

	manager(int id, string name, int deptId);//���캯��

	void showInfo();//��ʾ��Ϣ

	string getDept();//��ȡ������Ϣ


};