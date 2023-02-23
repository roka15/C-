#include "MemoryPool_2.h"

RBT<UINT, t_pool_info*> MemoryPool_2::memorypools;


void* MemoryPool_2::operator new(size_t _size)
{
	char* next_ptr = nullptr;
	int size = AssignSize(_size);
	if (size == -1)
	{
		//���� �߸� ��.
		return nullptr;
	}
	else if (size == 0)
	{
		// MAXMEMORY_BYTE/2 ���� ���� ū ��� �޸�Ǯ�� �����ϴ°� �����̱� ������
		// �� byte size ��ü�� new �� ���ش�.
		return malloc(_size);
	}
	t_pool_info* dummy=nullptr;
	if (memorypools.Find(size,dummy)==false)
	{
		//Ű ��ã��
		memorypools.Push(size, new t_pool_info(MAXMEMORY_BYTE, size));
	}
	else
	{
		//Ű ã�Ҵµ� current �� null �� ���(�̹� ��� �Ҵ��� ��� ���ο� �� �߰��� �ޱ�)
		if (memorypools[size]->current == nullptr)
		{
			char** ptr;
			char* ptr2;
			memorypools[size]->current = (char*)malloc(MAXMEMORY_BYTE);
			memset(memorypools[size]->current, 0, MAXMEMORY_BYTE);

			next_ptr = (char*)memorypools[size]->current;
			memorypools[size]->startptr.push_back(memorypools[size]->current);

			for (int i = 1; i < MAXMEMORY_BYTE / size; i++)
			{
				ptr2 = memorypools[size]->current + (size * i);
				ptr = &ptr2;
				memcpy(next_ptr, ptr, sizeof(char*));
				next_ptr += size;
			}
			ptr2 = nullptr;
			ptr = &ptr2;
			// �� �������� nullptr �ֱ� 
			memcpy(next_ptr, ptr, sizeof(char*));
		}

	}
	char* curptr = memorypools[size]->current;
	char* result = curptr;


	memcpy(&next_ptr, curptr, sizeof(char*));
	memorypools[size]->current = next_ptr;

	return result;
}

void MemoryPool_2::operator delete(void* _object, size_t _size)
{
	int size = AssignSize(_size);
	if (size == -1)
	{
		//���� �߸� ��.
		return;
	}
	else if (size == 0)
	{
		// MAXMEMORY_BYTE/2 ���� ���� ū ��� �޸�Ǯ�� �����ϴ°� �����̱� ������
		// �� byte size ��ü�� new �� �߱� ������ �� �޸� ��ü�� delete ���ش�.
		free(_object);
		return;
	}
	char* curptr = memorypools[size]->current;
	memcpy((char*)_object, &curptr, sizeof(char*));
	memorypools[size]->current = (char*)_object;
}

int MemoryPool_2::AssignSize(size_t _size)
{
	if (_size * 2 > MAXMEMORY_BYTE)
		return 0;
	int befor = 0;
	for (int i = 8; i <= MAXMEMORY_BYTE / 2; i *=2)
	{
		if (_size > befor && _size <= i)
		{
			return i;
		}
		befor = i;
	}

	//������ ���
	return -1;
}

void MemoryPool_2::End()
{
	int size = memorypools.Size();
	int count = 0;
	for (int i=8;i <= MAXMEMORY_BYTE/2;i*=2)
	{
		t_pool_info* pool = nullptr;
		if (memorypools.Find(i,pool) == true)
		{
			memorypools.Pop(i);
		}
	}
	memorypools.Clear();
}
