#include <iostream>
#include <GLFW/glfw3.h>
#include <outputConfig.h>

#include <unistd.h>

int main(int argc, const char *argv[]) {
    std::cout << argv[0] /*project name*/ << output_VERSION_MAJOR << "." << output_VERSION_MINOR << std::endl;
#ifdef USE_MYPRINT
    std::cout << "USE_MYPRINT" << std::endl;
    MyPrint::myprint();
#else
    char buf[10] = { 0 };
    getlogin_r(buf, 10);
    std::cout << "NOT USE_MYPRINT" << std::endl;
    std::cout << buf << std::endl;
#endif

    GLFWwindow *window;
    if(!glfwInit()) {
        fprintf(stderr, "Failed to initalize GLFW\n");
        exit(EXIT_FAILURE);
    }

    glfwWindowHint(GLFW_DEPTH_BITS, 16);
    glfwWindowHint(GLFW_TRANSPARENT_FRAMEBUFFER, GLFW_TRUE);

    window = glfwCreateWindow( 300, 300, "Gears", NULL, NULL );
    if (!window)
    {
        fprintf( stderr, "Failed to open GLFW window\n" );
        glfwTerminate();
        exit( EXIT_FAILURE );
    }
    // Main loop
    while( !glfwWindowShouldClose(window) )
    {
        // Swap buffers
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    // Terminate GLFW
    glfwTerminate();
    return 0;
}
