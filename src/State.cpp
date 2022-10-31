#include <State.hpp>

State::State() : gameRunning(true)
{
    window = new RenderWindow("Space Invaders", WINDOW_WIDTH, WINDOW_HEIGHT);

    SDL_Surface *spriteSheetSurface = IMG_Load("../res/sprites.png");
    spriteSheetTexture = SDL_CreateTextureFromSurface(window->getRenderer(), spriteSheetSurface);

    Vector2f startPos(0, 0);
    player = new Player(startPos, spriteSheetTexture);

    SDL_FreeSurface(spriteSheetSurface);
}

void State::createLaser()
{
    Vector2f startPos(player->getPos().x + (player->getCurrentFrame().w / 2), player->getPos().y - (6 * 5));
    Laser l(startPos, spriteSheetTexture);
    lasers.push_back(l);
}

State::~State()
{
    SDL_DestroyTexture(spriteSheetTexture);
    delete player;
    delete window;
    std::cout << "Terminated" << std::endl;
}