#include "AccessibleList.hpp"

AccessibleList::AccessibleList(ComputerId focusComp, std::uint32_t networkSize)
{
	this->focusComp = focusComp;
	this->accessibleList.MakeEmpty(networkSize);
}


/*
Purpose: This function find all accessible computers from focusComputer in the networkStructure.
		This is done using a recrusive algorithm described in the HW PDF page 3
Params: NetworkStructure, ColorArray. (We don't need focusComputer and accessible list because it 
		is the private members of this class
*/
void AccessibleList::FindAccessible(NetworkStructure*& networkStructure, ColorArray& colorArray)
{
	// point 1
	colorArray[this->focusComp] = YAFramework::Color::Black;
	// point 2
}
