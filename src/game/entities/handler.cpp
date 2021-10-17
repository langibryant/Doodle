#include "handler.hpp"

namespace satisfactoryTool {
    namespace entities {
        Handler::Handler(ge::Data *data, SDL_Texture *spritesheet, ui::Handler *uiHandler): data(data), uiHandler(uiHandler){
        }

        Handler::~Handler(){}

        void Handler::update(){
        }

        void Handler::checkSlect(){
        }
    }
}