#include <iostream>
#pragma region struct
//����ü�� ���  main�� ����ü ���� �κ��� c������ ���� c++����
//c++������ �⺻ �ڷ����� ����� ���� �ڷ����� ���Ͻ� ���ڴ� �⺻ ö���� ����.
/* 
struct A
{
	int age;
	char name[10];
};
int main()
{
	int a = 0;
	A _a;
	return 0;
}
*/
/*
c������ ����ü�� ����Լ��� ������ �������� c++������ ����
c++���� struct�� class �� ���̴� �⺻ �������� �̿ܿ��� ���̰� ����
������ struct�� class �� �����ؼ� ����ϴ� ������ �����Ҷ� ��κ��� �������
struct�� data�� ����, class �� data+�Լ� �� ���� ������ struct�� class ó�� ����ϸ� 
������ ���� �� �ִ�.

���� ��� struct�� virtual�� ���� v-tbl �����ͳ� ������ �����Ͱ� �ִٰ� �ϸ�,
struct�� ��� ����ڵ��� �����͸� ����ִٰ� �����ؼ� memcpy�� ����ϴ� ��찡 ������ 
�̷��� �� ��� ���� ���簡 �ƴ� ���� ���簡 �Ͼ�� ������ �� ��ü�� �ϳ��� ������ �ּҸ� ������ �ȴ�.
�̶� ���� �����Ͱ� ������� ����� �����ʹ� �߸��� �ּҸ� ����Ű�� �Ǵ� ��.
���� struct ���ÿ��� �ִ��� data �� ������ �ֵ��� �Ѵ�.
*/

#pragma endregion
#pragma region class
/*Ŭ������ ���� ������ �繰�� ����� ����, �������� ������ ������ 
�������� �߻�ȭ�� �̷���� ��ü�̴�.
=> [���] class = ��� ���� + ��� �Լ�*/
//[���� 1]
/*
class Calculator
{
private:
	int add_cnt;
	int min_cnt;
	int div_cnt;
	int mul_cnt;
public:
	void InIt()
	{
		add_cnt = 0;
		min_cnt = 0;
		div_cnt = 0;
		mul_cnt = 0;
	}
	int Add(int a, int b)
	{
		++add_cnt;
		return a + b;
	}
	int Min(int a,int b)
	{
		++min_cnt;
		return a - b;
	}
	double Div(int a, int b)
	{
		++div_cnt;
		return (double)(a)/ (double)(b);
	}
	int Mul(int a, int b)
	{
		++mul_cnt;
		return a * b;
	}
	void ShowOpCount()
	{
		std::cout << "����: " << add_cnt << " ����: " << min_cnt << " ����: " << mul_cnt << "������: " << div_cnt;
	}
};

int main()
{
	Calculator cal;
	cal.InIt();

	std::cout << "3+5=" << cal.Add(3, 5) << std::endl;
	std::cout << "3/5=" << cal.Div(3, 5) << std::endl;
	std::cout << "12-4=" << cal.Min(12, 4) << std::endl;
	std::cout << "12/4=" << cal.Div(12, 4) << std::endl;

	cal.ShowOpCount();
	return 0;
}
*/
//[����2]
/*
class Printer
{
private: 
	std::string str;
public:
	void SetString(const char* _str)
	{
		str = _str;
	}
	void PrintStrinf()
	{
		std::cout << str << std::endl;
	}
};
int main()
{
	Printer pt;
	pt.SetString("Hello World");
	pt.PrintStrinf();

	pt.SetString("I Love C++");
	pt.PrintStrinf();
	return 0;
}
*/
#pragma endregion