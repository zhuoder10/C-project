#pragma once
#include<iostream>
using namespace std;
#include"globalFile.h"
#include<fstream>
#include<map>
class orderFile {
public:
	orderFile();

	//更新预约记录
	void updateOrder();

	//记录预约条数
	int size;

	map<int, map<string, string>> orderData;//int表示第几个记录，map表示具体的键值对信息


};