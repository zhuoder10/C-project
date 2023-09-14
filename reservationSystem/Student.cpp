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
		vCom.push_back(com);//将所有机房信息读取到容器里
	}
	ifs.close();


}
void Student::openMenu() {
	cout << "欢迎学生代表" << this->name << "登录！" << endl;
	cout << "1.申请预约" << endl;
	cout << "2.查看预约" << endl;
	cout << "3.查看所有预约" << endl;
	cout << "4.取消预约" << endl;
	cout << "0.注销登录" << endl;
}

void Student::applyOrder() {
	//申请房间
	cout << "周几想预约？" << endl;
	cout << "请输入申请预约的时间" << endl;
	cout << "1-5 为周一到周五" << endl;
	int date = 0;
	int interval = 0;//时间段
	int room;
	while (true) {
		cin >> date;
		if (date >= 1 && date <= 5) {
			break;
		}
		else {
			cout << "输入有误" << endl;
		}
	}
	cout << "请输入申请的时间段" << endl;
	cout << "1 上午 2 下午" << endl;
	while (true) {

		cin >> interval;
		if (interval >= 1 && interval <= 2) {
			break;
		}
		else {
			cout << "输入有误" << endl;
		}
	}
	cout << "请选择机房" << endl;
	for (int i = 0; i < vCom.size(); i++) {
		cout << vCom[i].comId << "号房间容量是" << vCom[i].maxNum << endl;
	}

	while (true) {
		cin >> room;
		if (room >= 1 && room <= 3) {
			break;

		}
		else {
			cout << "输入有误" << endl;
		}
	}

	cout << "预约成功,进行审核" << endl;

	ofstream ofs;
	ofs.open(ORDER_FILE, ios::app);
	ofs << "date:" << date << " ";//这样分割是因为读取时按照空格分割，这样分割可以获得每个信息
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
		cout << "无预约记录" << endl;
		system("pause");
		system("cls");
		return;
	}
	else {
		for (int i = 0; i < ord.size; i++) {
			//因为要查看自身的预约，则需要和保存的对比id号
			if (this->id == atoi(ord.orderData[i]["stuId"].c_str())) {////将存储的字符串转为int类型
				//找到自身预约
				cout << "预约日期是： 周" << ord.orderData[i]["date"];
				cout << "时间段是： " << (ord.orderData[i]["interval"] == "1" ? "上午" : "下午");
				cout << "机房号是: " << ord.orderData[i]["roomId"];
				string status = "状态: ";
				//1审核中 2已预约 -1预约失败 0取消预约
				if (ord.orderData[i]["status"] == "1") {
					cout << status + "审核中" << endl;
				}
				else if (ord.orderData[i]["status"] == "2") {
					cout << status + "预约成功" << endl;
				}
				else if (ord.orderData[i]["status"] == "-1") {
					cout << status + "预约失败" << endl;
				}
				else if (ord.orderData[i]["status"] == "0") {
					cout << status + "预约已取消" << endl;
				}
			};
		}
	}
	system("pause");
	system("cls");
}

void Student::showAllOrder() {//显示所有人的预约记录
	orderFile ord;
	if (ord.size == 0) {
		cout << "无预约记录" << endl;
		system("pause");
		system("cls");
		return;
	}

	for (int i = 0; i < ord.size; i++) {
		cout << i + 1 << " ";
		cout << " 预约时间： 周" << ord.orderData[i]["date"];
		cout << " 时间段: " << (ord.orderData[i]["interval"] == "1" ? "上午" : "下午");
		cout << " 学号: " << ord.orderData[i]["stuId"];
		cout << " 姓名： " << ord.orderData[i]["stuName"];
		cout << " 机房编号: " << ord.orderData[i]["roomId"];
		string status = "状态: ";
		if (ord.orderData[i]["status"] == "1") {
			cout << status + "审核中";
		}
		else if (ord.orderData[i]["status"] == "2") {
			cout << status + "已预约";
		}
		else if (ord.orderData[i]["status"] == "-1") {
			cout << status + "预约失败";
		}
		else {
			cout << status + "预约取消";
		}
		cout << endl;
	}
	system("pause");
	system("cls");
}

void Student::cancelOrder() {//取消预约
	orderFile of;//从文件里读取信息
	if (of.size == 0) {
		cout << "无预约记录" << endl;
		system("pause");
		system("cls");
		return;
	}

	cout << "审核中或者预约成功的记录可以取消,请输入要取消的记录" << endl;
	vector<int> v;//存放在最大容器下标编号
	int index = 1;
	for (int i = 0; i < of.size; i++) {//打印一下可以取消的预约记录
		if (this->id == atoi(of.orderData[i]["stuId"].c_str())) {//先匹配学号一致
			if (of.orderData[i]["status"] == "1" || of.orderData[i]["status"] == "2") {//在筛选状态，只选择审核中或者预约成功的
				v.push_back(i);//存入要取消的索引
				cout << index << " ";
				index++;
				cout << "预约日期： 周" << of.orderData[i]["date"];
				cout << " 时间段： " << (of.orderData[i]["interval"] == "1" ? "上午" : "下午");
				cout << " 机房编号: " << of.orderData[i]["roomId"];
				string status = "状态: ";
				if (of.orderData[i]["status"] == "1") {
					status += "审核中";
				}
				else if (of.orderData[i]["status"] == "2") {
					status += "预约成功";
				}
				cout << status << endl;
			}
		}
	}
	cout << "请输入取消的记录，0代表返回" << endl;
	int select = 0;
	while (true) {
		cin >> select;
		if (select >= 0 && select <= v.size()) {
			if (select == 0) {
				//取消操作
				break;
			}
			else {
				of.orderData[v[select - 1]]["status"] = "0";//从v容器中取出要删除的索引，并改为0，即未预约
				of.updateOrder();//更新记录，保存到文件里
				cout << "已取消" << endl;
				break;
			}
		}
		cout << "输入有误，请重新输入" << endl;
	}
	system("pause");
	system("cls");
}
