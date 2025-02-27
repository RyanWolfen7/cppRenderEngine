#include <iostream>
#include "board.h"

Board::Board(int columns, int rows) : columns(columns), rows(rows), board(columns * rows, ' ') {
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
}

void Board::render() const {
    for (int i = 0; i < columns * rows; ++i) {
        std::cout << board[i];
        if ((i + 1) % columns == 0) {
            std::cout << "\n";
        }
    }
}

void Board::setChar(int x, int y, char ch) {
    board[y * x] = ch;
}

std::string Board::getBoard() const {
    return board;
}