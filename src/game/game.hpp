#pragma once
#include <ge.hpp>
#include "ui/handler.hpp"
#include "entities/handler.hpp"

namespace satisfactoryTool {
    class Game : public ge::Object {
    public:
        Game(ge::Data *data);
        ~Game();

        void update();
        void render();

    private:
        void background();

        SDL_Texture *spritesheet;

        ui::Handler *uiHandler;
        entities::Handler *entityHandler;

        ge::resource::Sprite *grid;

        SDL_Point offset;
        SDL_Point loopSize;
    };
}