#include "Node.hpp"

YAFramework::Node::Node()
{
	this->next = nullptr;
}

YAFramework::Node::Node(Type item, Node * ptr)
{
	this->data = item;
	this->next = ptr;
}

YAFramework::Node::~Node()
{
	delete this;
}

void YAFramework::Node::InsertAfter(Node * newNode)
{
	newNode->next = this->next;
	this->next = newNode;
}

YAFramework::Node* YAFramework::Node::DeleteAfter()
{
	Node* temp = this->next;
	if (this->next == nullptr)
	{
		return nullptr;
	}
	this->next = temp->next;
	return temp;
}
