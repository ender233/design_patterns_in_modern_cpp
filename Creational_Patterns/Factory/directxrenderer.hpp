//
// Created by ender on 1/25/18.
//

#ifndef FACTORY_DIRECTXRENDERER_HPP
#define FACTORY_DIRECTXRENDERER_HPP

#include "renderer.hpp"
#include <iostream>

class DirectxRenderer : public IRenderer
{
    virtual ~DirectxRenderer() {}
    virtual void whoIam() {
        std::cout<<"i am DirecxRender"<<std::endl;
    }
};

#endif //FACTORY_DIRECTXRENDERER_HPP
