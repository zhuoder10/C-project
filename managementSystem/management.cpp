#include<iostream>
#include<string>
#include"workerManager.h"
using namespace std;




int main() {

	workerManager wm;


	int choice = 0;//定义用户选择
	while (true) {
		wm.showMenu();//展示菜单

		cout << "请输入您的选择" << endl;
		cin >> choice;

		switch (choice) {
		case 0://退出
			wm.exitSystem();
			break;
		case 1://添加职工
			wm.addEmp();
			break;
		case 2://显示职工
			wm.show();
			break;
		case 3://删除职工
			wm.deleteEmp();
			break;
		case 4://修改职工
			wm.modifyEmp();
			break;
		case 5://查找职工
			wm.findEmp();
			break;
		case 6://排序职工
			wm.sortEmp();
			break;
		case 7://清空文档
			wm.clearEmp();
			break;

		default:
			system("cls");
			break;
		}
	}
	system("pause");
	return 0;
}