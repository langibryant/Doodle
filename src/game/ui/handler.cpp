#include "handler.hpp"

namespace herbglitch {
    namespace ui {
        Handler::Handler(ge::Data *data): data(data){}
        Handler::~Handler(){}

        void Handler::update(){}

        void Handler::render(){}
    }
}