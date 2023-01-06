#include <iostream>
/*클래스 4대 속성 
1. 캡슐화 :관련있는 데이터,함수를 하나의 단위로 묶음.
2. 다형성
3. 상속성
4. 정보 은닉*/
/*
!! 객체 생성시 발생하는 일 !!
	 1. 메모리 할당
	 2. 생성자 호출
!! 소멸자시 발생하는 일 !! 
     1. 소멸자 실행
	 2. 메모리 반환

new 는 메모리 할당, 생성자 호출을 하지만
malloc 은 메모리만 할당한다.
free와 delete 도 마찬가지.
그래서 객체 생성을 할때 malloc이나 free 쓰면 
생성자, 소멸자가 실행이 안된다.
*/
using std::cout;
using std::cin;
using std::endl;

//[문제 1] 
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
	cout << "면적:" << rec.GetArea() << endl;
	cout << "둘레:" << rec.GetGirth() << endl;

	Circle cir(5);
	cout << "면적:" << cir.GetArea() << endl;
	cout << "둘레:" << cir.GetGirth() << endl;

	return 0;
}
*/

//[문제2]
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
		cout << hour << "시 " << min << "분 " << sec << "초\n";
	}
	void ShowTimeinSec()
	{
		int sum = sec;
		sum += (min * distance);
		sum += (hour * distance * distance);
		cout << sum << "초\n";
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
