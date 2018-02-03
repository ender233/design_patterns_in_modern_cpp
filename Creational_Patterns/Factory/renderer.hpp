//
// Created by ender on 1/25/18.
//

#ifndef FACTORY_RENDERER_HPP
#define FACTORY_RENDERER_HPP

class IRenderer
{
public:
    virtual ~IRenderer() {}
    virtual void whoIam() = 0;
};

#endif //FACTORY_RENDERER_HPP
