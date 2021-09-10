//ͨѶ¼����ϵͳ���ܽ���
//�����ϵ�ˣ���ͨѶ¼��������ˣ���Ϣ�������������Ա����䡢��ϵ�绰����ͥסַ��
//����¼1000�ˣ�
//��ʾ��ϵ�ˣ���ʾͨѶ¼��������ϵ����Ϣ
//ɾ����ϵ�ˣ���������ɾ��ָ����ϵ��
//������ϵ�ˣ����������鿴ָ����ϵ����Ϣ
//�޸���ϵ�ˣ��������������޸�ָ����ϵ����Ϣ
//�����ϵ�ˣ����ͨѶ¼��������Ϣ
//�˳�ͨѶ¼���˳���ǰͨѶ¼

#include<iostream>
#include<string>
#include<ctime>//ʱ����ļ�����time�ĵ����й�
#include<math.h>
#include"�Ӻ���.h"
using namespace std;
#define MAX 100

//�����ϵ�˽ṹ��
struct person
{
	string name;//��ϵ������
	string sex;//��ϵ���Ա�
	int age; //��ϵ������
	string number;//��ϵ�˵绰
	string addr;//��ϵ�˵�ַ
};

//���ͨѶ¼�ṹ��
struct addressbook
{
	//ͨѶ¼�б������ϵ������
	struct person personArray[MAX];
	//ͨѶ¼�е�ǰ��¼��ϵ�˸���
	int m_size;
};

//ͨѶ¼��������
void addperson(addressbook* abs)
{
	if (abs->m_size == MAX)
	{
		cout << "ͨѶ¼�������޷���ӣ�" << endl;
	}
	else
	{
		//��Ӿ�����ϵ��
		cout << "����������" << endl;
		cin >> abs->personArray[abs->m_size].name;
		cout << "�������Ա�" << endl;
		cin >> abs->personArray[abs->m_size].sex;
		cout << "����������" << endl;
		cin >> abs->personArray[abs->m_size].age;
		cout << "������绰����" << endl;
		cin >> abs->personArray[abs->m_size].number;
		cout << "�������ַ" << endl;
		cin >> abs->personArray[abs->m_size].addr;
		abs->m_size++;//ͨѶ¼��������
		cout << "��ӳɹ�" << endl;
		system("pause");//�밴���������
		system("cls");//��������
	}
}

//��ʾ��ϵ��
void showperson(addressbook* abs)
{
	if (abs->m_size == 0)
	{
		cout << "ͨѶ¼����ʱ���ˣ��޷���ʾ��" << endl;
	}
	else
	{
		cout << "����" << "\t" << "�Ա�" << "\t" << "����" <<
			"\t" << "�绰����" << "\t" << "��ַ" << endl;
		for (int i = 0;i <= abs->m_size-1;i++)
		{
			//��ʾ������ϵ��
			cout << abs->personArray[i].name << "\t"
				<< abs->personArray[i].sex << "\t"
				<< abs->personArray[i].age << "\t"
				<< abs->personArray[i].number << "\t"
				<< abs->personArray[i].addr << endl;
		}
	}
	system("pause");
	system("cls");
}

//��ʾ��ϵ���Ƿ���ڣ�������ڷ��������еľ���λ�ã������ڷ���-1

int searchperson(addressbook* abs, string name)
{
	for (int i = 0;i < abs->m_size;i++)
	{
		//�ҵ��û������������
		if (abs->personArray[i].name == name)
		{
			return i;//�ҵ�������
		}
	}
	return -1;
}

//ɾ����ϵ��
void seleteperson(addressbook* abs)
{
	cout << "��������Ҫɾ������ϵ��" << endl;
	string name;
	cin >> name;
	//�ҵ���ϵ��
	int ret = searchperson(abs, name);//�˴�abs����Ҫָ��Ѱַ������Ϊ�����ڵ�abs���ǵ�ַ��
	if (ret != -1)
	{
		//ɾ����ϵ��
		//Ҫɾ�����ģ��������ĺ����Աǰ�ƣ�������¼����Ա����-1����
		for (int i = ret;i < abs->m_size;i++)
		{
			//����ǰ�Ʋ���
			abs->personArray[i] = abs->personArray[i + 1];
		}
		abs->m_size--;
		cout << "ɾ���ɹ�" << endl;
	}
	else
	{
		cout << "���޴���" << endl;
	}
	system("pause");
	system("cls");
}

//������ϵ��
void findperson(addressbook* abs)
{
	cout << "��������Ҫ���ҵ���ϵ��" << endl;
	string name;
	cin >> name;
	//�ҵ���ϵ��
	int ret = searchperson(abs, name);
	if (ret != -1)
	{
		//������ϵ�˲���ʾ
		cout << "��Ҫ���ҵ���ϵ�����£�" << endl;
		cout << "����" << "\t" << "�Ա�" << "\t" << "����" <<
			"\t" << "�绰����" << "\t" << "��ַ" << endl;
		cout << abs->personArray[ret].name << "\t"
			<< abs->personArray[ret].sex << "\t"
			<< abs->personArray[ret].age << "\t"
			<< abs->personArray[ret].number << "\t"
			<< abs->personArray[ret].addr << endl;
	}
	else
	{
		cout << "���޴���" << endl;
	}
	system("pause");
	system("cls");
}

int main()
{
	//����ͨѶ¼�ṹ�����
	addressbook abs;
	//��ʼ��ͨѶ¼�е�ǰ��Ա����
	abs.m_size = 0;

	while(true)
	{

		showMenu();//��ʾ�˵�
		int select;//�����û�ѡ��ı���
		cin >> select;
		switch (select)
		{
		case 1: //1�������ϵ��
			addperson(&abs);//���õ�ַ���ݿ�������ʵ��
			break;
		case 2: //2����ʾ��ϵ��
			showperson(&abs);
			break;
		case 3: //3��ɾ����ϵ��
		//��{}�������ס��ʾֻ��һ��������
		//{
		//	cout << "������ɾ����ϵ������" << endl;
		//	string name;
		//	cin >> name;
		//	if (searchperson(&abs, name))
		//	{
		//		cout << "û�ҵ�" << endl;
		//	}
		//}
			seleteperson(&abs);
			break;
		case 4: //4��������ϵ��
			findperson(&abs);
			break;
		case 5: //5���޸���ϵ��
			break;
		case 6: //6�������ϵ��
			break;
		case 0: //0���Ƴ�ͨѶ¼
			cout << "��ӭ�´�ʹ��" << endl;
			system("pause");
			return 0;
			break;
		default:
			break;
		}
	}
	system("pause");
	return 0;
}
