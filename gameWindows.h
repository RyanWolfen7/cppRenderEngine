#ifndef H_GAME_WINDOWS
#define H_GAME_WINDOWS

class Board;

class GameWindows {
private:
	Board* board;
public:
	GameWindows(Board* board);
	~GameWindows() = default;
	void render() const;
	void setBoard(Board* board);
};
#endif // H_GAME_WINDOWS
