#include <iostream>
#include <deque>
#include <string>

int main() {
    std::deque<std::string> textEdits;
    std::string currentContent = "";
    int choice;

    while (true) {
        std::cout << "\n1. Add Text\n";
        std::cout << "2. Undo Last Edit\n";
        std::cout << "3. Show Content\n";
        std::cout << "4. Exit\n";
        std::cout << "Choice: ";
        std::cin >> choice;
        std::cin.ignore(); // Ignore the newline left in the buffer

        if (choice == 1) {
            std::string newText;
            std::cout << "Enter text: ";
            std::getline(std::cin, newText);
            textEdits.push_back(currentContent); // Save current state for undo
            currentContent += (currentContent.empty() ? "" : " ") + newText; // Add space if not empty
            std::cout << "Text added successfully.\n";
        }
        else if (choice == 2) {
            if (!textEdits.empty()) {
                currentContent = textEdits.back(); // Revert to the last saved state
                textEdits.pop_back();              // Remove the last saved state
                std::cout << "Undo successful!\n";
            }
            else {
                std::cout << "No edits to undo.\n";
            }
        }
        else if (choice == 3) {
            std::cout << "Current Content: " << currentContent << "\n";
        }
        else if (choice == 4) {
            std::cout << "Exiting the editor. Goodbye!\n";
            break;
        }
        else {
            std::cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}