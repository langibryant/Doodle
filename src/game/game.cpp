#include "game.hpp"

namespace herbglitch {
    Game::Game(ge::Data *data): ge::Object(data){
        spritesheet = ge::resource::spritesheet(data->renderer, MAIN_GRID);
        uiHandler = new ui::Handler(data);
        entityHandler = new entities::Handler(data, spritesheet, uiHandler);
    }

    Game::~Game(){
        SDL_DestroyTexture(spritesheet);
    }

    void Game::update(){
        uiHandler->update();
        entityHandler->update();
    }

    void Game::render(){
        uiHandler->render();
        // entityHandler->render();
    }
}