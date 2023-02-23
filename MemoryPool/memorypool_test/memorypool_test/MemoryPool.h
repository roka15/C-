#pragma once
#include "CommonInclude.h"
namespace core
{
#define MEMORY_BYTE 16//32768 //32KB

	class MemoryPool
	{
	public:
		enum class EMemErrType
		{
			WRONGSIZE = -1,//음수 입력
			POOLSIZEOVER = 0,// (32KB/2) 보다 큰 데이터 할당시.
		};
		struct memory_pool_info
		{
			memory_pool_info();
			memory_pool_info(std::size_t capacity, std::size_t _size);
			~memory_pool_info();
			bool AddMemoryPool(std::size_t _capacity, std::size_t _size);

			byte* current;
			std::vector<byte*> memorys;
		};


		static void Initialize();
		static void Release();

		static void* operator new(std::size_t _size);
		static void operator delete(void* _memory, std::size_t _size);
		static int AssignSize(std::size_t _size);

		template<typename T>
		inline void* operator new[](size_t _size, T&& _data)
		{
			int mysize = 0;


			if (std::is_lvalue_reference_v<decltype(_data)>)
			{
				if (std::is_pointer<std::remove_reference_t<T>>::value)
					mysize = sizeof(decltype(*_data));
				else
				{
					mysize = sizeof(decltype(_data));
				}
			}
			else 
			{
				mysize = sizeof(decltype(_data));
			}
			std::cout << typeid(T).name() << std::endl;

			return malloc(mysize);
		}

			/*template <typename T>
			inline void* operator new[](size_t size, T&& data)
			{
				int mysize = sizeof(decltype(data));
				return malloc(sizeof(mysize));
			}
			template<typename T>
			inline void operator delete[](void* _memory, T& data)
			{

			}*/
	private:
		static RBT<std::size_t, memory_pool_info*> m_memory_pools;
	};





}

