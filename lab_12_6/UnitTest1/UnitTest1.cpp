#include "pch.h"
#include "CppUnitTest.h"
#include "../lab_12_6/lab_12_6.cpp"

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

			Elem * last = one;

			string numb = "60";

			enqueue(one, last, numb);

			Assert::AreEqual(last->info, numb);
		}
	};
}
