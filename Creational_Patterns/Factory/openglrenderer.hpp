//
// Created by ender on 1/25/18.
//

#ifndef FACTORY_OPENGLRENDERER_HPP
#define FACTORY_OPENGLRENDERER_HPP

#include "openglrenderer.hpp"
#include "renderer.hpp"
#include <iostream>

class OpenglRenderer : public IRenderer
{
    virtual ~OpenglRenderer() {}
    virtual void whoIam() {
        std::cout<<"i am Opengl"<<std::endl;
    }
};

#endif //FACTORY_OPENGLRENDERER_HPP
