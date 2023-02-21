//#include "MemoryPool.h"

#include <cstdlib>
#include <crtdbg.h>

//using namespace core;
#include "MemoryPool_2.h"
class Object:public MemoryPool_2
{
public:
	int data;
};
int main()
{
	
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	Object* objs[5];
	int index = 0;
	for (int i = 0; i < 5; i++)
	{
		Object* obj = new Object();
		objs[index] = obj;
		index++;
	}

	delete objs[0];
	delete objs[3];
	delete objs[4];
	MemoryPool_2::End();
}
