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
			break;
		case 3: //3��ɾ����ϵ��
			break;
		case 4: //4��������ϵ��
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
