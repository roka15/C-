#pragma once

#define MAXMEMORY_BYTE 32768

#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <vector>
#include <map>

using namespace std;

struct t_pool_info
{
	t_pool_info(const int _capacity, const int _size)
	{
		current = nullptr;
		char* next_ptr;
		char** ptr;
		char* ptr2;
		char* ptr3;

		current = (char*)malloc(_capacity);
		memset(current, 0, _capacity);

		next_ptr = (char*)current;
		startptr.push_back(current);
		
		for (int i = 1; i < _capacity/_size; i++)
		{
			ptr2 = current + (_size * i);
			ptr = &ptr2;
			memcpy(next_ptr, ptr, sizeof(char*));
			next_ptr += _size;
		}
		ptr2 = nullptr;
		ptr = &ptr2;
		// �� �������� nullptr �ֱ� 
		memcpy(next_ptr, ptr, sizeof(char*));

	}
	~t_pool_info()
	{
		int size = startptr.size();
		for (int i = 0; i < size; i++)
		{
			char* item = startptr.back();
			startptr.pop_back();
			free(item);
		}
	}
	char* current;
	//�̹� ������ ���� �� ���� ���ο� ���� ������� �� �� ���� ���� �ּ�.
	vector<char*> startptr;
	
};


class MemoryPool_2
{
public:
	static void* operator new(size_t _size);
	static void* operator new[](size_t size);

	static void operator delete(void* _object, size_t _size);

	static int AssignSize(size_t _size);
	static void End();

protected:
	static RBT</*��üũ��*/UINT,/*pool ����*/t_pool_info*> memorypools;
	
};


/*������ 64bit ������ �����Ͱ� 8byte �̴�.
  �� memory pool �� ��� x byte ��ŭ �ɰ��� �� ���� �� �տ� �ּҸ� �ְ� �����ϴٰ�
  new �� �������� �ش� ��ü Ÿ������ ĳ������ �ϴ°��̱� ������ 
  ���� ��ü�� 8byte �̸��� �� �ּҸ� �дٰ� ©���Ƿ� ������.*/