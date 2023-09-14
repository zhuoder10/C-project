#include"teacher.h"

Teacher::Teacher() {

};

Teacher::Teacher(int empId, string name, string pwd) {
	this->name = name;
	this->empId = empId;
	this->pwd = pwd;

}
void Teacher::openMenu() {
	cout << "欢迎老师： " << this->name << "登录！" << endl;
	cout << "1.查看所有预约" << endl;
	cout << "2.审核预约\t" << endl;
	cout << "0.注销登录\t" << endl;
	cout << "请选择您的操作\t" << endl;
}

void Teacher::showOrder() {
	orderFile ord;
	if (ord.size == 0) {
		cout << "无预约记录" << endl;
		system("pause");
		system("cls");
		return;
	}
	for (int i = 0; i < ord.size; i++) {
		cout << i + 1 << " " << "预约日期：周" << ord.orderData[i]["date"];
		cout << " 时间段：" << (ord.orderData[i]["interval"] == "1" ? "上午" : "下午");
		cout << "学号: " << ord.orderData[i]["stuId"];
		cout << "姓名: " << ord.orderData[i]["stuName"];
		cout << "机房： " << ord.orderData[i]["roomId"];
		string status = "状态： ";
		if (ord.orderData[i]["status"] == "1") {
			status += "审核中";
		}
		else if (ord.orderData[i]["status"] == "2") {
			status += "预约成功";
		}
		else if (ord.orderData[i]["status"] == "-1") {
			status += "预约失败，审核未通过";
		}
		else {
			status += "预约已取消";
		}
		cout << status << endl;
	}
	system("pause");
	system("cls");
}
void Teacher::validOrder() {
	orderFile ord;
	if (ord.size == 0) {
		cout << "无预约记录" << endl;
		system("pause");
		system("cls");
		return;
	}

	cout << "待审核的记录如下" << endl;
	vector<int> v;
	int index = 0;
	for (int i = 0; i < ord.size; i++) {
		if (ord.orderData[i]["status"] == "1") {
			v.push_back(i);//放入待审核的记录的索引
			cout << ++index << " ";
			cout << "预约日期：周" << ord.orderData[i]["date"];
			cout << " 时间段：" << (ord.orderData[i]["interval"] == "1" ? "上午" : "下午");
			cout << "学号: " << ord.orderData[i]["stuId"];
			cout << "姓名: " << ord.orderData[i]["stuName"];
			cout << "机房： " << ord.orderData[i]["roomId"];
			string status = "状态：审核中";
			cout << status << endl;
		}
	}
	cout << "请输入审核的预约记录，0表示返回" << endl;
	int select;
	while (true) {
		cin >> select;
		if (select >= 0 || select <= v.size()) {
			if (select == 0) {
				break;
			}
			else {
				cout << "请输入审核的结果" << endl;
				cout << "1 通过 2 不通过" << endl;
				int choice;
				cin >> choice;
				if (choice == 1) {
					//通过
					ord.orderData[v[select - 1]]["status"] = "2";
				}
				else {
					ord.orderData[v[select - 1]]["status"] = "-1";
				}
				ord.updateOrder();
				//更新数据
				cout << "审核完毕" << endl;
				break;
			}
		}
		else {
			cout << "无效输入" << endl;
		}
	}
	system("pause");
	system("cls");
}
