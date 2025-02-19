#include <iostream>
#include <vector>
#include <numeric>  

int main() {
    std::vector<int> numbers = { 5, 2, 15, 10, 20 };


    int sum = std::accumulate(numbers.begin(), numbers.end(), 0); // calculating the sum of the numbers 


    int product = std::accumulate(numbers.begin(), numbers.end(), 1, std::multiplies<int>()); // used to calculate product of numbers 

    std::cout << "Sum: " << sum << std::endl;
    std::cout << "Product: " << product << std::endl;

    return 0;
}