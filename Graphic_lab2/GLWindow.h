#pragma once
#define GLEW_STATIC
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <string>
#include <stdexcept>

namespace BBS {
    class GLWindow {
    public:
        GLWindow(const std::string& title, uint32_t width, uint32_t height) {
            _handle = glfwCreateWindow(width, height, title.c_str(), nullptr, nullptr);
            if (!_handle) {
                glfwTerminate();
                throw std::runtime_error("Не вдалося створити вікно GLFW");
            }
        }

        ~GLWindow() {
            glfwSetWindowShouldClose(_handle, true);
        }

        GLFWwindow* getGLFWHandle() const {
            return _handle;
        }

        void makeCurrent() {
            glfwMakeContextCurrent(_handle);
        }

    private:
        GLFWwindow* _handle;
    };
}
