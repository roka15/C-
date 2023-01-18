#include <iostream>
using std::cout;
using std::cin;
using std::endl;
//상속의 이해
/*//[문제1]
   //상속

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
		cout << "계좌 번호:" << acc_num<<endl;
		cout << "계좌잔액:" << balance << endl;
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
		cout << "이체한도:" << trans_limit << endl;
	}

};
int main()
{
	KBAccount acc("1234-5678", 5000, 100000);
	acc.ShowData();
	return 0;
}
*/
/*//[문제2]

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
		cout << "이름:" << name<<endl;
		cout << "나이:" << age << endl;
	}
	virtual ~Person()
	{
		cout << "person 소멸\n";
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
		cout << "전공:" << major << endl;
	}
	~Student()
	{
		cout << "student 소멸\n";
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
base 에서 private 인 멤버를 derived에서 private로 base를 상속받았다면
private이상의 접근금지 상태가 된다. 아래는 그것에 대한 실험.
base의 public 멤버는 상속과정에서 private가 되었음에도 Derived 객체에서
접근이 가능하다.
이게 느낌이 다른게 약간 private 상속으로 인해 바뀐 접근지정자의 경우
자식클래스에 새로쓰기 되어서 접근 가능한것처럼 생각하면 되고
기존에 부모클래스에서 private 선언이 되어있는 상태로 상속받은 멤버변수는 
public,protected,private 를 해도 접근 불가 멤버변수가 된다.
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
		//this->c//접근 불가!
	}
};
*/