#include"orderFile.h"

orderFile::orderFile() {
	ifstream ifs;
	ifs.open(ORDER_FILE, ios::in);
	//记录预约的内容
	string date;
	string interval;
	string stuId;
	string stuName;
	string roomId;
	string status;

	this->size = 0;
	while (ifs >> date && ifs >> interval && ifs >> stuId && ifs >> stuName
		&& ifs >> roomId && ifs >> status) {//按行读取,每读一行括号内操作一次，读取一行时将所有元素存入变量值
		string key;
		string value;
		map<string, string> m;//准备存入容器中
		int pos = date.find(":");
		if (pos != -1) {//找到了：后才操作
			key = date.substr(0, pos);//截取：前的内容
			value = date.substr(pos + 1, date.size() - 1);//截取：后的内容
			m.insert(make_pair(key, value));//插入map中
		}

		pos = interval.find(":");
		if (pos != -1) {//找到了：后才操作
			key = interval.substr(0, pos);//截取：前的内容
			value = interval.substr(pos + 1, interval.size() - 1);//截取：后的内容
			m.insert(make_pair(key, value));//插入map中
		}

		pos = stuId.find(":");
		if (pos != -1) {//找到了：后才操作
			key = stuId.substr(0, pos);//截取：前的内容
			value = stuId.substr(pos + 1, stuId.size() - 1);//截取：后的内容
			m.insert(make_pair(key, value));//插入map中
		}

		pos = stuName.find(":");
		if (pos != -1) {//找到了：后才操作
			key = stuName.substr(0, pos);//截取：前的内容
			value = stuName.substr(pos + 1, stuName.size() - 1);//截取：后的内容
			m.insert(make_pair(key, value));//插入map中
		}

		pos = roomId.find(":");
		if (pos != -1) {//找到了：后才操作
			key = roomId.substr(0, pos);//截取：前的内容
			value = roomId.substr(pos + 1, roomId.size() - 1);//截取：后的内容
			m.insert(make_pair(key, value));//插入map中
		}

		pos = status.find(":");
		if (pos != -1) {//找到了：后才操作
			key = status.substr(0, pos);//截取：前的内容
			value = status.substr(pos + 1, status.size() - 1);//截取：后的内容
			m.insert(make_pair(key, value));//插入map中
		}
		this->orderData.insert(make_pair(this->size, m));//插入当前元素的索引以及一个map（包含所有预约记录）
		this->size++;
	}
	ifs.close();


}

void orderFile::updateOrder() {//更新记录
	if (this->size == 0) {
		return;//无记录就不更新
	}
	ofstream ofs(ORDER_FILE, ios::out | ios::trunc);//清空原文件
	for (int i = 0; i < this->size; i++) {//根据当前存储的信息，将其保存到文件里
		ofs << "date:" << this->orderData[i]["date"] << " ";
		ofs << "inteval:" << this->orderData[i]["interval"] << " ";
		ofs << "stuId:" << this->orderData[i]["stuId"] << " ";
		ofs << "stuName:" << this->orderData[i]["stuName"] << " ";
		ofs << "roomId:" << this->orderData[i]["roomId"] << " ";
		ofs << "status:" << this->orderData[i]["status"] << endl;
	}
	ofs.close();
}