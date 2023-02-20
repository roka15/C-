#pragma once
#include "CommonInclude.h"
//namespace core
//{
    #define MEMORY_BYTE 16//32768 //32KB

	class MemoryPool
	{
	public:
		enum class EMemErrType
		{
			WRONGSIZE = -1,//���� �Է�
			POOLSIZEOVER=0,// (32KB/2) ���� ū ������ �Ҵ��.
		};
		struct memory_pool_info
		{
			memory_pool_info();
			memory_pool_info(std::size_t capacity, std::size_t _size);
			~memory_pool_info();

			byte* current;
			std::vector<byte*> memorys;
		};
		static void Initialize();
		static void Release();

		static void* operator new(std::size_t _size);
		static void operator delete(void* _memory,std::size_t _size);
		static int AssignSize(std::size_t _size);
	
	private:
		static std::map<std::size_t,memory_pool_info> m_memory_pools;
	};

//}
