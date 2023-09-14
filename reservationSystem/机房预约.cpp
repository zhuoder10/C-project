#include<iostream>
using namespace std;
#include"identity.h"
#include"student.h"
#include"teacher.h"
#include"manager.h"
#include<fstream>
#include"globalFile.h"

void managerMenu(identity* manager) {//管理员的子菜单
	while (true) {
		//调用子菜单
		manager->openMenu();
		//将父类指针转为子类指针，调用子类的其他接口
		Manager* man = (Manager*)manager;

		int select = 0;
		cin >> select;//接受选择
		if (select == 1) {//添加账号
			man->addPerson();
			cout << "添加账号" << endl;
		}
		else if (select == 2) {//查看账号
			cout << "查看账号" << endl;
			man->showPerson();
		}
		else if (select == 3) {//查看机房
			cout << "查看机房" << endl;
			man->showComputer();
		}
		else if (select == 4) {
			cout << "清空预约" << endl;
			man->clearFile();
		}
		else {//注销登录
			delete manager;
			cout << "注销成功" << endl;
			system("pause");
			system("cls");
			return;
		}

	}
}

//学生子菜单
void studentMenu(identity*& student) {
	while (true) {
		student->openMenu();
		Student* stu = (Student*)student;//强转
		int select = 0;
		cin >> select;
		if (select == 1) {
			cout << "申请预约" << endl;
			stu->applyOrder();
		}
		else if (select == 2) {
			cout << "查看自身预约" << endl;
			stu->showMyOrder();
		}
		else if (select == 3) {
			cout << "查看所有人预约" << endl;
			stu->showAllOrder();
		}
		else if (select == 4) {
			cout << "取消登录" << endl;
			stu->cancelOrder();
		}
		else {
			cout << "注销登录" << endl;
			delete student;
			cout << "注销成功" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}
//教师子菜单
void teacherMenu(identity*& teacher) {
	while (true) {
		teacher->openMenu();//调出菜单
		//同理，要调用子类特有的函数，要先转为子类指针
		Teacher* tea = (Teacher*)teacher;//强制转换
		int select = 0;
		cin >> select;
		if (select == 1) {//查看所有预约
			tea->showOrder();
		}
		else if (select == 2) {//审核预约
			tea->validOrder();
		}
		else {
			delete teacher;//从内存中删除
			cout << "注销成功" << endl;
			system("pasue");
			system("cls");
			return;
		}
	}
}


void login(string fileName, int type) {//登录函数,type表示操作身份
	identity* person = NULL;//创建父类用于指向子类

	//读文件
	ifstream ifs;
	ifs.open(fileName, ios::in);
	if (!ifs.is_open()) {
		cout << " 文件不存在" << endl;
		ifs.close();
		return;
	}
	//准备接受信息
	int id = 0;
	string name;
	string pwd;
	//判断身份
	if (type == 1) {
		cout << "请输入你的学号" << endl;
		cin >> id;
	}
	else if (type == 2) {
		cout << "请输入你的职工号" << endl;
		cin >> id;
	}
	cout << "请输入用户名" << endl;
	cin >> name;
	cout << "请输入密码" << endl;
	cin >> pwd;

	if (type == 1) {
		//学生身份验证
		int fId;//文件中读取的id
		string fName;//文件中获取的姓名
		string fPwd;//从文件中获取密码
		while (ifs >> fId && ifs >> fName && ifs >> fPwd) {//读取文件里的信息
			if (fId == id && fName == name && fPwd == pwd) {
				cout << "学生验证登陆成功" << endl;
				system("pause");
				system("cls");
				person = new Student(id, name, pwd);//指向新建的学生
				//进入学生身份的子菜单
				studentMenu(person);
				return;
			}
		}
		cout << "未找到该学生，请重新输入信息" << endl;
		system("pause");
		system("cls");
	}
	else if (type == 2) {
		//老师学生验证
		int fId;
		string fName;
		string fPwd;
		while (ifs >> fId && ifs >> fName && ifs >> fPwd) {
			if (fId == id && fName == name && fPwd == pwd) {
				cout << "教师登陆成功" << endl;
				system("pause");
				system("cls");
				person = new Teacher(id, name, pwd);
				//进入教师的子菜单
				teacherMenu(person);
				return;
			}
		}
	}
	else {
		//管理员身份验证
		string fName;
		string fPwd;
		while (ifs >> fName && ifs >> fPwd) {
			if (name == fName && fPwd == pwd) {
				cout << "管理员验证成功" << endl;
				system("pause");
				system("cls");
				person = new Manager(name, pwd);
				managerMenu(person);//进入manager子菜单
				return;
			}
		}
		cout << "验证失败" << endl;
	}
}


int main() {

	int select = 0;//用于接收用户的选择
	while (true) {

		cout << endl << "请输入您的身份" << endl;
		cout << "\t\t ---------------------\n";
		cout << "\t\t" << "|1.学生代表|" << endl;
		cout << "\t\t" << "|2.老师|" << endl;
		cout << "\t\t" << "|3.管理员|" << endl;
		cout << "\t\t" << "|0.退出|" << endl;
		cout << "\t\t ---------------------\n";
		cout << "请输入您的选择: ";

		cin >> select;

		switch (select) {

		case 1://学生身份
			login("student.txt", 1);
			break;
		case 2://老师身份
			login(TEACHER_FILE, 2);
			break;
		case 3://管理员身份
			login(ADMIN_FILE, 3);
			break;
		case 0://退出系统
			cout << "欢迎下一次使用" << endl;
			system("pause");
			return 0;
		default:
			cout << "输入有误 重新选择" << endl;
			system("pause");
			system("cls");
			break;
		}
	}
}