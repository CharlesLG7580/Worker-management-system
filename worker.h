#pragma once
#include<iostream>
using namespace std;
#include<string>

//ְ��������    ����һ������������࣬�Ѵ�ҹ�ͬ��������ȡ������������
//��Ҫ��������
class Worker
{
public:
	//��ʾ������Ϣ
	virtual void showInfo() = 0;

	//��ȡ��λ��Ϣ
	virtual string getDeptName() = 0;
	
	//ְ�����
	int m_Id;

	//ְ������
	string m_Name;
	//���ű��
	int m_DepId;

};