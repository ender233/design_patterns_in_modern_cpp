//
// Created by ender on 1/25/18.
//

#ifndef FACTORY_RENDERERFACTORY_HPP
#define FACTORY_RENDERERFACTORY_HPP

#include "renderer.hpp"
#include "openglrenderer.hpp"
#include "directxrenderer.hpp"
#include <boost/function.hpp>
#include <map>
#include <string>

class RendererFactory
{
public:
    // traditional
    IRenderer * CreateRenderer(const std::string &type);

    // callback
    typedef  boost::function<IRenderer *()> FuncReg;
    static std::map<std::string, FuncReg> mRenders_;

    static void RegisterRender(const std::string &type, FuncReg cb);
    static void UnregisterRender(const std::string &type);
    static IRenderer* createRenderer(const std::string &type);
};

#endif //FACTORY_RENDERERFACTORY_HPP
