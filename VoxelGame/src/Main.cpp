#include "Application.h"

#include <GLFW/glfw3.h>

void error_callback( int error, const char* description );
static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);

int main(void) {
    GLFWwindow* window;

    /* Initialize the library */
    if (!glfwInit())
        return -1;

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(1080, 720, "Voxel Game", NULL, NULL);
    if (!window) {
        glfwTerminate();
        return -1;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);

    glfwSetErrorCallback(error_callback);

    glfwSetKeyCallback(window, key_callback);

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window)) {
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();

        auto app = MoonDragon::Application();
        std::cout << "Hello, world!";
    }

    glfwTerminate();

    return 0;
}

void error_callback( int error, const char* description ){
    std::cout << stderr << "Error: %s\n" << description << std::endl;
}

static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods){
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GLFW_TRUE);
}