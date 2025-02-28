#include <iostream>
#include <conio.h>
#include "board.h"
#include "actor.h"

Actor::Actor(Board* board, int x = 0, int y = 0, char symbol = '@') : board(board), coords{x, y}, prevCoords{ x, y }, symbol(symbol) {};


// Setters
void Actor::setCoords(int x, int y) {
    // Check if the target position is walkable
    if (!board->isWalkable(x, y)) {
        return;
    }

    // Update previous coordinates
    prevCoords[0] = coords[0];
    prevCoords[1] = coords[1];

    // Set new coordinates
    coords[0] = x;
    coords[1] = y;

    // Clear the previous position on the board
    board->setChar(prevCoords[0], prevCoords[1], ' ');

    // Notify the board to render the updated position
    board->render();
}

// Listeners
void Actor::listenForInput() {
    if (_kbhit()) {
        char key = _getch();
        switch (key) {
        case 'w':
            setCoords(coords[0], coords[1] - 1);
            break;
        case 'a':
            setCoords(coords[0] - 1, coords[1]);
            break;
        case 's':
            setCoords(coords[0], coords[1] + 1);
            break;
        case 'd':
            setCoords(coords[0] + 1, coords[1]);
            break;
        }
    }
}

// Getters
std::array<int, 2> Actor::getCoords() const {
    return { coords[0], coords[1] };
}

char Actor::getSymbol() const {
    return symbol;
}