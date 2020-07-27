#pragma once
#include<iostream>
using namespace std;
#include<string>

//职工抽象类    这是一个最最基本的类，把大家共同的属性提取出来，接下来
//就要创建子类
class Worker
{
public:
	//显示个人信息
	virtual void showInfo() = 0;

	//获取岗位信息
	virtual string getDeptName() = 0;
	
	//职工编号
	int m_Id;

	//职工姓名
	string m_Name;
	//部门编号
	int m_DepId;

};