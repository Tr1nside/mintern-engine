#include <window.h>
#include <input.h>

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

bool InputSystem::isKeyPressed(unsigned int keyCode) const {
    // TODO: log in if
    if (keyCode >= MAX_KEYS) {
        return false;
    }
    return m_Keys[keyCode];
}

bool InputSystem::isMouseButtonPressed(unsigned int buttonCode) const {
    // TODO: log in if
    if (buttonCode >= MAX_BUTTONS) {
        return false;
    }
    return m_MouseButtons[buttonCode];
}

void InputSystem::getMousePosition(double& x, double& y) const {
    x = m_X;
    y = m_Y;
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

void InputSystem::mouse_button_callback(
    GLFWwindow* window,
    int button,
    int action,
    int mods) {
    Window* win = (Window*)glfwGetWindowUserPointer(window);
    m_MouseButtons[button] = action != GLFW_RELEASE;
}

void InputSystem::cursor_position_callback(
    GLFWwindow* window,
    double xpos,
    double ypos) {
    Window* win = (Window*)glfwGetWindowUserPointer(window);
    m_X = xpos;
    m_Y = ypos;
}

}  // namespace input
}  // namespace mintern