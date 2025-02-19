#include <iostream>
#include <vector>
#include <algorithm>  
#include <numeric>    

int main() {
    std::vector<int> numbers;
    int num;


    std::cout << "Enter a list of integers (enter -1 to stop): ";  // the prompt for list of integers 
    while (std::cin >> num && num != -1) {
        numbers.push_back(num);
    }

    if (numbers.empty()) {
        std::cerr << "No numbers entered. Exiting...\n";
        return 1;
    }


    std::cout << "Squared values: ";
    std::for_each(numbers.begin(), numbers.end(), [](int n) {
        std::cout << (n * n) << " ";
        });
    std::cout << std::endl;


    int sumOfSquares = std::accumulate(numbers.begin(), numbers.end(), 0, //the sum of lambda function
        [](int acc, int n) {
            return acc + (n * n);
        });


    std::cout << "Sum of squared values: " << sumOfSquares << std::endl;

    return 0;
}