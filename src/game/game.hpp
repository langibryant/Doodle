#pragma once
#include <ge.hpp>
#include "handler/handler.hpp"

namespace doodle {
    class Game : public ge::Object {
        public:
            Game();
            ~Game();

            void update();
            void render();

        private:
            Handler handler;
    };
}