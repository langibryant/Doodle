#include "app.hpp"

GE_MAIN(satisfactoryTool::App, 1920, 1080, "Satisfactory Tools");

namespace satisfactoryTool {
    App::App(ge::Data *data): ge::Object(data){
        data->config.load("./res/config/defaults.config");
        data->config.setGroup("");

        uiHandler = new ui::Handler(data);
        entityHandler = new entities::Handler(data, spritesheet, uiHandler);

        SDL_Rect gridBounds;
        int scale;

        data->config.get(GE_VAR_STR(spritesheet));
        data->config.get(GE_VAR_STR(gridBounds));
        data->config.get(GE_VAR_STR(scale));

        grid = new ge::Sprite(spritesheet, gridBounds, { 0, 0 });
        grid->setScale(scale);

        offset.x = -(grid->getPos().w - ((data->windowSize.w % grid->getPos().w) / 2));
        offset.y = -(grid->getPos().h - ((data->windowSize.h % grid->getPos().h) / 2));

        loopSize.x = (data->windowSize.w / grid->getPos().w) + 2;
        loopSize.y = (data->windowSize.h / grid->getPos().h) + 2;
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

                SDL_RenderCopy(data->renderer, spritesheet, &grid->getBounds(), &gridPos);
            }
        }
    }
}