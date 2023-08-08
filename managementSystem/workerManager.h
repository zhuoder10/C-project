#pragma once
#include<iostream>
using namespace std;
#include"worker.h"
#include"employee.h"
#include"manager.h"
#include"boss.h"
#include<fstream>
#define FILENAME "empFile.txt"

class workerManager {
public:
	workerManager();

	void showMenu();

	void exitSystem();//�˳�ϵͳ

	void addEmp();//�����ְ��

	void save();//�����ݴ����ļ�

	bool ifExist();//�ж��ļ��Ƿ����

	int getEmpNum();//��ȡ�ļ��е�����

	void initEmp();//���ݶ�ȡ�������ݳ�ʼ��Ա������

	void show();//չʾԱ������

	void deleteEmp();//ɾ��ְ��

	int existEmp(int id);//�ж�Ա���Ƿ���ڣ������������������

	void modifyEmp();//�޸�ְ��

	void findEmp();//����Ա��

	void sortEmp();//����Ա��

	void clearEmp();//���Ա��

	~workerManager();

	//��¼ְ��������
	int enpNum;

	//��¼ְ��������
	worker** empArray;//����*����˼�ǣ�ָ��worker*��ָ�룬�����д����worker*

	bool fileIsEmpty;//�򿪵��ļ��Ƿ�Ϊ��
};
