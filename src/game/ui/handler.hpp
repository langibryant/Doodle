#pragma once

#include <ge.hpp>

namespace herbglitch {
    namespace ui {
        class Handler {
        public:
            Handler(ge::Data *data);
            ~Handler();

            void update();
            void render();

        private:
            ge::Data *data;
        };
    }
}