// AcademyFindAccesible.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "List.hpp"
#include "Node.hpp"

// YA :: TODO :: Add Error Check In Input

void PopulateNetworkStructure(int numOfConnections, YAFramework::List<std::uint32_t>* networkStructure)
{
	int source = 0;
	int destination = 0;
	for (int i = 0; i < numOfConnections * 2; i++)
	{
		if (i % 2 == 0)
		{
			std::cin >> source;
		}
		else
		{
			std::cin >> destination;
			YAFramework::Node<std::uint32_t>* node = new YAFramework::Node<std::uint32_t>(destination);
			networkStructure[source].Insert(node);
		}
	}
}


int main()
{
	std::cout << "Please Enter Number Of Computer And Number Of Connections!" << std::endl;
	std::cout << "Example :: '5 5' - For 5 computers and 5 connections" << std::endl;

	int numOfComputers = 0;
	int numOfConnections = 0;

	std::cin >> numOfComputers;
	std::cin >> numOfConnections;

	std::cout << std::endl;
	std::cout << "Please Enter The Connections" << std::endl;
	std::cout << "Example :: '1 4 3 2' This will make 1->4 and 3->2 connections" << std::endl;

	
	// Index 0 is not used
	YAFramework::List<std::uint32_t>* networkStructure = new YAFramework::List<std::uint32_t>[numOfComputers + 1];
	PopulateNetworkStructure(numOfComputers, networkStructure);
}
