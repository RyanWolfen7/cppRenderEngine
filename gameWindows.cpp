#include <iostream>
#include <csignal>
#include <thread>
#include <chrono>
#include <signal.h>
#include "board.h"
#include "actor.h"

void signalHandler(int signum) {
	std::cout << "Interrupt signal (" << signum << ") received.\n";
	// Cleanup and close up stuff here
	// Terminate program
	exit(1);
}
