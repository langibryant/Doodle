#include "handler.hpp"
#include <iostream>

namespace doodle {
    Handler::Handler() {
        srand(time(NULL));

        SDL_Texture *playersheet;
        SDL_Rect playerBounds;

        ge::data->config.get(GE_VAR_STR(playersheet));
        ge::data->config.get(GE_VAR_STR(gamesheet));
        ge::data->config.get(GE_VAR_STR(platformBounds));
        ge::data->config.get(GE_VAR_STR(playerBounds));
        ge::data->config.get(GE_VAR_STR(scale));

        player = Player(
            playersheet, 
            playerBounds, 
            ge::data->windowSize.w / 2 - (playerBounds.w * scale / 2), 
            ge::data->windowSize.h - playerBounds.h * scale * 2, 
            scale
        );

        add(new Platform(
            gamesheet,
            platformBounds,
            ge::data->windowSize.w / 2 - (playerBounds.w * scale / 2), 
            ge::data->windowSize.h - playerBounds.h * scale,
            scale
        ));
        for(unsigned int i = 1; i <= ((ge::data->windowSize.h - playerBounds.h * scale) / platformBounds.h) / 4; i++) {
            CreatePlatform((ge::data->windowSize.h - playerBounds.h * scale) - (4 * platformBounds.h * i));
        }

    }

    Handler::~Handler() {

    }

    void Handler::update() {
        CleanPlatforms();
        Collision();
        MoveScreen();
        updateHandler<Platform>();
        player.update();
    }

    void Handler::render() {
        renderHandler<Platform>();
        player.render();
    }

    void Handler::Collision() {
        SDL_Rect bounds = { player->getPos().x + (player->getBounds().w / 4), player->getPos().y + player->getPos().h - 1, 3 * (player->getPos().w / 4), 1 };
        for(Platform *platform : hTypes) {
            if(player.getJumping() && (*platform)->collides(bounds)) {
                player.Landed();
                return;
            }
        }
    }

    void Handler::MoveScreen() {
        float acc = player.getAcc() * ge::data->dt;
        if(player->getPos().y <= ge::data->windowSize.h / 2 && acc > 0) {
            if(!player.getPause()) {
                player.setPause(true);
            }
            for(Platform *platform : hTypes) {
                (*platform)->move(0.0f, acc);
            }
        }
        else {
            player.setPause(false);
        }
    }

    void Handler::CleanPlatforms() {
        for(Platform *platform : hTypes) {
            if((*platform)->getPos().y > ge::data->windowSize.h) {
                remove(platform);
                CreatePlatform();
            }
        }
    }

    void Handler::CreatePlatform(int y) {
        int platY = (y == -1) ? -1 * platformBounds.h : y;
        int xCenter = ((rand() % (ge::data->windowSize.w - (ge::data->windowSize.w / 90) - platformBounds.w)) + ge::data->windowSize.w / 95);
        add(new Platform(gamesheet, platformBounds, xCenter - (platformBounds.w * scale / 2),  y, scale));
    }
}