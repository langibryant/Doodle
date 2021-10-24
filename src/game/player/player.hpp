#pragma once
#include <ge.hpp>

namespace doodle {
    class Player {
        public:
            Player();
            Player(SDL_Texture *playersheet, SDL_Rect &playerBounds, int x, int y, int scale);
            ~Player();

            void update();
            void render();

            void Landed();

            ge::Sprite *operator->() { return player; }

            bool getJumping() { return acc < 0 && jumping; }

            float getAcc() { return acc; }

            void setPause(bool pause){ this->pause = pause; }

            bool getPause() { return pause; }

        private:
            ge::Sprite *player;

            float acc;

            float gravity;

            bool jumping;

            bool pause;
    };
}