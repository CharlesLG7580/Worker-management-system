#pragma once  //��ֹͷ�ļ��ظ�����
#include<iostream>  //���������ͷ�ļ�
using namespace std; //ʹ�ñ�׼�����ռ�
#include"worker.h"
#include<fstream>
#define FILENAME "empFile.txt"
class WorkerManager
{
public:
	WorkerManager();

	//չʾ�˵�
	void Show_Menu();

	//�˳�
	void ExitSystem();

	//��¼ְ������
	int m_EmpNum;

	//ְ������ָ��
	Worker ** m_EmpArray;//����Ҫ���ָ��������һ��ָ������

	//���ְ��
	void Add_Emp();

	//�����ļ�
	void save();

	//�ж��ļ��Ƿ�Ϊ��
	bool m_FileIsEmpty;

	//ͳ���ļ��е�����
	int get_EmpNum();

	//��ʼ��Ա��--���ļ�����������
	void init_Emp();

	//2��ʾԱ��
	void Show_Emp();

	//3ɾ��ְ��
	void Del_Emp();

	//�ж�ְ���Ƿ���ڣ�������ڷ���ְ�����������е�λ�ã������ڷ���-1
	int IsExist(int id);

	//�޸�ְ��
	void Mod_Emp();

	//����ְ��
	void Find_Emp();

	//����ְ���ı�Ž�������
	void Sort_Emp();

	//����ļ�
	void Clean_File();
	~WorkerManager();
};