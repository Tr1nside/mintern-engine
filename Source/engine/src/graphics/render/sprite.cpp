#include <graphics/render/sprite.h>

namespace mintern
{
namespace graphics
{


Sprite::Sprite(
float x,
float y,
float width,
float height,
const math::Vec4& color)
    : Renderable2D(math::Vec3(x, y, 0), math::Vec2(width, height), color)
{
	 
}


}  // namespace graphics
}  // namespace mintern