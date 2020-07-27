#include"workerManager.h"
#include"boss.h"
#include"employee.h"
#include"manager.h"
#include"worker.h"

WorkerManager::WorkerManager()
{
	//1�ļ�������

	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	if (!ifs.is_open())  //����ļ�������
	{
		//cout << "�ļ�������" << endl;
		//��ʼ������
		//��ʼ����¼����
		this->m_EmpNum = 0;
		
		//��ʼ������ָ��
		this->m_EmpArray = NULL;

		//��ʼ���ļ��Ƿ�Ϊ��
		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	}
	//2 �ļ����ڣ�����Ϊ��
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		//cout << "�ļ�Ϊ��" << endl;
		//��ʼ������
		//��ʼ����¼����
		this->m_EmpNum = 0;

		//��ʼ������ָ��
		this->m_EmpArray = NULL;

		//��ʼ���ļ��Ƿ�Ϊ��
		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	}
	//3 �ļ����ڲ��Ҽ�¼������
	int num = this->get_EmpNum();
	//cout << "ְ������Ϊ�� " << num << endl;
	this->m_EmpNum = num;

	//���ٿռ�
	this->m_EmpArray = new Worker*[this->m_EmpNum];

	//���ļ��еĳԿγ̴浽������
	this->init_Emp();

	//for (int i = 0; i < this->m_EmpNum; i++)
	//{
	//	cout<< "ְ����ţ� "<<this->m_EmpArray[i]->m_Id << " "
	//		<< "������ "<<this->m_EmpArray[i]->m_Name << " "
	//		<< "���ű�ţ� "<<this->m_EmpArray[i]->m_DepId << endl;

	//}

}

//չʾ�˵�
void WorkerManager::Show_Menu()
{
	cout << "******************************************" << endl;
	cout << "**********��ӭʹ��ְ������ϵͳ************" << endl;
	cout << "**************0.�˳��������**************" << endl;
	cout << "**************1.����ְ����Ϣ**************" << endl;
	cout << "**************2.��ʾְ����Ϣ**************" << endl;
	cout << "**************3.ɾ����ְԱ��**************" << endl;
	cout << "**************4.�޸�ְ����Ϣ**************" << endl;
	cout << "**************5.����ְ����Ϣ**************" << endl;
	cout << "**************6.���ձ������**************" << endl;
	cout << "**************7.��������ĵ�**************" << endl;
	cout << "******************************************" << endl;
	cout << endl;


}

//�˳�
void WorkerManager::ExitSystem()
{
	cout << "��ӭ�´�ʹ��" << endl;
	system("pause");
	exit(0);
}

//���ְ��
void WorkerManager::Add_Emp()
{
	cout << "���������ְ����Ŀ�� " << endl;
	int addNum = 0;
	cin >> addNum;

	if (addNum > 0)
	{
		//���
		//��������¿ռ�Ĵ�С
		int newSize = this->m_EmpNum + addNum;

		//�����¿ռ�
		Worker ** newSpace = new Worker *[newSize];

		//��ԭ���Ŀռ��µ����ݿ������¿ռ�
		if (this->m_EmpArray != NULL)
		{
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				newSpace[i] = this->m_EmpArray[i];
			}
		}
		//�������������
		for (int i = 0; i < addNum; i++)
		{
			int id;
			string name;
			int dSelect;
			
			cout << "������� " << i + 1 << "����ְ�����" << endl;
			cin >> id;

			cout << "������� " << i + 1 << "����ְ������" << endl;
			cin >> name;

			cout << "��ѡ���ְ����λ�� " << endl;
			cout << "1 ��ְͨ��" << endl;
			cout << "2 ����" << endl;
			cout << "3 �ϰ�" << endl;
			cin >> dSelect;

			Worker *worker = NULL;
			switch (dSelect)
			{
			case 1:
				worker = new Employee(id, name, 1);
				break;
			case 2:
				worker = new Manager(id, name,2 );
				break;
			case 3:
				worker = new Boss(id, name,3);
				break;
			default:
				break;
			}
			//������ְ��ְ�𣬱��浽������
			newSpace[this->m_EmpNum + i] = worker;
			//newspace������ʱ�õ�
		}

		//�ͷ�ԭ�пռ�
		delete[] this->m_EmpArray;

		//�����¿ռ��ָ��
		this->m_EmpArray = newSpace;

		//�����µ�ְ������
		this->m_EmpNum = newSize;

		//����ְ����Ϊ�յ����
		this->m_FileIsEmpty = false;

		cout << "�ɹ����" << addNum << "����ְ��" << endl;

		this->save();//�������ݵ��ļ���

	}
	else
	{
		cout << "������������" << endl;
	}
	system("pause");
	system("cls");
}

