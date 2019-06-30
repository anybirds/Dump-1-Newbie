#pragma once

#include <string>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

using namespace std;

namespace Engine {
	/**
	 * @brief Engine::Window class is an abstraction of a cross-platform window that appears in the monitor. 
	 */
	class Window final {
	private:
		static unsigned window_cnt;

		static void glfwInit();
		static void glfwTerminate();
		static void glewInit();

	private:
		GLFWwindow *window;
		GLFWmonitor *monitor;
		int width;
		int height;
		string name;
		
		int viewport_x;
		int viewport_y;
		int viewport_width;
		int viewport_height;

	public:
		Window();
		explicit Window(const string &name);
		Window(int width, int height, string name);
		~Window();

		int Width() const { return width; };
		void Width(int width) { this->width = width; };
		int Height() const { return height; };
		void Height(int height) { this->height = height; };
		const string &Name() const { return name; };
		void Name(const string &name) { this->name = name; };

		void SetActive();
		void Viewport(int viewport_x, int viewport_y, int viewport_width, int viewport_height);
		bool Closed();
		void SwapBuffers();
	};
}
