#include"manager.h"
#include"globalFile.h"
#include<fstream>

Manager::Manager() {

};

Manager::Manager(string name, string pwd) {
	//��ʼ������Ա��Ϣ
	this->name = name;
	this->pwd = pwd;

	this->initVector();//��ʼ������

	ifstream ifs;
	ifs.open(COMPUTER_FILE, ios::in);
	computerRoom com;
	while (ifs >> com.comId && ifs >> com.maxNum) {
		vCom.push_back(com);
	}
	ifs.close();
	cout << "������������ " << vCom.size() << endl;
}

void Manager::openMenu() {
	cout << "��ӭ����Ա: " << this->name << "��¼��" << endl;
	cout << "1.����˺�" << endl;
	cout << "2.�鿴�˺�" << endl;
	cout << "3.�鿴����" << endl;
	cout << "4.���ԤԼ" << endl;
	cout << "0.ע���˺�" << endl;
};

void Manager::addPerson() {
	cout << "��������ӵ��˺ŵ�����" << endl;
	cout << "1.���ѧ��" << endl;
	cout << "2.�����ʦ" << endl;

	string fileName;
	string tip;//��ʾid��
	string errorTip;//����������ʾ

	ofstream ofs;
	int select = 0;
	cin >> select;

	if (select == 1) {
		fileName = STUDENT_FILE;
		tip = "������ѧ��";
		errorTip = "ѧ���ظ�������������";
	}
	else {
		fileName = TEACHER_FILE;
		tip = "������ְ����";
		errorTip = "ְ�����ظ�������������";
	}

	ofs.open(fileName, ios::out | ios::app);//׷�ӵķ�ʽд�ļ�
	int id;
	string name;
	string pwd;

	cout << tip << endl;

	while (true) {
		cin >> id;
		bool ret = checkRepeat(id, select);
		if (ret) {//���ظ�
			cout << errorTip;
		}
		else {
			break;
		}
	}

	cout << "������������ " << endl;
	cin >> name;

	cout << "���������� " << endl;
	cin >> pwd;
	//���ļ����������
	ofs << id << " " << name << " " << pwd << " " << endl;
	cout << "��ӳɹ�" << endl;
	system("pause");
	system("cls");
	ofs.close();
	this->initVector();//��������
};

void Manager::clearFile() {

	ofstream ofs(ORDER_FILE,ios::trunc);//����ļ�
	ofs.close();

	cout << "��ճɹ�" << endl;
	system("pause");
	system("cls");


}
void printStudent(Student& s) {
	cout << "ѧ�� " << s.id << "������ " << s.name << "����" << s.pwd << endl;

}
void printTeacher(Teacher& t) {
	cout << "ְ���� " << t.empId << "������ " << t.name << "����" << t.pwd << endl;

}


void Manager::showPerson() {
	cout << "��ѡ��鿴����" << endl;
	cout << "1.�鿴����ѧ��" << endl;
	cout << "2.�鿴������ʦ" << endl;

	int select = 0;
	cin >> select;
	if (select == 1) {
		//��ѧ��
		cout << "����Ϊѧ����Ϣ" << endl;
		for_each(vStu.begin(), vStu.end(), printStudent);//������ӡ����

	}
	else {
		cout << "����Ϊ��ʦ��Ϣ" << endl;
		for_each(tStu.begin(), tStu.end(), printTeacher);
	}
	system("pause");
	system("cls");
}

void Manager::showComputer() {

	cout << "������Ϣ����" << endl;
	for (vector<computerRoom>::iterator it = vCom.begin(); it != vCom.end(); it++) {
		cout << "�������" << it->comId << "����������� " << it->maxNum << endl;
	}
	system("pause");
	system("cls");

}

void Manager::initVector() {
	vStu.clear();
	tStu.clear();//�������
	//��ȡ��Ϣ
	ifstream ifs;
	ifs.open(STUDENT_FILE, ios::in);
	if (!ifs.is_open()) {
		cout << "�ļ���ȡʧ��" << endl;
		return;
	}

	Student s;
	while (ifs >> s.id && ifs >> s.name && ifs >> s.pwd) {
		vStu.push_back(s);//һ��һ�еĶ�ȡѧ���ļ�
	}
	cout << "��ǰѧ������Ϊ " << vStu.size() << endl;
	ifs.close();

	//��ȡ��ʦ��Ϣ
	ifs.open(TEACHER_FILE, ios::in);
	Teacher t;
	while (ifs >> t.empId && ifs >> t.name && ifs >> t.pwd) {
		tStu.push_back(t);
	}
	cout << "��ǰ��ʦ������ " << tStu.size() << endl;
	ifs.close();

}
bool Manager::checkRepeat(int id, int type) {
	if (type == 1) {
		//���ѧ��
		for (vector<Student>::iterator it = vStu.begin(); it != vStu.end(); it++) {
			if (id == it->id) {
				return true;
			}
		}
	}
	else {//�����ʦ
		for (vector<Teacher>::iterator it = tStu.begin(); it != tStu.end(); it++) {
			if (id == it->empId) {
				return true;
			}
		}
	}
	return false;
}
