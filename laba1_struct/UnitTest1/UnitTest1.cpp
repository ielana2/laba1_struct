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

		TEST_METHOD_INITIALIZE(setUp)
		{
			test = new List();
		}

		TEST_METHOD_CLEANUP(cleanUp)
		{
			delete test;
		}

		TEST_METHOD(pushBack) {
			test->push_back(0);
			test->push_back(1);
			test->push_back(2);
			Assert::AreEqual(test->at(1), 1);
			Assert::AreEqual(test->at(2), 2);
		}

		TEST_METHOD(pushFront) {
			test->push_front(2);
			test->push_front(1);
			test->push_front(0);
			Assert::AreEqual(test->at(1), 1);
			Assert::AreEqual(test->at(2), 2);
		}

		TEST_METHOD(popBack) {
			test->push_front(0);
			test->push_front(1);
			test->push_back(2);
			test->pop_back();
			Assert::AreEqual(test->get_size(), size_t(2));
		}

		TEST_METHOD(popFront) {
			test->push_back(0);
			test->push_back(1);
			test->push_front(2);
			test->pop_front();
			Assert::AreEqual(test->get_size(), size_t(2));
		}

		TEST_METHOD(insert) {
			test->push_back(0);
			test->push_back(1);
			test->push_front(2);
			test->insert(51, 2);
			Assert::AreEqual(test->at(2), 51);
			Assert::AreEqual(test->at(3), 1);
		}

		TEST_METHOD(at) {
			test->push_back(0);
			test->push_back(1);
			test->push_front(2);
			Assert::AreEqual(test->at(1), 0);
			Assert::AreEqual(test->at(2), 1);
		}

		TEST_METHOD(remove) {
			test->push_back(0);
			test->push_back(1);
			test->push_front(2);
			test->remove(1);
			Assert::AreEqual(test->get_size(), size_t(2));
			Assert::AreEqual(test->at(1), 1);
		}

		TEST_METHOD(getSize) {
			test->push_back(0);
			test->push_back(1);
			test->push_front(2);
			test->push_back(3);
			test->push_back(4);
			Assert::AreEqual(test->get_size(), size_t(5));
		}

		TEST_METHOD(clear) {
			test->push_back(0);
			test->push_back(1);
			test->push_front(2);
			test->clear();
			Assert::AreEqual(test->get_size(), size_t(0));
		}

		TEST_METHOD(set) {
			test->push_back(0);
			test->push_back(1);
			test->push_front(2);
			test->set(1, 56);
			Assert::AreEqual(test->at(1), 56);
		}

		TEST_METHOD(isEmpty) {
			test->push_back(0);
			test->push_back(1);
			test->push_front(2);
			Assert::AreEqual(test->isEmpty(), false);
		}
	};
}
