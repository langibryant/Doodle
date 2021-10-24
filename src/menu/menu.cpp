#include "menu.hpp"

namespace doodle {
    Menu::Menu() {
        ge::data->config.load("./res/config/defaults.config");
        ge::data->config.setGroup("");

        SDL_Rect playBounds;
        int scale;

        ge::data->config.get(GE_VAR_STR(menusheet));
        ge::data->config.get(GE_VAR_STR(playBounds));
        ge::data->config.get(GE_VAR_STR(scale));

        button = new ge::Sprite(menusheet, playBounds, ge::data->windowSize.w / 2 - (playBounds.w * scale / 2), 200 );
        button->setScale(scale);
    }

    Menu::~Menu() {

    }

    void Menu::update() {
        if(ge::data->mouse[SDL_BUTTON_LEFT] == ge::Mouse::RELEASED){
            if(button->collides(ge::data->mouse.x, ge::data->mouse.y)) {
                ge::data->state.add(new doodle::Game(), true);
            }
        }
    }

    void Menu::render() {

        button->draw();

    }
}