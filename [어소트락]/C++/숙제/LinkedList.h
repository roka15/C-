#pragma once

#ifndef GLOBAL_H
#define GLOBAL_H 

#endif
template<typename T>
class LinkedList
{
private:
	template<typename T>
	struct Node
	{
		Node<T>* next;
		Node<T>* befor;
		T data;
	};
	Node<T>* first;
	Node<T>* current;
public:
	LinkedList() :first(nullptr), current(nullptr) {}
	void Push(T _data)
	{
		if (first == nullptr)
		{
			first = new Node<T>();
			current = first;
			first->data = _data;
			first->next = nullptr;
			first->befor = nullptr;
		}
		else
		{
			Node<T>* node = new Node<T>();
			node->data = _data;
			node->befor = current;
			node->next = nullptr;
			current->next = node;
			current = node;
		}
	}
	T front_pop()
	{
		return first->data;
	}
	//구현 목록
	//find 
	Node<T>* Find(const T& _data)
	{
		Node<T>* ptr = first;
		while (ptr != nullptr)
		{
			if (ptr->data == _data)
			{
				return ptr;
			}
			ptr = ptr->next;
		}
		return nullptr;
	}
	//n번 index 뒤에 삽입
	void insert_push(const int& _index, T _data)
	{
		Node<T>* node = new Node<T>();
		node->data = _data;
		Node<T>* ptr = first;
		int i = 0;
		while (ptr != nullptr)
		{
			if (i == _index)
			{
				if (ptr->next == nullptr)
				{
					Push(_data);
					return;
				}
				node->next = ptr->next;
				node->befor = ptr;
				ptr->next->befor = node;
				ptr->next = node;
				return;
			}

			ptr = ptr->next;
			i++;
		}
	}
	//삭제
	void delete_data(const T& _data)
	{
		
		Node<T>* FindNode = Find(_data);
		
		Node<T>* temp = FindNode;

		if (first != FindNode && current != FindNode)
		{
			FindNode = temp->next;
			FindNode->befor = temp->befor;
			temp->befor->next = FindNode;
		}
		
		if (first == FindNode)
		{
			first = temp->next;
			first->befor = nullptr;
		}
		
		if (current == FindNode)
		{
			current = FindNode->befor;
			current->next = nullptr;
		}
		
		
		
		delete temp;
		return;
	}
	//메모리 해제
	void Release()
	{
		Node<T>* ptr = first;
		while (ptr != nullptr)
		{
			Node<T>* temp = ptr->next;
			delete ptr;
			ptr = temp;
		}
	}
};


