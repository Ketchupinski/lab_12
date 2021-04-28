#include "pch.h"
#include "CppUnitTest.h"
#include "../lab_12_2_recur/lab_12_2_recur.cpp"

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
			one->info = 50;
			one->link = new Elem;
			one->link->info = 60;
			one->link->link = new Elem;
			one->link->link->info = 70;

			Process(one, 60);

			Assert::AreEqual(one->info, 60);
		}
	};
}
