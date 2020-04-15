// AcademyFindAccesible.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Common.hpp"
#include "AccessibleList.hpp"


void CheckIsComputerInRange(ComputerId checkComp, std::uint32_t numOfComputers)
{
	if (checkComp <= 0 || checkComp > numOfComputers)
	{
		std::cout << "no such computer " << checkComp;
		exit(1);
	}
}

void PopulateNetworkStructure(std::uint32_t& numOfConnections, NetworkStructure*& networkStructure, std::uint32_t numOfComputers)
{
	ComputerId source = 0;
	ComputerId destination = 0;
	for (std::uint32_t i = 0; i < numOfConnections * 2; i++)
	{
		if (i % 2 == 0)
		{
			std::cin >> source;
			CheckIsComputerInRange(source, numOfComputers);
		}
		else
		{
			std::cin >> destination;
			CheckIsComputerInRange(destination, numOfComputers);
			YAFramework::Node<ComputerId>* node = new YAFramework::Node<ComputerId>(destination);
			networkStructure[source].Insert(node);
		}
	}
}

void RunRecursiveAlgo(ComputerId focusComp, std::uint32_t numOfComputers, NetworkStructure* networkStructure)
{
	// Algo 5
	AccessibleList accessibleListForUserComp(focusComp, numOfComputers);
	ColorArray colorArr(numOfComputers + 1, YAFramework::Color::White);
	accessibleListForUserComp.FindAccessibleRecrusive(networkStructure, colorArr);
	accessibleListForUserComp.PrintAccessibleList();
	std::cout << std::endl;
}

void RunIterativeAlgo(ComputerId focusComp, std::uint32_t numOfComputers, NetworkStructure* networkStructure)
{
	// Solution Recrusive To Iterative
	AccessibleList accessibleListForUserComp(focusComp, numOfComputers);
	ColorArray colorArr(numOfComputers + 1, YAFramework::Color::White);
	accessibleListForUserComp.FindAccessibleIterative(networkStructure, colorArr);
	accessibleListForUserComp.PrintAccessibleList();
}

int main()
{
	std::uint32_t numOfComputers	= 0;
	std::uint32_t numOfConnections	= 0;

	std::cin >> numOfComputers;
	std::cin >> numOfConnections;

	// Index 0 is not used
	NetworkStructure* networkStructure = new NetworkStructure[numOfComputers + 1];
	PopulateNetworkStructure(numOfConnections, networkStructure, numOfComputers);

	ComputerId focusComp = 0;
	std::cin >> focusComp;

	CheckIsComputerInRange(focusComp, numOfComputers);

	RunRecursiveAlgo(focusComp, numOfComputers, networkStructure);
	RunIterativeAlgo(focusComp, numOfComputers, networkStructure);
}
