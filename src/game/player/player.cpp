#include "player.hpp"
#include "../../over/over.hpp"


namespace doodle {
    Player::Player(){ }
    Player::Player(SDL_Texture *playersheet, SDL_Rect &playerBounds, int x, int y, int scale): acc(0.0f), gravity(0.002f), jumping(false), pause(false) {
        player = new ge::Sprite(playersheet, playerBounds, x, y);
        player->setScale(scale);
    }

    Player::~Player(){}

    void Player::update() {
        if(player->getPos().y >= ge::data->windowSize.h){
            ge::data->state.add(new Over(), true);
        }
        if(ge::data->keyboard[SDLK_a] == ge::Keyboard::State::PRESSED) {
            player->move(-1.0f * ge::data->dt, 0.0f);
        }
        if(ge::data->keyboard[SDLK_d] == ge::Keyboard::State::PRESSED) {
            player->move(1.0f * ge::data->dt, 0.0f);
        }
        if(jumping) {
            acc -= gravity * ge::data->dt;
            if(acc <= -10.0f){
                acc = -10.0f;
            }
            if(!pause) {
                player->move(0.0f, -1.0f * acc * ge::data->dt);
            }
        }
        if(!jumping) {
            acc = 1.0f;
            jumping = true;
        }
    }

    void Player::render() {
        player->draw();
    }

    void Player::Landed() {
        jumping = false;
    }

}