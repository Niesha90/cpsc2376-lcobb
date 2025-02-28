#include <iostream>
#include <stdexcept>
#include <limits> 
#include "Fraction.h"
#include "MixedFraction.h"


void calculatorUI() {
    Fraction current; // Starts with 0/1 (Fraction default constrct

    while (true) {
        std::cout << "\nCurrent Fraction: " << current << "\n\n"

            << "Options:\n"
            << "1. Enter a fraction manually\n"
            << "2. Add a fraction\n"
            << "3. Subtract a fraction\n"
            << "4. Multiply by a fraction\n"
            << "5. Divide by a fraction\n"
            << "6. Display as Mixed Fraction\n"
            << "7. Clear Fraction\n"
            << "8. Exit\n\n"
            << "Choice: ";

        int choice;
        std::cin >> choice;


        if (!std::cin) {
            std::cin.clear();

            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Please enter a number.\n";
            continue;
        }

        try {
            if (choice == 1) {
                // Enter fraction manually
                int n, d;
                std::cout << "Enter numerator and denominator: ";
                std::cin >> n >> d;
                current = Fraction(n, d);

            }
            else if (choice == 2) {
                // Add fraction
                int n, d;
                std::cout << "Enter fraction to add (numerator denominator): ";
                std::cin >> n >> d;
                current = current + Fraction(n, d);

            }
            else if (choice == 3) {
                // Subtract fraction
                int n, d;
                std::cout << "Enter fraction to subtract (numerator denominator): ";
                std::cin >> n >> d;
                current = current - Fraction(n, d);

            }
            else if (choice == 4) {
                // Multiply fraction
                int n, d;
                std::cout << "Enter fraction to multiply (numerator denominator): ";
                std::cin >> n >> d;
                current = current * Fraction(n, d);

            }
            else if (choice == 5) {
                // Divide fraction
                int n, d;
                std::cout << "Enter fraction to divide (numerator denominator): ";
                std::cin >> n >> d;
                current = current / Fraction(n, d);

            }
            else if (choice == 6) {
                // Display Mixed Fraction
                MixedFraction mixed(current);
                std::cout << "Mixed Fraction: " << mixed << "\n";

            }
            else if (choice == 7) {
                // Clear fraction (reset to 0/1)
                current = Fraction();
                std::cout << "Fraction cleared (0/1).\n";

            }
            else if (choice == 8) {
                // Exit the loop (and program)
                std::cout << "Goodbye!\n";
                break;

            }
            else {
                // Invalid menu choice
                std::cout << "Invalid choice. Try again.\n";
            }

        }
        catch (const std::exception& e) {
            // Catch exceptions, e.g., division by zero
            std::cout << "Error: " << e.what() << "\n";
        }
    }
}

int main() {
    calculatorUI();
    return 0;
}