#include <State.hpp>
#include <Math.hpp>

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

void State::createEnemy()
{
    Vector2f startPos((rand() % (WINDOW_WIDTH - (ENEMY_SCALE * 8))), -(rand() % WINDOW_HEIGHT));
    Enemy e(startPos, spriteSheetTexture);
    enemies.push_back(e);
}

void State::update()
{
    player->update();

    int laserPos = 0;
    for (Laser &laser : lasers)
    {
        if (laser.shouldBeRemoved())
        {
            lasers.erase(lasers.begin() + laserPos);
            std::cout << "Laser removed" << std::endl;
        }
        else
        {
            laser.update();

            for (Enemy &enemy : enemies)
            {
                if (checkCollision(laser.getPosRect(), enemy.getPosRect()))
                {
                    std::cout << rand() % 1000 << " Collision detected" << std::endl;
                }
            }
        }
        laserPos++;
    }

    int enemyPos = 0;
    for (Enemy &enemy : enemies)
    {
        if (enemy.shouldBeRemoved())
        {
            enemies.erase(enemies.begin() + enemyPos);
            std::cout << "Enemy removed" << std::endl;
        }
        else
        {
            enemy.update();
        }
        enemyPos++;
    }
}

void State::render()
{
    window->render(player, PLAYER_SCALE, PLAYER_SCALE);

    for (Laser laser : lasers)
    {
        window->render(&laser, 5, 5);
    }

    for (Enemy enemy : enemies)
    {
        window->render(&enemy, ENEMY_SCALE, ENEMY_SCALE);
    }
}

State::~State()
{
    SDL_DestroyTexture(spriteSheetTexture);
    delete player;
    delete window;
    std::cout << "Terminated" << std::endl;
}