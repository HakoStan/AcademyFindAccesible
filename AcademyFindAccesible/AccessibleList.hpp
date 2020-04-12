#pragma once
#include "FreeList.hpp"
#include "Common.hpp"

class AccessibleList
{
public:
	AccessibleList(ComputerId focusComp, std::uint32_t networkSize);
	void FindAccessible(NetworkStructure*& networkStructure, ColorArray& colorArray);
private:
	YAFramework::FreeList<std::uint32_t> accessibleList;
	ComputerId focusComp;
};