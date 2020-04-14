#pragma once

#include "Node.hpp"
#include "ItemType.hpp"
#include <stdlib.h>

namespace YAFramework
{
	template <typename T>
	class Stack
	{
	public:
		Stack();
		~Stack();
		void MakeEmpty();
		bool IsEmpty();
		void Push(ItemType<T> item);
		ItemType<T> Pop();
		ItemType<T> Top();
	private:
		Node<ItemType<T>>* top;
	};
	
	template<typename T>
	Stack<T>::Stack()
	{
		top = nullptr;
	}

	template<typename T>
	Stack<T>::~Stack()
	{
		MakeEmpty();
	}

	template<typename T>
	void Stack<T>::MakeEmpty()
	{
		Node<ItemType<T>>* temp;
		while (top != nullptr)
		{
			temp = top;
			top = top->GetNext();
			delete temp;
		}
	}

	template<typename T>
	bool Stack<T>::IsEmpty()
	{
		return (top == nullptr);
	}

	template<typename T>
	void Stack<T>::Push(ItemType<T> item)
	{
		top = new Node<ItemType<T>>(item, top);
	}

	template<typename T>
	ItemType<T> Stack<T>::Pop()
	{
		if (IsEmpty())
		{
			std::cout << "Error: STACK UNDERFLOW\n";
			exit(1);
		}

		Node<ItemType<T>>* temp = top;
		ItemType<T> item = top->GetData();
		top = top->GetNext();
		delete temp;
		return item;
	}

	template<typename T>
	ItemType<T> Stack<T>::Top()
	{
		if (IsEmpty())
		{
			std::cout << "Error: STACK UNDERFLOW\n";
			exit(1);
		}
		return top->GetData();
	}


}