#include"employee.h"

employee::employee(int id, string name, int deptId) {
	this->id = id;
	this->name = name;
	this->deptId = deptId;
};//���캯��

void employee::showInfo() {
	cout << "Ա��id��" << this->id << " ";
	cout << "Ա����" << this->name << " ";
	cout << "Ա����" << this->deptId << endl;

};//��ʾ��Ϣ

string employee::getDept() {
	return string("Ա��");
};//��ȡ������Ϣ