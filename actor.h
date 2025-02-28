#ifndef ACTOR_H
#define ACTOR_H

#include <array>

class Board;

class Actor {
private:
    int coords[2];
    int prevCoords[2];
    char symbol;
    Board* board;
public:
    Actor(Board* board, int x, int y, char symbol);
    ~Actor() = default;

    // Getters
    std::array<int, 2> getCoords() const;
    char getSymbol() const;

    // Setters
    void setCoords(int x, int y);

    // Listeners
    void listenForInput();
};

#endif // ACTOR_H