//�����ļ�
void WorkerManager::save()
{
	ofstream ofs;
	ofs.open(FILENAME, ios::out);

	//��ÿ���˵�����д�뵽�ļ���
	for (int i = 0; i < this->m_EmpNum; i++)
	{
		ofs << this->m_EmpArray[i]->m_Id << " "
			<< this->m_EmpArray[i]->m_Name << " "
			<< this->m_EmpArray[i]->m_DepId << endl;
	}
	ofs.close();
}

//ͳ���ļ�������
int WorkerManager::get_EmpNum()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);//���ļ�����

	int id;
	string name;
	int dId;

	int num = 0;
	while (ifs >> id&&ifs >> name&&ifs >> dId) //����Ķ��ļ���ʽ����һ������
	{
		num++;

	}
	return num;
}
void WorkerManager::init_Emp()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	int id;
	string name;
	int dId;

	int index = 0;

	while (ifs >> id&&ifs >> name&&ifs >> dId)
	{
		Worker *worker = NULL;
		if (dId == 1) //��ְͨ��
		{
			worker = new Employee(id, name, dId);
		}
		else if (dId == 2) //����
		{
			worker = new Manager(id, name, dId);
		}
		else //�ϰ�
		{
			worker = new Boss(id, name, dId);
		}
		this->m_EmpArray[index] = worker;
		index++;

	}
	ifs.close();
}
void WorkerManager::Show_Emp()
{
	//�ж��ļ��Ƿ�Ϊ��
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ��¼Ϊ��" << endl;
	}
	else
	{
		for (int i = 0; i < m_EmpNum; i++)
		{
			//���ö�̬���ó���ӿ�
			this->m_EmpArray[i]->showInfo();
		}
	}
	system("pause");
	system("cls");
}
//ɾ��ְ��
void WorkerManager::Del_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ��߼�¼Ϊ��" << endl;
	}
	else
	{
		//����ְ�����ɾ��
		cout << "��������Ҫɾ����ְ����ţ� " << endl;
		int id = 0;
		cin >> id;

		int index = this->IsExist(id);

		if (index != -1)//�ҵ�,����Ҫɾ��indexλ���ϵ�Ա��
		{ 
			//����ǰ��
			for (int i = index; i < this->m_EmpNum - 1; i++)
			{
				this->m_EmpArray[i] = this->m_EmpArray[i + 1];
			}
			this->m_EmpNum--;

			this->save();//����ͬ�����µ��ļ���ȥ

			cout << "ɾ���ɹ�" << endl;
		}
		else
		{
			cout << "ɾ��ʧ�ܣ�δ�ҵ���ְ��" << endl;
		}
		
	}
	system("pause");
	system("cls");
}
int WorkerManager::IsExist(int id)
{
	int index = -1;

	for (int i = 0; i < this->m_EmpNum; i++)
	{
		if (this->m_EmpArray[i]->m_Id == id)
		{
			//�ҵ�ְ��
			index = i;
			break;
		}
	}
	return index;
}
//�޸�ְ��
void WorkerManager::Mod_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ��¼Ϊ�գ�" << endl;
	}
	else
	{
		cout << "�������޸�ְ���ı�ţ� " << endl;
		int id;
		cin >> id;

		int ret = this->IsExist(id);
		if (ret != -1)
		{
			//���ҵ���ŵ�ְ��

			delete this->m_EmpArray[ret];   //�˴���Ҫ���ͷ�һ��ջ��������ȫ�������¸�
			
			int newId = 0;
			string newName = "";
			int dSelect = 0;
			cout << "�鵽��" << id << "��ְ������������ְ���ţ� " << endl;
			cin >> newId;

			cout << "������������ " << endl;
			cin >> newName;

			cout << "�������λ��" << endl;
			cout << "1 ��ְͨ��" << endl;
			cout << "2 ����" << endl;
			cout << "3 �ϰ�" << endl;

			cin >> dSelect;

			Worker *worker = NULL;
			switch (dSelect)
			{
			case 1:
				worker = new Employee(newId, newName, dSelect);
				break;
			case 2:
				worker = new Manager(newId, newName, dSelect);
				break;
			case 3:
				worker = new Boss(newId, newName, dSelect);
				break;
			default:
				break;
			}
			//�������ݵ�������

			this->m_EmpArray[ret] = worker;

			cout << "�޸ĳɹ�" << endl;

			//���浽�ļ���
			this->save();
		}
		else
		{
			cout << "�޸�ʧ�ܣ����޴���" << endl;
		}
	}
	system("pause");
	system("cls");
}

