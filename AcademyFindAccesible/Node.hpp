#pragma once

namespace YAFramework
{
	typedef int Type;

	class Node
	{
	public:
		Node();
		Node(Type item, Node* ptr = nullptr);
		~Node();
		void InsertAfter(Node* newNode);
		Node* DeleteAfter();
	private:
		Type data;
		Node* next = nullptr;

		friend class List;
	};
}