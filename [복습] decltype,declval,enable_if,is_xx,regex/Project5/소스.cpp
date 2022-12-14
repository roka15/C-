#include <iostream>
#include <type_traits>

//enable_if,decltype,declval, is_xx �� ���.

#pragma region ���ø� ���� Ÿ�� ����
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

#pragma region enable_if �ٸ� ����
/*
template<typename T>
class vector 
{
public:
	vector(size_t num, const T& element) { std::cout << "size_t ������" << std::endl; }
    
	//�̰� iterator ����ó�� �����ָ� main�� vector �⺻������ ȣ���Ҷ� ���� �Լ��� �����ε� �ȴ�.
	//������ size_t �� ��ȣ�ִ� ����, �Ű������� ���� ���� ��ȣ �ִ� �����̱� ������ ���� �Լ��� �� �����ϴٰ� �Ǵ� ��.
	template<typename Iterator,typename = std::enable_if_t<std::_Is_iterator_v<Iterator>>>
	vector(Iterator start, Iterator end) { std::cout << "iterator ������" << std::endl; }
};
int main()
{
	vector<int> v(10, 3);
}
*/
#pragma endregion
#pragma region Ư�� ��� �Լ��� �����ϴ� Ÿ�Ը� �޴� �Լ�
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
	val.test(); //! �Ű������� const T& �� �޴µ� ���ο��� const �Լ��� �ƴ� �Լ��� ������ �θ� �����϶� ���� �߻�.
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
#pragma region Ư������Լ� + ����Ÿ�Ա��� �����ϴ� ��
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
#pragma region void_t ���
/*���Ǹ��� typename = ���� �̷������� ���ø��� �����ϸ� �ʹ� ������� ������ void_t<a,b,c>�̷������� ���
  ������ ����Ǹ� void ��ġ���� ������ ����.*/
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
#pragma region ����Ʈ ���ø� ���ڿ� ���� �ִ� ������ ����
#include <list>
#include <vector>

//����Ÿ�Կ� �־ SFINAE �˻�.
//����Ÿ�� �ִ� ��� 1 )
//template <typename T>
//std::enable_if_t<std::is_same_v<void, std::void_t<decltype(std::declval<T>().begin()), decltype(std::declval<T>().end())>>>
//print()
//{
//
//}
//����Ÿ�� �ִ� ��� 2 )
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