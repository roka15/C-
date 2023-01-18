// ���� �ý���
#include <iostream>
#define ACCOUNT_MAX 30
#define STRING_MAX 20
using std::cout;
using std::cin;
using std::endl;
class Account
{
private:
	char* name;
	int id;
	int balance;
public:
	Account() :name(nullptr), id(0), balance(0) {}
	Account(const char* _n, int _id, int _bal = 0) :id(_id), balance(_bal)
	{
		int strsize = strlen(_n);
		name = new char[strsize + 1];
		strcpy(name, _n);
	}
	Account(const Account& _account)
	{
		int strsize = strlen(_account.name);
		name = new char[strsize + 1];
		strcpy(name, _account.name);
		balance = _account.balance;
		id = _account.id;
	}
	~Account()
	{
		delete name;
	}
	int GetID()const
	{
		return id;
	}
	const char* GetName()const
	{
		return name;
	}
	int GetBalance()const
	{
		return balance;
	}
	void AddMoney(int val)
	{
		balance += val;
	}
	void MinMoney(int val)
	{
		balance -= val;
	}
	void ShowData()
	{
		cout << "�̸�:" << name << endl;
		cout << "���̵�:" << id << endl;
		cout << "�ܾ�:" << balance << endl;
	}
};
class AccountManager
{
private:
	Account** account_list;
	int list_size;
	Account* SearchAccount(int id)
	{
		for (int i = 0; i < list_size; i++)
		{
			if (account_list[i]->GetID() == id)
			{
				return account_list[i];
			}
		}
		return nullptr;
	}
public:
	AccountManager() :account_list(nullptr), list_size(0)
	{
		account_list = new Account * [ACCOUNT_MAX];
	}
	void PrintMenu()
	{

		cout << "-----Menu------" << endl;
		cout << "1.���� ����" << endl;;
		cout << "2.�Ա�" << endl;
		cout << "3.���" << endl;
		cout << "4.�ܾ� ��ȸ" << endl;
		cout << "5.���α׷� ����" << endl;
	}
	void MakeAccount()
	{
		if (list_size == ACCOUNT_MAX)
		{
			cout << "���� �Ұ�" << endl;
		}
		std::string name;
		int id;

		cout << "�̸� �Է�";
		cin >> name;
		cout << "���̵�";
		cin >> id;
		// �ߺ��Ǵ� ���̵� ���ٴ� �����Ͽ� ����
		Account* account = new Account(name.c_str(), id);
		account_list[list_size] = account;
		list_size++;
	}
	void Deposit()
	{
		int id;
		int n;
		cout << "���̵� �Է�";
		cin >> id;
		cout << "�Աݾ� �Է�";
		cin >> n;
		Account* a = SearchAccount(id);
		if (a == nullptr)
		{
			cout << "���� ���̵�" << endl;
			return;
		}
		a->AddMoney(n);
	}

	void Withdraw()
	{
		int id;
		int n;
		cout << "���̵� �Է�";
		cin >> id;
		cout << "��ݾ� �Է�";
		cin >> n;
		Account* a = SearchAccount(id);
		if (a == nullptr)
		{
			cout << "���� ���̵�" << endl;
			return;
		}
		a->MinMoney(n);
	}
	void Inquire()
	{
		int id;
		cout << "���̵� �Է�";
		cin >> id;
		const Account* a = SearchAccount(id);
		if (a == nullptr)
		{
			cout << "���� ���̵�" << endl;
			return;
		}
		cout << "���� �ݾ�: " << a->GetBalance() << endl;
	}
};
enum class Menu
{
	MAKE = 1,
	DEPOSIT,
	WITHDRAW,
	INQUIRE,
	EXIT,
};
int main()
{
	int choice;
	AccountManager M_account;
	while (1)
	{
		M_account.PrintMenu();
		cin >> choice;
		switch ((Menu)choice)
		{
		case Menu::MAKE:
			M_account.MakeAccount();
			break;
		case Menu::DEPOSIT:
			M_account.Deposit();
			break;
		case Menu::WITHDRAW:
			M_account.Withdraw();
			break;
		case Menu::INQUIRE:
			M_account.Inquire();
			break;
		case Menu::EXIT:
			cout << "����" << endl;
			return 0;
		}
	}
}

