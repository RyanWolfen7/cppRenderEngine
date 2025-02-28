#ifndef BOARD_H
#define BOARD_H

#include <string>
#include <array>
#include <vector>
#include "actor.h"

class Board {
private:
	mutable std::string board;
	mutable std::string buffer;
	mutable std::vector<Actor*> actors;
	int columns;
	int rows;

	// Helper function
	void generateBoard();
	void updateBuffer() const;
public:
	// Constructor
	Board(int columns, int rows);

	// Destructor
	~Board() = default;

	// Render
	void render() const;

	// Setters
	void setChar(int x, int y, char c);
	void setActor(Actor* actor);

	// Getters
	std::string getBoard() const;
};

#endif // BOARD_H