// practice03.cpp (Buggy Code to be tested)
#include "practice03.h"
#include <iostream>
#include <vector>


int main() {
	std::cout << "Sum from 1 to 5: " << MathUtils::sumRange(1, 5) << std::endl;

	std::vector<int> values = { 3, -1, 5, 7 };
	std::cout << "Contains negative? " << (MathUtils::containsNegative(values) ? "Yes" : "No") << std::endl;

	std::cout << "Max value: " << MathUtils::findMax(values) << std::endl;

	return 0;
}