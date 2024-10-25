#include<iostream>
#include<string>
#define MAX 1000
using namespace std;
void showMenu()
{	
	cout << "******************************" << endl;
	cout << "*********1.添加联系人*********" << endl;
	cout << "*********2.显示联系人*********" << endl;
	cout << "*********3.删除联系人*********" << endl;
	cout << "*********4.查找联系人*********" << endl;
	cout << "*********5.修改联系人*********" << endl;
	cout << "*********6.清空联系人*********" << endl;
	cout << "*********0.退出通讯录*********" << endl;
	cout << "******************************" << endl;

}
struct person
{
	string name;
	int m_sex;
	int m_age;
	string m_phone;
	string m_addr;
};
struct addressbooks
{
	person per[MAX];
	int m_size;
};
void addperson(addressbooks* abs)
{
	if (abs->m_size == MAX)
	{
		cout << "通讯录已经满了，无法添加" << endl;
		return;
	}
	else
	{
		string name;
		cout << "请输入姓名" << endl;
		cin >> name;
		abs->per[abs->m_size].name = name;
		int m_sex;
		cout << "请输入性别" << endl;
		cout << "1----男" << endl << "2----女" << endl;

		while (true)
		{
			cin >> m_sex;
			if (m_sex == 2 || m_sex == 1)
			{
				abs->per[abs->m_size].m_sex = m_sex;
				break;
			}
			else
			{
				cout << "输入有误，重新输入" << endl;
			}
		}
		int m_age;
		cout << "请输入年龄" << endl;

		while (true)
		{
			cin >> m_age;
			if (m_age > 0 && m_age < 110)
			{
				abs->per[abs->m_size].m_age = m_age;
				break;
			}
			else
			{
				cout << "输入有误，重新输入" << endl;
			}
		}
		string m_phone;
		cout << "请输入电话" << endl;

		while (true)
		{
			cin >> m_phone;
			cout << "电话位数是：" << m_phone.length() << endl;
			if (m_phone.length() == 11)
			{
				abs->per[abs->m_size].m_phone = m_phone;
				break;
			}
			else
			{
				cout << "输入有误，重新输入" << endl;
			}
		}
		string address;
		cout << "请输入家庭住址" << endl;
		cin >> address;
		abs->per[abs->m_size].m_addr = address;
		abs->m_size++;
		cout << "添加成功" << endl;
		system("pause");
		system("cls");

	}
}

void showperson(addressbooks * abs)
{
	if (abs->m_size == 0)
	{
		cout << "当前记录为空" << endl;
	}
	else
	{
		for (int i = 0; i < abs->m_size; i++)
		{
			cout << "姓名：" << abs->per[i].name << "\t";
			cout << "性别: " << (abs->per[i].m_sex == 1?"男":"女") << "\t";
			cout << "年龄: " << abs->per[i].m_age << "\t";
			cout << "电话: " << abs->per[i].m_phone << "\t";
			cout << "住址: " << abs->per[i].m_addr << endl;
			cout << "------------------------" << endl;
		}
	}
	system("pause");
	system("cls");
}
int isexit(addressbooks* abs,string name)
{
	for (int i = 0; i < abs->m_size; i++)
	{
		if (abs->per[i].name == name)
		{
			return i;
		}
		
	}
	return -1;
	system("pause");
	system("cls");
}
void deleteperson(addressbooks* abs)
{
	cout << "输入要删除的联系人" << endl;
	string name;
	cin >> name;
	int ret = isexit(abs, name);
	if (ret != -1)
	{
		for (int i = ret+1; i < abs->m_size; i++)
		{
			abs->per[i-1] = abs->per[i];
		}
		abs->m_size--;
		cout << "删除成功！" << endl;
	}
	else
	{
		cout << "查无此人" << endl;
	}

}

