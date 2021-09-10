//通讯录管理系统功能介绍
//添加联系人：向通讯录中添加新人，信息包括（姓名、性别、年龄、联系电话、家庭住址）
//最多记录1000人；
//显示联系人：显示通讯录中所有联系人信息
//删除联系人：按照姓名删除指定联系人
//查找联系人：按照姓名查看指定联系人信息
//修改联系人：按照姓名重新修改指定联系人信息
//清空联系人：清空通讯录中所有信息
//退出通讯录：退出当前通讯录

#include<iostream>
#include<string>
#include<ctime>//时间的文件，与time的调用有关
#include<math.h>
#include"子函数.h"
using namespace std;
#define MAX 100

//设计联系人结构体
struct person
{
	string name;//联系人姓名
	string sex;//联系人性别
	int age; //联系人年龄
	string number;//联系人电话
	string addr;//联系人地址
};

//设计通讯录结构体
struct addressbook
{
	//通讯录中保存的联系人数组
	struct person personArray[MAX];
	//通讯录中当前记录联系人个数
	int m_size;
};

//通讯录函数定义
void addperson(addressbook* abs)
{
	if (abs->m_size == MAX)
	{
		cout << "通讯录已满，无法添加！" << endl;
	}
	else
	{
		//添加具体联系人
		cout << "请输入姓名" << endl;
		cin >> abs->personArray[abs->m_size].name;
		cout << "请输入性别" << endl;
		cin >> abs->personArray[abs->m_size].sex;
		cout << "请输入年龄" << endl;
		cin >> abs->personArray[abs->m_size].age;
		cout << "请输入电话号码" << endl;
		cin >> abs->personArray[abs->m_size].number;
		cout << "请输入地址" << endl;
		cin >> abs->personArray[abs->m_size].addr;
		abs->m_size++;//通讯录人数增加
		cout << "添加成功" << endl;
		system("pause");//请按任意键继续
		system("cls");//清屏操作
	}
}

//显示联系人
void showperson(addressbook* abs)
{
	if (abs->m_size == 0)
	{
		cout << "通讯录中暂时无人，无法显示！" << endl;
	}
	else
	{
		cout << "姓名" << "\t" << "性别" << "\t" << "年龄" <<
			"\t" << "电话号码" << "\t" << "地址" << endl;
		for (int i = 0;i <= abs->m_size-1;i++)
		{
			//显示具体联系人
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

//显示联系人是否存在，如果存在返回数组中的具体位置，不存在返回-1

int searchperson(addressbook* abs, string name)
{
	for (int i = 0;i < abs->m_size;i++)
	{
		//找到用户输入的姓名了
		if (abs->personArray[i].name == name)
		{
			return i;//找到了人名
		}
	}
	return -1;
}

//删除联系人
void seleteperson(addressbook* abs)
{
	cout << "请输入您要删除的联系人" << endl;
	string name;
	cin >> name;
	//找到联系人
	int ret = searchperson(abs, name);//此处abs不需要指针寻址符，因为函数内的abs就是地址符
	if (ret != -1)
	{
		//删除联系人
		//要删除李四，即将李四后的人员前移，并将记录的人员个数-1即可
		for (int i = ret;i < abs->m_size;i++)
		{
			//数据前移操作
			abs->personArray[i] = abs->personArray[i + 1];
		}
		abs->m_size--;
		cout << "删除成功" << endl;
	}
	else
	{
		cout << "查无此人" << endl;
	}
	system("pause");
	system("cls");
}

//查找联系人
void findperson(addressbook* abs)
{
	cout << "请输入您要查找的联系人" << endl;
	string name;
	cin >> name;
	//找到联系人
	int ret = searchperson(abs, name);
	if (ret != -1)
	{
		//查找联系人并显示
		cout << "您要查找的联系人如下：" << endl;
		cout << "姓名" << "\t" << "性别" << "\t" << "年龄" <<
			"\t" << "电话号码" << "\t" << "地址" << endl;
		cout << abs->personArray[ret].name << "\t"
			<< abs->personArray[ret].sex << "\t"
			<< abs->personArray[ret].age << "\t"
			<< abs->personArray[ret].number << "\t"
			<< abs->personArray[ret].addr << endl;
	}
	else
	{
		cout << "查无此人" << endl;
	}
	system("pause");
	system("cls");
}

int main()
{
	//创建通讯录结构体变量
	addressbook abs;
	//初始化通讯录中当前人员个数
	abs.m_size = 0;

	while(true)
	{

		showMenu();//显示菜单
		int select;//创建用户选择的变量
		cin >> select;
		switch (select)
		{
		case 1: //1、添加联系人
			addperson(&abs);//利用地址传递可以修饰实参
			break;
		case 2: //2、显示联系人
			showperson(&abs);
			break;
		case 3: //3、删除联系人
		//用{}将代码包住表示只有一个代码行
		//{
		//	cout << "请输入删除联系人姓名" << endl;
		//	string name;
		//	cin >> name;
		//	if (searchperson(&abs, name))
		//	{
		//		cout << "没找到" << endl;
		//	}
		//}
			seleteperson(&abs);
			break;
		case 4: //4、查找联系人
			findperson(&abs);
			break;
		case 5: //5、修改联系人
			break;
		case 6: //6、清空联系人
			break;
		case 0: //0、推出通讯录
			cout << "欢迎下次使用" << endl;
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
