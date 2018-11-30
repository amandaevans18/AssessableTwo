#include "LinkedList.h"
#include"ObjectPool.h"
#include"Queue.h"
#include"Stack.h"
#include"Vector.h"

#include<iostream>

bool stillTestin = true;
int userInput = 0;

int main()
{
	int amt = 10;
	tVector<int> vectTest;
	tForwardList<int> linkedListTest;
	tObjectPool<size_t> objPoolTest(10);
	tStack<int> stackTest;
	tQueue<int> queueTest;

	std::cout << "Select Container to test" << std::endl;
	std::cout << "[1] Vector" << std::endl;
	std::cout << "[2] Linked List" << std::endl;
	std::cout << "[3] Object pools" << std::endl;
	std::cout << "[4] Stack" << std::endl;
	std::cout << "[5] Queue" << std::endl;

	while (stillTestin) 
	{

		std::cin >> userInput;

		switch (userInput)
		{
		case 1:
			std::cout << "Vector reserve it " << std::endl;
			vectTest.reserve(amt);
			vectTest.print();
			
			break;
		case 2:
			std::cout << "Linked list display" << std::endl;
			break;

		case 3:
			std::cout << "Object pools display" << std::endl;
			break;

		case 4:
			std::cout << "Stack display" << std::endl;
			break;

		case 5:
			std::cout << "Queue display" << std::endl;
			break;
		default:
			std::cout << "Try again" << std::endl;
			break;
		}
	}
	return 0;
}