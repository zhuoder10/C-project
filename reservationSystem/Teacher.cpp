#include"teacher.h"

Teacher::Teacher() {

};

Teacher::Teacher(int empId, string name, string pwd) {
	this->name = name;
	this->empId = empId;
	this->pwd = pwd;

}
void Teacher::openMenu() {
	cout << "��ӭ��ʦ�� " << this->name << "��¼��" << endl;
	cout << "1.�鿴����ԤԼ" << endl;
	cout << "2.���ԤԼ\t" << endl;
	cout << "0.ע����¼\t" << endl;
	cout << "��ѡ�����Ĳ���\t" << endl;
}

void Teacher::showOrder() {
	orderFile ord;
	if (ord.size == 0) {
		cout << "��ԤԼ��¼" << endl;
		system("pause");
		system("cls");
		return;
	}
	for (int i = 0; i < ord.size; i++) {
		cout << i + 1 << " " << "ԤԼ���ڣ���" << ord.orderData[i]["date"];
		cout << " ʱ��Σ�" << (ord.orderData[i]["interval"] == "1" ? "����" : "����");
		cout << "ѧ��: " << ord.orderData[i]["stuId"];
		cout << "����: " << ord.orderData[i]["stuName"];
		cout << "������ " << ord.orderData[i]["roomId"];
		string status = "״̬�� ";
		if (ord.orderData[i]["status"] == "1") {
			status += "�����";
		}
		else if (ord.orderData[i]["status"] == "2") {
			status += "ԤԼ�ɹ�";
		}
		else if (ord.orderData[i]["status"] == "-1") {
			status += "ԤԼʧ�ܣ����δͨ��";
		}
		else {
			status += "ԤԼ��ȡ��";
		}
		cout << status << endl;
	}
	system("pause");
	system("cls");
}
void Teacher::validOrder() {
	orderFile ord;
	if (ord.size == 0) {
		cout << "��ԤԼ��¼" << endl;
		system("pause");
		system("cls");
		return;
	}

	cout << "����˵ļ�¼����" << endl;
	vector<int> v;
	int index = 0;
	for (int i = 0; i < ord.size; i++) {
		if (ord.orderData[i]["status"] == "1") {
			v.push_back(i);//�������˵ļ�¼������
			cout << ++index << " ";
			cout << "ԤԼ���ڣ���" << ord.orderData[i]["date"];
			cout << " ʱ��Σ�" << (ord.orderData[i]["interval"] == "1" ? "����" : "����");
			cout << "ѧ��: " << ord.orderData[i]["stuId"];
			cout << "����: " << ord.orderData[i]["stuName"];
			cout << "������ " << ord.orderData[i]["roomId"];
			string status = "״̬�������";
			cout << status << endl;
		}
	}
	cout << "��������˵�ԤԼ��¼��0��ʾ����" << endl;
	int select;
	while (true) {
		cin >> select;
		if (select >= 0 || select <= v.size()) {
			if (select == 0) {
				break;
			}
			else {
				cout << "��������˵Ľ��" << endl;
				cout << "1 ͨ�� 2 ��ͨ��" << endl;
				int choice;
				cin >> choice;
				if (choice == 1) {
					//ͨ��
					ord.orderData[v[select - 1]]["status"] = "2";
				}
				else {
					ord.orderData[v[select - 1]]["status"] = "-1";
				}
				ord.updateOrder();
				//��������
				cout << "������" << endl;
				break;
			}
		}
		else {
			cout << "��Ч����" << endl;
		}
	}
	system("pause");
	system("cls");
}
