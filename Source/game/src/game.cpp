#include <game.h>

int main()
{
    using namespace mintern;
    using namespace graphics;
    using namespace input;
    using namespace math;

    Window window("Mintern", 1920, 1080);
    //glClearColor(1.0f, 1.0f, 1.0f, 1.0f);

    GLfloat vertices[] = 
    {
        -2, -1, 0,
        1, 3, 0,
        2, -1, 0,
        2, -1, 0,
        1, 3, 0,
        4, 3, 0
    };

    GLuint vbo;

    glGenBuffers(1, &vbo);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
    glEnableVertexAttribArray(0);

    Mat4 ortho = Mat4::orthographic(0.0f, 16.0f, 0.0f, 9.0f, -1.0f, 1.0f);

    Shader shader(
        "../../../Source/engine/src/shaders/basic.vert",
        "../../../Source/engine/src/shaders/basic.frag");
    shader.enable();
    shader.setUniformMat4("pr_matrix", ortho);
    shader.setUniformMat4("ml_matrix", Mat4::translation(Vec3(4, 3, 0)));

    shader.setUniform2f("light_pos", Vec2(2.0f, 2.0f));
    shader.setUniform4f("colour", Vec4(0.2f, 0.3f, 0.8f, 1.0f));

    while (!window.closed())
    {
        window.clear();
        glDrawArrays(GL_TRIANGLES, 0, 6);
        window.update();
    }

    glfwTerminate();
    return 0;
}
