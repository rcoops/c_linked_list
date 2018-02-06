// LinkedList.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "conio.h"
#include "rpcLinkedList.h"
#include <iostream>

int main()
{
	rpcLinkedList *linkedList = new rpcLinkedList();
	linkedList->append(1); // 1
	linkedList->append(4); // 1 4
	linkedList->append(3); // 1 4 3
	linkedList->append(12); // 1 4 3 12
	linkedList->prepend(31); // 31 1 4 3 12
	linkedList->printList();
	int data = linkedList->getAt(0);
	std::cout << "data at 0: " << data << std::endl;
	data = linkedList->getAt(1);
	std::cout << "data at 1: " << data << std::endl;
	data = linkedList->getAt(2);
	std::cout << "data at 2: " << data << std::endl;
	data = linkedList->getAt(3);
	std::cout << "data at 3: " << data << std::endl;
	data = linkedList->getAt(4);
	std::cout << "data at 4: " << data << std::endl;
	data = linkedList->getAt(-1);
	std::cout << "data at -1: " << data << std::endl;
	data = linkedList->getAt(5);
	std::cout << "data at 5: " << data << std::endl;
	linkedList->insertAt(5, 8); // 31 1 4 3 12 8
	linkedList->insertAt(0, 22); // 22 31 1 4 3 12 8
	linkedList->insertAt(-1, 6); // 6 22 31 1 4 3 12 8
	linkedList->insertAt(1, 2); // 6 2 22 31 1 4 3 12 8
	linkedList->printList();
	linkedList->sort(rpcLinkedList::DESC);
	linkedList->printList();
	linkedList->sort(rpcLinkedList::ASC);
	linkedList->printList();
//	linkedList->removeHead(); // 2 22 31 1 4 3 12 8
//	linkedList->removeTail(); // 2 22 31 1 4 3 12
//	linkedList->printList();
//	data = linkedList->removeFrom(3); // 1 - 2 22 31 4 3 12
//	std::cout << "data removed from 3: " << data << std::endl;
//	linkedList->printList();
//	data = linkedList->removeFrom(0); // 2 - 22 31 4 3 12
//	std::cout << "data removed from 0: " << data << std::endl;
//	linkedList->printList();
//	data = linkedList->removeFrom(4); // 12 - 22 31 4 3
//	std::cout << "data removed from 4: " << data << std::endl;
//	linkedList->printList();
//	data = linkedList->removeFrom(4); // INT_MAX - 22 31 4 3
//	std::cout << "data removed from 4: " << data << std::endl;
//	linkedList->printList();
//	data = linkedList->removeFrom(-1); // INT_MAX - 22 31 4 3
//	std::cout << "data removed from 4: " << data << std::endl;
//	linkedList->printList();
//	data = linkedList->getAt(2);
//	std::cout << "data retrieved from 2: " << data << std::endl;
//	linkedList->printList();

	_getch();
	delete linkedList;
    return 0;
}

