#include <iostream>
#include <string>
#include <map>

int main() {
    float redPotion{ 0.0f };    // Amount of red potion in mL
    float bluePotion{ 0.0f };   // Amount of blue potion in mL
    float* const flask{ nullptr };    // Pointer to the selected potion (now using a better pointer approach)

    std::string choice;

    while (true) {
        std::cout << "Which potion would you like to add to? (Red/Blue) or type 'Done' to exit: ";
        std::cin >> choice;

        if (!choice.compare("Done")) {
            break;
        }
        if (!choice.compare("done")) {
            break;
        }

        std::map<std::string, float*> potionMap = {
            {"Red", &redPotion}, {"red", &redPotion},
            {"Blue", &bluePotion}, {"blue", &bluePotion}
        };

        auto it = potionMap.find(choice);
        if (it == potionMap.end()) {
            std::cout << "Invalid choice. Please enter 'Red', 'Blue', or 'Done'." << std::endl;
            continue;
        }

        float* const selectedPotion = it->second;

        float amount;
        std::cout << "How many milliliters would you like to add? ";
        std::cin >> amount;

        if (!(amount >= 0)) {
            std::cout << "Invalid amount. Please enter a positive value." << std::endl;
            continue;
        }

        *selectedPotion += amount;

        std::cout << "Potion levels: Red = " << redPotion << "mL, Blue = " << bluePotion << "mL" << std::endl;
    }

    std::cout << "Final potion levels: Red = " << redPotion << "mL, Blue = " << bluePotion << "mL" << std::endl;
    std::cout << "Goodbye!" << std::endl;

    return 0;
}