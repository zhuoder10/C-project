#include<iostream>
#include<string>
#include"workerManager.h"
using namespace std;




int main() {

	workerManager wm;


	int choice = 0;//�����û�ѡ��
	while (true) {
		wm.showMenu();//չʾ�˵�

		cout << "����������ѡ��" << endl;
		cin >> choice;

		switch (choice) {
		case 0://�˳�
			wm.exitSystem();
			break;
		case 1://���ְ��
			wm.addEmp();
			break;
		case 2://��ʾְ��
			wm.show();
			break;
		case 3://ɾ��ְ��
			wm.deleteEmp();
			break;
		case 4://�޸�ְ��
			wm.modifyEmp();
			break;
		case 5://����ְ��
			wm.findEmp();
			break;
		case 6://����ְ��
			wm.sortEmp();
			break;
		case 7://����ĵ�
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