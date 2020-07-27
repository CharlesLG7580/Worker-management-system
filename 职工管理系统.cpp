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
	//worker = new Employee(1, "张三", 1); //这就是多态，这里很关键，我们先构造一个基类，然后再新建一个子类
	//worker->showInfo();

	/*Worker *worker1 = NULL;
	worker1 = new Manager(2, "charles", 2);
	worker1->showInfo();
	delete worker1;

	Worker *worker2 = NULL;
	worker2 = new Boss(2, "boss_cjar", 2);
	worker2->showInfo();
	delete worker2;*/
	//先实例化一个管理者的对象
	WorkerManager wm;
	
	int choice = 0;

	while (true)
	{
		wm.Show_Menu();

		cout << "请输入您的选择" << endl;
		cin >> choice;//接收用户的选择
		switch (choice)
		{
			cout << choice;
		case 0: //退出系统
			wm.ExitSystem();
			break;
		case 1: //增加
			wm.Add_Emp();
			break;
		case 2: //显示
			wm.Show_Emp();
			break;
		case 3: //删除
			wm.Del_Emp();
			break;
		case 4: //修改
			wm.Mod_Emp();
			break;
		case 5: //查找
			wm.Find_Emp();
			break;
		case 6: //排序(这里用到的是选择排序)
			wm.Sort_Emp();
			break;
		case 7: //清空
			wm.Clean_File();
			break;
		default:
			system("cls");//清屏操作
			break;
		}
	}
	system("pause");
	return 0;
}