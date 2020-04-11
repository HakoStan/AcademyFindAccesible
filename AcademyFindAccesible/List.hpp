#pragma once
#include "Node.hpp"

namespace YAFramework
{
	class List
	{
	public:
		List();
		List(Node* ptr = nullptr);
		~List();
		void MakeEmpty();
		bool IsEmpty();
		Node* First();
		Node* Last();
		void Insert(Node* newNode);
		void InsertAfter(Node* position, Node* newNode);
	private:
		void FreeList();
		Node* head = nullptr;
		Node* tail = nullptr;
	};
}