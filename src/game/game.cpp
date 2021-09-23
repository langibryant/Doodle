#include "game.hpp"

namespace herbglitch {
    Game::Game(ge::Data *data): ge::Object(data){
        spritesheet = ge::resource::spritesheet(data->renderer, SPRITE_SHEET);

        uiHandler = new ui::Handler(data);
        entityHandler = new entities::Handler(data, spritesheet, uiHandler);

        grid = new ge::resource::Sprite(spritesheet, DEFAULT_GRID, { 0, 0 });
        grid->setScale(SCALE);

        offset.x = -(grid->getPos().w - ((data->windowSize.w % grid->getPos().w) / 2));
        offset.y = -(grid->getPos().h - ((data->windowSize.h % grid->getPos().h) / 2));

        loopSize.x = (data->windowSize.w / grid->getPos().w) + 2;
        loopSize.y = (data->windowSize.h / grid->getPos().h) + 2;
    }

    Game::~Game(){
        // SDL_DestroyTexture(spritesheet); //TODO: Figure out if this causes a memory leak
        delete uiHandler;
        delete entityHandler;
        delete grid;
    }

    void Game::update(){
        uiHandler->update();
        entityHandler->update();
    }

    void Game::render(){
        background();
        uiHandler->render();
        // entityHandler->render();
    }

    void Game::background(){
        SDL_Rect gridPos = grid->getPos();

        for(unsigned int x = 0; x < loopSize.x; x++){
            for(unsigned int y = 0; y < loopSize.y; y++){
                gridPos.x = (x * gridPos.w) + offset.x;
                gridPos.y = (y * gridPos.h) + offset.y;

                SDL_RenderCopy(data->renderer, spritesheet, &grid->getBounds(), &gridPos);
            }
        }
    }
}