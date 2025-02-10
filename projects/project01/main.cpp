#include <iostream>
#include <vector>
#include <random>
#include <limits>

enum class Cell { EMPTY, WALL, PLAYER, EXIT };
enum class GameState { ONGOING, WIN, QUIT };

class Labyrinth {  //Chose Labyrinth because of my love for David Bowie 
private:
    std::vector<std::vector<Cell>> board;
    int playerRow = 0, playerCol = 0;
    GameState state = GameState::ONGOING;
    std::mt19937 rng{ std::random_device{}() };

public:
    Labyrinth(int size = 10) {
        makeBoard(size);
        placeExit();
    }

    void makeBoard(int size) {
        board = std::vector<std::vector<Cell>>(size, std::vector<Cell>(size, Cell::EMPTY));
        std::uniform_int_distribution<int> dist(0, size - 1);
        for (int i = 0; i < size * size / 4; ++i) board[dist(rng)][dist(rng)] = Cell::WALL;
        board[playerRow][playerCol] = Cell::PLAYER;
    }

    void placeExit() { board[board.size() - 1][board.size() - 1] = Cell::EXIT; }

    void printBoard() const {
        for (const auto& row : board) {
            for (const auto& cell : row) std::cout << (cell == Cell::EMPTY ? '.' : cell == Cell::WALL ? '#' : cell == Cell::PLAYER ? 'P' : 'E') << " ";
            std::cout << "\n";
        }
    }

    void play() {
        while (state == GameState::ONGOING) {
            printBoard();
            handleMove(getValidInput());
            if (board[playerRow][playerCol] == Cell::EXIT) state = GameState::WIN;
        }
        printBoard();
        std::cout << (state == GameState::WIN ? "Congratulations! You reached the exit!\n" : "You quit the game. Goodbye!\n");
    }

    char getValidInput() {
        char move;
        while (true) {
            std::cout << "Move (w: up, s: down, a: left, d: right, q: quit): ";
            std::cin >> move;
            if (move == 'w' || move == 's' || move == 'a' || move == 'd' || move == 'q') return move;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Please enter w, s, a, d, or q.\n";
        }
    }

    void handleMove(char move) {
        if (move == 'q') { state = GameState::QUIT; return; }
        int newRow = playerRow + (move == 'w' ? -1 : move == 's' ? 1 : 0);
        int newCol = playerCol + (move == 'a' ? -1 : move == 'd' ? 1 : 0);
        if (isValidMove(newRow, newCol)) {
            board[playerRow][playerCol] = Cell::EMPTY;
            playerRow = newRow;
            playerCol = newCol;
            board[playerRow][playerCol] = Cell::PLAYER;
        }
        else {
            std::cout << "You hit a wall! Try again.\n";
        }
    }

    bool isValidMove(int row, int col) {
        return row >= 0 && row < board.size() && col >= 0 && col < board.size() && board[row][col] != Cell::WALL;
    }
};

void displayRules() {
    std::cout << "Welcome to Niesha's Labyrinth Game!\n"
        << "Your goal is to reach the exit 'E' without hitting the walls '#'.\n"
        << "Controls: w (up), s (down), a (left), d (right), q (quit)\n\n";
}

int main() {
    char choice;
    do {
        displayRules();
        Labyrinth game;
        game.play();
        std::cout << "Play again? (y/n): ";
        std::cin >> choice;
        while (choice != 'y' && choice != 'n') {
            std::cout << "Invalid input. Enter 'y' or 'n': ";
            std::cin >> choice;
        }
    } while (choice == 'y');
    std::cout << "Thanks for playing!\n";
    return 0;
}