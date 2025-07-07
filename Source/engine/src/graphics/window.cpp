#include <window.h>
#include <input.h>
using namespace mintern::input;

namespace mintern {
namespace graphics {
void windowResize(GLFWwindow* window, int width, int height);

Window::Window(const char* title, int width, int height) {
    m_Title = title;
    m_Width = width;
    m_Height = height;
    if (!init()) {
        glfwTerminate();
    }
}
Window::~Window() {
    glfwTerminate();
}

bool Window::init() {
    if (!glfwInit()) {
        std::cout << "Failed to init GLFW!" << std::endl;
        return false;
    }

    m_Window = glfwCreateWindow(m_Width, m_Height, m_Title, NULL, NULL);
    if (!m_Window) {
        glfwTerminate();
        std::cout << "Filed to create GLFW window!" << std::endl;
        return false;
    }
    glfwMakeContextCurrent(m_Window);
    glfwSetWindowUserPointer(m_Window, this);
    glfwSetWindowSizeCallback(m_Window, windowResize);
    glfwSetKeyCallback(m_Window, InputSystem::key_callback);

    return true;
}

bool Window::closed() const {
    return glfwWindowShouldClose(m_Window);
}

void Window::clear() const {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void Window::update() {
    glfwPollEvents();
    // glfwGetFramebufferSize(m_Window, &m_Width, &m_Height);
    glfwSwapBuffers(m_Window);
}

void windowResize(GLFWwindow* window, int width, int height) {
    glViewport(0, 0, width, height);
}

}  // namespace graphics
}  // namespace mintern
