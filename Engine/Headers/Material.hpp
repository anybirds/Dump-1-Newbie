#pragma once

#include <exception>
#include <string>

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

using namespace std;

namespace Engine {
	class ShaderCreationException final : public exception {
	public:
		const char *what() const noexcept {
			return "[ShaderCreationException] Failed to create a new shader.";
		}
	};

	class ShaderNotFoundException final : public exception {
	private:
		string msg;
	public:
		ShaderNotFoundException(const char *file_name) : msg("[ShaderNotFoundException] Failed to find a shader: ") {
			msg += file_name;
		}

		const char *what() const noexcept {
			return msg.c_str();
		}
	};

	class ShaderCompilationException : public exception {
	private:
		string msg;
	public:
		ShaderCompilationException(GLuint shader) : msg("[ShaderCompilationException] Failed to Compile a shader:\n") {
			GLint len;
			glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &len);
			GLchar *log = new GLchar[len + 1];
			glGetShaderInfoLog(shader, len, NULL, log);

			msg += log;

			delete[] log;
		}

		const char *what() const noexcept {
			return msg.c_str();
		}
	};

	/**
	 * @brief Engine::Material class 
	 */
	class Material final {
	private:
		GLuint program;

		GLuint CompileShader(const char *path, GLenum type);
	public:
		Material();
		Material(const string &vert_path, const string &frag_path);
		Material(const string &vert_path, const string &geom_path, const string &frag_path);
		~Material();

		/**
		 * @brief UseShaders method enables using the linked program with the provided shaders attached.
		 * @details UseShaders method automatically compiles the given shaders and attach it to a generated program object, which gets linked right after.
		 * @todo Come up with a method that automatically detects whether if the shader specified by the given path already exists, therefore no need to recompile.
		 */
		void UseShaders(const string &vert_path, const string &frag_path);
		void UseShaders(const string &vert_path, const string &geom_path, const string &frag_path);

		friend class Renderer;
	};
}