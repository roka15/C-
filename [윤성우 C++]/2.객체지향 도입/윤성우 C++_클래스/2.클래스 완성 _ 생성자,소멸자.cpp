#include <iostream>
/*Ŭ���� 4�� �Ӽ� 
1. ĸ��ȭ :�����ִ� ������,�Լ��� �ϳ��� ������ ����.
2. ������
3. ��Ӽ�
4. ���� ����*/
/*
!! ��ü ������ �߻��ϴ� �� !!
	 1. �޸� �Ҵ�
	 2. ������ ȣ��
!! �Ҹ��ڽ� �߻��ϴ� �� !! 
     1. �Ҹ��� ����
	 2. �޸� ��ȯ

new �� �޸� �Ҵ�, ������ ȣ���� ������
malloc �� �޸𸮸� �Ҵ��Ѵ�.
free�� delete �� ��������.
�׷��� ��ü ������ �Ҷ� malloc�̳� free ���� 
������, �Ҹ��ڰ� ������ �ȵȴ�.
*/
using std::cout;
using std::cin;
using std::endl;

//[���� 1] 
/*
class Rectangle
{
private:
	double x;
	double y;
public:
	Rectangle(double x, double y)
	{
		this->x = x;
		this->y = y;
	}
	double GetArea()
	{
		return x * y;
	}
	double GetGirth()
	{
		return (x + y) * 2;
	}
};
class Circle
{
private:
	double radius;
public:
	Circle(double radius) :radius(radius)
	{

	}
	double GetArea()
	{
		return radius * radius * 3.14;
	}
	double GetGirth()
	{
		return 3.14 * radius * 2;
	}
};
int main()
{
	Rectangle rec(3, 4);
	cout << "����:" << rec.GetArea() << endl;
	cout << "�ѷ�:" << rec.GetGirth() << endl;

	Circle cir(5);
	cout << "����:" << cir.GetArea() << endl;
	cout << "�ѷ�:" << cir.GetGirth() << endl;

	return 0;
}
*/

//[����2]
/*
class Time
{
private:
	static const int distance = 60;
	int hour;
	int min;
	int sec;
public:
	Time(int h=0, int m=0, int s=0) :hour(h), min(m), sec(s)
	{

	}
	~Time()
	{

	}
	void ShowTime()
	{
		cout << hour << "�� " << min << "�� " << sec << "��\n";
	}
	void ShowTimeinSec()
	{
		int sum = sec;
		sum += (min * distance);
		sum += (hour * distance * distance);
		cout << sum << "��\n";
	}
};
int main()
{
	Time time1(10);
	Time time2(10, 20);
	Time time3(10, 20, 30);
	time2.ShowTime();
	time2.ShowTimeinSec();
	return 0;
}
*/
