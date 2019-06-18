#include <Window.hpp>

using Engine::Window;

void Window::Initialize() {
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	glewInit();
}

void Window::Terminate() {
	glfwTerminate();
}

Window::Window() {
	monitor = glfwGetPrimaryMonitor();
	const GLFWvidmode *mode = glfwGetVideoMode(monitor);
	window = glfwCreateWindow(mode->width, mode->height, "No Title", monitor, NULL);
	glfwMakeContextCurrent(window);
}

Window::Window(const std::string &name) 
	: name(name) {
	monitor = glfwGetPrimaryMonitor();
	window = glfwCreateWindow(width, height, name.c_str(), NULL, NULL);
	glfwMakeContextCurrent(window);
}

Window::Window(int width, int height, std::string name) 
	: width(width), height(height), name(name) {
	monitor = glfwGetPrimaryMonitor();
	window = glfwCreateWindow(width, height, name.c_str(), NULL, NULL);
	glfwMakeContextCurrent(window);
}

Window::~Window() {
	glfwDestroyWindow(window);
}

void Window::SetActive() {
	glfwMakeContextCurrent(window);
}

void Window::Viewport(int viewport_x, int viewport_y, int viewport_width, int viewport_height) {
	this->viewport_x = viewport_x;
	this->viewport_y = viewport_y;
	this->viewport_width = viewport_width;
	this->viewport_height = viewport_height;

	glViewport(viewport_x, viewport_y, viewport_width, viewport_height);
}

bool Window::Closed() {
	return static_cast<bool>(glfwWindowShouldClose(window));
}

void Window::SwapBuffers() {
	glfwSwapBuffers(window);
}