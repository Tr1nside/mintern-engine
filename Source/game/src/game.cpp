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


    Shader shader(
        "../../../Source/engine/src/shaders/basic.vert",
        "../../../Source/engine/src/shaders/basic.frag");
    shader.enable();
    shader.setUniformMat4("pr_matrix", ortho);

    std::vector<Renderable2D*> sprites;


    for (float y = 0; y < 9.0f; y+=0.05f)
    {
        for (float j = 0; j < 16.0f; j+=0.05f)
        {
            sprites.push_back(new 
#if BATCH_RENDERER                
                Sprite
#else
                StaticSprite
#endif
                (j, y, 0.04f, 0.04f, Vec4(rand() % 1000 / 1000.f, rand() % 1000 / 1000.f, 1, 1)
#if !BATCH_RENDERER  
                , shader
#endif
                    ));
        }
    }

#if BATCH_RENDERER
    BatchRenderer2D renderer;
#else
    Simple2DRenderer renderer;
#endif

    shader.setUniform2f("light_pos", Vec2(2.0f, 2.0f));
    shader.setUniform4f("colour", Vec4(0.2f, 0.3f, 0.8f, 1.0f));


    Timer time;
    float timer = 0;
    unsigned int frames = 0;
    float t = 0;

    while (!window.closed())
    {

        Mat4 mat = Mat4::translation(Vec3(5, 5, 5));
        mat = mat * Mat4::rotation(time.elapsed() * 100.0f, Vec3(0,0,1));
        mat = mat * Mat4::translation(Vec3(-5, -5, -5));

        shader.setUniformMat4("ml_matrix", mat);
        
        window.clear();

        // light shader on mouse position
        double x, y;
        input.getMousePosition(x, y);

        shader.setUniform2f(
            "light_pos",
            Vec2(
                (float)(x * 16.0f / 1920.0f),
                (float)(9.0f - y * 9.0f / 1080.0f)));


        // render
#if BATCH_RENDERER
        renderer.begin();
#endif
        for (int i = 0; i < sprites.size(); i++)
        {
            renderer.submit(sprites[i]);
        }
#if BATCH_RENDERER
        renderer.end();
#endif

        renderer.flush();
        window.update();
        
        frames++;
        if (time.elapsed() - timer > 1.0f)
        {
            timer += 1.0f;
            printf("%d fps\n", frames);
            frames = 0;
        }
        //printf("%f ms\n", timer.elapsed() * 1000.0);
    }

    glfwTerminate();
    return 0;
}
