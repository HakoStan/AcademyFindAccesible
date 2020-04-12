#pragma once

namespace YAFramework
{
	template <typename T>
	class Node
	{
	public:
		Node();
		Node(T item, Node* ptr = nullptr);
		~Node();
		void InsertAfter(Node* newNode);
		Node* DeleteAfter();
	private:
		T data;
		Node* next = nullptr;

		template <typename T>
		friend class List;
	};

	template <typename T>
	Node<T>::Node()
	{
		this->next = nullptr;
	}

	template <typename T>
	Node<T>::Node(T item, Node<T>* ptr)
	{
		this->data = item;
		this->next = ptr;
	}

	template <typename T>
	Node<T>::~Node()
	{
		delete this;
	}

	template <typename T>
	void Node<T>::InsertAfter(Node<T>* newNode)
	{
		newNode->next = this->next;
		this->next = newNode;
	}

	template <typename T>
	Node<T>* Node<T>::DeleteAfter()
	{
		Node<T>* temp = this->next;
		if (this->next == nullptr)
		{
			return nullptr;
		}
		this->next = temp->next;
		return temp;
	}
}