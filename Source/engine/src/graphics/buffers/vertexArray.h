#pragma once

#include <GL/glew.h>

#include <vector>

#include <graphics/buffers/buffer.h>

namespace mintern
{
namespace graphics
{

class VertexArray
{
   private:
    GLuint m_ArrayID;
    std::vector<Buffer*> m_Buffers;

   public:
    VertexArray();
    ~VertexArray();

    void addBuffer(Buffer* buffer, GLuint index);
    void bind() const;
    void unbind() const;
};

}  // namespace graphics
}  // namespace mintern