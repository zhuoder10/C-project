#include "workerManager.h"

workerManager::workerManager() {//初始化


	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	if (!ifs.is_open()) {//如果文件不存在
		cout << "文件不存在" << endl;
		//初始化
		this->enpNum = 0;
		this->empArray = NULL;
		this->fileIsEmpty = true;
		ifs.close();
		return;
	}
	//如果文件存在，但数据为空
	char ch;
	ifs >> ch;
	if (ifs.eof()) {
		this->enpNum = 0;
		this->empArray = NULL;
		this->fileIsEmpty = true;
		ifs.close();
		return;
	}
	//当文件存在且有数据
	int num = this->getEmpNum();
	cout << "职工人数目前有 " << num << endl;
	this->enpNum = num;//存储当前的职工人数
	this->fileIsEmpty = false;//声明当前文件不为空
	//开辟空间，并初始化
	this->empArray = new worker * [this->enpNum];
	this->initEmp();


}

void workerManager::showMenu() {
	cout << "*********************" << endl;
	cout << "***欢迎使用职工管理系统**" << endl;
	cout << "0.退出管理系统" << endl;
	cout << "1.增加职工信息" << endl;
	cout << "2.显示职工信息" << endl;
	cout << "3.删除离职员工" << endl;
	cout << "4.修改职工信息" << endl;
	cout << "5.查找职工信息" << endl;
	cout << "6.按照编号排序" << endl;
	cout << "7.清空所有文档" << endl;
	cout << "********************" << endl;
}

void workerManager::exitSystem() {
	cout << "欢迎下次使用" << endl;
	system("pause");
	exit(0);
}


void workerManager::addEmp() {
	cout << "请输入添加职工的数量" << endl;
	int addNum = 0;//要添加的数量
	cin >> addNum;

	if (addNum > 0) {

		int newSize = this->enpNum + addNum;//新数组的大小

		worker** newSpace = new worker * [newSize];//新数组的定义

		if (this->empArray != NULL) {
			for (int i = 0; i < this->enpNum; i++) {
				newSpace[i] = this->empArray[i];//先把旧数组的数据拷贝进新数组
			}
		}

		int empArray[20];//维护一个新的数组确保在一次添加多个的时候不会导致重复添加相同的id
		int size = 0;//要维护的数组的长度
		bool flag = false;//用于帮助后续跳出true循环
		for (int i = 0; i < addNum; i++) {
			int id;
			string name;
			int department;


			while (true) {
				cout << "请输入第" << i + 1 << "个新职工的编号" << endl;
				cin >> id;
				flag = true;//先设置为true，如果经过条件判断还是true，就退出
				if (existEmp(id) != -1) {
					cout << "请重新输入，该id已经被占用" << endl;
					flag = false;//禁止退出循环
					continue;
				}
				for (int i = 0; i < size; i++) {
					if (empArray[i] == id) {
						cout << "请重新输入，该id已经被占用" << endl;
						flag = false;//禁止退出循环
						break;
					}
				}
				if (flag) {
					break;
				}
			}
			empArray[size] = id;
			size++;//更新id数组

			cout << "请输入第" << i + 1 << "个新职工的姓名" << endl;
			cin >> name;


			cout << "请选择职工岗位" << endl;
			cout << "1 职员" << endl;
			cout << "2 经理" << endl;
			cout << "3 老板" << endl;
			cin >> department;
			worker* worker = NULL;//创建的新员工
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
			newSpace[this->enpNum + i] = worker;//添加新员工到数组里


		}
		delete[] this->empArray;
		this->empArray = newSpace;//释放原空间，指向新空间
		this->enpNum = newSize;//更新人数

		this->fileIsEmpty = false;//更新为文件不为空
		cout << "成功添加" << endl;
		save();
	}
	else {
		cout << "数据有误" << endl;
	}
	system("pause");
	system("cls");//清屏
}

void workerManager::save() {
	ofstream ofs;
	ofs.open(FILENAME, ios::out);//输出写文件

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

	while (ifs >> id && ifs >> name && ifs >> dID) {//如果ifs读取不到会返回0
		number++;//统计人数
	}
	return number;
}

