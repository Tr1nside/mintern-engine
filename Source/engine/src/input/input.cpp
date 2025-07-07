#include <input.h>
#include <window.h>
using namespace mintern::graphics;

namespace mintern {
namespace input {

bool InputSystem::m_Keys[MAX_KEYS];
bool InputSystem::m_MouseButtons[MAX_BUTTONS];
double InputSystem::m_X;
double InputSystem::m_Y;

InputSystem::InputSystem(GLFWwindow* window) {
    m_Window = window;

    for (int i = 0; i < MAX_KEYS; i++) {
        m_Keys[i] = false;
    }
    for (int i = 0; i < MAX_BUTTONS; i++) {
        m_MouseButtons[i] = false;
    }
}

bool InputSystem::isKeyPressed(unsigned int keyCode) {
    // TODO: log in if
    if (keyCode >= MAX_KEYS) {
        return false;
    }
    return m_Keys[keyCode];
}

void InputSystem::key_callback(
    GLFWwindow* window,
    int key,
    int scancode,
    int action,
    int mods) {
    Window* win = (Window*)glfwGetWindowUserPointer(window);
    m_Keys[key] = action != GLFW_RELEASE;
}

}  // namespace input
}  // namespace mintern