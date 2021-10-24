#pragma once
#include <ge.hpp>
#include <stdlib.h>
#include <time.h>
#include "../platform/platform.hpp"
#include "../player/player.hpp"

namespace doodle {
    class Handler : public ge::Handler<Platform> {
        public:
            Handler();
            ~Handler();

            void update();
            void render();

            void Collision();

            void MoveScreen();

            void CleanPlatforms();
            void CreatePlatform(int y = -1);

        private:
            Player player;

            SDL_Rect platformBounds;

            SDL_Texture *gamesheet;

            int scale;
    };
}