#include"boss.h"

boss::boss(int id, string name, int deptId){
	this->id = id;
	this->name = name;
	this->deptId = deptId;
}

void boss::showInfo() {
	cout << "Ա��id��" << this->id << " ";
	cout << "Ա����" << this->name << " ";
	cout << "Ա����" << this->deptId << endl;
}

string boss::getDept() {
	return string("�ϰ�");
}