#include "pch.h"
#include "CppUnitTest.h"
#include "../lab_12_5/lab_12_5.cpp"

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

			string num = "59";
			push(one, num);

			Assert::AreEqual(one->info, num);
		}
	};
}
