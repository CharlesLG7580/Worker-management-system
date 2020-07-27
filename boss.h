//普通员工文件
#pragma once
#include<iostream>
using namespace std;
#include"worker.h"

class Boss :public Worker
{
public:

	Boss(int id, string name, int dId);

	//显示个人信息
	virtual void showInfo();  //多态的一点就是重写父类的纯虚函数

	//获取岗位名称
	virtual string getDeptName();
};

