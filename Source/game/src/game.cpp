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
        if (inputSystem.isKeyPressed(GLFW_KEY_A)) {
            std::cout << "PRESSED!" << std::endl;
        }
        
        
        
        auto a = -0.5f;
        auto b = -0.5f;
        auto c = 0.5f;
        auto d = 0.5f;
        
        window.clear();
        glBegin(GL_QUADS);
        glVertex2f(a, b);
        glVertex2f(b, c);
        glVertex2f(c, d);
        glVertex2f(d, a);
        glEnd();
        window.update();
    }

    glfwTerminate();
    return 0;
}
