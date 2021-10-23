#pragma once

#include <ge.hpp>

namespace satisfactoryTool {
    namespace ui {
        class Handler {
        public:
            Handler();
            ~Handler();

            void update();
            void render();
        };
    }
}