#pragma once
#include "FreeList.hpp"
#include "Common.hpp"

class AccessibleList
{
public:
	AccessibleList(ComputerId focusComp, std::uint32_t networkSize);
	void FindAccessible(NetworkStructure*& networkStructure, ColorArray& colorArray);
	void FindAccessible(NetworkStructure*& networkStructure, ColorArray& colorArray, ComputerId compId);
private:
	YAFramework::FreeList<ComputerId> accessibleList;
	ComputerId focusComp;
};