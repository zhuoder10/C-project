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

	void exitSystem();//退出系统

	void addEmp();//添加新职工

	void save();//将数据存入文件

	bool ifExist();//判断文件是否存在

	int getEmpNum();//获取文件中的人数

	void initEmp();//根据读取到的数据初始化员工数组

	void show();//展示员工名单

	void deleteEmp();//删除职工

	int existEmp(int id);//判断员工是否存在，返回所在数组的索引

	void modifyEmp();//修改职工

	void findEmp();//查找员工

	void sortEmp();//排序员工

	void clearEmp();//清空员工

	~workerManager();

	//记录职工的人数
	int enpNum;

	//记录职工的数组
	worker** empArray;//两个*的意思是：指向worker*的指针，数组中存的是worker*

	bool fileIsEmpty;//打开的文件是否为空
};
