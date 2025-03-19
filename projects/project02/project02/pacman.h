#ifndef PACMAN_H
#define PACMAN_H

#include <vector>
#include <iostream>

// Game status
enum Status { ONGOING, PLAYER_WINS, GAME_OVER };

// Board elements
enum Cell { EMPTY, WALL, PACMAN, DOT, GHOST };

class Game {
private:
    std::vector<std::vector<Cell>> board;
    std::vector<std::vector<Cell>>::iterator rowIt;
    std::vector<Cell>::iterator colIt;

    int pacmanX, pacmanY;
    int score;
    Status gameStatus;

    void placeGhosts();
    void placePacman();

public:
    Game();
    void play(char move);
    Status status() const;
    void display() const;
    friend std::ostream& operator<<(std::ostream& os, const Game& game);
};

#endif