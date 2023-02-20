#include "MemoryPool.h"
//using namespace core;
class Object:public MemoryPool
{
public:
	int data;
};
int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	Object* obj = new Object();
}
