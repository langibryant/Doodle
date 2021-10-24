#pragma once
#include <ge.hpp>

namespace doodle {
    class Platform : public ge::Object {
        public:
            Platform(SDL_Texture *gamesheet, SDL_Rect &platformBounds, int x, int y, int scale);
            ~Platform();

            void update();
            void render();

            bool moving;

            ge::Sprite *operator->() {
                return platform;
            }

        private:
            ge::Sprite *platform;
    };
}