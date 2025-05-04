#include "pacman.h"
#include <cstdlib>
#include <ctime>
#include <iterator>

Game::Game() {
    std::srand(static_cast<unsigned>(std::time(nullptr)));
    reset();
}

void Game::countDots() {
    totalDots = 0;
    for (auto& row : board)
        for (auto c : row)
            if (c == DOT) ++totalDots;
}

void Game::reset() {
    board.clear();
    // Fill grid with dots and walls on borders
    for (int i = 0; i < ROWS; ++i) {
        std::vector<Cell> row;
        for (int j = 0; j < COLS; ++j) {
            if (i == 0 || i == ROWS - 1 || j == 0 || j == COLS - 1)
                row.push_back(WALL);
            else if (i == 2 && j == 2) // example interior wall
                row.push_back(WALL);
            else
                row.push_back(DOT);
        }
        board.push_back(row);
    }

    score = 0;
    gameStatus = ONGOING;
    countDots();
    placeGhosts();
    placePacman();
}

void Game::placeGhosts() {
    int placed = 0;
    while (placed < NUM_GHOSTS) {
        int x = std::rand() % (ROWS - 2) + 1;
        int y = std::rand() % (COLS - 2) + 1;
        if (board[x][y] == DOT) {
            board[x][y] = GHOST;
            ++placed;
        }
    }
}

void Game::placePacman() {
    while (true) {
        int x = std::rand() % (ROWS - 2) + 1;
        int y = std::rand() % (COLS - 2) + 1;
        if (board[x][y] == DOT) {
            pacmanX = x;
            pacmanY = y;
            board[x][y] = PACMAN;
            break;
        }
    }
}

void Game::play(char move) {
    if (gameStatus != ONGOING) return;

    int dx = 0, dy = 0;
    if (move == 'w') dx = -1;
    else if (move == 's') dx = 1;
    else if (move == 'a') dy = -1;
    else if (move == 'd') dy = 1;

    int nx = pacmanX + dx, ny = pacmanY + dy;
    if (nx < 0 || nx >= ROWS || ny < 0 || ny >= COLS) return;

    Cell dest = board[nx][ny];
    if (dest == WALL)      return;
    if (dest == GHOST) { gameStatus = GAME_OVER; return; }
    if (dest == DOT && ++score == totalDots)
        gameStatus = PLAYER_WINS;

    board[pacmanX][pacmanY] = EMPTY;
    pacmanX = nx;
    pacmanY = ny;
    board[pacmanX][pacmanY] = PACMAN;
}

Status Game::status() const {
    return gameStatus;
}

void Game::draw(SDL_Renderer* ren) const {
    SDL_Rect rect;
    for (auto rowIt = board.begin(); rowIt != board.end(); ++rowIt) {
        int i = static_cast<int>(std::distance(board.begin(), rowIt));
        for (auto cellIt = rowIt->begin(); cellIt != rowIt->end(); ++cellIt) {
            int j = static_cast<int>(std::distance(rowIt->begin(), cellIt));
            rect.x = j * CELL_SIZE;
            rect.y = i * CELL_SIZE;
            rect.w = rect.h = CELL_SIZE;

            // Color by cell type
            if (*cellIt == WALL)   SDL_SetRenderDrawColor(ren, 0, 255, 0, 255);
            else if (*cellIt == EMPTY)  SDL_SetRenderDrawColor(ren, 0, 0, 0, 255);
            else if (*cellIt == DOT)    SDL_SetRenderDrawColor(ren, 255, 255, 255, 255);
            else if (*cellIt == PACMAN) SDL_SetRenderDrawColor(ren, 255, 255, 0, 255);
            else                         SDL_SetRenderDrawColor(ren, 0, 0, 0, 255);

            SDL_RenderFillRect(ren, &rect);

            // Small dot indicator
            if (*cellIt == DOT) {
                SDL_SetRenderDrawColor(ren, 200, 200, 200, 255);
                SDL_Rect d{ rect.x + CELL_SIZE / 4,
                           rect.y + CELL_SIZE / 4,
                           CELL_SIZE / 2, CELL_SIZE / 2 };
                SDL_RenderFillRect(ren, &d);
            }
        }
    }
}





