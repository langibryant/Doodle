#pragma once
#include <ge.hpp>
#include "../game/game.hpp"


namespace doodle {
    class Menu : public ge::Object {
        public:
            Menu();
            ~Menu();

            void update();
            void render();
        
        private:
            SDL_Texture *menusheet;
            
            ge::Sprite *button;

    };
}