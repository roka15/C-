/* 
��������� �Ű������� & �� �ٿ����� ������ ���ѷ����� ������ ����: 
���� ���� ������� ���ÿ� ���������� �׿��� �׷���?
��������� ȣ�� -> ���ڷ� �Ѿ�� ��ü�� ���� -> 
������, ��������� ȣ�� -> �� ��������� �ȿ��� �Ǵٽ� ��ü ���� -> ��������� ȣ�� -> ... ���ѹݺ� ...

������� ������ �������� ��ü �޸� �Ҵ� �� ��������ڸ� �����ϴµ� �� ���� �����ڿ����� �� ��������ڸ� 
ȣ���ϸ� ���ѹݺ��� �Ǵ°�.

�� ����� ���۷���(&)�� ����� Call by Reference�� ���ڸ� �Ѱ��ִ� ������ ������ ���� ũ�� 2�����̴�.

1. &�� ������� �ʰ� �����͸� ����ϸ� ������ ������ �����ϱ� ������ �߸��� �޸� ������ �� ���ɼ��� ��������.
2. �ణ�� ��������� �����ϴ�.
*/
#include <iostream>
//[����1]
/*
class NameCard
{
private:
	char* name;
	char* phone;
public:
	NameCard(const char* _name, const char* _phone)
	{
		int strsize = strlen(_name);
		name = new char[strsize+1];
		strcpy(name, _name);
		strsize = strlen(_phone);
		phone = new char[strsize + 1];
		strcpy(phone, _phone);
	}
	NameCard(const NameCard& nc)
	{
		int strsize = strlen(nc.name);
		name = new char[strsize+1];
		strcpy(name, nc.name);
		strsize = strlen(nc.phone);
		phone = new char[strsize+1];
		strcpy(phone, nc.phone);
	}
	void ShowData()
	{
		std::cout << "name:" << name << std::endl;
		std::cout << "phone:" << phone << std::endl;
	}
	~NameCard()
	{
		delete name;
		delete phone;
	}
};
int main()
{
	NameCard Lee("Lee Hun", "333-3333");
	NameCard Lee2(Lee);
	Lee2.ShowData();
	return 0;
}*/