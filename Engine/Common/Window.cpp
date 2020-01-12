#include <Common/Utility.hpp>
#include <Common/Window.hpp>

using namespace System;
using namespace Engine;

void Window::glfwInit() {
	::glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
}

void Window::glfwTerminate() {
	::glfwTerminate();
}

void Window::glewInit() {
	GLenum glew_error = ::glewInit();
	if (glew_error != GLEW_OK) {
		// Initializing GLEW failed
	}
	glEnable(GL_DEPTH_TEST); // move this to framebuffer specification
}

static Window::Window() {
	Window::glfwInit();
}

Window::Window(String ^name) : m_name(name) {
	// full-screen window
	GLFWmonitor *monitor = glfwGetPrimaryMonitor();
	const GLFWvidmode *mode = glfwGetVideoMode(monitor);
	m_width = mode->width;
	m_height = mode->height;

	m_window = glfwCreateWindow(m_width, m_height, Utility::StringToCharArray(m_name), NULL, NULL);
	glfwMakeContextCurrent(m_window);

	Window::glewInit();
	glViewport(0, 0, m_width, m_height);
}

Window::Window(String ^name, int width, int height)
	: m_name(name), m_width(width), m_height(height) {
	m_window = glfwCreateWindow(m_width, m_height, Utility::StringToCharArray(m_name), NULL, NULL);
	glfwMakeContextCurrent(m_window);

	Window::glewInit();
	glViewport(0, 0, m_width, m_height);
}

Window::!Window() {
	glfwDestroyWindow(m_window);
}

bool Window::ShouldClose() {
	return static_cast<bool>(glfwWindowShouldClose(m_window));
}

void Window::SwapBuffers() {
	glfwSwapBuffers(m_window);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // move this to framebuffer specification
}

void Window::PollEvents() {
	glfwPollEvents();
}