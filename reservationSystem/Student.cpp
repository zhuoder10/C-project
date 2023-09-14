#include"student.h"

Student::Student() {

};

Student::Student(int id, string name, string pwd) {
	this->id = id;
	this->name = name;
	this->pwd = pwd;

	ifstream ifs;
	ifs.open(COMPUTER_FILE, ios::in);
	computerRoom com;
	while (ifs >> com.comId && ifs >> com.maxNum) {
		vCom.push_back(com);//�����л�����Ϣ��ȡ��������
	}
	ifs.close();


}
void Student::openMenu() {
	cout << "��ӭѧ������" << this->name << "��¼��" << endl;
	cout << "1.����ԤԼ" << endl;
	cout << "2.�鿴ԤԼ" << endl;
	cout << "3.�鿴����ԤԼ" << endl;
	cout << "4.ȡ��ԤԼ" << endl;
	cout << "0.ע����¼" << endl;
}

void Student::applyOrder() {
	//���뷿��
	cout << "�ܼ���ԤԼ��" << endl;
	cout << "����������ԤԼ��ʱ��" << endl;
	cout << "1-5 Ϊ��һ������" << endl;
	int date = 0;
	int interval = 0;//ʱ���
	int room;
	while (true) {
		cin >> date;
		if (date >= 1 && date <= 5) {
			break;
		}
		else {
			cout << "��������" << endl;
		}
	}
	cout << "�����������ʱ���" << endl;
	cout << "1 ���� 2 ����" << endl;
	while (true) {

		cin >> interval;
		if (interval >= 1 && interval <= 2) {
			break;
		}
		else {
			cout << "��������" << endl;
		}
	}
	cout << "��ѡ�����" << endl;
	for (int i = 0; i < vCom.size(); i++) {
		cout << vCom[i].comId << "�ŷ���������" << vCom[i].maxNum << endl;
	}

	while (true) {
		cin >> room;
		if (room >= 1 && room <= 3) {
			break;

		}
		else {
			cout << "��������" << endl;
		}
	}

	cout << "ԤԼ�ɹ�,�������" << endl;

	ofstream ofs;
	ofs.open(ORDER_FILE, ios::app);
	ofs << "date:" << date << " ";//�����ָ�����Ϊ��ȡʱ���տո�ָ�����ָ���Ի��ÿ����Ϣ
	ofs << "inteval:" << interval << " ";
	ofs << "stuId:" << this->id << " ";
	ofs << "stuName:" << this->name << " ";
	ofs << "roomId:" << room << " ";
	ofs << "status:" << 1 << endl;
	ofs.close();
	system("pause");
	system("cls");
}

void Student::showMyOrder() {
	orderFile ord;
	if (ord.size == 0) {
		cout << "��ԤԼ��¼" << endl;
		system("pause");
		system("cls");
		return;
	}
	else {
		for (int i = 0; i < ord.size; i++) {
			//��ΪҪ�鿴�����ԤԼ������Ҫ�ͱ���ĶԱ�id��
			if (this->id == atoi(ord.orderData[i]["stuId"].c_str())) {////���洢���ַ���תΪint����
				//�ҵ�����ԤԼ
				cout << "ԤԼ�����ǣ� ��" << ord.orderData[i]["date"];
				cout << "ʱ����ǣ� " << (ord.orderData[i]["interval"] == "1" ? "����" : "����");
				cout << "��������: " << ord.orderData[i]["roomId"];
				string status = "״̬: ";
				//1����� 2��ԤԼ -1ԤԼʧ�� 0ȡ��ԤԼ
				if (ord.orderData[i]["status"] == "1") {
					cout << status + "�����" << endl;
				}
				else if (ord.orderData[i]["status"] == "2") {
					cout << status + "ԤԼ�ɹ�" << endl;
				}
				else if (ord.orderData[i]["status"] == "-1") {
					cout << status + "ԤԼʧ��" << endl;
				}
				else if (ord.orderData[i]["status"] == "0") {
					cout << status + "ԤԼ��ȡ��" << endl;
				}
			};
		}
	}
	system("pause");
	system("cls");
}

void Student::showAllOrder() {//��ʾ�����˵�ԤԼ��¼
	orderFile ord;
	if (ord.size == 0) {
		cout << "��ԤԼ��¼" << endl;
		system("pause");
		system("cls");
		return;
	}

	for (int i = 0; i < ord.size; i++) {
		cout << i + 1 << " ";
		cout << " ԤԼʱ�䣺 ��" << ord.orderData[i]["date"];
		cout << " ʱ���: " << (ord.orderData[i]["interval"] == "1" ? "����" : "����");
		cout << " ѧ��: " << ord.orderData[i]["stuId"];
		cout << " ������ " << ord.orderData[i]["stuName"];
		cout << " �������: " << ord.orderData[i]["roomId"];
		string status = "״̬: ";
		if (ord.orderData[i]["status"] == "1") {
			cout << status + "�����";
		}
		else if (ord.orderData[i]["status"] == "2") {
			cout << status + "��ԤԼ";
		}
		else if (ord.orderData[i]["status"] == "-1") {
			cout << status + "ԤԼʧ��";
		}
		else {
			cout << status + "ԤԼȡ��";
		}
		cout << endl;
	}
	system("pause");
	system("cls");
}

void Student::cancelOrder() {//ȡ��ԤԼ
	orderFile of;//���ļ����ȡ��Ϣ
	if (of.size == 0) {
		cout << "��ԤԼ��¼" << endl;
		system("pause");
		system("cls");
		return;
	}

	cout << "����л���ԤԼ�ɹ��ļ�¼����ȡ��,������Ҫȡ���ļ�¼" << endl;
	vector<int> v;//�������������±���
	int index = 1;
	for (int i = 0; i < of.size; i++) {//��ӡһ�¿���ȡ����ԤԼ��¼
		if (this->id == atoi(of.orderData[i]["stuId"].c_str())) {//��ƥ��ѧ��һ��
			if (of.orderData[i]["status"] == "1" || of.orderData[i]["status"] == "2") {//��ɸѡ״̬��ֻѡ������л���ԤԼ�ɹ���
				v.push_back(i);//����Ҫȡ��������
				cout << index << " ";
				index++;
				cout << "ԤԼ���ڣ� ��" << of.orderData[i]["date"];
				cout << " ʱ��Σ� " << (of.orderData[i]["interval"] == "1" ? "����" : "����");
				cout << " �������: " << of.orderData[i]["roomId"];
				string status = "״̬: ";
				if (of.orderData[i]["status"] == "1") {
					status += "�����";
				}
				else if (of.orderData[i]["status"] == "2") {
					status += "ԤԼ�ɹ�";
				}
				cout << status << endl;
			}
		}
	}
	cout << "������ȡ���ļ�¼��0������" << endl;
	int select = 0;
	while (true) {
		cin >> select;
		if (select >= 0 && select <= v.size()) {
			if (select == 0) {
				//ȡ������
				break;
			}
			else {
				of.orderData[v[select - 1]]["status"] = "0";//��v������ȡ��Ҫɾ��������������Ϊ0����δԤԼ
				of.updateOrder();//���¼�¼�����浽�ļ���
				cout << "��ȡ��" << endl;
				break;
			}
		}
		cout << "������������������" << endl;
	}
	system("pause");
	system("cls");
}
