#include "AccessibleList.hpp"

AccessibleList::AccessibleList(ComputerId focusComp, std::uint32_t networkSize)
{
	this->focusComp = focusComp;
	this->accessibleList.MakeEmpty(networkSize);
}


/*
Purpose: 
	This function find all accessible computers from focusComputer in the networkStructure.
	This is done using a recrusive algorithm described in the HW PDF page 3.
Params: 
	NetworkStructure, ColorArray. (We don't need focusComputer and accessible list because it is the private members of this class
Remark: 
	This function is actually called only to pass the focusComp as param to the real recursive function
*/
void AccessibleList::FindAccessibleRecrusive(NetworkStructure*& networkStructure, ColorArray& colorArray)
{
	FindAccessibleRecrusive(networkStructure, colorArray, this->focusComp);
}

/*
Purpose: 
	This function find all accessible computers from focusComputer in the networkStructure.
	This is done using a recrusive algorithm described in the HW PDF page 3.
Params: 
	NetworkStructure, ColorArray. (We don't need focusComputer and accessible list because it is the private members of this class
*/
void AccessibleList::FindAccessibleRecrusive(NetworkStructure*& networkStructure, ColorArray& colorArray, ComputerId compId)
{
	// Point 1
	colorArray[compId] = YAFramework::Color::Black;
	this->accessibleList.InsertToEnd(compId);
	
	// Point 2
	YAFramework::Node<ComputerId>* tempNode = networkStructure[compId].First();
	while (tempNode != nullptr)
	{
		if (colorArray[tempNode->GetData()] == YAFramework::Color::White)
		{
			FindAccessibleRecrusive(networkStructure, colorArray, tempNode->GetData());
		}
		tempNode = tempNode->GetNext();
	}
}

void AccessibleList::FindAccessibleIterative(NetworkStructure*& networkStructure, ColorArray& colorArray)
{
	YAFramework::Stack<State> stateStack;
	State current;
	State next;
	YAFramework::Node<ComputerId>* tempNode = nullptr;

	current = { this->focusComp, Stage::STAGE1, nullptr };
	stateStack.Push(YAFramework::ItemType<State>(current));
	while (!stateStack.IsEmpty())
	{
		current = stateStack.Pop().GetItem();
		if (current.stage == Stage::STAGE1)
		{
			if (colorArray[current.computerId] == YAFramework::Color::White)
			{
				colorArray[current.computerId] = YAFramework::Color::Black;
				this->accessibleList.InsertToEnd(current.computerId);
			}
			current.stage = Stage::STAGE2;
			stateStack.Push(YAFramework::ItemType<State>(current));
		}
		else if (current.stage == Stage::STAGE2)
		{
			tempNode = networkStructure[current.computerId].First();
			if (tempNode != nullptr)
			{
				current.nodePtr = tempNode;
				current.stage = Stage::STAGE3;
				stateStack.Push(YAFramework::ItemType<State>(current));
				if (colorArray[tempNode->GetData()] == YAFramework::Color::White)
				{
					next = { tempNode->GetData(), Stage::STAGE1, nullptr };
					stateStack.Push(YAFramework::ItemType<State>(next));
				}
			}
		}
		else if (current.stage == Stage::STAGE3)
		{
			tempNode = current.nodePtr->GetNext();
			if (tempNode != nullptr)
			{	
				current.nodePtr = tempNode;
				stateStack.Push(YAFramework::ItemType<State>(current));

				next = { tempNode->GetData(), Stage::STAGE1, nullptr };
				stateStack.Push(YAFramework::ItemType<State>(next));
			}
		}
	}
}

void AccessibleList::PrintAccessibleList()
{
	std::int32_t headList = this->accessibleList.GetHeadList();
	YAFramework::FreeListNode<ComputerId> temp = this->accessibleList.Get(headList);
	while (temp.next != headList)
	{
		std::cout << temp.data << " ";
		temp = this->accessibleList.Get(temp.next);
	}
	std::cout << temp.data;
}
