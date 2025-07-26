#pragma once

#include <graphics/render/renderer2d.h>
#include <graphics/render/staticSprite.h>
#include <deque>

namespace mintern
{
namespace graphics
{

class Simple2DRenderer : public Renderer2D
{
   private:
    std::deque<const StaticSprite*> m_RenderQueue;

   public:
    void submit(const Renderable2D* renderable) override;
    void flush() override;
};

}  // namespace graphics
}  // namespace minter
