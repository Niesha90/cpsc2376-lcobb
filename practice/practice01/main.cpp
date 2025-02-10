#include <iostream>
#include <vector>

using namespace std;

void printVector(const vector<int>& vec) {
    if (vec.empty()) {
        std::cout << "The vector is empty.\n";
        return;
    }
    for (size_t i = 0; i < vec.size(); ++i) {
        std::cout << vec.at(i) << " ";  // Using .at() everywhere
    }
    std::cout << endl;
}

void doubleVector(vector<int>& vec) {
    for (size_t i = 0; i < vec.size(); ++i) {
        vec.at(i) *= 2;  // Using .at() here too 
    }
}

int calculateSum(const vector<int>& vec) {
    int sum = 0;
    for (size_t i = 0; i < vec.size(); ++i) {
        sum += vec.at(i);  // Using .at() instead of those []
    }
    return sum;
}

void printMultiples(const vector<int>& vec, int value) {
    if (value == 0) {
        std::cout << "Cannot divide by 0.\n";
        return;
    }

    bool foundAny = false;
    for (size_t i = 0; i < vec.size(); ++i) {
        if (vec.at(i) % value == 0) {  // Check if the element is a multiple of 'value'
            std::cout << vec.at(i) << " ";  // Print the multiples
            foundAny = true;
        }
    }

    if (!foundAny) {
        std::cout << "No multiples of " << value << " found.\n";
    }
    std::cout << endl;
}

int main() {
    vector<int> numbers;
    int choice = 0;
    while (choice != 6) {
        std::cout << "\nMenu:\n1. Add an item\n2. Print vector\n3. Double vector\n4. Find sum\n5. Print multiples of a user-defined value\n6. Exit\nChoice: ";
        std::cin >> choice;

        if (choice == 1) {
            int num;
            std::cout << "Enter number: ";
            std::cin >> num;
            numbers.push_back(num);
        }
        else if (choice == 2) {
            printVector(numbers);
        }
        else if (choice == 3) {
            doubleVector(numbers);
            std::cout << "Vector doubled.\n";
        }
        else if (choice == 4) {
            std::cout << "Sum: " << calculateSum(numbers) << std::endl;
        }
        else if (choice == 5) {
            int value;
            std::cout << "Enter a number to find its multiples: ";
            std::cin >> value;
            printMultiples(numbers, value);
        }
        else if (choice == 6) {
            std::cout << "Exiting.\n";
        }
        else {
            std::cout << "Invalid choice. Try again.\n";
        }
    }
    return 0;
}