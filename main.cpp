#include<iostream>
#include<string>
#define MAX 1000
using namespace std;
void showMenu()
{	
	cout << "******************************" << endl;
	cout << "*********1.�����ϵ��*********" << endl;
	cout << "*********2.��ʾ��ϵ��*********" << endl;
	cout << "*********3.ɾ����ϵ��*********" << endl;
	cout << "*********4.������ϵ��*********" << endl;
	cout << "*********5.�޸���ϵ��*********" << endl;
	cout << "*********6.�����ϵ��*********" << endl;
	cout << "*********0.�˳�ͨѶ¼*********" << endl;
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
		cout << "ͨѶ¼�Ѿ����ˣ��޷����" << endl;
		return;
	}
	else
	{
		string name;
		cout << "����������" << endl;
		cin >> name;
		abs->per[abs->m_size].name = name;
		int m_sex;
		cout << "�������Ա�" << endl;
		cout << "1----��" << endl << "2----Ů" << endl;

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
				cout << "����������������" << endl;
			}
		}
		int m_age;
		cout << "����������" << endl;

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
				cout << "����������������" << endl;
			}
		}
		string m_phone;
		cout << "������绰" << endl;

		while (true)
		{
			cin >> m_phone;
			cout << "�绰λ���ǣ�" << m_phone.length() << endl;
			if (m_phone.length() == 11)
			{
				abs->per[abs->m_size].m_phone = m_phone;
				break;
			}
			else
			{
				cout << "����������������" << endl;
			}
		}
		string address;
		cout << "�������ͥסַ" << endl;
		cin >> address;
		abs->per[abs->m_size].m_addr = address;
		abs->m_size++;
		cout << "��ӳɹ�" << endl;
		system("pause");
		system("cls");

	}
}

void showperson(addressbooks * abs)
{
	if (abs->m_size == 0)
	{
		cout << "��ǰ��¼Ϊ��" << endl;
	}
	else
	{
		for (int i = 0; i < abs->m_size; i++)
		{
			cout << "������" << abs->per[i].name << "\t";
			cout << "�Ա�: " << (abs->per[i].m_sex == 1?"��":"Ů") << "\t";
			cout << "����: " << abs->per[i].m_age << "\t";
			cout << "�绰: " << abs->per[i].m_phone << "\t";
			cout << "סַ: " << abs->per[i].m_addr << endl;
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
	cout << "����Ҫɾ������ϵ��" << endl;
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
		cout << "ɾ���ɹ���" << endl;
	}
	else
	{
		cout << "���޴���" << endl;
	}

}

void findperson(addressbooks* abs)
{
	cout << "������ϵ������" << endl;
	string name;
	cin >> name;
	int ret = isexit(abs, name);
	if (ret != -1)
	{
		cout << "������" << abs->per[ret].name << "\t";
		cout << "�Ա�: " << (abs->per[ret].m_sex == 1 ? "��" : "Ů") << "\t";
		cout << "����: " << abs->per[ret].m_age << "\t";
		cout << "�绰: " << abs->per[ret].m_phone << "\t";
		cout << "סַ: " << abs->per[ret].m_addr << endl;
	}
	else
	{
		cout << "δ�ҵ���ɫ" << endl;
	}
	system("pause");
	system("cls");
}

void modifyperson(addressbooks* abs)
{
	string name;
	cout << "��������Ҫ�޸ĵ���ϵ��" << endl;
	cin >> name;

	int ret = isexit(abs, name);
	if (ret != -1)
	{
		int choose;
		cout << "******************************" << endl;
		cout << "*********1.�޸�����*********" << endl;
		cout << "*********2.�޸��Ա�*********" << endl;
		cout << "*********3.�޸�����*********" << endl;
		cout << "*********4.�޸ĵ绰*********" << endl;
		cout << "*********5.�޸�סַ*********" << endl;
		cout << "*********6.�˳�*********" << endl;
		cout << "******************************" << endl;
		cin >> choose;
		switch (choose)
		{
		case 1:
		{
			string name;
			cout << "����������" << endl;
			cin >> name;
			abs->per[ret].name = name;
			modifyperson(abs);
			break;
		}
			
		case 2:
		{
			int m_sex;
			cout << "�������Ա�" << endl;
			cout << "1----��" << endl << "2----Ů" << endl;

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
					cout << "����������������" << endl;
				}
			}
			modifyperson(abs);
			break;
		}
			
		case 3:
		{
			int m_age;
			cout << "����������" << endl;

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
					cout << "����������������" << endl;
				}
			}
			modifyperson(abs);
			break;
		}
			
		case 4:
		{
			string m_phone;
			cout << "������绰" << endl;

			while (true)
			{
				cin >> m_phone;
				cout << "�绰λ���ǣ�" << m_phone.length() << endl;
				if (m_phone.length() == 11)
				{
					abs->per[ret].m_phone = m_phone;
					break;
				}
				else
				{
					cout << "����������������" << endl;
				}
			}
			modifyperson(abs);
			break;
		}
			
		case 5:
		{
			string address;
			cout << "�������ͥסַ" << endl;
			cin >> address;
			abs->per[ret].m_addr = address;
			modifyperson(abs);
			break;
		}
		case 6:
		{
			cout << "��ӭ�´�ʹ��" << endl;
			break;
		}
		default:
			break;
		}

	}
	else
	{
		cout << "δ���ҵ���ϵ��" << endl;
	}
	system("pause");
	system("cls");
}

void clearperson(addressbooks* abs)
{
	abs->m_size = 0;
	cout << "ͨѶ¼�Ѿ������" << endl;
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
				/*cout << "����ɾ����ϵ�˵�����" << endl;
								string name;
								cin >> name;
								cout << (isexit(&abs, name) == -1 ? "û�ҵ�����" : "�ҵ�����") << endl;*/
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