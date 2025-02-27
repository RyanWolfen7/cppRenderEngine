#ifndef BOARD_H
#define BOARD_H

#include <string>

class Board {
private:
	std::string board;
	mutable std::string updatedboard; // Cache of updated state
	int columns;
	int rows;

	// Helper function
	void generateBoard();
public:
	// Constructor
	Board(int columns, int rows);

	// Destructor
	~Board() = default;

	// Render
	void render() const;

	// Setters
	void setChar(int x, int y, char c);

	// Getters
	std::string getBoard() const;
};

#endif // BOARD_H