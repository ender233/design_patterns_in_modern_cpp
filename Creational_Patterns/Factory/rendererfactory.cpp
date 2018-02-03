//
// Created by ender on 1/25/18.
//

#include "renderer.hpp"
#include "rendererfactory.hpp"
#include <string>

std::map<std::string, RendererFactory::FuncReg> RendererFactory::mRenders_;

IRenderer *RendererFactory::CreateRenderer(const std::string &type) {
    if(type == "opengl"){
        return new OpenglRenderer();
    }
    if(type == "directx") {
        return new DirectxRenderer();
    }
    return NULL;
}

void RendererFactory::RegisterRender(const std::string &type, FuncReg cb)
{
    mRenders_[type] = cb;
}

void RendererFactory::UnregisterRender(const std::string &type) {
    mRenders_.erase(type);
}

IRenderer* RendererFactory::createRenderer(const std::string &type) {
    auto itr = mRenders_.find(type);
    return (itr!=mRenders_.end()) ? (itr->second)() : NULL;
}
