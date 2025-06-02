#pragma once
#define GLEW_STATIC
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <cmath>

#define PI 3.14159265358979323846

namespace BBS {
    namespace GraphCore {

        class GLRenderSystem {
        public:
            virtual ~GLRenderSystem() = default;
            virtual void init() = 0;
            virtual void render(GLFWwindow* window) = 0;
        };

        // Window 1: Точки 
        class GLRendererPoints : public GLRenderSystem {
            GLuint vao = 0, vbo = 0;

        public:
            void init() override {
                GLfloat points[] = {
                    -0.5f, -0.5f, 0.0f,
                     0.0f,  0.5f, 0.0f,
                     0.5f, -0.5f, 0.0f
                };

                glGenVertexArrays(1, &vao);
                glBindVertexArray(vao);

                glGenBuffers(1, &vbo);
                glBindBuffer(GL_ARRAY_BUFFER, vbo);
                glBufferData(GL_ARRAY_BUFFER, sizeof(points), points, GL_STATIC_DRAW);

                glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, nullptr);
                glEnableVertexAttribArray(0);

                glPointSize(10.0f);
            }

            void render(GLFWwindow* window) override {
                glClearColor(0.05f, 0.05f, 0.1f, 1.0f);
                glClear(GL_COLOR_BUFFER_BIT);

                glBindVertexArray(vao);
                glDrawArrays(GL_POINTS, 0, 3);
            }

            ~GLRendererPoints() {
                glDeleteBuffers(1, &vbo);
                glDeleteVertexArrays(1, &vao);
            }
        };

        // Window 2: Трикутник 
        class GLRendererOld2_1 : public GLRenderSystem {
            float colorRGB = 0;

        public:
            void init() override {
                glEnable(GL_DEPTH_TEST);
            }

            void render(GLFWwindow* window) override {
                glClearColor(
                    std::sin(colorRGB * PI / 180),
                    std::abs(std::cos(colorRGB * PI / 180)),
                    std::abs(std::sin(colorRGB * PI / 180) + std::cos(colorRGB * PI / 180)),
                    1.0f
                );
                glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

                if (colorRGB <= 360)
                    colorRGB += 0.5f;
                else
                    colorRGB = 0;

                glLoadIdentity();
                glRotatef((float)glfwGetTime() * 50.f, 0.f, 0.f, 1.f);

                glBegin(GL_TRIANGLES);
                glColor3f(1.f, 0.f, 0.f);
                glVertex3f(-0.6f, -0.4f, 0.f);
                glColor3f(0.f, 1.f, 0.f);
                glVertex3f(0.6f, -0.4f, 0.f);
                glColor3f(0.f, 0.f, 1.f);
                glVertex3f(0.f, 0.6f, 0.f);
                glEnd();
            }
        };

        // Window 3: Круг 
        class GLRendererCircle : public GLRenderSystem {
            float x = 0.0f, y = 0.0f;
            float dx = 0.003f, dy = 0.0025f;
            const float radius = 0.1f;

        public:
            void init() override {
                glEnable(GL_BLEND);
                glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
            }

            void render(GLFWwindow* window) override {
                int width, height;
                glfwGetFramebufferSize(window, &width, &height);
                float aspect = (float)width / height;

                if ((x + radius > aspect) || (x - radius < -aspect)) dx = -dx;
                if ((y + radius > 1.0f) || (y - radius < -1.0f)) dy = -dy;

                x += dx;
                y += dy;

                glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
                glClear(GL_COLOR_BUFFER_BIT);

                glLoadIdentity();
                glTranslatef(x, y, 0.0f);

                glBegin(GL_TRIANGLE_FAN);
                glColor3f(1.0f, 1.0f, 0.0f);
                glVertex2f(0.0f, 0.0f);
                for (int i = 0; i <= 30; ++i) {
                    float angle = i * 2.0f * PI / 30;
                    glVertex2f(std::cos(angle) * radius, std::sin(angle) * radius);
                }
                glEnd();
            }
        };
    }
}
