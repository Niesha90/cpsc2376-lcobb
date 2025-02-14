#include <iostream>
#include <iomanip>  // For std::setprecision

// Function to convert temperature
double convertTemperature(double temp, char scale) {
    if (scale == 'F') {  // Convert Celsius to Fahrenheit
        return (temp * 9.0 / 5.0) + 32;
    }
    else if (scale == 'C') {  // Convert Fahrenheit to Celsius
        return (temp - 32) * 5.0 / 9.0;
    }
    return temp;
}

// Function to display the menu and get user input
int displayMenu() {
    int option;
    std::cout << "1. Convert Celsius to Fahrenheit\n";
    std::cout << "2. Convert Fahrenheit to Celsius\n";
    std::cout << "Choose an option: ";
    std::cin >> option;
    return option;
}

// Function to get the temperature from the user
double getTemperature() {
    double temp;
    std::cout << "Enter temperature: ";
    std::cin >> temp;
    return temp;
}

int main() {
    int option = displayMenu();
    double temp = getTemperature();
    double convertedTemp;

    if (option == 1) {
        convertedTemp = convertTemperature(temp, 'F');
        std::cout << "Converted: " << std::fixed << std::setprecision(2) << convertedTemp << "°F\n";
    }
    else if (option == 2) {
        convertedTemp = convertTemperature(temp, 'C');
        std::cout << "Converted: " << std::fixed << std::setprecision(2) << convertedTemp << "°C\n";
    }
    else {
        std::cerr << "Invalid option. Please choose 1 or 2.\n";
        return 1;
    }

    return 0;
}
