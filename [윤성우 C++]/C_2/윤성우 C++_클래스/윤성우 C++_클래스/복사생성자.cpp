/* 
복사생성자 매개변수에 & 를 붙여주지 않으면 무한루프에 빠지는 이유: 
들어온 값이 값복사로 스택에 지역변수로 쌓여서 그런가?
복사생성자 호출 -> 인자로 넘어가는 객체의 복사 -> 
생성자, 복사생성자 호출 -> 그 복사생성자 안에서 또다시 객체 복사 -> 복사생성자 호출 -> ... 무한반복 ...

값복사로 들어오는 과정에서 객체 메모리 할당 후 복사생성자를 실행하는데 그 복사 생성자에서도 또 복사생성자를 
호출하며 무한반복이 되는것.

※ 참고로 레퍼런스(&)를 사용한 Call by Reference로 인자를 넘겨주는 이유는 다음과 같이 크게 2가지이다.

1. &를 사용하지 않고 포인터를 사용하면 포인터 연산이 가능하기 때문에 잘못된 메모리 접근을 할 가능성이 높아진다.
2. 약간의 성능향상이 가능하다.
*/
#include <iostream>
//[문제1]
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