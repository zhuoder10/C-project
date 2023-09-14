#include"orderFile.h"

orderFile::orderFile() {
	ifstream ifs;
	ifs.open(ORDER_FILE, ios::in);
	//��¼ԤԼ������
	string date;
	string interval;
	string stuId;
	string stuName;
	string roomId;
	string status;

	this->size = 0;
	while (ifs >> date && ifs >> interval && ifs >> stuId && ifs >> stuName
		&& ifs >> roomId && ifs >> status) {//���ж�ȡ,ÿ��һ�������ڲ���һ�Σ���ȡһ��ʱ������Ԫ�ش������ֵ
		string key;
		string value;
		map<string, string> m;//׼������������
		int pos = date.find(":");
		if (pos != -1) {//�ҵ��ˣ���Ų���
			key = date.substr(0, pos);//��ȡ��ǰ������
			value = date.substr(pos + 1, date.size() - 1);//��ȡ���������
			m.insert(make_pair(key, value));//����map��
		}

		pos = interval.find(":");
		if (pos != -1) {//�ҵ��ˣ���Ų���
			key = interval.substr(0, pos);//��ȡ��ǰ������
			value = interval.substr(pos + 1, interval.size() - 1);//��ȡ���������
			m.insert(make_pair(key, value));//����map��
		}

		pos = stuId.find(":");
		if (pos != -1) {//�ҵ��ˣ���Ų���
			key = stuId.substr(0, pos);//��ȡ��ǰ������
			value = stuId.substr(pos + 1, stuId.size() - 1);//��ȡ���������
			m.insert(make_pair(key, value));//����map��
		}

		pos = stuName.find(":");
		if (pos != -1) {//�ҵ��ˣ���Ų���
			key = stuName.substr(0, pos);//��ȡ��ǰ������
			value = stuName.substr(pos + 1, stuName.size() - 1);//��ȡ���������
			m.insert(make_pair(key, value));//����map��
		}

		pos = roomId.find(":");
		if (pos != -1) {//�ҵ��ˣ���Ų���
			key = roomId.substr(0, pos);//��ȡ��ǰ������
			value = roomId.substr(pos + 1, roomId.size() - 1);//��ȡ���������
			m.insert(make_pair(key, value));//����map��
		}

		pos = status.find(":");
		if (pos != -1) {//�ҵ��ˣ���Ų���
			key = status.substr(0, pos);//��ȡ��ǰ������
			value = status.substr(pos + 1, status.size() - 1);//��ȡ���������
			m.insert(make_pair(key, value));//����map��
		}
		this->orderData.insert(make_pair(this->size, m));//���뵱ǰԪ�ص������Լ�һ��map����������ԤԼ��¼��
		this->size++;
	}
	ifs.close();


}

void orderFile::updateOrder() {//���¼�¼
	if (this->size == 0) {
		return;//�޼�¼�Ͳ�����
	}
	ofstream ofs(ORDER_FILE, ios::out | ios::trunc);//���ԭ�ļ�
	for (int i = 0; i < this->size; i++) {//���ݵ�ǰ�洢����Ϣ�����䱣�浽�ļ���
		ofs << "date:" << this->orderData[i]["date"] << " ";
		ofs << "inteval:" << this->orderData[i]["interval"] << " ";
		ofs << "stuId:" << this->orderData[i]["stuId"] << " ";
		ofs << "stuName:" << this->orderData[i]["stuName"] << " ";
		ofs << "roomId:" << this->orderData[i]["roomId"] << " ";
		ofs << "status:" << this->orderData[i]["status"] << endl;
	}
	ofs.close();
}