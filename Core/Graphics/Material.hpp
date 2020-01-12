#pragma once

#include <exception>
#include <unordered_map>
#include <string>
#include <vector>

#include <GL/glew.h>
#include <glm/glm.hpp>

namespace Core {

	class Shader;
	class Texture;

	class Material final {
	private:
		GLuint program;
		
		/*
		std::unordered_map<std::string, int> ints;
		std::unordered_map<std::string, std::vector<int>> intarrs;
		std::unordered_map<std::string, float> floats;
		std::unordered_map<std::string, std::vector<float>> floatarrs;
		std::unordered_map<std::string, glm::vec4> vecs;
		std::unordered_map<std::string, std::vector<glm::vec4>> vecarrs;
		std::unordered_map<std::string, glm::mat4> mats;
		std::unordered_map<std::string, std::vector<glm::mat4>> matarrs;
		*/

	public:
		Material(const Shader *vert_shader, const Shader *frag_shader);
		~Material();

		/*
		const int* GetInteger(const char *name) const;
		const std::vector<int>* GetIntegerArray(const char *name) const;
		const float* GetFloat(const char *name) const;
		const std::vector<float>* GetFloatArray(const char *name) const;
		const glm::vec4* GetVector(const char *name) const;
		const std::vector<glm::vec4>* GetVectorArray(const char *name) const;
		const glm::mat4* GetMatrix(const char *name) const;
		const std::vector<glm::mat4>* GetMatrixArray(const char *name) const;

		void SetInteger(const char *name, int value);
		void SetIntegerArray(const char *name, const int *value, int length);
		void SetFloat(const char *name, float value);
		void SetFloatArray(const char *name, const float *value, int length);
		void SetVector(const char *name, const glm::vec4 &value);
		void SetVectorArray(const char *name, const glm::vec4 *value, int length);
		void SetMatrix(const char *name, const glm::mat4 &value);
		void SetMatrixArray(const char *name, const glm::mat4 *value, int length);
		*/

		GLuint GetProgram() const { return program; }
	};
}
