#include<iostream>
using namespace std;
#include"identity.h"
#include"student.h"
#include"teacher.h"
#include"manager.h"
#include<fstream>
#include"globalFile.h"

void managerMenu(identity* manager) {//����Ա���Ӳ˵�
	while (true) {
		//�����Ӳ˵�
		manager->openMenu();
		//������ָ��תΪ����ָ�룬��������������ӿ�
		Manager* man = (Manager*)manager;

		int select = 0;
		cin >> select;//����ѡ��
		if (select == 1) {//����˺�
			man->addPerson();
			cout << "����˺�" << endl;
		}
		else if (select == 2) {//�鿴�˺�
			cout << "�鿴�˺�" << endl;
			man->showPerson();
		}
		else if (select == 3) {//�鿴����
			cout << "�鿴����" << endl;
			man->showComputer();
		}
		else if (select == 4) {
			cout << "���ԤԼ" << endl;
			man->clearFile();
		}
		else {//ע����¼
			delete manager;
			cout << "ע���ɹ�" << endl;
			system("pause");
			system("cls");
			return;
		}

	}
}

//ѧ���Ӳ˵�
void studentMenu(identity*& student) {
	while (true) {
		student->openMenu();
		Student* stu = (Student*)student;//ǿת
		int select = 0;
		cin >> select;
		if (select == 1) {
			cout << "����ԤԼ" << endl;
			stu->applyOrder();
		}
		else if (select == 2) {
			cout << "�鿴����ԤԼ" << endl;
			stu->showMyOrder();
		}
		else if (select == 3) {
			cout << "�鿴������ԤԼ" << endl;
			stu->showAllOrder();
		}
		else if (select == 4) {
			cout << "ȡ����¼" << endl;
			stu->cancelOrder();
		}
		else {
			cout << "ע����¼" << endl;
			delete student;
			cout << "ע���ɹ�" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}
//��ʦ�Ӳ˵�
void teacherMenu(identity*& teacher) {
	while (true) {
		teacher->openMenu();//�����˵�
		//ͬ��Ҫ�����������еĺ�����Ҫ��תΪ����ָ��
		Teacher* tea = (Teacher*)teacher;//ǿ��ת��
		int select = 0;
		cin >> select;
		if (select == 1) {//�鿴����ԤԼ
			tea->showOrder();
		}
		else if (select == 2) {//���ԤԼ
			tea->validOrder();
		}
		else {
			delete teacher;//���ڴ���ɾ��
			cout << "ע���ɹ�" << endl;
			system("pasue");
			system("cls");
			return;
		}
	}
}


void login(string fileName, int type) {//��¼����,type��ʾ�������
	identity* person = NULL;//������������ָ������

	//���ļ�
	ifstream ifs;
	ifs.open(fileName, ios::in);
	if (!ifs.is_open()) {
		cout << " �ļ�������" << endl;
		ifs.close();
		return;
	}
	//׼��������Ϣ
	int id = 0;
	string name;
	string pwd;
	//�ж����
	if (type == 1) {
		cout << "���������ѧ��" << endl;
		cin >> id;
	}
	else if (type == 2) {
		cout << "���������ְ����" << endl;
		cin >> id;
	}
	cout << "�������û���" << endl;
	cin >> name;
	cout << "����������" << endl;
	cin >> pwd;

	if (type == 1) {
		//ѧ�������֤
		int fId;//�ļ��ж�ȡ��id
		string fName;//�ļ��л�ȡ������
		string fPwd;//���ļ��л�ȡ����
		while (ifs >> fId && ifs >> fName && ifs >> fPwd) {//��ȡ�ļ������Ϣ
			if (fId == id && fName == name && fPwd == pwd) {
				cout << "ѧ����֤��½�ɹ�" << endl;
				system("pause");
				system("cls");
				person = new Student(id, name, pwd);//ָ���½���ѧ��
				//����ѧ����ݵ��Ӳ˵�
				studentMenu(person);
				return;
			}
		}
		cout << "δ�ҵ���ѧ����������������Ϣ" << endl;
		system("pause");
		system("cls");
	}
	else if (type == 2) {
		//��ʦѧ����֤
		int fId;
		string fName;
		string fPwd;
		while (ifs >> fId && ifs >> fName && ifs >> fPwd) {
			if (fId == id && fName == name && fPwd == pwd) {
				cout << "��ʦ��½�ɹ�" << endl;
				system("pause");
				system("cls");
				person = new Teacher(id, name, pwd);
				//�����ʦ���Ӳ˵�
				teacherMenu(person);
				return;
			}
		}
	}
	else {
		//����Ա�����֤
		string fName;
		string fPwd;
		while (ifs >> fName && ifs >> fPwd) {
			if (name == fName && fPwd == pwd) {
				cout << "����Ա��֤�ɹ�" << endl;
				system("pause");
				system("cls");
				person = new Manager(name, pwd);
				managerMenu(person);//����manager�Ӳ˵�
				return;
			}
		}
		cout << "��֤ʧ��" << endl;
	}
}


int main() {

	int select = 0;//���ڽ����û���ѡ��
	while (true) {

		cout << endl << "�������������" << endl;
		cout << "\t\t ---------------------\n";
		cout << "\t\t" << "|1.ѧ������|" << endl;
		cout << "\t\t" << "|2.��ʦ|" << endl;
		cout << "\t\t" << "|3.����Ա|" << endl;
		cout << "\t\t" << "|0.�˳�|" << endl;
		cout << "\t\t ---------------------\n";
		cout << "����������ѡ��: ";

		cin >> select;

		switch (select) {

		case 1://ѧ�����
			login("student.txt", 1);
			break;
		case 2://��ʦ���
			login(TEACHER_FILE, 2);
			break;
		case 3://����Ա���
			login(ADMIN_FILE, 3);
			break;
		case 0://�˳�ϵͳ
			cout << "��ӭ��һ��ʹ��" << endl;
			system("pause");
			return 0;
		default:
			cout << "�������� ����ѡ��" << endl;
			system("pause");
			system("cls");
			break;
		}
	}
}