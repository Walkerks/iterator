#include <list>
#include <cstdlib>
#include <iostream>

#define NUMELEMENTS 50

typedef std::list<int>::iterator MyIterator;

//Simple how to use std container iterator
int main() {

	std::list<int> myList;

	for (size_t i = 0; i < NUMELEMENTS; i++) {
		myList.push_back(i);
		if (i == 25) {
			//new int[500];
		}
	}
	MyIterator prev;
	size_t counter = 0;
	for (MyIterator it = myList.begin(); it != myList.end(); ++it) {
		//Notice the memory isn't continous like an array
		std::cout << "Located of the memory " << &(*it) << std::endl;
		std::cout << "What the located contains " << *it <<  std::endl;
		if(counter != 0)
			//Notice the differences in memory locations are not constant either
			std::cout << "Difference " << &(*it) - &(*prev) << std::endl;
		prev = it;
		counter++;
	}



return EXIT_SUCCESS;
}