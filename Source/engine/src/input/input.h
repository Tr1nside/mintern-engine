#pragma once
#include <GLFW/glfw3.h>

namespace mintern {
namespace input {

#define MAX_KEYS 1024
#define MAX_BUTTONS 32

class InputSystem {
   public:
    InputSystem(GLFWwindow* window);
    void update();
    bool isKeyJustPressed(int glfwKeyCode);
    static bool isKeyPressed(unsigned int keyCode);
    static void key_callback(
        GLFWwindow* window,
        int key,
        int scancode,
        int action,
        int mods);

   private:
    GLFWwindow* m_Window;
    bool init();
    static bool m_Keys[MAX_KEYS];
    static bool m_MouseButtons[MAX_BUTTONS];
    static double m_X, m_Y;

};
}  // namespace input
}  // namespace mintern