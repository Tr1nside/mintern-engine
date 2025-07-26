#pragma once

#include <graphics/buffers/buffer.h>
#include <graphics/buffers/indexBuffer.h>
#include <graphics/buffers/vertexArray.h>

#include <math/maths.h>
#include <graphics/shader.h>

namespace mintern
{
namespace graphics
{

struct VertexData
{
    math::Vec3 vertex;
    //math::Vec4 color;
    unsigned int color;
};

class Renderable2D
{
   protected:
    math::Vec3 m_Position;
    math::Vec2 m_Size;
    math::Vec4 m_Color;

   public:
    Renderable2D(
        math::Vec3 position,
        math::Vec2 size,
        math::Vec4 color)
        : m_Position(position), m_Size(size), m_Color(color)
    {
        
    }

    virtual ~Renderable2D() { }


    inline const math::Vec3& getPosition() const
    {
        return m_Position;
    }
    inline const math::Vec2& getSize() const
    {
        return m_Size;
    }
    inline const math::Vec4& getColor() const
    {
        return m_Color;
    }


    inline void setPosition(const math::Vec3& position)
    {
        m_Position = position;
    }
};

}  // namespace graphics
}  // namespace mintern