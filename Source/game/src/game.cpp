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

    for (float y = 0; y < 9.0f; y+=0.5f)
    {
        for (float j = 0; j < 16.0f; j+=0.5f)
        {
            sprites.push_back(new 
#if BATCH_RENDERER                
                Sprite
#else
                StaticSprite
#endif
                (j, y, 0.4f, 0.4f, Vec4(rand() % 1000 / 1000.f, rand() % 1000 / 1000.f, 1, 1)
#if !BATCH_RENDERER  
                , shader
#endif
                    ));
        }
    }

    
#if BATCH_RENDERER
    
    Sprite sprite(5, 5, 4, 4, Vec4(1, 0, 1, 1));
    Sprite sprite2(10, 1, 2, 3, Vec4(0.2f, 0, 1, 1));
    BatchRenderer2D renderer;


#else
    
    StaticSprite sprite(5, 5, 4, 4, Vec4(1, 0, 1, 1), shader);
    StaticSprite sprite2(10, 1, 2, 3, Vec4(0.2f, 0, 1, 1), shader);
    Simple2DRenderer renderer;

#endif

    shader.setUniform2f("light_pos", Vec2(2.0f, 2.0f));
    shader.setUniform4f("colour", Vec4(0.2f, 0.3f, 0.8f, 1.0f));

    float speed = 5.0f;
    double lastTime = glfwGetTime();

    while (!window.closed())
    {
        window.clear();

        double currentTime = glfwGetTime();
        float deltaTime = static_cast<float>(currentTime - lastTime);
        lastTime = currentTime;

        double x, y;
        input.getMousePosition(x, y);

        shader.setUniform2f(
            "light_pos",
            Vec2(
                (float)(x * 16.0f / 1920.0f),
                (float)(9.0f - y * 9.0f / 1080.0f)));
        
        if (input.isKeyPressed(GLFW_KEY_D))
        {
            std::cout << "D PRESSED" << std::endl;
            Vec3 currentPosition = sprite.getPosition();
            currentPosition.x += speed * deltaTime;
            sprite.setPosition(currentPosition);
        } else if (input.isKeyPressed(GLFW_KEY_A))
        {
            std::cout << "A PRESSED" << std::endl;
            Vec3 currentPosition = sprite.getPosition();
            currentPosition.x -= speed * deltaTime;
            sprite.setPosition(currentPosition);
        } else if (input.isKeyPressed(GLFW_KEY_W))
        {
            std::cout << "W PRESSED" << std::endl;
            Vec3 currentPosition = sprite.getPosition();
            currentPosition.y += speed * deltaTime;
            sprite.setPosition(currentPosition);
        } else if (input.isKeyPressed(GLFW_KEY_S))
        {
            std::cout << "S PRESSED" << std::endl;
            Vec3 currentPosition = sprite.getPosition();
            currentPosition.y -= speed * deltaTime;
            sprite.setPosition(currentPosition);
        }
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
        printf("Sprites %d\n", sprites.size());
        window.update();
    }

    glfwTerminate();
    return 0;
}
