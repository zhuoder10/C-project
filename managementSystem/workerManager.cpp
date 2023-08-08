#include "workerManager.h"

workerManager::workerManager() {//��ʼ��


	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	if (!ifs.is_open()) {//����ļ�������
		cout << "�ļ�������" << endl;
		//��ʼ��
		this->enpNum = 0;
		this->empArray = NULL;
		this->fileIsEmpty = true;
		ifs.close();
		return;
	}
	//����ļ����ڣ�������Ϊ��
	char ch;
	ifs >> ch;
	if (ifs.eof()) {
		this->enpNum = 0;
		this->empArray = NULL;
		this->fileIsEmpty = true;
		ifs.close();
		return;
	}
	//���ļ�������������
	int num = this->getEmpNum();
	cout << "ְ������Ŀǰ�� " << num << endl;
	this->enpNum = num;//�洢��ǰ��ְ������
	this->fileIsEmpty = false;//������ǰ�ļ���Ϊ��
	//���ٿռ䣬����ʼ��
	this->empArray = new worker * [this->enpNum];
	this->initEmp();


}

void workerManager::showMenu() {
	cout << "*********************" << endl;
	cout << "***��ӭʹ��ְ������ϵͳ**" << endl;
	cout << "0.�˳�����ϵͳ" << endl;
	cout << "1.����ְ����Ϣ" << endl;
	cout << "2.��ʾְ����Ϣ" << endl;
	cout << "3.ɾ����ְԱ��" << endl;
	cout << "4.�޸�ְ����Ϣ" << endl;
	cout << "5.����ְ����Ϣ" << endl;
	cout << "6.���ձ������" << endl;
	cout << "7.��������ĵ�" << endl;
	cout << "********************" << endl;
}

void workerManager::exitSystem() {
	cout << "��ӭ�´�ʹ��" << endl;
	system("pause");
	exit(0);
}


void workerManager::addEmp() {
	cout << "���������ְ��������" << endl;
	int addNum = 0;//Ҫ��ӵ�����
	cin >> addNum;

	if (addNum > 0) {

		int newSize = this->enpNum + addNum;//������Ĵ�С

		worker** newSpace = new worker * [newSize];//������Ķ���

		if (this->empArray != NULL) {
			for (int i = 0; i < this->enpNum; i++) {
				newSpace[i] = this->empArray[i];//�ȰѾ���������ݿ�����������
			}
		}

		int empArray[20];//ά��һ���µ�����ȷ����һ����Ӷ����ʱ�򲻻ᵼ���ظ������ͬ��id
		int size = 0;//Ҫά��������ĳ���
		bool flag = false;//���ڰ�����������trueѭ��
		for (int i = 0; i < addNum; i++) {
			int id;
			string name;
			int department;


			while (true) {
				cout << "�������" << i + 1 << "����ְ���ı��" << endl;
				cin >> id;
				flag = true;//������Ϊtrue��������������жϻ���true�����˳�
				if (existEmp(id) != -1) {
					cout << "���������룬��id�Ѿ���ռ��" << endl;
					flag = false;//��ֹ�˳�ѭ��
					continue;
				}
				for (int i = 0; i < size; i++) {
					if (empArray[i] == id) {
						cout << "���������룬��id�Ѿ���ռ��" << endl;
						flag = false;//��ֹ�˳�ѭ��
						break;
					}
				}
				if (flag) {
					break;
				}
			}
			empArray[size] = id;
			size++;//����id����

			cout << "�������" << i + 1 << "����ְ��������" << endl;
			cin >> name;


			cout << "��ѡ��ְ����λ" << endl;
			cout << "1 ְԱ" << endl;
			cout << "2 ����" << endl;
			cout << "3 �ϰ�" << endl;
			cin >> department;
			worker* worker = NULL;//��������Ա��
			switch (department)
			{
			case 1:
				worker = new employee(id, name, 1);
				break;
			case 2:
				worker = new manager(id, name, 2);
				break;
			case 3:
				worker = new boss(id, name, 3);
				break;
			default:
				break;
			}
			newSpace[this->enpNum + i] = worker;//�����Ա����������


		}
		delete[] this->empArray;
		this->empArray = newSpace;//�ͷ�ԭ�ռ䣬ָ���¿ռ�
		this->enpNum = newSize;//��������

		this->fileIsEmpty = false;//����Ϊ�ļ���Ϊ��
		cout << "�ɹ����" << endl;
		save();
	}
	else {
		cout << "��������" << endl;
	}
	system("pause");
	system("cls");//����
}

