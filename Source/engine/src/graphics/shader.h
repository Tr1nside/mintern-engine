#pragma once

#include <GL/glew.h>
#include <utils/fileutils.h>

#include <math/maths.h>
#include <iostream>
#include <vector>

namespace mintern
{
namespace graphics
{

class Shader
{
   private:
    const char *m_VertPath, *m_FragPath;

    GLuint load();

   public:
    GLuint m_ShaderID;
    Shader(const char* vertPath, const char* fragPath);
    ~Shader();

    void enable() const;
    void disable() const;

    GLint getUniformLocation(const GLchar* name);

    void setUniform1f(const GLchar* name, float value);
    void setUniform1i(const GLchar* name, int value);
    void setUniform2f(const GLchar* name, const math::Vec2& vector);
    void setUniform3f(const GLchar* name, const math::Vec3& vector);
    void setUniform4f(const GLchar* name, const math::Vec4& vector);
    void setUniformMat4(const GLchar* name, const math::Mat4& matrix);
};

}  // namespace graphics
}  // namespace mintern