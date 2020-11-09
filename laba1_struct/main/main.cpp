#include <iostream>
#include "List.h"
#include <stdexcept>

int main()
{
	List test1;
	test1.push_front(1);
	test1.push_back(11);
	test1.push_front(111);
	test1.print_to_console();
	List test;
	test.push_front(1);
	test.push_back(2);
	test.push_back(3);
	test.insert(888, 1);
	test.push_front(4);
	test.push_back(5);
	test.push_back(6);
	test.push_front(7);
	test.push_back(8);
	test.push_back(9);
	test.push_front(10);
	test.push_back(11);
	test.push_front(12);
	test.remove(0);
	test.remove(1);
	test.remove((int)test.get_size() - 1);
	test.print_to_console();
	test.clear();
	test.print_to_console();
	return 0;
}
