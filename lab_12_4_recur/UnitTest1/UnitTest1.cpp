#include "pch.h"
#include "CppUnitTest.h"
#include "../lab_12_4_recur/lab_12_4_recur.cpp"

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

			one->info = 29;
			one->link = new Elem;

			one->link->info = 60;
			one->link->link = new Elem;

			one->link->link->info = 97;
			one->link->link->link = one;

			Elem* first = one;
			Assert::AreEqual(Count(one, first, 0), 2);
		}
	};
}
