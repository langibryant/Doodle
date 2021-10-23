#pragma once

// #include "entity.hpp"
#include "../ui/handler.hpp"

namespace satisfactoryTool {
    namespace entities {
        class Handler {
        public:
            Handler(SDL_Texture *spritesheet, ui::Handler *uiHandler);
            ~Handler();

            void update();

        private:
            void checkSlect();

            ui::Handler *uiHandler;
        };
    }
}