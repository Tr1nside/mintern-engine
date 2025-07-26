#pragma once

#include <graphics/render/renderer2d.h>
#include <graphics/render/renderable2d.h>

namespace mintern
{
namespace graphics
{

	
class Layer
{
   protected:
    Renderer2D* m_Renderer;
    std::vector<Renderable2D*> m_Renderables;
    Shader* m_Shader;
    math::Mat4 m_ProjectionMatrix;
    Layer(Renderer2D* renderer, Shader* shader, math::Mat4 projectionMatrix);

   public:
    virtual ~Layer();
    virtual void add(Renderable2D* renderable);
    virtual void render();
};


}  // namespace graphics
}  // namespace mintern
