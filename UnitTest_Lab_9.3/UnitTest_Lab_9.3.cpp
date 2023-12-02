#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_9.3/LAb.cpp"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestLab93
{
	TEST_CLASS(UnitTestLab93)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{ 
			const int  N = 3;
			Tramvai train[N];
			train[1] = { "Львів", Z_V, 9.45};
			train[2] = { "Китай", Z_V , 8.45 };
			train[3] = { " Рим", SPEED_E, 4.25 };

			Assert::IsTrue(LineSearch(train, N, "Львів", Z_V, 9.45));

		}
	};
}
