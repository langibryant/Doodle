#include "platform.hpp"

namespace doodle {

    Platform::Platform(SDL_Texture *gamesheet, SDL_Rect &platformBounds, int x, int y, int scale): moving(false) {
        platform = new ge::Sprite(gamesheet, platformBounds, x, y );
        platform->setScale(scale);
    }

    Platform::~Platform(){}

    void Platform::update() {
        if(moving) {
            platform->move(0.0f, 1.0f * ge::data->dt);
        }
    }

    void Platform::render() {
        platform->draw();
    }

}