void workerManager::save() {
	ofstream ofs;
	ofs.open(FILENAME, ios::out);//���д�ļ�

	for (int i = 0; i < this->enpNum; i++) {
		ofs << this->empArray[i]->id << " " << this->empArray[i]->name
			<< " " << this->empArray[i]->deptId << endl;
	}
	ofs.close();
}
int workerManager::getEmpNum() {
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	int id;
	string name;
	int dID;
	int number = 0;

	while (ifs >> id && ifs >> name && ifs >> dID) {//���ifs��ȡ�����᷵��0
		number++;//ͳ������
	}
	return number;
}

void workerManager::initEmp() {
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	int id;
	string name;
	int dId;
	int index = 0;//Ա��������ڴ�
	while (ifs >> id && ifs >> name && ifs >> dId) {//�����˶��в�����ifs�ȶ�ȡ�ո�ǰ��idȻ����name�������did
		worker* worker = NULL;
		if (dId == 1) {
			//Ա��
			worker = new employee(id, name, 1);
		}
		else if (dId == 2) {
			worker = new manager(id, name, 2);
		}
		else
		{
			worker = new manager(id, name, 3);
		}
		this->empArray[index] = worker;
		index++;
	}

	ifs.close();
}

void workerManager::show() {
	//�ж��Ƿ�Ϊ��
	if (this->fileIsEmpty) {
		cout << "��ǰ�ļ�Ϊ��" << endl;
	}
	else {
		for (int i = 0; i < this->enpNum; i++) {
			this->empArray[i]->showInfo();
		}
	}
	system("pause");
	system("cls");
}
/*
* �жϸ����Ƿ����
*/
int workerManager::existEmp(int id) {

	int index = -1;//���鵽id���˵�����
	for (int i = 0; i < this->enpNum; i++) {
		if (this->empArray[i]->id == id) {
			index = i;
			return index;
		}
	}
	return index;

}

void workerManager::deleteEmp() {

	if (this->fileIsEmpty) {
		cout << "�޷�ɾ��" << endl;
	}
	else
	{
		cout << "������Ҫɾ�����˵ı��" << endl;
		int id = 0;
		cin >> id;

		int getReturn = existEmp(id);
		if (getReturn != -1) {
			cout << "�ѽ�" << this->empArray[getReturn]->name << "Ա��ɾ�� ";
			for (int i = getReturn; i < this->enpNum - 1; i++) {
				this->empArray[i] = this->empArray[i + 1];
			}
			this->enpNum--;//ɾ����Ա
			this->save();//�����ļ�
		}
		else {
			cout << "ɾ��ʧ�� δ�ҵ���ְ��" << endl;
		}
		system("pause");
		system("cls");
	}




}

void workerManager::modifyEmp() {
	if (this->fileIsEmpty) {
		cout << "�ļ������ڻ�Ϊ��" << endl;

	}
	else {
		cout << "�������޸�ְ���ı��" << endl;
		int id;
		cin >> id;

		int getReturn = this->existEmp(id);
		if (getReturn != -1) {
			delete this->empArray[getReturn];//ɾ��ԭ�������������

			int newID = 0;
			string newName = "";
			int depart = 0;
			cout << "�鵽 " << id << "��ְ�����������µ�ְ����: " << endl;
			cin >> newID;
			cout << "������������" << endl;
			cin >> newName;
			cout << "�������λ" << endl;
			cin >> depart;

			worker* newWorker = NULL;
			switch (depart) {
			case 1:
				newWorker = new employee(newID, newName, depart);
			case 2:
				newWorker = new manager(newID, newName, depart);
			case 3:
				newWorker = new boss(newID, newName, depart);
			}
			this->empArray[getReturn] = newWorker;//�����޸ĺ��Ա��
			cout << "�޸ĳɹ�" << endl;
			this->save();
		}
		else {
			cout << "δ���ҵ���ְ��" << endl;
		}
		system("pause");
		system("cls");

	}
}