//����ְ��
void WorkerManager::Find_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ��¼Ϊ��" << endl;
	}
	else
	{
		cout << "��������ҵķ�ʽ�� " << endl;
		cout << "1 ��ְ����Ų��� " << endl;
		cout << "2 ��ְ���������� " << endl;

		int select = 0;
		cin >> select;

		if(select==1)
		{
			//���ձ�Ų�
			int id;
			cout << "��������ҵ�ְ����ţ� " << endl;
			cin >> id;

			int ret = IsExist(id);
			if (ret != -1)
			{
				//�ҵ�ְ��
				cout << "���ҳɹ�����ְ����Ϣ����" << endl;
				this->m_EmpArray[ret]->showInfo();
			}
			else
			{
				cout << "����ʧ�ܣ����޴���" << endl;
			}

		}
		else if (select == 2)
		{
			//����������
			//���ձ�Ų�
			string name;
			cout << "��������ҵ�ְ�������� " << endl;
			cin >> name;
			
			//����һ���жϲ����Ƿ�鵽�ı�־
			bool flag = false;//Ĭ��δ�ҵ�ְ��

			for (int i = 0; i < m_EmpNum; i++)
			{
				if (this->m_EmpArray[i]->m_Name == name)
				{
					cout << "���ҳɹ���ְ�����Ϊ��"
						<< this->m_EmpArray[i]->m_Id
						<< "��ְ����ϢΪ��" << endl;
					flag = true;
					this->m_EmpArray[i]->showInfo();
				}
			}
			if (flag==false)
			{
				cout << "����ʧ�ܣ����޴���" << endl;
			}
		}
		else
		{
			cout << "�����ѡ������" << endl;
		}
		
	}
	system("pause");
	system("cls");
}
void WorkerManager::Sort_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ��߼�¼Ϊ��" << endl;
		system("pause");
		system("cls");
	}
	cout << "����������ķ�ʽ�� " << endl;
	cout << "1 ��ְ��������� " << endl;
	cout << "2 ��ְ���������� " << endl;

	int select = 0;
	cin >> select;

	for (int i = 0; i < m_EmpNum; i++)
	{
		int minOrMax = i; //������Сֵ�����ֵ�±�
		for (int j = i + 1; j < this->m_EmpNum; j++)  //ͨ�����for�����ж�һ��ʼ�϶�����Сֵ�ǲ��Ƿ�ʯ
		{
			if (select == 1)//����
			{
				if (this->m_EmpArray[minOrMax]->m_Id>this->m_EmpArray[j]->m_Id)
				{
					minOrMax = j;
				}

			}
			else //����
			{
				if (this->m_EmpArray[minOrMax]->m_Id>this->m_EmpArray[j]->m_Id)
				{
					minOrMax = j;
				}
			}
		}
		if (i != minOrMax)
		{
			Worker *temp = this->m_EmpArray[i];
			this->m_EmpArray[i] = this->m_EmpArray[minOrMax];
			this->m_EmpArray[minOrMax] = temp;
		}
	}
	cout << "����ɹ��������Ľ��Ϊ�� " << endl;
	this->save();
	this->Show_Emp();//չʾ���е�ְ��

	
}
void WorkerManager::Clean_File()
{
	cout << "ȷ����գ�" << endl;
	cout << "1 ȷ��" << endl;
	cout << "2 ����" << endl;
	int select = 0;
	cin >> select;

	if (select == 1)
	{
		//ɾ���ļ������´���
		ofstream ofs(FILENAME, ios::trunc);//ɾ���ļ������´���
		ofs.close();

		if (this->m_EmpArray != NULL)
		{
			//ɾ��������ÿ��ְ������
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				delete this->m_EmpArray[i];
				this->m_EmpArray[i] = NULL;

			}
			//ɾ����������ָ��
			delete[] this->m_EmpArray;
			this->m_EmpArray = NULL;
			this->m_EmpNum = 0;
			this->m_FileIsEmpty = true;
		}
		cout << "��ճɹ�" << endl;
	}
	system("pause");
	system("cls");
}
WorkerManager::~WorkerManager()
{

}