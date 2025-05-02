#include <iostream>
#include <memory>
#include <string>
#include <algorithm>
#include <cctype>
#include <vector>
#include <unordered_set>
#include <limits>

// Strategy interface
class TextFilter {
public:
    virtual std::string filter(const std::string& input) const = 0;
    virtual ~TextFilter() = default;
};

// Reverse the text
class ReverseFilter : public TextFilter {
public:
    std::string filter(const std::string& input) const override {
        std::string output(input);
        std::reverse(output.begin(), output.end());
        return output;
    }
};

// Convert text to uppercase
class UppercaseFilter : public TextFilter {
public:
    std::string filter(const std::string& input) const override {
        std::string output(input);
        std::transform(output.begin(), output.end(), output.begin(), ::toupper);
        return output;
    }
};

// Remove vowels from text
class RemoveVowelsFilter : public TextFilter {
public:
    std::string filter(const std::string& input) const override {
        std::string output;
        std::unordered_set<char> vowels;
        vowels.insert('a'); vowels.insert('e'); vowels.insert('i'); vowels.insert('o'); vowels.insert('u');
        vowels.insert('A'); vowels.insert('E'); vowels.insert('I'); vowels.insert('O'); vowels.insert('U');
        auto it = input.begin();
        while (it != input.end()) {
            char c = *it;
            if (vowels.count(c) == 0) {
                output.append(1, c);
            }
            ++it;
        }
        return output;
    }
};

// Censor bad words by replacing with asterisks
class CensorFilter : public TextFilter {
public:
    CensorFilter() {
        badWordsList.push_back("hell");
        badWordsList.push_back("ugly");
        badWordsList.push_back("mean");
    }
    std::string filter(const std::string& input) const override {
        std::string output(input);
        std::string lower;
        lower.reserve(output.size());
        for (char ch : output) {
            lower.push_back(std::tolower(ch));
        }
        auto listIt = badWordsList.begin();
        while (listIt != badWordsList.end()) {
            const std::string& word = *listIt;
            std::string lowerWord(word);
            std::transform(lowerWord.begin(), lowerWord.end(), lowerWord.begin(), ::tolower);
            size_t pos = lower.find(lowerWord);
            while (pos != std::string::npos) {
                output.replace(pos, lowerWord.length(), std::string(lowerWord.length(), '*'));
                lower.replace(pos, lowerWord.length(), std::string(lowerWord.length(), '*'));
                pos = lower.find(lowerWord, pos + lowerWord.length());
            }
            ++listIt;
        }
        return output;
    }

private:
    std::vector<std::string> badWordsList;
};

// Factory functions instead of lambdas
std::unique_ptr<TextFilter> makeReverse() {
    return std::unique_ptr<TextFilter>(new ReverseFilter());
}
std::unique_ptr<TextFilter> makeUppercase() {
    return std::unique_ptr<TextFilter>(new UppercaseFilter());
}
std::unique_ptr<TextFilter> makeRemoveVowels() {
    return std::unique_ptr<TextFilter>(new RemoveVowelsFilter());
}
std::unique_ptr<TextFilter> makeCensor() {
    return std::unique_ptr<TextFilter>(new CensorFilter());
}

int main() {
    std::string sentence;
    std::cout << "Enter a sentence: ";
    std::getline(std::cin, sentence);

    std::unique_ptr<TextFilter> filter;
    int choice;

    // Map menu choices to factory functions using vector
    std::vector<std::pair<int, std::unique_ptr<TextFilter>(*)()>> strategies;
    strategies.push_back(std::make_pair(1, &makeReverse));
    strategies.push_back(std::make_pair(2, &makeUppercase));
    strategies.push_back(std::make_pair(3, &makeRemoveVowels));
    strategies.push_back(std::make_pair(4, &makeCensor));

    while (true) {
        std::cout << "\nCurrent sentence: " << sentence << "\n";
        std::cout << "Choose a filter strategy:\n"
            << " 1) Reverse text\n"
            << " 2) Uppercase text\n"
            << " 3) Remove vowels\n"
            << " 4) Censor bad words\n"
            << " 5) Enter new sentence\n"
            << " 0) Exit\n"
            << "> ";
        std::cin >> choice;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        if (choice == 0) {
            std::cout << "Exiting.\n";
            break;
        }
        if (choice == 5) {
            std::cout << "Enter a new sentence: ";
            std::getline(std::cin, sentence);
            continue;
        }

        bool applied = false;
        auto it = strategies.begin();
        while (it != strategies.end()) {
            if (it->first == choice) {
                filter = (it->second)();
                std::string result = filter->filter(sentence);
                std::cout << "Filtered result: " << result << "\n";
                applied = true;
                break;
            }
            ++it;
        }
        if (!applied) {
            std::cout << "Invalid choice, try again.\n";
        }
    }

    return 0;
}
