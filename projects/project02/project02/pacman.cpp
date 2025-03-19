#include "pacman.h"
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

// Board size
const int ROWS = 5;
const int COLS = 7;
const int NUM_GHOSTS = 2;  // Number of ghosts

// Constructor initializes the game board
Game::Game() {
    srand(static_cast<unsigned int>(time(0))); // Random seed

    // Initialize board using iterators
    board = {
        { WALL, WALL, WALL, WALL, WALL, WALL, WALL },
        { WALL, DOT,  DOT,  DOT,  DOT,  DOT,  WALL },
        { WALL, DOT,  WALL, DOT,  WALL, DOT,  WALL },
        { WALL, DOT,  DOT,  DOT,  DOT,  DOT,  WALL },
        { WALL, WALL, WALL, WALL, WALL, WALL, WALL }
    };

    placeGhosts();
    placePacman();
    score = 0;
    gameStatus = ONGOING;
}

// Function to place multiple ghosts randomly
void Game::placeGhosts() {
    int placed = 0;
    while (placed < NUM_GHOSTS) {
        int x = rand() % (ROWS - 2) + 1;
        int y = rand() % (COLS - 2) + 1;

        rowIt = board.begin();
        std::advance(rowIt, x);
        colIt = rowIt->begin();
        std::advance(colIt, y);

        if (*colIt == DOT) {
            *colIt = GHOST;
            placed++;
        }
    }
}

// Function to randomly place Pac-Man
void Game::placePacman() {
    while (true) {
        int x = rand() % (ROWS - 2) + 1;
        int y = rand() % (COLS - 2) + 1;

        rowIt = board.begin();
        std::advance(rowIt, x);
        colIt = rowIt->begin();
        std::advance(colIt, y);

        if (*colIt == DOT) {
            pacmanX = x;
            pacmanY = y;
            *colIt = PACMAN;
            break;
        }
    }
}


void Game::play(char move) {
    if (gameStatus != ONGOING) return;

    int newX = pacmanX, newY = pacmanY;

    if (move == 'w') newX--;
    else if (move == 's') newX++;
    else if (move == 'a') newY--;
    else if (move == 'd') newY++;
    else return;

    if (newX < 0 || newX >= ROWS || newY < 0 || newY >= COLS) return;

    rowIt = board.begin();
    std::advance(rowIt, newX);
    colIt = rowIt->begin();
    std::advance(colIt, newY);

    if (*colIt == WALL) return;
    if (*colIt == GHOST) {
        gameStatus = GAME_OVER;
        return;
    }

    if (*colIt == DOT) {
        score++;
        if (score == 6) gameStatus = PLAYER_WINS;
    }

    rowIt = board.begin();
    std::advance(rowIt, pacmanX);
    colIt = rowIt->begin();
    std::advance(colIt, pacmanY);
    *colIt = EMPTY;

    pacmanX = newX;
    pacmanY = newY;

    rowIt = board.begin();
    std::advance(rowIt, pacmanX);
    colIt = rowIt->begin();
    std::advance(colIt, pacmanY);
    *colIt = PACMAN;
}


Status Game::status() const {
    return gameStatus;
}


std::ostream& operator<<(std::ostream& os, const Game& game) {
    for (auto row = game.board.begin(); row != game.board.end(); ++row) {
        for (auto col = row->begin(); col != row->end(); ++col) {
            if (*col == WALL) os << "# ";
            else if (*col == EMPTY) os << "  ";
            else if (*col == PACMAN) os << "P ";
            else if (*col == DOT) os << ". ";
            else if (*col == GHOST) os << "G ";
        }
        os << "\n";
    }
    return os;
}







