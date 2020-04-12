#pragma once
#include "Node.hpp"

namespace YAFramework
{
	template <typename T>
	class List
	{
	public:
		List();
		List(Node<T>* ptr);
		~List();
		void MakeEmpty();
		bool IsEmpty();
		Node<T>* First();
		Node<T>* Last();
		void Insert(Node<T>* newNode);
		void InsertAfter(Node<T>* position, Node<T>* newNode);
	private:
		void FreeList();
		Node<T>* head = nullptr;
		Node<T>* tail = nullptr;
	};

	template <typename T>
	List<T>::List()
	{
		MakeEmpty();
	}

	template <typename T>
	List<T>::List(Node<T> * ptr)
	{
		this->head = ptr;
		this->tail = ptr;
	}

	template <typename T>
	List<T>::~List()
	{
		FreeList();
		delete this;
	}

	template <typename T>
	void List<T>::MakeEmpty()
	{
		this->head = nullptr;
		this->tail = nullptr;
	}

	template <typename T>
	bool List<T>::IsEmpty()
	{
		return head == nullptr;
	}

	template <typename T>
	Node<T> * List<T>::First()
	{
		return this->head;
	}

	template <typename T>
	Node<T> * List<T>::Last()
	{
		return this->tail;
	}

	template <typename T>
	void List<T>::Insert(Node<T> * newNode)
	{
		if (this->head == nullptr && this->tail == nullptr)
		{
			this->head = newNode;
			this->tail = newNode;
			return;
		}
		this->tail->InsertAfter(newNode);
		this->tail = newNode;
	}

	template <typename T>
	void List<T>::InsertAfter(Node<T>* position, Node<T> * newNode)
	{
		if (position == nullptr)
		{
			// Error - Invalid position
			return;
		}
		else if (position == this->tail)
		{
			this->tail->InsertAfter(newNode);
			this->tail = newNode;
			return;
		}
		else
		{
			Node<T>* temp = this->head;
			while (temp != nullptr)
			{
				if (temp == position)
				{
					temp->InsertAfter(newNode);
					return;
				}
				temp = temp->next;
			}
		}
	}

	template <typename T>
	void List<T>::FreeList()
	{
		Node<T>* temp = this->head;
		Node<T>* tempNext = nullptr;
		while (temp != nullptr)
		{
			tempNext = temp->next;
			delete temp;
			temp = tempNext;
		}
	}
}