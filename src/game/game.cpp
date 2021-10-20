#include "game.hpp"

namespace satisfactoryTool {
    Game::Game(ge::Data *data): ge::Object(data){
        data->config.load("./res/config/defaults.config");
        data->config.setGroup("");

        uiHandler = new ui::Handler(data);
        entityHandler = new entities::Handler(data, spritesheet, uiHandler);

        SDL_Rect gridBounds;
        int scale;

        data->config.ge_var(spritesheet);
        data->config.ge_var(gridBounds);
        data->config.ge_var(scale);

        grid = new ge::resource::Sprite(spritesheet, gridBounds, { 0, 0 });
        grid->setScale(scale);

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