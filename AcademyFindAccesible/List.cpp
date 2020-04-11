#include "List.hpp"

YAFramework::List::List()
{
	MakeEmpty();
}

YAFramework::List::List(Node * ptr)
{
	this->head = ptr;
	this->tail = ptr;
}

YAFramework::List::~List()
{
	FreeList();
	delete this;
}

void YAFramework::List::MakeEmpty()
{
	this->head = nullptr;
	this->tail = nullptr;
}

bool YAFramework::List::IsEmpty()
{
	return head == nullptr;
}

Node * YAFramework::List::First()
{
	return this->head;
}

Node * YAFramework::List::Last()
{
	return this->tail;
}

void YAFramework::List::Insert(Node * newNode)
{
	if (this->head == nullptr && this->tail == nullptr)
	{
		this->head = newNode;
		this->tail = newNode;
		return;
	}
	this->tail->InsertAfter(newNode);
}

void YAFramework::List::InsertAfter(Node * position, Node * newNode)
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
		Node* temp = this->head;
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

void YAFramework::List::FreeList()
{
	Node* temp = this->head;
	Node* tempNext = nullptr;
	while (temp != nullptr)
	{
		tempNext = temp->next;
		delete temp;
		temp = tempNext;
	}
}
