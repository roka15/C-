#include "MemoryPool.h"
//#include <iostream>

#include <cstdlib>
#include <crtdbg.h>


//#include <iostream>
//#include "RBT.h"
//using namespace core;
//#include "MemoryPool_2.h"

class Object :public core::MemoryPool
{
public:
	double a;
	double b;
};

int main()
{
	//_CrtSetBreakAlloc(161);
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	{
		Object obj;
		Object* obj2 = new Object();
		Object* objs;
		objs = new (obj2)Object[5];
		//Object* a = new(objs)Object[5];
		Object* a = new(std::move(Object()))Object[5];
		//delete[] objs;
		
		core::MemoryPool::Release();
	}
	
	//map iterator test
	/*RBT<int, int> mymap;
	mymap.Push(1, 1);
	mymap.Push(2, 2);
	mymap.Push(3, 3);
	mymap.Push(4, 5);

	Iterator<int,int>::MapIterator itr;
	for (Iterator<int, int>::MapIterator itr = mymap.begin(); itr != mymap.end(); itr++)
	{
		std::cout<<*itr;
	}*/
	//map test
	/*RBT<int, int> _map;
	_map.insert(std::make_pair(1, 1));
	_map.insert(std::make_pair(2, 2));
	_map.insert(std::make_pair(3, 3));
	_map.insert(std::make_pair(4, 4));


	auto node = _map.find(3);

	_map.erase(2);

	for (auto itr = _map.begin(); itr != _map.end(); itr++)
	{
		std::cout << (*itr);
	}
	_map.clear();*/

	//_CrtDumpMemoryLeaks();

}
