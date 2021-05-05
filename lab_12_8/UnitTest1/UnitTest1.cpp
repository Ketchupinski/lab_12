#include "pch.h"
#include "CppUnitTest.h"
#include "../lab_12_8/lab_12_8.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			Elem* one;
			one = new Elem;

			one->punktOne = "Mel";
			one->punktTwo = "Gibson";
			one->next = new Elem;

			one->next->punktOne = "You";
			one->next->punktTwo = "Tu";
			one->next->next = new Elem;

			one->next->next->punktOne = "Geovani";
			one->next->next->punktTwo = "Jeorjeo";
			one->next->next->next = one;
			Elem* last = one->next->next->next;

			insert(one, last, "Mike", "Lucky", 100);

			Assert::AreEqual(last->distance, 100);
		}
	};
}
