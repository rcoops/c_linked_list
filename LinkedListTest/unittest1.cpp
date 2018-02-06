#include "stdafx.h"
#include "CppUnitTest.h"
#include "../LinkedList/rpcLinkedList.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace LinkedListTest
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			rpcLinkedList pEmptyList;// = new rpcLinkedList();
			Assert::IsTrue(pEmptyList.isEmpty());
			Assert::AreEqual(pEmptyList.size(), 0);
		}

	};
}