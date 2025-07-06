#include <game.h>
#include <GLFW/glfw3.h>


int main() {
    if (!glfwInit) {
        std::cout << "Glfw dont init(" << std::endl;
        return 1;
    }
    
    std::cout << "Start game." << std::endl;
    return 0;
}
