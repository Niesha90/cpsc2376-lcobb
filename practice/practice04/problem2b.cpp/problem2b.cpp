#include <iostream>
#include <string>
#include <algorithm> // for std::max

template <typename T>
T findMax(T a, T b, T c) {
    return std::max({ a, b, c });
}

int main() {
    int choice;
    std::cout << "Compare (1) Numbers or (2) Strings? ";
    std::cin >> choice;
    std::cin.ignore(); // Ignore the newline character left in the input buffer

    if (choice == 1) {
        int a, b, c;
        std::cout << "Enter first value: ";
        std::cin >> a;
        std::cout << "Enter second value: ";
        std::cin >> b;
        std::cout << "Enter third value: ";
        std::cin >> c;

        int result = findMax<int>(a, b, c);
        std::cout << "Max value: " << result << std::endl;
    }
    else if (choice == 2) {
        std::string a, b, c;
        std::cout << "Enter first value: ";
        std::cin >> a;
        std::cout << "Enter second value: ";
        std::cin >> b;
        std::cout << "Enter third value: ";
        std::cin >> c;

        std::string result = findMax<std::string>(a, b, c);
        std::cout << "Max value: " << result << std::endl;
    }
    else {
        std::cout << "Invalid choice. Please choose 1 or 2." << std::endl;
    }

    return 0;
}