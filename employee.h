//��ͨԱ���ļ�
#pragma once
#include<iostream>
using namespace std;
#include"worker.h"

class Employee :public Worker
{
public:
	
	Employee(int id,string name,int dId);

	//��ʾ������Ϣ
	virtual void showInfo();  //��̬��һ�������д����Ĵ��麯��

	//��ȡ��λ����
	virtual string getDeptName();
};

