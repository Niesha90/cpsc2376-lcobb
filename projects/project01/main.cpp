#include <iostream>
#include <vector>
#include <random>
#include <limits>

enum class Cell { EMPTY, WALL, PLAYER, EXIT };
enum class GameState { ONGOING, WIN, QUIT };

class Labyrinth {
private:
    std::vector<std::vector<Cell>> board;
    int playerRow = 0, playerCol = 0;
    GameState state = GameState::ONGOING;
    std::mt19937 rng{ std::random_device{}() };

public:
    Labyrinth(int size = 10) {
        generateBoard(size);
    }

    void play() {
        while (state == GameState::ONGOING) {
            displayBoard();
            handleMove(getValidInput());
            if (state == GameState::WIN) {
                std::cout << "Congratulations! You reached the end of the Labyrinth and won the game!\n";
                break;
            }
            else if (state == GameState::QUIT) {
                std::cout << "You quit the Labyrinth. Goodbye!\n";
                break;
            }
        }
    }

private:
    void generateBoard(int size) {
        board = std::vector<std::vector<Cell>>(size, std::vector<Cell>(size, Cell::EMPTY));
        std::uniform_int_distribution<int> dist(0, size - 1);

        for (int i = 0; i < size * size / 4; ++i) {
            int row = dist(rng);
            int col = dist(rng);
            if (board[row][col] == Cell::EMPTY && !(row == size - 1 && col == size - 1)) {
                board[row][col] = Cell::WALL;
            }
        }

        board[playerRow][playerCol] = Cell::PLAYER;
        board[size - 1][size - 1] = Cell::EXIT;
    }

    void displayBoard() const {
        for (const auto& row : board) {
            for (const auto& cell : row) {
                std::cout << cellToChar(cell) << " ";
            }
            std::cout << "\n";
        }
    }

    char cellToChar(Cell cell) const {
        if (cell == Cell::EMPTY) return '.';
        if (cell == Cell::WALL) return '#';
        if (cell == Cell::PLAYER) return 'P';
        return 'E';
    }

    char getValidInput() {
        char move;
        while (true) {
            std::cout << "Move (w: up, s: down, a: left, d: right, q: quit): ";
            std::cin >> move;
            if (isValidMoveInput(move)) return move;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Please enter w, s, a, d, or q.\n";
        }
    }

    bool isValidMoveInput(char move) const {
        return move == 'w' || move == 's' || move == 'a' || move == 'd' || move == 'q';
    }

    void handleMove(char move) {
        if (move == 'q') {
            state = GameState::QUIT;
            return;
        }

        int newRow = playerRow + (move == 'w' ? -1 : move == 's' ? 1 : 0);
        int newCol = playerCol + (move == 'a' ? -1 : move == 'd' ? 1 : 0);

        if (isValidMove(newRow, newCol)) {
            updatePlayerPosition(newRow, newCol);

            if (playerRow == board.size() - 1 && playerCol == board.size() - 1) {
                state = GameState::WIN;
            }
        }
        else {
            std::cout << "You hit a wall! Try again.\n";
        }
    }

    bool isValidMove(int row, int col) const {
        return row >= 0 && row < board.size() && col >= 0 && col < board.size() && board[row][col] != Cell::WALL;
    }

    void updatePlayerPosition(int newRow, int newCol) {
        board[playerRow][playerCol] = Cell::EMPTY;
        playerRow = newRow;
        playerCol = newCol;
        board[playerRow][playerCol] = Cell::PLAYER;
    }
};

void displayRules() {
    std::cout << "Welcome to Niesha's Labyrinth Game!\n"
        << "Your goal is to reach the 'E' at the end of the Maze without hitting the walls '#'.\n"
        << "Controls: w (up), s (down), a (left), d (right), q (quit)\n\n";
}

char getReplayChoice() {
    char choice;
    while (true) {
        std::cout << "Play again? (y/n): ";
        std::cin >> choice;
        if (choice == 'y' || choice == 'n') return choice;
        std::cout << "Invalid input. Enter 'y' or 'n'.\n";
    }
}

int main() {
    displayRules();
    char choice;
    do {
        Labyrinth game;
        game.play();
        choice = getReplayChoice();
    } while (choice == 'y');

    std::cout << "Thanks for playing!\n";
    return 0;
}