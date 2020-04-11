// AcademyFindAccesible.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <list>

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

	std::vector<std::list<int>> computersVector(numOfComputers);

	int source = 0;
	int destination = 0;
	for (int i = 1; i < numOfConnections; i++)
	{
		if (i % 2 == 0)
		{
			std::cin >> source;
		}
		else
		{
			std::cin >> destination;
			// new node
			//computersVector[source].InsertAfter(computersVector[source].Last());
		}
	}
}
