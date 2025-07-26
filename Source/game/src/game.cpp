#include <game.h>

#define BATCH_RENDERER 1


int main()
{
    using namespace mintern;
    using namespace graphics;
    using namespace input;
    using namespace math;

    Window window("Mintern", 1920, 1080);
    // glClearColor(1.0f, 1.0f, 1.0f, 1.0f);

    InputSystem input(window.getNativeWindow());


    Mat4 ortho = Mat4::orthographic(0.0f, 16.0f, 0.0f, 9.0f, -1.0f, 1.0f);



    Shader* s = new Shader(
        "../../../Source/engine/src/shaders/basic.vert",
        "../../../Source/engine/src/shaders/basic.frag");
    Shader* s2 = new Shader(
        "../../../Source/engine/src/shaders/basic.vert",
        "../../../Source/engine/src/shaders/basic.frag");
    Shader& shader = *s;
    Shader& shader2 = *s2;
    
    shader.enable();
    shader2.enable();
    shader.setUniform2f("light_pos", Vec2(2.0f, 2.0f));
    shader2.setUniform2f("light_pos", Vec2(2.0f, 2.0f));


    TileLayer layer(&shader);
    for (float y = -9.0f; y < 9.0f; y += 0.1)
    {
        for (float x = -16.0f; x < 16.0f; x += 0.1)
        {
            layer.add(new Sprite(x, y, 0.08f, 0.08f, Vec4(rand() % 1000 / 1000.0f, rand() % 1000 / 1000.0f, 1, 1)));
        }
    }
    
    TileLayer layer2(&shader2);
    layer2.add(new Sprite(-2, -2, 4, 4, Vec4(1, 0, 1, 1)));

    Timer time;
    float timer = 0;
    unsigned int frames = 0;
    float t = 0;

    while (!window.closed())
    {   
        window.clear();

        // light shader on mouse position
        double x, y;
        input.getMousePosition(x, y);
        shader.enable();
        shader.setUniform2f(
            "light_pos",
            Vec2(
                (float)(x * 32.0f / 1920.0f - 16.0f),
                (float)(9.0f - y * 18.0f / 1080.0f)));
        shader2.enable();
        shader2.setUniform2f(
            "light_pos",
            Vec2(
                (float)(x * 32.0f / 1920.0f - 16.0f),
                (float)(9.0f - y * 18.0f / 1080.0f)));

        layer.render();
        layer2.render();

        window.update();
        
        frames++;
        if (time.elapsed() - timer > 1.0f)
        {
            timer += 1.0f;
            printf("%d fps\n", frames);
            frames = 0;
        }
    }

    glfwTerminate();
    return 0;
}
