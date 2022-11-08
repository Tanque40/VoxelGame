#include "Application.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

void error_callback( int error, const char* description );
static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);

int main(void) {
    GLFWwindow* window;

    /* Initialize the library */
    if (!glfwInit())
        return -1;
    unsigned int width = 1080, height = 720;
    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(width, height, "Voxel Game", NULL, NULL);
    if (!window) {
        glfwTerminate();
        return -1;
    }

    glfwSetErrorCallback(error_callback);

    glfwSetKeyCallback(window, key_callback);

    /* Make the window's context current */
    glfwMakeContextCurrent(window);
    gladLoadGL();
    glfwSwapInterval( 1 );

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window)) {
        /* Render here */

        glViewport( 0, 0, width, height );
        glClear(GL_COLOR_BUFFER_BIT);


        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();

        auto app = MoonDragon::Application();
        std::cout << "Hello, world!";
    }

    glfwDestroyWindow(window);

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