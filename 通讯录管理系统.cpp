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
			break;
		case 3: //3、删除联系人
			break;
		case 4: //4、查找联系人
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
