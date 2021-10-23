#pragma once
#include <ge.hpp>
#include "ui/handler.hpp"
#include "entities/handler.hpp"

namespace satisfactoryTool {
    class App : public ge::Object {
    public:
        App();
        ~App();

        void update();
        void render();

    private:
        void background();

        SDL_Texture *spritesheet;

        ui::Handler *uiHandler;
        entities::Handler *entityHandler;

        ge::Sprite *grid;

        SDL_Point offset;
        SDL_Point loopSize;
    };
}