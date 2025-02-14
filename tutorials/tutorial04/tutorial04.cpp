#include <iostream>


struct Point
{
    int x;
    int y;
};

template<typename T>
void display(T value) {
    std::cout << "Value: " << value << "\n";
}