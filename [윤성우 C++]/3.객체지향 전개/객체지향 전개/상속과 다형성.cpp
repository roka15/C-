#include <iostream>
using std::cout;
using std::endl;
using std::cin;
#define PI 3.141592
//is-s have-a 근데 보통 포함관계는 상속이 아닌 내부 객체 포인터 멤버로 하는게 좋음. 결합도가 낮아지기 때문.

//[문제1]
/*
class Point
{
private:
	int x;
	int y;
public:
	Point() :x(0), y(0)
	{

	}
	Point(int _x, int _y):x(_x),y(_y)
	{

	}
	Point(const Point& _ref) :x(_ref.x), y(_ref.y)
	{

	}
	void SetPoint(int _x, int _y)
	{
		x = _x;
		y = _y;
	}
	virtual void ShowData()
	{
		cout << "중심 좌표: (" << x << "," << y << ")\n";
	}
	virtual ~Point()
	{

	}
};
class Circle:public Point
{
private:
	double radius;
	double area;
public:
	Circle() :Point(),radius(0),area(0)
	{

	}
	Circle(int _x, int _y, double _radius) :Point(_x, _y), radius(_radius)
	{
		area = radius * radius * PI;
	}
	Circle(const Circle& _ref) :Point(_ref),radius(_ref.radius),area(_ref.area)
	{

	}
	void SetData(int _x, int _y, double _radius)
	{
		SetPoint(_x, _y);
		radius = _radius;
		area = radius*radius*PI;
	}
	void ShowData()
	{
		Point::ShowData();
		cout << "반지름: " << radius<<endl;
		cout << "원의 넓이:" << area<<endl;
	}
	~Circle()
	{

	}

};
int main()
{
	Circle cir(3, 5, 2.2);
	cir.ShowData();
	return 0;
}
*/
//[문제 2] 포함관계를 상속하지 않고 표현하기
/*
class Point
{
private:
	int x;
	int y;
public:
	Point() :x(0), y(0)
	{

	}
	Point(int _x, int _y) :x(_x), y(_y)
	{

	}
	Point(const Point& _ref) :x(_ref.x), y(_ref.y)
	{

	}
	const int GetPosX()
	{
		return x;
	}
	const int GetPosY()
	{
		return y;
	}
	void SetPoint(int _x, int _y)
	{
		x = _x;
		y = _y;
	}
	void ShowData()
	{
		cout << "중심 좌표: (" << x << "," << y << ")\n";
	}
	~Point()
	{

	}
};
class Circle 
{
private:
	Point* point;
	double radius;
	double area;
public:
	Circle() : radius(0), area(0),point(nullptr)
	{

	}
	Circle(int _x, int _y, double _radius) : radius(_radius)
	{
		point = new Point(_x, _y);
		area = radius * radius * PI;
	}
	Circle(const Circle& _ref) :radius(_ref.radius), area(_ref.area)
	{
		point = new Point(_ref.point->GetPosX(), _ref.point->GetPosY());
	}
	void SetData(int _x, int _y, double _radius)
	{
		if(point!=nullptr)
		point->SetPoint(_x, _y);
		radius = _radius;
		area = radius * radius * PI;
	}
	void ShowData()
	{
		if (point != nullptr)
		point->ShowData();
		cout << "반지름: " << radius << endl;
		cout << "원의 넓이:" << area << endl;
	}
	~Circle()
	{
		delete point;
	}

};
int main()
{
	Circle cir(3, 5, 2.2);
	cir.ShowData();
	return 0;
}
*/
//[문제 3] 객체 포인터로 관리하기 예제에서 문제점 찾아라.
//근데 문제점 찾아가지고 그냥 복습 겸 내 맘대로 짜봄.
/*
class Person
{
public:
	void sleep()
	{
		cout << "sleep" << endl;
	}
};
class Student:public Person
{
public:
	void study()
	{
		cout << "study" << endl;
	}
};
class PartTimeStd :public Student
{
public:
	void work()
	{
		cout << "work" << endl;
	}
};
int main()
{
	Person* person[3];
	person[0] = new Person();
	person[1] = new Student();
	person[2] = new PartTimeStd();
	//방법 1 ) 추상클래스로 동작에 대한 추상함수를 적고 virtual 로 상속
	//방법 2 ) 타입을 내가 알고 있다는 가정하에 cast 해서 사용.
	//아직 여기서의 진도에서는 추상클래스가 안나왔기때문에 후자로 사용하기
	//근데 함정은 cast도 아직 안나옴.
	person[0]->sleep();
	Student* st =reinterpret_cast<Student*>(person[1]);
	st->study();
	PartTimeStd* ptst = reinterpret_cast<PartTimeStd*>(person[2]);
	ptst->work();
	Person* p = dynamic_cast<Person*>(st); // 업캐스팅
}
*/
 //상속 객체간의 참조 사용. 이것도 포인터와 같은 접근 권한.

//static binding 컴파일 시점에 호출할 함수가 정해짐 / dynamic binding 런타임중에 호출할 함수가 결정됨
//==> 다형성 : 같은 이름이지만 다른것.
//함수가 이름이 같은데 객체에 따라 다르게 동작하는것, 같은 포인터로 저장되어 있지만 다른 함수가 호출되는 것 등.

//순수 가상함수
//하나 이상의 순수 가상 함수가 선언되어 있다면 객체화 할 수 없으므로 추상클래스가 된다.

class Employee
{
protected:
	char* name;
public:
	Employee(const char* _str)
	{
		int strsize = strlen(_str);
		name = new char[strsize+1];
		strcpy(name, _str);
	}
	const char* Getname()
	{
		return name;
	}

	virtual int GetPay() = 0;
	virtual ~Employee()
	{
		delete[] name;
		cout << "emp 소멸자" << endl;
	}
};

class Permanent :public Employee
{
protected:
	int salary;
public:
	Permanent(const char* _str, int _sal) :Employee(_str), salary(_sal)
	{

	}
	virtual int GetPay()
	{
		return salary;
	}
	virtual ~Permanent()
	{
		cout << "permanent 소멸자" << endl;
	}
};
class Temporary:public Permanent
{
private:
	int time;
public:
	Temporary(const char* _str, int _sal, int _t) :Permanent(_str, _sal), time(_t)
	{

	}
	virtual int GetPay()
	{
		return salary * time;
	}
	virtual ~Temporary()
	{
		cout << "temp 소멸자" << endl;
	}
};
class Department 
{
private:
	Employee* em[100];
	int emp_size;
public:
	Department() :emp_size(0) {};
	void AddEmployee(Employee* _emp)
	{
		em[emp_size++] = _emp;
	}
	void ShowList()
	{
		for (int i=0;i<emp_size;i++)
		{
			cout<<em[i]->Getname() << endl;
			cout<<em[i]->GetPay() << endl;
		}
	}
	~Department()
	{
		for (int i = 0; i < emp_size; i++)
		{
			delete em[i];
		}
	}
};

int main()
{
	Department department;
	department.AddEmployee(new Temporary("yeram", 10000, 5));
	department.AddEmployee(new Permanent("hi", 100000));

	department.ShowList();
	
}