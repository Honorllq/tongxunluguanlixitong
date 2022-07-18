#include<iostream>
#include<string>
#define max 1000
using namespace std;
//联系人的结构体
struct person
{
	string name;//姓名
	int sex;//性别 1.男 2.女
	int age;//年龄
	string phonenumber;//联系电话
	string add;//地址
};
// 通讯录的结构体
struct addressbooks
{
	struct person personnumber[max];//通讯录中保存的联系人数组

	int size;//通讯录中记录的联系人个数
};
//菜单界面
void showmenu()
{
	cout << "****************************"<< endl;
	cout << "*******  1.添加联系人  *****" << endl;
	cout << "*******  2.显示联系人  *****" << endl;
	cout << "*******  3.删除联系人  *****" << endl;
	cout << "*******  4.查找联系人  *****" << endl;
	cout << "*******  5.修改联系人  *****" << endl;
	cout << "*******  6.清空联系人  *****" << endl;
	cout << "*******  0.退出通讯录  *****" << endl;
	cout << "****************************" << endl;
}
//1.添加联系人
void addperson(addressbooks* abs)
{
	if (abs->size == max)
	{
		cout << "通讯录已满，无法添加" << endl;
		return;
	}
	else
	{
		//添加具体的联系人
		string name;//姓名
		cout << "请输入姓名：" << endl;
		cin >> name;
		abs->personnumber[abs->size].name = name;
		int sex;//性别


		cout << "请输入性别：" << endl;
		while (true)
		{
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->personnumber[abs->size].sex = sex;
				break;
			}
			else
				cout << "您的输入有误，请重新输入" << endl;
		}



		int age;//年龄
		cout << "请输入年龄:" << endl;
		cin >> age;
		abs->personnumber[abs->size].age = age;


		string phonenumber;//电话
		cout << "请输入联系电话:" << endl;
		cin >> phonenumber;
		abs->personnumber[abs->size].phonenumber = phonenumber;



		string add;//住址
		cout << "请输入住址" << endl;
		cin >> add;
		abs->personnumber[abs->size].add = add;

		abs->size++;//更新通讯录人数
		cout << "您添加成功了" << endl;
		system("pause");//请按任意键继续
		system("cls");//清屏

	}

}
//2.显示联系人
void showperson(addressbooks* abs)
{
	if (abs->size == 0)
	{
		cout << "当前内容为空" << endl;
	}
	else
	{
		int i;
		for (i = 0; i < abs->size; i++)
		{
			cout << "姓名：" << abs->personnumber[i].name << "\t";
			cout << "性别：" <<( abs->personnumber[i].sex==1?"男":"女") << "\t";
			cout << "年龄：" << abs->personnumber[i].age << "\t";
			cout << "电话: " << abs->personnumber[i].phonenumber << "\t";
			cout << "住址：" << abs->personnumber[i].add << "\t\n";
		}
	}
	system("pause");//请按任意键继续
	system("cls");//清屏

}
//搜索联系人
//用遍历的方法搜索联系人，如果可以搜索到返回值为i，即在数组中的位置，如果搜索不到就返回-1
//参数一是通讯录，参数二为姓名
int isexit(addressbooks *abs, string name)
{
	for (int i = 0; i < abs->size; i++)
	{
		if (abs->personnumber[i].name == name)
			return i;
	}
	return -1;
}
//3.删除联系人
void deleteperson(addressbooks* abs)
{
	cout << "请输入您所要删除联系人的姓名" << endl;
	string name;
	cin >> name;
	int ret = isexit(abs, name);
	if (ret!=0)
	{

		for (int i = ret; ret < abs->size; i++)
		{
			abs->personnumber[i] = abs->personnumber[i + 1];//数据前移，以此达到删除联系人的目的
		}
		abs->size--;//更新联系人人数
		cout << "删除成功" << endl;
	}
	else
	{
		cout << "查无此人" << endl;
		
	}
	system("pause");//请按任意键继续
	system("cls");//清屏
}
//4.查找联系人
void findperson(addressbooks* abs)
{
	cout << "请输入要查找联系人的姓名" << endl;
	string name;
	cin >> name;
	int ret = isexit(abs, name);
	if (ret != -1)
	{
		cout << "姓名：" << abs->personnumber[ret].name << "\t";
		cout << "性别：" << (abs->personnumber[ret].sex == 1 ? "男" : "女") << "\t";
		cout << "年龄：" << abs->personnumber[ret].age << "\t";
		cout << "电话: " << abs->personnumber[ret].phonenumber << "\t";
		cout << "住址：" << abs->personnumber[ret].add << "\t\n";
	}
	else
	{
		cout << "查无此人" << endl;
	}
	system("pause");//请按任意键继续
	system("cls");//清屏
}
//5.修改联系人
void modifyperson(addressbooks *abs)
{	
	cout << "请输入要修改联系人的姓名" << endl;
	string name;
	cin >> name;
	int ret = isexit(abs, name);
	if (ret != -1)
	{
		//修改内容
		string name;//姓名
		cout << "请输入姓名：" << endl;
		cin >> name;
		abs->personnumber[ret].name = name;
		int sex;//性别


		cout << "请输入性别：" << endl;
		while (true)
		{
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->personnumber[ret].sex = sex;
				break;
			}
			else
				cout << "您的输入有误，请重新输入" << endl;
		}



		int age;//年龄
		cout << "请输入年龄:" << endl;
		cin >> age;
		abs->personnumber[ret].age = age;


		string phonenumber;//电话
		cout << "请输入联系电话:" << endl;
		cin >> phonenumber;
		abs->personnumber[ret].phonenumber = phonenumber;



		string add;//住址
		cout << "请输入住址" << endl;
		cin >> add;
		abs->personnumber[ret].add = add;
	}
	else
	{
		cout << "查无此人" << endl;
	}
	system("pause");//请按任意键继续
	system("cls");//清屏

}
//6.清空通讯录
void cleanperson(addressbooks* abs)
{
	abs->size = 0;//将当前联系人数量置为零，做逻辑清空
	cout << "通讯录已清空" << endl;
	system("pause");//请按任意键继续
	system("cls");//清屏

}




int main()
{
	addressbooks abs;//创建结构体变量
	abs.size = 0;
	while (true)
	{
		showmenu();
		int select = 0;
		cin >> select;
		switch (select)
		{
		case 1:addperson(&abs);//1.添加联系人
			break;
		case 2:showperson(&abs);//2.显示联系人
			break;
		case 3:deleteperson(&abs);//3.删除联系人
			break;
		case 4:findperson(&abs);//4.查找联系人
			break;
		case 5:modifyperson(&abs); //5.修改联系人
			break;
		case 6:cleanperson(&abs);//6.清空联系人
			break;
		case 0 :
			cout << "欢迎下次使用" << endl;
			system("pause");
			return 0;
			break;


		}
	}
	system("pause");
	return 0;

}