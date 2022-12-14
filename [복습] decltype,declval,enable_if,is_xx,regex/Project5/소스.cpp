#include <iostream>
#include <type_traits>

//enable_if,decltype,declval, is_xx 등 사용.

#pragma region 템플릿 변수 타입 제한
/*
template<typename T,typename = std::enable_if_t<std::is_integral_v<T>>>
void integral_check(T& val)
{
	std::cout << "integeral_check : " << val << std::endl;
}

struct A {};
int main() 
{
	int n = 1;
	integral_check(n);
	integral_check(A{});
}
*/
#pragma endregion

#pragma region enable_if 다른 예시
/*
template<typename T>
class vector 
{
public:
	vector(size_t num, const T& element) { std::cout << "size_t 생성자" << std::endl; }
    
	//이거 iterator 예외처리 안해주면 main의 vector 기본생성자 호출할때 밑의 함수로 오버로딩 된다.
	//이유는 size_t 는 부호있는 정수, 매개변수로 들어온 값은 부호 있는 정수이기 때문에 밑의 함수가 더 적합하다고 판단 됨.
	template<typename Iterator,typename = std::enable_if_t<std::_Is_iterator_v<Iterator>>>
	vector(Iterator start, Iterator end) { std::cout << "iterator 생성자" << std::endl; }
};
int main()
{
	vector<int> v(10, 3);
}
*/
#pragma endregion
#pragma region 특정 멤버 함수가 존재하는 타입만 받는 함수
/*class A
{
public:
	void print()const { std::cout << "print A" << std::endl; }
};
class B
{
public:
	void print()const { std::cout << "print B" << std::endl; }
};
class C
{
public:
	void test() {};
};

template <typename T,typename = decltype(std::declval<T>().print())>
void print(const T& val)
{
	val.print();
}
template<typename T>
void test(const T& val)
{
	val.test(); //! 매개변수를 const T& 로 받는데 내부에서 const 함수가 아닌 함수를 선언해 두면 컴파일때 오류 발생.
}

int main()
{
	A a;
	B b;
	C c;
	print(a);
	print(b);
	test(c); //!error 
	print(c);//!error
}
*/
#pragma endregion
#pragma region 특정멤버함수 + 리턴타입까지 강제하는 법
/*
template <typename T, typename = std::enable_if_t <std::is_void_v<decltype(std::declval<T>().print())>>>
void print(const T& val)
{
	val.print();
}
class A
{
public:
	void print()const { std::cout << "print a" << std::endl; }
};
class B
{
};
int main()
{
	A a;
	B b;
	print(a);
	print(b);//! error
}*/
#pragma endregion 
#pragma region regex
/*
#include <list>
#include <vector>
#include <regex>
#include <string>
void print(const std::string& str)
{
	std::smatch match;
	//match
	//std::regex pattern(R"(class std::_(\w+)_const_iterator<class std::_\w+_val<struct std::_\w+_simple_types<int> > >)");
	//std::regex_match(type, match, pattern);
	//search
	std::regex pattern(R"(class std::(_(\w+)_|(\w+)))");
	std::regex_search(str, match, pattern);
	
	for (int i = 0; i < match.size(); ++i)
	{
		if (match[i].str() == "List" || match[i].str() == "list"|| match[i].str() == "List_const")
		{
			std::cout << "List" << std::endl;
			return;
		}
		else if(match[i].str() == "Vector" || match[i].str() == "vector" || match[i].str() == "Vector_const")
		{
			std::cout << "Vector" << std::endl;
			return;
		}
	}
}
int main()
{
	std::list<int> l{ 1,2,3,4 };
	std::vector<int> v{ 4, 3, 2, 1 };
	const std::list<int> l2{ 0,0,0,0 };
	const std::vector<int> v2{ 4, 3, 2, 1 };

	
	print(typeid(l.begin()).name());
	print(typeid(l).name());
	print(typeid(v.begin()).name());
	print(typeid(v).name());

	print(typeid(l2).name());
	print(typeid(l2.begin()).name());
	print(typeid(v2).name());
	print(typeid(v2.begin()).name());

}*/
#pragma endregion
#pragma region void_t 사용
/*조건마다 typename = 조건 이런식으로 템플릿을 선언하면 너무 길어지기 때문에 void_t<a,b,c>이런식으로 사용
  조건이 통과되면 void 일치하지 않으면 제외.*/
//#include <list>
//#include <vector>
//template < typename T, typename = std::void_t<decltype(std::declval<T>().begin()), decltype(std::declval<T>().end())>>
//void print(const T& val)
//{
//	for (auto itr = val.begin(); itr != val.end(); ++itr)
//	{
//		std::cout << *itr << std::endl;
//	}
//}
//class A
//{
//};
//int main()
//{
//	std::list<int> l{ 1,2,3,4 };
//	std::vector<int> v{ 4,3,2,1 };
//	A a;
//	print(l);
//	print(v);
//	//print(a); //! error
//}
#pragma endregion
#pragma region 디폴트 템플릿 인자에 값을 넣는 문제를 예방
#include <list>
#include <vector>

//리턴타입에 넣어서 SFINAE 검사.
//리턴타입 넣는 방법 1 )
//template <typename T>
//std::enable_if_t<std::is_same_v<void, std::void_t<decltype(std::declval<T>().begin()), decltype(std::declval<T>().end())>>>
//print()
//{
//
//}
//리턴타입 넣는 방법 2 )
template <typename T>
auto print(const T& val)
->std::enable_if_t<std::is_same_v<void, std::void_t<decltype(std::declval<T>().begin()), decltype(std::declval<T>().end())>>>
{
	for (auto i = val.begin(); i != val.end(); ++i)
	{
		std::cout << *i << std::endl;
	}
}
class A
{
};
int main()
{
	std::list<int> l{ 1,2,3,4,5 };
	std::vector<int> v{6, 7, 8, 9, 10};
	A a;
	print(l);
	print(v);
	//print(a); // ! error
}

#pragma endregion