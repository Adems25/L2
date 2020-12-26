#include "pch.h"
#include "CppUnitTest.h"
#include "../lab2/lab2.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace lab2UnitTests
{
	TEST_CLASS(lab2UnitTests)
	{
	public:

		TEST_METHOD(CountingSort_test)
		{
			ChArr Ch(10);
			Ch.CountingSort();
			Assert::IsTrue(Ch.sorted());
			Ch.CountingSort();
			Assert::IsTrue(Ch.sorted());
		}
		TEST_METHOD(QuickSort_test)
		{
			IntArr Int(10);
			Int.QuickSort();
			Assert::IsTrue(Int.sorted());
			Int.QuickSort();
			Assert::IsTrue(Int.sorted());
		}
		TEST_METHOD(InsertionSort_test)
		{
			IntArr Int(10);
			Int.InsertionSort();
			Assert::IsTrue(Int.sorted());
			Int.InsertionSort();
			Assert::IsTrue(Int.sorted());
		}
		TEST_METHOD(BogoSort_test)
		{
			IntArr Int(5);
			Int.BogoSort();
			Assert::IsTrue(Int.sorted());
			Int.BogoSort();
			Assert::IsTrue(Int.sorted());
		}
		TEST_METHOD(BiniarySearch_test)
		{
			IntArr Int(10);
			int elem = Int.getelem(4);
			Int.InsertionSort();
			size_t index = Int.BiniarySearch(elem);
			Assert::AreEqual(elem, Int.getelem(index));
		}
	};
}
