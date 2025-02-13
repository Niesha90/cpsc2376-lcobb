#include <iostream>
#include <vector>
#include <limits>
#include "practice03.cpp"

class MathUtils {
public:
    static int sumRange(int start, int end) {
        int sum = 0;
        for (int i = start; i <= end; i++) {
            sum += i;
        }
        return sum;
    }

    static bool containsNegative(const std::vector<int>& numbers) {
        for (size_t i = 0; i < numbers.size(); i++) {
            if (numbers[i] < 0) {
                return true;
            }
        }
        return false;
    }

    static int findMax(const std::vector<int>& numbers) {
        if (numbers.empty()) {
            return std::numeric_limits<int>::min();  
        }
        int maxVal = numbers[0];
        for (size_t i = 1; i < numbers.size(); i++) {
            if (numbers[i] > maxVal) {
                maxVal = numbers[i];
            }
        }
        return maxVal;
    }
};