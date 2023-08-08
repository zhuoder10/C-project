#include"employee.h"

employee::employee(int id, string name, int deptId) {
	this->id = id;
	this->name = name;
	this->deptId = deptId;
};//构造函数

void employee::showInfo() {
	cout << "员工id是" << this->id << " ";
	cout << "员工叫" << this->name << " ";
	cout << "员工在" << this->deptId << endl;

};//显示信息

string employee::getDept() {
	return string("员工");
};//获取部门信息