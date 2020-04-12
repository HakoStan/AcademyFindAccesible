// AcademyFindAccesible.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Common.hpp"
#include "AccessibleList.hpp"

// YA :: TODO :: Add Error Check In Input

void PopulateNetworkStructure(std::uint32_t& numOfConnections, NetworkStructure*& networkStructure)
{
	ComputerId source = 0;
	ComputerId destination = 0;
	for (std::uint32_t i = 0; i < numOfConnections * 2; i++)
	{
		if (i % 2 == 0)
		{
			std::cin >> source;
		}
		else
		{
			std::cin >> destination;
			YAFramework::Node<ComputerId>* node = new YAFramework::Node<ComputerId>(destination);
			networkStructure[source].Insert(node);
		}
	}
}

// YA :: TODO :: Make Main Smaller

int main()
{
	std::uint32_t numOfComputers	= 0;
	std::uint32_t numOfConnections	= 0;
	
	std::cout << "Please Enter Number Of Computer And Number Of Connections!" << std::endl;
	std::cout << "Example :: '5 5' - For 5 computers and 5 connections" << std::endl;

	std::cin >> numOfComputers;
	std::cin >> numOfConnections;

	std::cout << "Number Of Computers :: " << numOfComputers << std::endl;
	std::cout << "Number Of Connections :: " << numOfConnections << std::endl;

	std::cout << "Please Enter The Connections" << std::endl;
	std::cout << "Example :: '1 4 3 2' This will make 1->4 and 3->2 connections" << std::endl;

	// Index 0 is not used
	NetworkStructure* networkStructure = new NetworkStructure[numOfComputers + 1];
	PopulateNetworkStructure(numOfConnections, networkStructure);

	std::cout << "The Network Structure Has Been Populated!" << std::endl;
	ComputerId focusComp = 0;
	std::cout << "Please enter focus computer index!" << std::endl;
	std::cout << "Example :: '3' - for computer index 3" << std::endl;
	std::cin >> focusComp;

	// Algo 5
	AccessibleList accessibleListForUserComp(focusComp, numOfComputers);
	ColorArray colorArr(numOfComputers, YAFramework::Color::White);
	
}
