#pragma once
#include<iostream>
using namespace std;
#include"globalFile.h"
#include<fstream>
#include<map>
class orderFile {
public:
	orderFile();

	//����ԤԼ��¼
	void updateOrder();

	//��¼ԤԼ����
	int size;

	map<int, map<string, string>> orderData;//int��ʾ�ڼ�����¼��map��ʾ����ļ�ֵ����Ϣ


};