#pragma once
#include <GLFW/glfw3.h>

namespace mintern {
namespace input {

#define MAX_KEYS 1024
#define MAX_BUTTONS 32

class InputSystem {
   public:
    InputSystem(GLFWwindow* window);
    bool isKeyPressed(unsigned int keyCode) const;
    bool isMouseButtonPressed(unsigned int buttonCode) const;
    void getMousePosition(double& x, double& y) const;


    static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods); 
    static void mouse_button_callback(GLFWwindow* window, int button, int action, int mods);
    static void cursor_position_callback(GLFWwindow* window, double xpos, double ypos);
   
   private:
    GLFWwindow* m_Window;
    bool init();
    static bool m_Keys[MAX_KEYS];
    static bool m_MouseButtons[MAX_BUTTONS];
    static double m_X, m_Y;

};
}  // namespace input
}  // namespace mintern