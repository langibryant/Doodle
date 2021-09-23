#include "game.hpp"

namespace herbglitch {
    Game::Game(ge::Data *data): ge::Object(data){
        spritesheet = ge::resource::spritesheet(data->renderer, SPRITE_SHEET);
        uiHandler = new ui::Handler(data);
        entityHandler = new entities::Handler(data, spritesheet, uiHandler);

        gridInit();
    }

    Game::~Game(){
        // SDL_DestroyTexture(spritesheet); //TODO: Figure out if this causes a memory leak
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

    void Game::gridInit(){
        grid = new ge::resource::Sprite(spritesheet, DEFAULT_GRID, { 0, 0 });
        grid->setScale(SCALE);

        // SDL_Texture 
    }

    void Game::background(){
        grid->draw(data->renderer);
    }
}