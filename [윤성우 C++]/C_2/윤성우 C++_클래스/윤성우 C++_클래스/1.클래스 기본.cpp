#include <iostream>
#pragma region struct
//구조체의 경우  main의 구조체 선언 부분이 c에서는 오류 c++정상
//c++에서는 기본 자료형과 사용자 정의 자료형을 동일시 하자는 기본 철학이 있음.
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
c에서는 구조체는 멤버함수를 가지지 못하지만 c++에서는 가능
c++에서 struct와 class 의 차이는 기본 공개범위 이외에는 차이가 없다
하지만 struct와 class 를 구분해서 써야하는 이유는 협업할때 대부분의 사람들이
struct는 data의 모음, class 는 data+함수 로 쓰기 때문에 struct를 class 처럼 사용하면 
문제가 생길 수 있다.

예를 들어 struct에 virtual로 생긴 v-tbl 포인터나 포인터 데이터가 있다고 하면,
struct의 경우 사용자들이 데이터만 들어있다고 생각해서 memcpy를 사용하는 경우가 많은데 
이렇게 될 경우 깊은 복사가 아닌 얕은 복사가 일어나기 때문에 두 객체가 하나의 포인터 주소를 가지게 된다.
이때 원본 데이터가 사라지면 복사된 데이터는 잘못된 주소를 가르키게 되는 것.
따라서 struct 사용시에는 최대한 data 의 정보만 넣도록 한다.
*/

#pragma endregion
#pragma region class
/*클래스는 현실 세계의 사물을 기능적 측면, 데이터적 측면을 정의한 
데이터의 추상화가 이루어진 객체이다.
=> [요약] class = 멤버 변수 + 멤버 함수*/
//[문제 1]
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
		std::cout << "덧셈: " << add_cnt << " 뺄셈: " << min_cnt << " 곱셈: " << mul_cnt << "나눗셈: " << div_cnt;
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
//[문제2]
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