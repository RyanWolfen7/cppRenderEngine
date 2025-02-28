#ifndef ACTOR_H
#define ACTOR_H

#include <array>

class Actor {
private:
	int coords[2];
	char symbol;
public:
	Actor(int x = 0, int y = 0, char symbol = '@') : coords{ x, y }, symbol(symbol) {};
	~Actor() = default;

	// Getters
	std::array<int, 2> getCoords() const { return { coords[0], coords[1] }; };
	std::char_traits<char>::int_type getSymbol() const { return symbol; };

	// Setters
	void setCoords(int x, int y) {
		coords[0] = x;
		coords[1] = y;
	};

};

#endif // ACTOR_H