// STL
#include <iostream>
#include <vector>

// OpenGL
#include <GL/glew.h>
#include <glm/glm.hpp>
#include <GLFW/glfw3.h>

// Engine
#include <Window.hpp>

int main(int argv, char **argc) {
	
	// GLFW initialization
	Engine::Window::Initialize();
	Engine::Window window(800, 600, "OpenGL_Practice");
	window.Viewport(0, 0, 800, 600);
	while (!window.Closed()) {
		window.SwapBuffers();
		glfwPollEvents();
	}
	Engine::Window::Terminate();
	return 0;
}