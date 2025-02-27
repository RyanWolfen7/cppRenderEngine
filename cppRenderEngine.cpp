#include <iostream>
#include <csignal>
#include <thread>
#include <chrono>
#include <signal.h>
#include "board.h"

void signalHandler(int signum) {
	std::cout << "Interrupt signal (" << signum << ") received.\n";
	// Cleanup and close up stuff here
	// Terminate program
	exit(1);
}

int main()
{
    std::cout << "Hello World!\n";
	signal(SIGINT, signalHandler);
	std::cout << "Press Ctrl+E to terminate the program...\n";
	Board board(10, 10);
	board.setChar(5, 5, '@');
	while (true)
	{
		board.render();


		// Pause for a short duration to achieve 30 FPS (1000ms / 30 = ~33ms per frame)
		std::this_thread::sleep_for(std::chrono::milliseconds(6000));
	}
	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
