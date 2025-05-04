#define SDL_MAIN_HANDLED
#include <SDL2/SDL.h>
#include <iostream>
#include "pacman.h"

int main(int, char* []) {
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        std::cerr << "SDL_Init Error: " << SDL_GetError() << "\n";
        return 1;
    }

    const int WIDTH = Game::COLS * Game::CELL_SIZE;  // 700
    const int HEIGHT = Game::ROWS * Game::CELL_SIZE;  // 500

    SDL_Window* window = SDL_CreateWindow(
        "PAC-MAN SDL2",  // ASCII hyphen U+002D
        SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
        WIDTH, HEIGHT,
        SDL_WINDOW_SHOWN
    );
    if (!window) {
        std::cerr << "SDL_CreateWindow Error: " << SDL_GetError() << "\n";
        SDL_Quit();
        return 1;
    }

    SDL_Renderer* renderer = SDL_CreateRenderer(
        window, -1, SDL_RENDERER_ACCELERATED
    );
    if (!renderer) {
        std::cerr << "SDL_CreateRenderer Error: " << SDL_GetError() << "\n";
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }

    Game game;
    bool running = true;
    SDL_Event e;

    while (running) {
        // Input
        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_QUIT)
                running = false;
            else if (e.type == SDL_KEYDOWN) {
                char m = '\0';
                if (e.key.keysym.sym == SDLK_w) m = 'w';
                else if (e.key.keysym.sym == SDLK_s) m = 's';
                else if (e.key.keysym.sym == SDLK_a) m = 'a';
                else if (e.key.keysym.sym == SDLK_d) m = 'd';
                else if (e.key.keysym.sym == SDLK_r) {
                    game = Game();  // replay
                    continue;
                }
                if (m) game.play(m);
            }
        }

        // Render
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);

        game.draw(renderer);

        // Overlay green on win, red on loss
        if (game.status() != ONGOING) {
            SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);
            if (game.status() == PLAYER_WINS)
                SDL_SetRenderDrawColor(renderer, 0, 255, 0, 150);
            else
                SDL_SetRenderDrawColor(renderer, 255, 0, 0, 150);
            SDL_Rect ov{ 0, 0, WIDTH, HEIGHT };
            SDL_RenderFillRect(renderer, &ov);
        }

        SDL_RenderPresent(renderer);
        SDL_Delay(16);  // ~60 FPS
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}








