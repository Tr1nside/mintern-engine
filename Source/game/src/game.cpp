#include <game.h>

int main() {
    using namespace mintern;
    using namespace graphics;
    using namespace input;
    using namespace math;

    // std::string file = read_file("../../../LICENSE");
    // std::cout << file << std::endl;
    // std::cin.get();
    // return 0;

    Window window("Mintern", 1920, 1080);
    glClearColor(0.2f, 0.3f, 0.8f, 1.0f);

    GLuint vao;
    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);

    InputSystem inputSystem(window.getNativeWindow());

    Vec3 vector1(1.0f, 2.0f, 4.0f);
    Vec3 vector2(1.0f, 2.0f, 4.0f);

    vector1 -= vector2;

    Mat4 position = Mat4::translation(Vec3(2, 3, 4));

    Vec4 column = position.columns[1];
    std::cout << column << std::endl;

    while (!window.closed()) {
        window.clear();

#if 0
        glBegin(GL_QUADS);
        glVertex2f(-0.5f, -0.5f);
        glVertex2f(-0.5f, 0.5f);
        glVertex2f(0.5f, 0.5f);
        glVertex2f(0.5f, -0.5f);
        glEnd();
#else
        glDrawArrays(GL_ARRAY_BUFFER, 0, 6);
#endif
        window.update();
    }

    glfwTerminate();
    return 0;
}