void workerManager::initEmp() {
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	int id;
	string name;
	int dId;
	int index = 0;//员工数组的内存
	while (ifs >> id && ifs >> name && ifs >> dId) {//代表了读行操作，ifs先读取空格前的id然后是name，最后是did
		worker* worker = NULL;
		if (dId == 1) {
			//员工
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
	//判断是否为空
	if (this->fileIsEmpty) {
		cout << "当前文件为空" << endl;
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
* 判断该人是否存在
*/
int workerManager::existEmp(int id) {

	int index = -1;//所查到id的人的索引
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
		cout << "无法删除" << endl;
	}
	else
	{
		cout << "输入想要删除的人的编号" << endl;
		int id = 0;
		cin >> id;

		int getReturn = existEmp(id);
		if (getReturn != -1) {
			cout << "已将" << this->empArray[getReturn]->name << "员工删除 ";
			for (int i = getReturn; i < this->enpNum - 1; i++) {
				this->empArray[i] = this->empArray[i + 1];
			}
			this->enpNum--;//删除人员
			this->save();//更新文件
		}
		else {
			cout << "删除失败 未找到该职工" << endl;
		}
		system("pause");
		system("cls");
	}




}

void workerManager::modifyEmp() {
	if (this->fileIsEmpty) {
		cout << "文件不存在或为空" << endl;

	}
	else {
		cout << "请输入修改职工的编号" << endl;
		int id;
		cin >> id;

		int getReturn = this->existEmp(id);
		if (getReturn != -1) {
			delete this->empArray[getReturn];//删除原来数组里的数据

			int newID = 0;
			string newName = "";
			int depart = 0;
			cout << "查到 " << id << "号职工，请输入新的职工号: " << endl;
			cin >> newID;
			cout << "请输入新姓名" << endl;
			cin >> newName;
			cout << "请输入岗位" << endl;
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
			this->empArray[getReturn] = newWorker;//更新修改后的员工
			cout << "修改成功" << endl;
			this->save();
		}
		else {
			cout << "未查找到该职工" << endl;
		}
		system("pause");
		system("cls");

	}
}

void workerManager::findEmp() {
	if (this->fileIsEmpty) {
		cout << "文件不存在或者为空" << endl;
	}
	else
	{
		cout << "你查找的方式是？" << endl;
		cout << "1 按姓名查找" << endl;
		cout << "2 按id查找" << endl;

		int select = 0;
		cin >> select;
		if (select == 1) {
			string name;
			cout << "请输入要查找的人的名字" << endl;
			cin >> name;
			int flag = false;//判断是否找到职工
			for (int i = 0; i < this->enpNum; i++) {
				if (this->empArray[i]->name == name) {
					cout << "查找到了该员工,编号是 " << this->empArray[i]->id << endl;
					this->empArray[i]->showInfo();
					flag = true;
				}
			}
			if (flag == false) {
				cout << "查找失败" << endl;
			}
		}
		else if (select == 2) {
			int id;
			cout << "输入查找的编号" << endl;
			cin >> id;

			int ret = existEmp(id);
			if (ret != -1) {
				cout << "找到了这个人" << endl;
				cout << "信息如下" << endl;
				this->empArray[ret]->showInfo();//展示查到的这个人的信息
			}
			else {
				cout << "查无此人" << endl;
			}
		}
		else {
			cout << "输入选项有误" << endl;
		}
	}
	system("pause");
	system("cls");
}

void workerManager::sortEmp() {

	if (this->fileIsEmpty) {
		cout << "文件不存在或为空" << endl;
		system("pause");
		system("cls");
	}
	else {
		cout << "选择排序方式 1升序 2降序" << endl;
		int select = 0;
		cin >> select;
		for (int i = 0; i < this->enpNum; i++) {
			int minOrMax = i;//下标
			for (int j = i + 1; j < this->enpNum; j++) {
				if (select == 1) {
					if (this->empArray[minOrMax]->id > this->empArray[j]->id) {
						minOrMax = j;//更新下标
					}
				}
				else {
					if (this->empArray[minOrMax]->id < this->empArray[j]->id) {
						minOrMax = j;
					}
				}
			}
			if (minOrMax != i) {//如果最小值或者最大值不等于一开始的i
				worker* temp = this->empArray[i];
				this->empArray[i] = this->empArray[minOrMax];
				this->empArray[minOrMax] = temp;//交换元素
			}
		}
	}

	cout << "排序成功，结果是： " << endl;
	this->save();
	this->show();//展示排序后的结果


}

void workerManager::clearEmp() {
	if (this->fileIsEmpty) {
		cout << "文件为空或不存在" << endl;
	}
	else {

		cout << "确定吗？1确定 2返回" << endl;
		int select = 0;
		cin >> select;

		if (select == 1) {
			ofstream ofs(FILENAME, ios::trunc);//删除文件后再重新创建
			ofs.close();
			if (this->empArray != NULL) {
				for (int i = 0; i < this->enpNum; i++) {
					delete this->empArray[i];//删除数组里的每一个元素
					this->empArray[i] = NULL;
				}
				//删除指向数组的指针
				delete[] this->empArray;
				this->empArray = NULL;
				this->enpNum = 0;//清空数组
				this->fileIsEmpty = true;
				cout << "清空成功" << endl;
			}
			
		}
	}
	system("pause");
	system("cls");
}

workerManager::~workerManager() {

}
