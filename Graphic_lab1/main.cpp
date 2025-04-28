#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include <windows.h>
#include <conio.h> 
#include <locale.h>
#include <cmath>                                       // ��� ������� sin
#include <string>
#include <vector>

// OpenGL
#define GLUT_DISABLE_ATEXIT_HACK
#define PI 3.14159265                                  // ����� ��
//#define GLFW_DLL
#define GLEW_STATIC

#include <GL/glew.h>
#include <GLFW/glfw3.h>


using namespace std;

namespace print_lib
{
	template <typename T>
	void print(T i, string endline = "\n") {
		cout << i << endline;
	}

	void argsEcho(int argc, char** argv) {
		print("____ARGS____");
		if (argc == 0) {
			print("NO ARGS");
		}
		else {
			for (int i = 0; i < argc; i++) {
				if (i != argc - 1) {
					cout << i + 1 << ") ";
					print(argv[i], ";\n");
				}
				else {
					cout << i + 1 << ") ";
					print(argv[i], ".\n");
				}
			}
		}
		print("____________\n");
	}
}
using namespace print_lib;

// It will print the version of OpenGL supported by your GPU
void getOpenGLVerison() {
	std::cout << "OpenGL 1.1: " << ((GLEW_VERSION_1_1 != 0) ? "Available" : "Unavailable") << std::endl;
	std::cout << "OpenGL 1.2: " << ((GLEW_VERSION_1_2 != 0) ? "Available" : "Unavailable") << std::endl;
	std::cout << "OpenGL 1.3: " << ((GLEW_VERSION_1_3 != 0) ? "Available" : "Unavailable") << std::endl;
	std::cout << "OpenGL 1.4: " << ((GLEW_VERSION_1_4 != 0) ? "Available" : "Unavailable") << std::endl;
	std::cout << "OpenGL 1.5: " << ((GLEW_VERSION_1_5 != 0) ? "Available" : "Unavailable") << std::endl;
	std::cout << "OpenGL 2.0: " << ((GLEW_VERSION_2_0 != 0) ? "Available" : "Unavailable") << std::endl;
	std::cout << "OpenGL 2.1: " << ((GLEW_VERSION_2_1 != 0) ? "Available" : "Unavailable") << std::endl;

	std::cout << "OpenGL 3.0: " << ((GLEW_VERSION_3_0 != 0) ? "Available" : "Unavailable") << std::endl;
	std::cout << "OpenGL 3.1: " << ((GLEW_VERSION_3_1 != 0) ? "Available" : "Unavailable") << std::endl;
	std::cout << "OpenGL 3.2: " << ((GLEW_VERSION_3_2 != 0) ? "Available" : "Unavailable") << std::endl;
	std::cout << "OpenGL 3.3: " << ((GLEW_VERSION_3_3 != 0) ? "Available" : "Unavailable") << std::endl;

	std::cout << "OpenGL 4.0: " << ((GLEW_VERSION_4_0 != 0) ? "Available" : "Unavailable") << std::endl;
	std::cout << "OpenGL 4.1: " << ((GLEW_VERSION_4_1 != 0) ? "Available" : "Unavailable") << std::endl;
	std::cout << "OpenGL 4.2: " << ((GLEW_VERSION_4_3 != 0) ? "Available" : "Unavailable") << std::endl;
	std::cout << "OpenGL 4.3: " << ((GLEW_VERSION_4_3 != 0) ? "Available" : "Unavailable") << std::endl;
	std::cout << "OpenGL 4.4: " << ((GLEW_VERSION_4_4 != 0) ? "Available" : "Unavailable") << std::endl;
	std::cout << "OpenGL 4.5: " << ((GLEW_VERSION_4_5 != 0) ? "Available" : "Unavailable") << std::endl;
	std::cout << "OpenGL 4.6: " << ((GLEW_VERSION_4_6 != 0) ? "Available" : "Unavailable") << std::endl;
}

/*
* The main part of the code
*/
int main(int argc, char** argv) {
	argsEcho(argc, argv);
	print("Hello OpenGL");
	//println("It is me", "Mario", 12.34, PI, 's', mySuperStructure());

	if (!glfwInit())
	{
		// ������ ��� ������������� GLFW
		fprintf(stderr, "GLFW - Initialization error\n");
		return -1;
	}
	glfwWindowHint(GLFW_SAMPLES, 4); // 4x Anti-Aliasing - ����������� 4x
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3); // �� ����� ������������ OpenGL 3.3
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // To make MacOS happy; should not be necessary

	// ������� ���� � ������� � ��� �������� OpenGL
	GLFWwindow* window; // (� ���������������� �������� ���� ��� ���������� �������� ����������)
	window = glfwCreateWindow(640, 480, "Lesson 01 - RAINBOW - (Harry James Potter/Hermione Jean Granger)", NULL, NULL);

	if (window == NULL) {
		fprintf(stderr, "It is not possible to open the window GLFW. If you have Intel GPU, then it does not support the OpenGL 3.3. Try OpenGL 2.1.\n");
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);

	// �������������� GLEW
	glewExperimental = true; // ���� ��������� � Core-������ OpenGL
	if (glewInit() != GLEW_OK) {
		fprintf(stderr, "Unable to initialize GLEW\n");
		return -1;
	}

	getOpenGLVerison();

	// ������� ����� ������������ ������� ������, ��� �������� ����
	glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);

	float colorRGB = 0.0;
	// ��������� ������� ������� Escape ��� �������� ����
	while (glfwGetKey(window, GLFW_KEY_ESCAPE) != GLFW_PRESS &&
		glfwWindowShouldClose(window) == 0)
	{
		glClearColor(sin(colorRGB * PI / 180), abs(cos(colorRGB * PI / 180)), abs(sin(colorRGB * PI / 180) + cos(colorRGB * PI / 180)), 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
		// ���������� ������
		glfwSwapBuffers(window);
		glfwPollEvents();

		{
			colorRGB <= 180 ? colorRGB += 0.1 : colorRGB = 0;
		}
	}

	glfwTerminate();
	system("pause");
	return 0;
}