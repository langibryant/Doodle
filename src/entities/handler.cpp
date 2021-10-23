#include "handler.hpp"

namespace satisfactoryTool {
    namespace entities {
        Handler::Handler(SDL_Texture *spritesheet, ui::Handler *uiHandler): uiHandler(uiHandler){
        }

        Handler::~Handler(){}

        void Handler::update(){
        }

        void Handler::checkSlect(){
        }
    }
}