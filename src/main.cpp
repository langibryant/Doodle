#include <ge.hpp>
#include "game/game.hpp"

int main(int argc, char *argv[]){
    ge::Data *data = new ge::Data();

    ge::Run<herbglitch::Game>(data, 1920, 1080, "Satisfactory Tools");

    delete data;

    return 0;
} 