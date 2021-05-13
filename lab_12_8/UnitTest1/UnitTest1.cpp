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
			Elem* one = NULL;
			Elem* last = NULL;

			insert(one, last, "Mike", 100);

			Assert::AreEqual(last->distance, 100);
		}
	};
}
