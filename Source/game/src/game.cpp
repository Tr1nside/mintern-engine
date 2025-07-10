#include <GLFW/glfw3.h>
#include <game.h>
#include <input.h>
#include <window.h>
#include <maths.h>

int main() {
    using namespace mintern;
    using namespace graphics;
    using namespace input;
    using namespace math;

    Window window("Mintern", 1920, 1080);
    glClearColor(0.2f, 0.3f, 0.8f, 1.0f);

    InputSystem inputSystem(window.getNativeWindow());

    Vec3 vector1(1.0f, 2.0f, 4.0f);
    Vec3 vector2(1.0f, 2.0f, 4.0f);

    vector1 -= vector2;


    Mat4 position = Mat4::translation(Vec3(2, 3, 4));

    while (!window.closed()) {
        window.clear();
        std::cout << vector1 << std::endl;

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
