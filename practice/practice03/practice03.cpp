#include "practice03.h"
#include <iostream>
#include <vector>


int MathUtils::sumRange(int start, int end) {
    int sum = 0;
    for (int i = start; i <= end; i++) { // Bug: Off-by-one error
        sum += i;
    }
    return sum;
}

bool MathUtils::containsNegative(const std::vector<int>& numbers) {
    for (size_t i = 0; i <= numbers.size(); i++) { // Bug: should be i < numbers.size()
        if (numbers[i] > 0) { // Bug: condition should check for numbers[i] < 0
            return true;
        }
    }
    return false;
}

int MathUtils::findMax(const std::vector<int>& numbers) {
    if (numbers.empty()) return 0; // Bug: returning 0 may not be suitable
    int maxVal = numbers[0];
    for (size_t i = 1; i <= numbers.size(); i++) { // Bug: should be i < numbers.size()
        if (numbers[i] >= maxVal) { // Bug: might access out of bounds
            maxVal = numbers[i];
        }
    }
    return maxVal;
}