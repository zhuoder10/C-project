#include"manager.h"

manager::manager(int id, string name, int deptId) {
	this->id = id;
	this->name = name;
	this->deptId = deptId;
}

void manager::showInfo() {
	cout << "Ա��id��" << this->id << " ";
	cout << "Ա����" << this->name << " ";
	cout << "Ա����" << this->deptId << endl;
}

string manager::getDept() {
	return string("����");
}
