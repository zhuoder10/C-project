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

	void addPerson();//����˺�

	void showPerson();//�鿴�˺�

	void showComputer();//�鿴������Ϣ

	void clearFile();//���ԤԼ��¼ 

	void initVector();//��ʼ������

	bool checkRepeat(int id, int type);//�ж���û���ظ�

	vector<Student> vStu;//��ѧ����
	vector<Teacher> tStu;//����ʦ������
	vector<computerRoom> vCom;//�洢��������Ϣ
};