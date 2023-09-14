#include"manager.h"
#include"globalFile.h"
#include<fstream>

Manager::Manager() {

};

Manager::Manager(string name, string pwd) {
	//初始化管理员信息
	this->name = name;
	this->pwd = pwd;

	this->initVector();//初始化容器

	ifstream ifs;
	ifs.open(COMPUTER_FILE, ios::in);
	computerRoom com;
	while (ifs >> com.comId && ifs >> com.maxNum) {
		vCom.push_back(com);
	}
	ifs.close();
	cout << "机房的数量是 " << vCom.size() << endl;
}

void Manager::openMenu() {
	cout << "欢迎管理员: " << this->name << "登录！" << endl;
	cout << "1.添加账号" << endl;
	cout << "2.查看账号" << endl;
	cout << "3.查看机房" << endl;
	cout << "4.清空预约" << endl;
	cout << "0.注销账号" << endl;
};

void Manager::addPerson() {
	cout << "请输入添加的账号的类型" << endl;
	cout << "1.添加学生" << endl;
	cout << "2.添加老师" << endl;

	string fileName;
	string tip;//提示id号
	string errorTip;//如果错误的提示

	ofstream ofs;
	int select = 0;
	cin >> select;

	if (select == 1) {
		fileName = STUDENT_FILE;
		tip = "请输入学号";
		errorTip = "学号重复，请重新输入";
	}
	else {
		fileName = TEACHER_FILE;
		tip = "请输入职工号";
		errorTip = "职工号重复，请重新输入";
	}

	ofs.open(fileName, ios::out | ios::app);//追加的方式写文件
	int id;
	string name;
	string pwd;

	cout << tip << endl;

	while (true) {
		cin >> id;
		bool ret = checkRepeat(id, select);
		if (ret) {//有重复
			cout << errorTip;
		}
		else {
			break;
		}
	}

	cout << "请输入姓名： " << endl;
	cin >> name;

	cout << "请输入密码 " << endl;
	cin >> pwd;
	//向文件中添加数据
	ofs << id << " " << name << " " << pwd << " " << endl;
	cout << "添加成功" << endl;
	system("pause");
	system("cls");
	ofs.close();
	this->initVector();//更新容器
};

void Manager::clearFile() {

	ofstream ofs(ORDER_FILE,ios::trunc);//清空文件
	ofs.close();

	cout << "清空成功" << endl;
	system("pause");
	system("cls");


}
void printStudent(Student& s) {
	cout << "学号 " << s.id << "姓名： " << s.name << "密码" << s.pwd << endl;

}
void printTeacher(Teacher& t) {
	cout << "职工号 " << t.empId << "姓名： " << t.name << "密码" << t.pwd << endl;

}


void Manager::showPerson() {
	cout << "请选择查看内容" << endl;
	cout << "1.查看所有学生" << endl;
	cout << "2.查看所有老师" << endl;

	int select = 0;
	cin >> select;
	if (select == 1) {
		//看学生
		cout << "以下为学生信息" << endl;
		for_each(vStu.begin(), vStu.end(), printStudent);//遍历打印内容

	}
	else {
		cout << "以下为老师信息" << endl;
		for_each(tStu.begin(), tStu.end(), printTeacher);
	}
	system("pause");
	system("cls");
}

void Manager::showComputer() {

	cout << "机房信息如下" << endl;
	for (vector<computerRoom>::iterator it = vCom.begin(); it != vCom.end(); it++) {
		cout << "机房编号" << it->comId << "机房最大容量 " << it->maxNum << endl;
	}
	system("pause");
	system("cls");

}

void Manager::initVector() {
	vStu.clear();
	tStu.clear();//清空容器
	//读取信息
	ifstream ifs;
	ifs.open(STUDENT_FILE, ios::in);
	if (!ifs.is_open()) {
		cout << "文件读取失败" << endl;
		return;
	}

	Student s;
	while (ifs >> s.id && ifs >> s.name && ifs >> s.pwd) {
		vStu.push_back(s);//一行一行的读取学生文件
	}
	cout << "当前学生数量为 " << vStu.size() << endl;
	ifs.close();

	//读取老师信息
	ifs.open(TEACHER_FILE, ios::in);
	Teacher t;
	while (ifs >> t.empId && ifs >> t.name && ifs >> t.pwd) {
		tStu.push_back(t);
	}
	cout << "当前老师数量是 " << tStu.size() << endl;
	ifs.close();

}
bool Manager::checkRepeat(int id, int type) {
	if (type == 1) {
		//检查学生
		for (vector<Student>::iterator it = vStu.begin(); it != vStu.end(); it++) {
			if (id == it->id) {
				return true;
			}
		}
	}
	else {//检查老师
		for (vector<Teacher>::iterator it = tStu.begin(); it != tStu.end(); it++) {
			if (id == it->empId) {
				return true;
			}
		}
	}
	return false;
}
