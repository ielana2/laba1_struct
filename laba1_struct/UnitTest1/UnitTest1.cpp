#include "pch.h"
#include "CppUnitTest.h"
#include "../main/List.cpp"
#include "../main/List.h"
#include <stdexcept>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
	TEST_CLASS(UnitTest)
	{
	public:
		List* test;

		TEST_METHOD_INITIALIZE(setUp) //inizialization list's test
		{
			test = new List();
		}

		TEST_METHOD_CLEANUP(cleanUp) //deleting list's test
		{
			delete test;
		}

		TEST_METHOD(pushBack) { //test for adding element in the back
			test->push_back(0);
			test->push_back(1);
			test->push_back(2);
			Assert::AreEqual(test->at(1), 1);
			Assert::AreEqual(test->at(2), 2);
		}

		TEST_METHOD(pushFront) { //test for adding element in the front
			test->push_front(2);
			test->push_front(1);
			test->push_front(0);
			Assert::AreEqual(test->at(1), 1);
			Assert::AreEqual(test->at(2), 2);
		}

		TEST_METHOD(popBack) { //test for deleting last element
			test->push_front(0);
			test->push_front(1);
			test->push_back(2);
			test->pop_back();
			Assert::AreEqual(test->get_size(), size_t(2));
		}

		TEST_METHOD(popFront) { //test for deleting first element
			test->push_back(0);
			test->push_back(1);
			test->push_front(2);
			test->pop_front();
			Assert::AreEqual(test->get_size(), size_t(2));
		}

		TEST_METHOD(insert) { //test for inserting element before element with chosen index
			test->push_back(0);
			test->push_back(1);
			test->push_front(2);
			test->insert(51, 2);
			Assert::AreEqual(test->at(2), 51);
			Assert::AreEqual(test->at(3), 1);
		}

		TEST_METHOD(at) { //test for getting element by index
			test->push_back(0);
			test->push_back(1);
			test->push_front(2);
			Assert::AreEqual(test->at(1), 0);
			Assert::AreEqual(test->at(2), 1);
		}

		TEST_METHOD(remove) { //test for deleting element with chosen index
			test->push_back(0);
			test->push_back(1);
			test->push_front(2);
			test->remove(1);
			Assert::AreEqual(test->get_size(), size_t(2));
			Assert::AreEqual(test->at(1), 1);
		}

		TEST_METHOD(getSize) { //test for getting list's size
			test->push_back(0);
			test->push_back(1);
			test->push_front(2);
			test->push_back(3);
			test->push_back(4);
			Assert::AreEqual(test->get_size(), size_t(5));
		}

		TEST_METHOD(clear) { //test for clearing the list
			test->push_back(0);
			test->push_back(1);
			test->push_front(2);
			test->clear();
			Assert::AreEqual(test->get_size(), size_t(0));
		}

		TEST_METHOD(set) { //test for changing one element by another
			test->push_back(0);
			test->push_back(1);
			test->push_front(2);
			test->set(1, 56);
			Assert::AreEqual(test->at(1), 56);
		}

		TEST_METHOD(isEmpty) { //test for checking if the list is empty
			test->push_back(0);
			test->push_back(1);
			test->push_front(2);
			Assert::AreEqual(test->isEmpty(), false);
		}
	};
}
