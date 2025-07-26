#pragma once

#include <graphics/render/renderer2d.h>

namespace mintern
{
namespace graphics
{


class Sprite : public Renderable2D
{
   private:
   public:
    Sprite(
        float x,
        float y,
        float width,
        float height,
        const math::Vec4& color);


};


}  // namespace graphics
}  // namespace mintern