void findperson(addressbooks* abs)
{
	cout << "输入联系人姓名" << endl;
	string name;
	cin >> name;
	int ret = isexit(abs, name);
	if (ret != -1)
	{
		cout << "姓名：" << abs->per[ret].name << "\t";
		cout << "性别: " << (abs->per[ret].m_sex == 1 ? "男" : "女") << "\t";
		cout << "年龄: " << abs->per[ret].m_age << "\t";
		cout << "电话: " << abs->per[ret].m_phone << "\t";
		cout << "住址: " << abs->per[ret].m_addr << endl;
	}
	else
	{
		cout << "未找到角色" << endl;
	}
	system("pause");
	system("cls");
}

void modifyperson(addressbooks* abs)
{
	string name;
	cout << "请输入需要修改的联系人" << endl;
	cin >> name;

	int ret = isexit(abs, name);
	if (ret != -1)
	{
		int choose;
		cout << "******************************" << endl;
		cout << "*********1.修改姓名*********" << endl;
		cout << "*********2.修改性别*********" << endl;
		cout << "*********3.修改年龄*********" << endl;
		cout << "*********4.修改电话*********" << endl;
		cout << "*********5.修改住址*********" << endl;
		cout << "*********6.退出*********" << endl;
		cout << "******************************" << endl;
		cin >> choose;
		switch (choose)
		{
		case 1:
		{
			string name;
			cout << "请输入姓名" << endl;
			cin >> name;
			abs->per[ret].name = name;
			modifyperson(abs);
			break;
		}
			
		case 2:
		{
			int m_sex;
			cout << "请输入性别" << endl;
			cout << "1----男" << endl << "2----女" << endl;

			while (true)
			{
				cin >> m_sex;
				if (m_sex == 2 || m_sex == 1)
				{
					abs->per[ret].m_sex = m_sex;
					break;
				}
				else
				{
					cout << "输入有误，重新输入" << endl;
				}
			}
			modifyperson(abs);
			break;
		}
			
		case 3:
		{
			int m_age;
			cout << "请输入年龄" << endl;

			while (true)
			{
				cin >> m_age;
				if (m_age > 0 && m_age < 110)
				{
					abs->per[ret].m_age = m_age;
					break;
				}
				else
				{
					cout << "输入有误，重新输入" << endl;
				}
			}
			modifyperson(abs);
			break;
		}
			
		case 4:
		{
			string m_phone;
			cout << "请输入电话" << endl;

			while (true)
			{
				cin >> m_phone;
				cout << "电话位数是：" << m_phone.length() << endl;
				if (m_phone.length() == 11)
				{
					abs->per[ret].m_phone = m_phone;
					break;
				}
				else
				{
					cout << "输入有误，重新输入" << endl;
				}
			}
			modifyperson(abs);
			break;
		}
			
		case 5:
		{
			string address;
			cout << "请输入家庭住址" << endl;
			cin >> address;
			abs->per[ret].m_addr = address;
			modifyperson(abs);
			break;
		}
		case 6:
		{
			cout << "欢迎下次使用" << endl;
			break;
		}
		default:
			break;
		}

	}
	else
	{
		cout << "未能找到联系人" << endl;
	}
	system("pause");
	system("cls");
}

void clearperson(addressbooks* abs)
{
	abs->m_size = 0;
	cout << "通讯录已经被清空" << endl;
	system("pause");
	system("cls");
}

int main()
{
	addressbooks abs;
	abs.m_size = 0;
	int select = 0;
	while(true)
	{
		showMenu();
			cin >> select;
			switch (select)
			{
			case 1:
				addperson(&abs);
				break;
			case 2:
				showperson(&abs);
				break;
			case 3: 
			{
				/*cout << "输入删除联系人的姓名" << endl;
								string name;
								cin >> name;
								cout << (isexit(&abs, name) == -1 ? "没找到此人" : "找到此人") << endl;*/
				deleteperson(&abs);
				break;
			}
				
			case 4:
				findperson(&abs);
				break;
			case 5:
				modifyperson(&abs);
				break;
			case 6:
				clearperson(&abs);
				break;
			case 0:
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