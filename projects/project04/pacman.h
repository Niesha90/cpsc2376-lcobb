#ifndef PACMAN_H
#define PACMAN_H

#include <vector>
#include <SDL2/SDL.h>


// Game status
enum Status { ONGOING, PLAYER_WINS, GAME_OVER };
// Cell types
enum Cell { EMPTY, WALL, PACMAN, DOT, GHOST };

class Game {
public:
    static const int ROWS = 5;
    static const int COLS = 7;
    static const int CELL_SIZE = 100;

    Game();
    // Move Pac‑Man: 'w','a','s','d'
    void play(char move);
    // Current game status
    Status status() const;
    // Draw the board into an SDL_Renderer
    void draw(SDL_Renderer* renderer) const;
    // Reset to a new game
    void reset();

private:
    static const int NUM_GHOSTS = 2;

    std::vector<std::vector<Cell>> board;
    int pacmanX, pacmanY;
    int score, totalDots;
    Status gameStatus;

    void countDots();
    void placeGhosts();
    void placePacman();
};

#endif // PACMAN_H


