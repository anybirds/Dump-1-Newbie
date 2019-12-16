#pragma once

#include <string>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

namespace Engine {
	
	/*
	Window

	Abstraction of a cross-platform window that appears in the monitor. 
	 */
	class Window final {
	private:
		static void glfwInit();
		static void glfwTerminate();
		static void glewInit();

	public:
		GLFWwindow *window;
		int width;
		int height;
		std::string name;
		
		int viewport_x;
		int viewport_y;
		int viewport_width;
		int viewport_height;

	public:
		struct Detail {
			int Width;
			int Height;
			string Name;
		};
		explicit Window(const Detail &window);
		~Window();

		int Width() const { return width; };
		Window& Width(int width) { this->width = width; return *this; };
		int Height() const { return height; };
		Window& Height(int height) { this->height = height; return *this; };
		const std::string& Name() const { return name; };
		Window& Name(const std::string &name) { this->name = name; return *this; };

		void SetActive();
		void Viewport(int viewport_x, int viewport_y, int viewport_width, int viewport_height);
		bool Closed();
		void SwapBuffers();
	};
}
