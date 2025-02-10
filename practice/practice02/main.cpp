#include <iostream>
#include <fstream>
#include <iomanip>
#include <limits>


const std::string FILENAME = "account_balance.txt";
const double INITIAL_BALANCE = 100.00;


double getBalance() {
    std::ifstream file(FILENAME); //used to read balance from filename 
    double balance = INITIAL_BALANCE;

    if (file.is_open()) {
        if (file >> balance) return balance;
    }

    std::ofstream outFile(FILENAME);
    if (!outFile) {
        std::cerr << "Error: Could not create balance file!\n"; // used if the filename is not readable
        exit(1);
    }

    outFile << std::fixed << std::setprecision(2) << INITIAL_BALANCE;
    return INITIAL_BALANCE;
}


void updateBalance(double balance) {
    std::ofstream file(FILENAME);
    if (!file) {
        std::cerr << "Error: Could not update balance file!\n";
        exit(1);
    }
    file << std::fixed << std::setprecision(2) << balance;
}


double getAmount(const std::string& prompt) {
    double amount;
    std::cout << prompt;
    std::cin >> amount;
    if (std::cin.fail() || amount <= 0) {
        std::cin.clear(), std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cerr << "Error: Amount must be positive.\n";
        return -1;
    }
    return amount;
}

void showMenu() {
    std::cout << "\n=== Bank Account Menu ===\n"
        << "1. Check Balance\n"
        << "2. Deposit Money\n"
        << "3. Withdraw Money\n"
        << "4. Exit\n"
        << "Enter your choice: ";
}

int main() {
    std::cout << "Welcome to your Ozark Bank !\n";
    int choice;
    while (true) {
        showMenu();
        std::cin >> choice;
        if (std::cin.fail() || choice < 1 || choice > 4) {
            std::cin.clear(), std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cerr << "Invalid input! Enter 1-4.\n";
            continue;
        }
        if (choice == 4) return 0;

        double balance = getBalance(), amount;
        std::cout << "Your current balance is: $" << balance << "\n";

        if (choice == 1) continue;
        if ((amount = getAmount(choice == 2 ? "Enter deposit amount: $" : "Enter withdrawal amount: $")) > 0) {
            if (choice == 3 && amount > balance) std::cerr << "Error: Insufficient funds! Transaction canceled.\n";
            else updateBalance(balance + (choice == 2 ? amount : -amount)),
                std::cout << "Transaction successful! New balance: $" << getBalance() << "\n";
        }
    }
}