#pragma once
#include <ge.hpp>
#include "../DEFINITIONS.hpp"
#include "ui/handler.hpp"
#include "entities/handler.hpp"

namespace herbglitch {
    class Game : public ge::Object {
    public:
        Game(ge::Data *data);
        ~Game();

        void update();
        void render();

    private:
        SDL_Texture *spritesheet;

        ui::Handler *uiHandler;
        entities::Handler *entityHandler;
    };
}