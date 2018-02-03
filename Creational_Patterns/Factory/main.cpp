#include <iostream>
#include "renderer.hpp"
#include "rendererfactory.hpp"

class MesaRenderer : public IRenderer
{
public:
    virtual ~MesaRenderer() { }
    void whoIam() override {
        std::cout<<"i am MesaRender"<<std::endl;
    }
    static IRenderer *create() {return new MesaRenderer();}
};

int main() {
    RendererFactory fac;
    IRenderer *r = fac.CreateRenderer("opengl");
    r->whoIam();

    // callback Factory
    RendererFactory::RegisterRender("meas", MesaRenderer::create);
    IRenderer *r2 = RendererFactory::createRenderer("meas");
    r2->whoIam();
    return 0;
}
