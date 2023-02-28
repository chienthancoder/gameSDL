#include "Game.h"

Game* game = NULL;
int main(int argc, char* argv[]) {
	game = new Game();
	game->init("Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 640, 0);
	while (game->running()) {
		game->update();
		game->HandleEvent();
		game->render();
		SDL_Delay(15);
	}
	game->clean();
	return 0;
}