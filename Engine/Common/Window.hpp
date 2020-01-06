#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>

namespace Engine {
	public ref class Window {
	private:
		static void glfwInit();
		static void glfwTerminate();
		static void glewInit();

	private:
		GLFWwindow *m_window;
		System::String ^m_name;
		int m_width;
		int m_height;
		
	public:
		static Window();
		Window(System::String ^name);
		Window(System::String ^name, int width, int height);
		!Window();
		
		bool ShouldClose();
		void SwapBuffers();
	};
}