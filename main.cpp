#include "Game.h"

/*
<summary>
Entry point of the program. Main should only be used for initializatoin and running of Game as well
as getting any values that need to be set to const on initialization.
</summary>
*/
int main() {
	Game game;
	game.Setup();
	game.Run();
	return 0;
}