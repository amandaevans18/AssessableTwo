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
			std::cout << "Vector display " << std::endl;
			vectTest.empty();
			vectTest.push_back(7);
			vectTest.push_back(2);
			vectTest.push_back(8);
			vectTest.push_back(9);
			vectTest.push_back(2);
			vectTest.print(); 
			vectTest.remove(2);
			vectTest.print();
			vectTest.clear();
			vectTest.print(); // nothing
			
			break;
		case 2:
			std::cout << "Linked list display" << std::endl;
			linkedListTest.push_front(7);
			linkedListTest.push_front(6);
			linkedListTest.push_front(5);
			linkedListTest.push_front(4);
			linkedListTest.pop_front();
			linkedListTest.print();
			std::cout << "Iterators" << std::endl;
			for (auto it = linkedListTest.begin(); it != linkedListTest.end(); ++it)
			{
				std::cout << (*it) << std::endl;
			}
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