# Board Game Café Lending Out Tool 

## 1. Program Specification

This C++ program is a lightweight tool for managing the board game lending operations of a local café. It allows the café owner to track all the board games in the inventory, see how many copies are available, and manage lending to customers. When a customer borrows a game, the program records who borrowed it and the due date. It also updates the game’s availability and allows for tracking returns.

The main entities involved are:  
- **Games**, which have titles and copy counts  
- **Customers**, who borrow and return games  
- **Lending records**, which associate a customer with a borrowed game and a due date

The program will offer basic functionality: listing available games, checking out games to customers, and marking games as returned.

---

## 2. Key Nouns and Verbs

### 🔑 Nouns (likely candidates for classes or attributes):
- Game
- Customer
- LendingRecord
- Title
- Copies
- Name
- Due date

### 🔧 Verbs (likely candidates for methods or behaviors):
- Add game
- Check out
- Return
- Borrow
- List
- Get name/title
- Get due date
- Track availability

---

## 3. Class Declarations

### 📦 Game

//Game.h
class Game {
private:
    std::string title;
    int totalCopies;
    int availableCopies;

public:
    std::string getTitle();
    int getAvailableCopies();
    void checkoutCopy();
    void returnCopy();
};

// Customer.h
class Customer {
private:
    std::string name;
    std::vector<LendingRecord> borrowedGames;

public:
    Customer(const std::string& name);
    std::string getName() const;
    void borrowGame(Game* game, const std::string& dueDate);
    void returnGame(Game* game);
};

// Lending Record.h 

class LendingRecord {
private:
    Game* game;
    std::string dueDate;

public:
    LendingRecord(Game* game, const std::string& dueDate);
    Game* getGame() const;
    std::string getDueDate() const;


```mermaid
classDiagram
    class Game {
        - std::string title
        - int totalCopies
        - int availableCopies
        + std::string getTitle()
        + int getAvailableCopies()
        + void checkoutCopy()
        + void returnCopy()
    }

    class Customer {
        - std::string name
        - std::vector<LendingRecord> borrowedGames
        + std::string getName()
        + void borrowGame(Game*, std::string dueDate)
        + void returnGame(Game*)
    }

    class LendingRecord {
        - Game* game
        - std::string dueDate
        + Game* getGame()
        + std::string getDueDate()
    }

    Game "1" --> "*" LendingRecord : referenced in
    Customer "1" --> "*" LendingRecord : has