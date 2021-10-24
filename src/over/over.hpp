#pragma once
#include <ge.hpp>
#include "../game/game.hpp"


namespace doodle {
    class Over : public ge::Object {
        public:
            Over();
            ~Over();

            void update();
            void render();
        
        private:
            SDL_Texture *menusheet;

            ge::Sprite *playButton;
            ge::Sprite *gameOver;

    };
}