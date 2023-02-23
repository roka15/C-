#pragma once
#include <iostream>
#include <type_traits>
#include <utility>
class newtype
{
public:
	template <typename T>
	static inline size_t allocate(size_t _size, T& _data)
	{
		int mysize = 0;
		if (std::is_pointer<std::remove_reference_t<decltype(_data)>>::value)
		{
			mysize = sizeof(decltype(*_data));
		}
		else
		{
			mysize = sizeof(decltype(_data));
		}
		return mysize;
	}
	template <typename T>
	static inline size_t allocate(size_t _size, T&& _data)
	{
		int mysize = 0;

		mysize = sizeof(decltype(_data));

		return mysize;
	}
	template<typename T>
	static inline void* operator new[](size_t _size, T&& _data)
	{
		size_t mysize = 0;

		mysize = allocate(_size, std::forward<T>(_data));

		return malloc(sizeof(mysize));
	}
	void func();
	/*template<typename T>
	void func2(T&& _Data)
	{
		int size = 0;
		T temp = static_cast<T>(_Data);
		if (std::is_pointer<std::remove_reference_t<T>>::value)
		{
			size = sizeof(decltype(*_Data));
		}
	}*/

};

