#pragma once

#include <ge.hpp>

namespace satisfactoryTool {
    class Entity : public ge::Object {
    public:
        Entity(): ge::Object(1), select(false){}
        virtual ~Entity(){ delete sprite; }

        virtual void update() = 0;
        virtual void render(){ sprite->draw(ge::data->renderer); }

        void setSelect(bool select = true){ this->select = select; }

        SDL_Rect &getPos(){ return sprite->getPos(); }

    protected:
        ge::Sprite *sprite;

        bool select;
    };
}