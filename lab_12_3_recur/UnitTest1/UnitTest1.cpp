#include "pch.h"
#include "CppUnitTest.h"
#include "../lab_12_3_recur/lab_12_3_recur.cpp"

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

			one->info = 90;
			one->prev = NULL;
			one->next = new Elem;

			one->next->info = 60;
			one->next->prev = one;
			one->next->next = new Elem;

			one->next->next->info = 60;
			one->next->next->prev = one->next;
			one->next->next->next = NULL;

			bool x = Check(one);

			Assert::AreEqual(x, true);
		}
	};
}
