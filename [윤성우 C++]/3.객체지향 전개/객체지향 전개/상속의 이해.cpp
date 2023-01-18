#include <iostream>
using std::cout;
using std::cin;
using std::endl;
//����� ����
/*//[����1]
   //���

class Account
{
private:
	char acc_num[10];
	int balance;
public:
	Account(const char* num, int bal)
	{
		balance = bal;
		strcpy(acc_num, num);
	}
	virtual void ShowData()
	{
		cout << "���� ��ȣ:" << acc_num<<endl;
		cout << "�����ܾ�:" << balance << endl;
	}
};
class KBAccount :public Account
{
private:
	int trans_limit;
public:
	KBAccount(const char* num, int bal, int limit) :Account(num, bal)
	{
		trans_limit = limit;
	}
	virtual void ShowData()final
	{
		Account::ShowData();
		cout << "��ü�ѵ�:" << trans_limit << endl;
	}

};
int main()
{
	KBAccount acc("1234-5678", 5000, 100000);
	acc.ShowData();
	return 0;
}
*/
/*//[����2]

class Person
{
private:
	char* name;
	int age;
public:
	Person() :name(nullptr), age(-1)
	{

	}
	Person(const char* _name, int _age):age(_age)
	{
		int strsize = strlen(_name);
		name = new char[strsize+1];
		strcpy(name, _name);
	}
	Person(const Person& _ref) :age(_ref.age)
	{
		int strsize = strlen(_ref.name);
		name = new char[strsize+1];
		strcpy(name, _ref.name);
	}
	virtual void ShowData()
	{
		cout << "�̸�:" << name<<endl;
		cout << "����:" << age << endl;
	}
	virtual ~Person()
	{
		cout << "person �Ҹ�\n";
		delete name;
	}
};
class Student:public Person
{
private:
	char* major;
public:
	Student() :Person(), major(nullptr)
	{

	}
	Student(const char* _name, int _age, const char* _major):Person(_name,_age)
	{
		int strsize = strlen(_major);
		major = new char[strsize+1];
		strcpy(major, _major);
	}
	Student(const Student& _ref) :Person(_ref)
	{
		int strsize = strlen(_ref.major);
		major = new char[strsize+1];
		strcpy(major, _ref.major);
	}
	virtual void ShowData()final
	{
		Person::ShowData();
		cout << "����:" << major << endl;
	}
	~Student()
	{
		cout << "student �Ҹ�\n";
		delete major;
	}
};

int main()
{
	Student Hong1("Hong gil dong", 20, "computer");
	Hong1.ShowData();
	Student Hong2 = Hong1;
	Hong2.ShowData();
}
*/
/*
base ���� private �� ����� derived���� private�� base�� ��ӹ޾Ҵٸ�
private�̻��� ���ٱ��� ���°� �ȴ�. �Ʒ��� �װͿ� ���� ����.
base�� public ����� ��Ӱ������� private�� �Ǿ������� Derived ��ü����
������ �����ϴ�.
�̰� ������ �ٸ��� �ణ private ������� ���� �ٲ� ������������ ���
�ڽ�Ŭ������ ���ξ��� �Ǿ ���� �����Ѱ�ó�� �����ϸ� �ǰ�
������ �θ�Ŭ�������� private ������ �Ǿ��ִ� ���·� ��ӹ��� ��������� 
public,protected,private �� �ص� ���� �Ұ� ��������� �ȴ�.
*/
/*
class Base
{
public:
	int a;
	int b;
private:
	int c;
};
class Derived :private Base
{
	void Show()
	{
		this->a = 2;
		this->b = 3;
		//this->c//���� �Ұ�!
	}
};
*/