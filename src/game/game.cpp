#include "game.hpp"

namespace doodle {
    Game::Game() {

    }

    Game::~Game() {

    }

    void Game::update() {
        handler.update();
    }

    void Game::render() {
        handler.render();
    }
}