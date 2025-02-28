#include <iostream>
#include "board.h"

Board::Board(int columns, int rows) : columns(columns), rows(rows), board(columns * rows, ' '), buffer(columns* rows, ' ') {
    generateBoard();
}

void Board::generateBoard() {
    for (int i = 0; i < columns * rows; ++i) {
        int column = i % columns;
        int row = i / columns;
        if (row == 0 || row == rows - 1 || column == 0 || column == columns - 1) {
            board[i] = '#';
        }
        else {
            board[i] = ' ';
        }
    }
    buffer = board;
}

void Board::updateBuffer() const {
    buffer = board; // Reset the buffer to the initial board state

    for (const auto& actor : actors) {
        int x = actor->getCoords()[0];
        int y = actor->getCoords()[1];
        buffer[y * columns + x] = actor->getSymbol();
    }
}

void Board::render() const {
    std::string previousBuffer = buffer;
    updateBuffer();

    // Check if there are changes
    if (previousBuffer != buffer) {
        #ifdef _WIN32
                system("cls");
        #else
                system("clear");
        #endif // _WIN32

        for (int i = 0; i < columns * rows; ++i) {
            std::cout << buffer[i];
            if ((i + 1) % columns == 0) {
                std::cout << "\n";
            }
        }
    }
}

void Board::setChar(int x, int y, char ch) {
    board[y * columns + x] = ch;
}

void Board::setActor(Actor* actor) {
    actors.push_back(actor);
}

std::string Board::getBoard() const {
    return board;
}