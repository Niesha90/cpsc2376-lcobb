#include "pacman.h"
#include <iostream>

int main() {
    Game game;
    char move;

    std::cout << "PAC-MAN Game! Use W, A, S, D to move.\n";
    std::cout << "Controls:\n";
    std::cout << "  W = Move Up\n";
    std::cout << "  A = Move Left\n";
    std::cout << "  S = Move Down\n";
    std::cout << "  D = Move Right\n\n";

    while (game.status() == ONGOING) {
        std::cout << game;  
        std::cout << "Enter move (W/A/S/D): ";
        std::cin >> move;

        
        move = std::tolower(move);

        
        if (move != 'w' && move != 'a' && move != 's' && move != 'd') {
            std::cout << "Invalid move! Please enter W, A, S, or D.\n";
            continue;
        }

        game.play(move);  
    }

    
    std::cout << game;
    if (game.status() == PLAYER_WINS) {
        std::cout << "Congratulations! You collected all the dots!\n";
    }
    else {
        std::cout << "Game Over! You were caught by a ghost.\n";
    }

    return 0;
}
