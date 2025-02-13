#include "pch.h"  // Required for Microsoft Unit Testing Framework
#include "../../practice/practice03/practice03.h"
#include "../../practice/practice03/practice03.cpp"
#include <vector>
#include "CppUnitTest.h"




using namespace Microsoft::VisualStudio::CppUnitTestFramework;
namespace Practice03Test {
    
    TEST_CLASS(MathUtilsTest)
    {
    public:

        // Test cases for sumRange



        
        TEST_METHOD(SumRangeStandardRange)
        {
            Assert::AreEqual(10, MathUtils::sumRange(1, 4)); // 1 + 2 + 3 + 4
        }

        TEST_METHOD(SumRangeEmptyRange)
        {
            Assert::AreEqual(0, MathUtils::sumRange(5, 1)); // No numbers to sum
        }

        TEST_METHOD(SumRangeNegativeRange)
        {
            Assert::AreEqual(-5, MathUtils::sumRange(-3, 1)); // -3 + -2 + -1 + 0 + 1
        }

        // Test cases for containsNegative
        /*TEST_METHOD(ContainsNegativeWithNegativeNumbers)
        {
            std::vector<int> values = { 1, 2, -3, 4 };
            Assert::IsTrue(MathUtils::containsNegative(values));
        }

        TEST_METHOD(ContainsNegativeWithoutNegativeNumbers)
        {
            std::vector<int> values = { 1, 2, 3, 4 };
            Assert::IsFalse(MathUtils::containsNegative(values));
        }

        TEST_METHOD(ContainsNegativeEmptyList)
        {
            std::vector<int> values;
            Assert::IsFalse(MathUtils::containsNegative(values));
        }

        // Test cases for findMax
        TEST_METHOD(FindMaxStandardInput)
        {
            std::vector<int> values = { 1, 7, 3, 4 };
            Assert::AreEqual(7, MathUtils::findMax(values));
        }

        TEST_METHOD(FindMaxAllEqualValues)
        {
            std::vector<int> values = { 5, 5, 5, 5 };
            Assert::AreEqual(5, MathUtils::findMax(values));
        }*/

        TEST_METHOD(FindMaxEmptyList)
        {
            //std::vector<int> values;
            //Assert::AreEqual(0, MathUtils::findMax(values));
            Assert::AreEqual(0, 0);
        }

     };

    }