#include <iostream>
using std::cout;
using std::endl;
using std::cin;
#define PI 3.141592
//is-s have-a �ٵ� ���� ���԰���� ����� �ƴ� ���� ��ü ������ ����� �ϴ°� ����. ���յ��� �������� ����.

//[����1]
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
		cout << "�߽� ��ǥ: (" << x << "," << y << ")\n";
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
		cout << "������: " << radius<<endl;
		cout << "���� ����:" << area<<endl;
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
//[���� 2] ���԰��踦 ������� �ʰ� ǥ���ϱ�
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
		cout << "�߽� ��ǥ: (" << x << "," << y << ")\n";
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
		cout << "������: " << radius << endl;
		cout << "���� ����:" << area << endl;
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
//[���� 3] ��ü �����ͷ� �����ϱ� �������� ������ ã�ƶ�.
//�ٵ� ������ ã�ư����� �׳� ���� �� �� ����� ¥��.
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
	//��� 1 ) �߻�Ŭ������ ���ۿ� ���� �߻��Լ��� ���� virtual �� ���
	//��� 2 ) Ÿ���� ���� �˰� �ִٴ� �����Ͽ� cast �ؼ� ���.
	//���� ���⼭�� ���������� �߻�Ŭ������ �ȳ��Ա⶧���� ���ڷ� ����ϱ�
	//�ٵ� ������ cast�� ���� �ȳ���.
	person[0]->sleep();
	Student* st =reinterpret_cast<Student*>(person[1]);
	st->study();
	PartTimeStd* ptst = reinterpret_cast<PartTimeStd*>(person[2]);
	ptst->work();
	Person* p = dynamic_cast<Person*>(st); // ��ĳ����
}
*/
 //��� ��ü���� ���� ���. �̰͵� �����Ϳ� ���� ���� ����.

//static binding ������ ������ ȣ���� �Լ��� ������ / dynamic binding ��Ÿ���߿� ȣ���� �Լ��� ������
//==> ������ : ���� �̸������� �ٸ���.
//�Լ��� �̸��� ������ ��ü�� ���� �ٸ��� �����ϴ°�, ���� �����ͷ� ����Ǿ� ������ �ٸ� �Լ��� ȣ��Ǵ� �� ��.

//���� �����Լ�
//�ϳ� �̻��� ���� ���� �Լ��� ����Ǿ� �ִٸ� ��üȭ �� �� �����Ƿ� �߻�Ŭ������ �ȴ�.

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
		cout << "emp �Ҹ���" << endl;
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
		cout << "permanent �Ҹ���" << endl;
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
		cout << "temp �Ҹ���" << endl;
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