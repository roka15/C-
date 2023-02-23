//#include <iostream>
#include <vector>

#include <crtdbg.h>
#include <cstdlib>
#include <type_traits>
#include "newtype.h"

class Object : public newtype
{
	int a;
};
template<typename T>
T* NewT() 
{

}

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	Object* p = new Object();
	Object* A = new (p)Object[5];
	//bool flag = std::is_lvalue_reference<decltype(std::move(Object()))>::value;
	//int size = sizeof(decltype(std::move(Object())));
	Object* B = new (std::move(Object()))Object[5];
	return 0;
}