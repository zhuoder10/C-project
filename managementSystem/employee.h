#pragma once
#include<iostream>
using namespace std;
#include<string>
#include"worker.h"

class employee :public worker {//����ְ�����࣬�̳���worker
public:

	employee(int id, string name, int deptId);//���캯��

	void showInfo();//��ʾ��Ϣ

	string getDept();//��ȡ������Ϣ
};