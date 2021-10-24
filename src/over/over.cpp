#include "over.hpp"

namespace doodle {
    Over::Over() {
        ge::data->config.load("./res/config/defaults.config");
        ge::data->config.setGroup("");

        SDL_Rect playBounds;
        SDL_Rect gameOverBounds;
        int scale;

        ge::data->config.get(GE_VAR_STR(menusheet));
        ge::data->config.get(GE_VAR_STR(playBounds));
        ge::data->config.get(GE_VAR_STR(gameOverBounds));
        ge::data->config.get(GE_VAR_STR(scale));

        playButton = new ge::Sprite(menusheet, playBounds, ge::data->windowSize.w / 2 - (playBounds.w * scale / 2), 400 );
        playButton->setScale(scale);

        gameOver = new ge::Sprite(menusheet, gameOverBounds, ge::data->windowSize.w / 2 - (gameOverBounds.w * scale / 2), 250 );
        gameOver->setScale(scale);
    }

    Over::~Over() {

    }

    void Over::update() {
        if(ge::data->mouse[SDL_BUTTON_LEFT] == ge::Mouse::RELEASED){
            if(playButton->collides(ge::data->mouse.x, ge::data->mouse.y)) {
                ge::data->state.add(new doodle::Game(), true);
            }
        }
    }

    void Over::render() {

        playButton->draw();
        gameOver->draw();

    }
}