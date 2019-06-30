#pragma once

#include <iostream>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#define DEBUG_GENERAL
#define DEBUG_GRAPHICS
#define DEBUG_RENDERING
#define DEBUG_MEMORY

namespace Engine {
	/**
	 * @brief Engine::Debug class provides a set of useful static functions for debugging.
	 */
	class Debug {
	public:
		/**
		 * @brief GrpahicsErrorLog function is a callback function that leaves an error message to the console window. It is called when OpenGL related functions fail. 
		 */
		static void APIENTRY GraphicsErrorLog(GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const GLchar *message, const void *userParam);
	};
}