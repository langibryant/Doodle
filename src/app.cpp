#include "app.hpp"

GE_MAIN(satisfactoryTool::App, 1920, 1080, "Satisfactory Tools");

namespace satisfactoryTool {
    App::App(){
        ge::data->config.load("./res/config/defaults.config");
        ge::data->config.setGroup("");

        uiHandler = new ui::Handler();
        entityHandler = new entities::Handler(spritesheet, uiHandler);

        SDL_Rect gridBounds;
        int scale;

        ge::data->config.get(GE_VAR_STR(spritesheet));
        ge::data->config.get(GE_VAR_STR(gridBounds));
        ge::data->config.get(GE_VAR_STR(scale));

        grid = new ge::Sprite(spritesheet, gridBounds, { 0, 0 });
        grid->setScale(scale);

        offset.x = -(grid->getPos().w - ((ge::data->windowSize.w % grid->getPos().w) / 2));
        offset.y = -(grid->getPos().h - ((ge::data->windowSize.h % grid->getPos().h) / 2));

        loopSize.x = (ge::data->windowSize.w / grid->getPos().w) + 2;
        loopSize.y = (ge::data->windowSize.h / grid->getPos().h) + 2;
    }

    App::~App(){
        delete uiHandler;
        delete entityHandler;
        delete grid;
    }

    void App::update(){
        uiHandler->update();
        entityHandler->update();
    }

    void App::render(){
        background();
        uiHandler->render();
        // entityHandler->render();
    }

    void App::background(){
        SDL_Rect gridPos = grid->getPos();

        for(unsigned int x = 0; x < loopSize.x; x++){
            for(unsigned int y = 0; y < loopSize.y; y++){
                gridPos.x = (x * gridPos.w) + offset.x;
                gridPos.y = (y * gridPos.h) + offset.y;

                SDL_RenderCopy(ge::data->renderer, spritesheet, &grid->getBounds(), &gridPos);
            }
        }
    }
}