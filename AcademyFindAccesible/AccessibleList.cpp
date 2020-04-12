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
void AccessibleList::FindAccessible(NetworkStructure*& networkStructure, ColorArray& colorArray)
{
	FindAccessible(networkStructure, colorArray, this->focusComp);
}

/*
Purpose: 
	This function find all accessible computers from focusComputer in the networkStructure.
	This is done using a recrusive algorithm described in the HW PDF page 3.
Params: 
	NetworkStructure, ColorArray. (We don't need focusComputer and accessible list because it is the private members of this class
*/
void AccessibleList::FindAccessible(NetworkStructure*& networkStructure, ColorArray& colorArray, ComputerId compId)
{
	// Point 1
	colorArray[compId] = YAFramework::Color::Black;
	this->accessibleList.Insert(compId);
	
	// Point 2
	YAFramework::Node<ComputerId>* tempNode = networkStructure[compId].First();
	while (tempNode != nullptr)
	{
		if (colorArray[tempNode->GetData()] == YAFramework::Color::White)
		{
			FindAccessible(networkStructure, colorArray, tempNode->GetData());
		}
		tempNode = tempNode->GetNext();
	}
}
