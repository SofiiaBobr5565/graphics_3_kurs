#include "GLWindow.h"
#include "GLRenderSystem.h"
#include <iostream>

using namespace BBS;
using namespace BBS::GraphCore;

int main() {
    std::cout << "Task 2\n";
    std::cout << "Author: The student of the faculty of Applied Mathematics Bobrovytska Sofiia Serhiivna\n";

    if (!glfwInit()) {
        std::cerr << "GLFW init failed\n";
        return -1;
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 2); 
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);

    GLWindow* win1 = new GLWindow("Window 1 - Points", 400, 400);
    GLWindow* win2 = new GLWindow("Window 2 - Triangle", 400, 400);
    GLWindow* win3 = new GLWindow("Window 3 - Circle", 400, 400);

    win1->makeCurrent();
    if (glewInit() != GLEW_OK) {
        std::cerr << "GLEW init failed\n";
        return -1;
    }

    GLRenderSystem* renderer1 = new GLRendererPoints();
    GLRenderSystem* renderer2 = new GLRendererOld2_1();
    GLRenderSystem* renderer3 = new GLRendererCircle();

    win1->makeCurrent(); renderer1->init();
    win2->makeCurrent(); renderer2->init();
    win3->makeCurrent(); renderer3->init();

    while (
        !glfwWindowShouldClose(win1->getGLFWHandle()) &&
        !glfwWindowShouldClose(win2->getGLFWHandle()) &&
        !glfwWindowShouldClose(win3->getGLFWHandle())) {

        win1->makeCurrent(); renderer1->render(win1->getGLFWHandle()); glfwSwapBuffers(win1->getGLFWHandle());
        win2->makeCurrent(); renderer2->render(win2->getGLFWHandle()); glfwSwapBuffers(win2->getGLFWHandle());
        win3->makeCurrent(); renderer3->render(win3->getGLFWHandle()); glfwSwapBuffers(win3->getGLFWHandle());

        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}
