#include <GLFW/glfw3.h>
#include <game.h>
#include <input.h>
#include <window.h>

int main() {
    using namespace mintern;
    using namespace graphics;
    using namespace input;
    Window window("Mintern", 1920, 1080);
    glClearColor(0.2f, 0.3f, 0.8f, 1.0f);

    InputSystem inputSystem(window.getNativeWindow());

    while (!window.closed()) {
        window.clear();
        
        double x, y;
        inputSystem.getMousePosition(x, y);
        std::cout << x << ", " << y << std::endl;
        
        glBegin(GL_QUADS);
        glVertex2f(-0.5f, -0.5f);
        glVertex2f(-0.5f, 0.5f);
        glVertex2f(0.5f, 0.5f);
        glVertex2f(0.5f, -0.5f);
        glEnd();
        window.update();
    }

    glfwTerminate();
    return 0;
}
