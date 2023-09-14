#pragma once
#include<iostream>
using namespace std;

class identity {//身份的抽象基类

public:
	//操作菜单 纯虚函数
	virtual void openMenu() = 0;

	string name;//用户名
	string pwd;//密码
};