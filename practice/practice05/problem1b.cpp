#include <iostream>
#include <vector>

int main() {
    std::vector<int> numbers = { 5, 43, 33, 55, 45 };

    std::cout << "Numbers in reverse order: ";
    for (auto it = numbers.rbegin(); it != numbers.rend(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    return 0;
}