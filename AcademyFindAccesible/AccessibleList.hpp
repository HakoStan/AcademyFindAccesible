#pragma once
#include "FreeList.hpp"
#include "Common.hpp"
#include "Stack.hpp"
#include <iostream>

enum Stage : std::uint8_t
{
	STAGE1 = 0,
	STAGE2
};

struct State
{
	ComputerId computerId;
	Stage stage;
};

class AccessibleList
{
public:
	AccessibleList(ComputerId focusComp, std::uint32_t networkSize);
	void FindAccessibleRecrusive(NetworkStructure*& networkStructure, ColorArray& colorArray);
	void FindAccessibleRecrusive(NetworkStructure*& networkStructure, ColorArray& colorArray, ComputerId compId);
	void FindAccessibleIterative(NetworkStructure*& networkStructure, ColorArray& colorArray);
	void PrintAccessibleList();
private:
	YAFramework::FreeList<ComputerId> accessibleList;
	ComputerId focusComp;
};