void workerManager::findEmp() {
	if (this->fileIsEmpty) {
		cout << "�ļ������ڻ���Ϊ��" << endl;
	}
	else
	{
		cout << "����ҵķ�ʽ�ǣ�" << endl;
		cout << "1 ����������" << endl;
		cout << "2 ��id����" << endl;

		int select = 0;
		cin >> select;
		if (select == 1) {
			string name;
			cout << "������Ҫ���ҵ��˵�����" << endl;
			cin >> name;
			int flag = false;//�ж��Ƿ��ҵ�ְ��
			for (int i = 0; i < this->enpNum; i++) {
				if (this->empArray[i]->name == name) {
					cout << "���ҵ��˸�Ա��,����� " << this->empArray[i]->id << endl;
					this->empArray[i]->showInfo();
					flag = true;
				}
			}
			if (flag == false) {
				cout << "����ʧ��" << endl;
			}
		}
		else if (select == 2) {
			int id;
			cout << "������ҵı��" << endl;
			cin >> id;

			int ret = existEmp(id);
			if (ret != -1) {
				cout << "�ҵ��������" << endl;
				cout << "��Ϣ����" << endl;
				this->empArray[ret]->showInfo();//չʾ�鵽������˵���Ϣ
			}
			else {
				cout << "���޴���" << endl;
			}
		}
		else {
			cout << "����ѡ������" << endl;
		}
	}
	system("pause");
	system("cls");
}

void workerManager::sortEmp() {

	if (this->fileIsEmpty) {
		cout << "�ļ������ڻ�Ϊ��" << endl;
		system("pause");
		system("cls");
	}
	else {
		cout << "ѡ������ʽ 1���� 2����" << endl;
		int select = 0;
		cin >> select;
		for (int i = 0; i < this->enpNum; i++) {
			int minOrMax = i;//�±�
			for (int j = i + 1; j < this->enpNum; j++) {
				if (select == 1) {
					if (this->empArray[minOrMax]->id > this->empArray[j]->id) {
						minOrMax = j;//�����±�
					}
				}
				else {
					if (this->empArray[minOrMax]->id < this->empArray[j]->id) {
						minOrMax = j;
					}
				}
			}
			if (minOrMax != i) {//�����Сֵ�������ֵ������һ��ʼ��i
				worker* temp = this->empArray[i];
				this->empArray[i] = this->empArray[minOrMax];
				this->empArray[minOrMax] = temp;//����Ԫ��
			}
		}
	}

	cout << "����ɹ�������ǣ� " << endl;
	this->save();
	this->show();//չʾ�����Ľ��


}

void workerManager::clearEmp() {
	if (this->fileIsEmpty) {
		cout << "�ļ�Ϊ�ջ򲻴���" << endl;
	}
	else {

		cout << "ȷ����1ȷ�� 2����" << endl;
		int select = 0;
		cin >> select;

		if (select == 1) {
			ofstream ofs(FILENAME, ios::trunc);//ɾ���ļ��������´���
			ofs.close();
			if (this->empArray != NULL) {
				for (int i = 0; i < this->enpNum; i++) {
					delete this->empArray[i];//ɾ���������ÿһ��Ԫ��
					this->empArray[i] = NULL;
				}
				//ɾ��ָ�������ָ��
				delete[] this->empArray;
				this->empArray = NULL;
				this->enpNum = 0;//�������
				this->fileIsEmpty = true;
				cout << "��ճɹ�" << endl;
			}
			
		}
	}
	system("pause");
	system("cls");
}

workerManager::~workerManager() {

}
