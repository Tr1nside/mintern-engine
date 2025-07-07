#pragma once

#include <GLFW/glfw3.h>

#include <iostream>

namespace mintern {
namespace graphics {
class Window {
   private:
    const char* m_Title;
    int m_Width, m_Height;
    GLFWwindow* m_Window;

    bool init();

   public:
    Window(const char* title, int width, int height);
    ~Window();
    bool closed() const;
    void update();
    void clear() const;

    inline GLFWwindow* getNativeWindow() {
        return m_Window;
    }
    inline int getWidth() const {
        return m_Width;
    }
    inline int getHeight() const {
        return m_Height;
    }
};
}  // namespace graphics
}  // namespace mintern
