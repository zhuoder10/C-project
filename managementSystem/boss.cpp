#include"boss.h"

boss::boss(int id, string name, int deptId){
	this->id = id;
	this->name = name;
	this->deptId = deptId;
}

void boss::showInfo() {
	cout << "员工id是" << this->id << " ";
	cout << "员工叫" << this->name << " ";
	cout << "员工在" << this->deptId << endl;
}

string boss::getDept() {
	return string("老板");
}