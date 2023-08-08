#include"manager.h"

manager::manager(int id, string name, int deptId) {
	this->id = id;
	this->name = name;
	this->deptId = deptId;
}

void manager::showInfo() {
	cout << "员工id是" << this->id << " ";
	cout << "员工叫" << this->name << " ";
	cout << "员工在" << this->deptId << endl;
}

string manager::getDept() {
	return string("经理");
}
