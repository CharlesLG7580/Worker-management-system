#include<iostream>
#include"workerManager.h"
using namespace std;
#include"worker.h"
#include"employee.h"
#include"boss.h"
#include"manager.h"
int main()
{
	//Worker *worker = NULL;
	//worker = new Employee(1, "����", 1); //����Ƕ�̬������ܹؼ��������ȹ���һ�����࣬Ȼ�����½�һ������
	//worker->showInfo();

	/*Worker *worker1 = NULL;
	worker1 = new Manager(2, "charles", 2);
	worker1->showInfo();
	delete worker1;

	Worker *worker2 = NULL;
	worker2 = new Boss(2, "boss_cjar", 2);
	worker2->showInfo();
	delete worker2;*/
	//��ʵ����һ�������ߵĶ���
	WorkerManager wm;
	
	int choice = 0;

	while (true)
	{
		wm.Show_Menu();

		cout << "����������ѡ��" << endl;
		cin >> choice;//�����û���ѡ��
		switch (choice)
		{
			cout << choice;
		case 0: //�˳�ϵͳ
			wm.ExitSystem();
			break;
		case 1: //����
			wm.Add_Emp();
			break;
		case 2: //��ʾ
			wm.Show_Emp();
			break;
		case 3: //ɾ��
			wm.Del_Emp();
			break;
		case 4: //�޸�
			wm.Mod_Emp();
			break;
		case 5: //����
			wm.Find_Emp();
			break;
		case 6: //����(�����õ�����ѡ������)
			wm.Sort_Emp();
			break;
		case 7: //���
			wm.Clean_File();
			break;
		default:
			system("cls");//��������
			break;
		}
	}
	system("pause");
	return 0;
}