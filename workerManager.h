#pragma once  //防止头文件重复包含
#include<iostream>  //输入输出的头文件
using namespace std; //使用标准命名空间
#include"worker.h"
#include<fstream>
#define FILENAME "empFile.txt"
class WorkerManager
{
public:
	WorkerManager();

	//展示菜单
	void Show_Menu();

	//退出
	void ExitSystem();

	//记录职工人数
	int m_EmpNum;

	//职工数组指针
	Worker ** m_EmpArray;//这里要存放指针所以是一个指针数组

	//添加职工
	void Add_Emp();

	//保存文件
	void save();

	//判断文件是否为空
	bool m_FileIsEmpty;

	//统计文件中的人数
	int get_EmpNum();

	//初始化员工--将文件读到数组里
	void init_Emp();

	//2显示员工
	void Show_Emp();

	//3删除职工
	void Del_Emp();

	//判断职工是否存在，如果存在返回职工所在数组中的位置，不存在返回-1
	int IsExist(int id);

	//修改职工
	void Mod_Emp();

	//查找职工
	void Find_Emp();

	//按照职工的编号进行排序
	void Sort_Emp();

	//清空文件
	void Clean_File();
	~WorkerManager();
};