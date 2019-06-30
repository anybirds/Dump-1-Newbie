#pragma once

#include <string>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

namespace Engine {
	/**
	 * @brief Engine::Window class is an abstraction of a cross-platform window that appears in the monitor. 
	 */
	class Window final {
	public:
		static void Initialize();
		static void Terminate();

	private:
		GLFWwindow *window;
		GLFWmonitor *monitor;
		int width;
		int height;
		std::string name;
		
		int viewport_x;
		int viewport_y;
		int viewport_width;
		int viewport_height;

		void glewInit();

	public:
		Window();
		explicit Window(const std::string &name);
		Window(int width, int height, std::string name);
		~Window();

		int Width() const { return width; };
		void Width(int width) { this->width = width; };
		int Height() const { return height; };
		void Height(int height) { this->height = height; };
		const std::string &Name() const { return name; };
		void Name(const std::string &name) { this->name = name; };

		void SetActive();
		void Viewport(int viewport_x, int viewport_y, int viewport_width, int viewport_height);
		bool Closed();
		void SwapBuffers();
	};
}
