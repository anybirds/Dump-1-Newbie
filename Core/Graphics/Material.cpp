#include <algorithm>
#include <exception>
#include <iostream>
#include <vector>

#include <Common/Debug.hpp>
#include <Graphics/Material.hpp>
#include <Graphics/Shader.hpp>
#include <Graphics/Texture.hpp>

#ifdef DEBUG_GRAPHICS
#define DEBUG
#endif

using namespace std;
using namespace glm;
using namespace Core;

Material::Material(const Shader *vert_shader, const Shader *frag_shader) {
	if (vert_shader->GetType() != GL_VERTEX_SHADER ||
		frag_shader->GetType() != GL_FRAGMENT_SHADER) {
#ifdef DEBUG
		cout << '[' << __FUNCTION__ << ']' << " shader type mismatch occurred";
#endif
		throw std::exception();
	}
	
	// attach shaders and link
	program = glCreateProgram();
	glAttachShader(program, vert_shader->GetId());
	glAttachShader(program, frag_shader->GetId());
	glLinkProgram(program);
}

Material::~Material() {
	glDeleteProgram(program);
}

/*
const int* Material::GetInteger(const char *name) const {
	auto it = ints.find(name);
	if (it == ints.end()) {
		return nullptr;
	}
	return &it->second;
}

const std::vector<int>* Material::GetIntegerArray(const char *name) const {
	auto it = intarrs.find(name);
	if (it == intarrs.end()) {
		return nullptr;
	}
	return &it->second;
}

const float* Material::GetFloat(const char *name) const {
	auto it = floats.find(name);
	if (it == floats.end()) {
		return nullptr;
	}
	return &it->second;
}

const std::vector<float>* Material::GetFloatArray(const char *name) const {
	auto it = floatarrs.find(name);
	if (it == floatarrs.end()) {
		return nullptr;
	}
	return &it->second;
}

const vec4* Material::GetVector(const char *name) const {
	auto it = vecs.find(name);
	if (it == vecs.end()) {
		return nullptr;
	}
	return &it->second;
}

const std::vector<vec4>* Material::GetVectorArray(const char *name) const {
	auto it = vecarrs.find(name);
	if (it == vecarrs.end()) {
		return nullptr;
	}
	return &it->second;
}

const mat4* Material::GetMatrix(const char *name) const {
	auto it = mats.find(name);
	if (it == mats.end()) {
		return nullptr;
	}
	return &it->second;
}

const std::vector<mat4>* Material::GetMatrixArray(const char *name) const {
	auto it = matarrs.find(name);
	if (it == matarrs.end()) {
		return nullptr;
	}
	return &it->second;
}

void Material::SetInteger(const char *name, int value) {
	ints.insert_or_assign(name, value);
}

void Material::SetIntegerArray(const char *name, const int *value, int length) {
	intarrs.insert_or_assign(name, move(vector<int>(value, value + length)));
}

void Material::SetFloat(const char *name, float value) {
	floats.insert_or_assign(name, value);
}

void Material::SetFloatArray(const char *name, const float *value, int length) {
	floatarrs.insert_or_assign(name, move(vector<float>(value, value + length)));
}

void Material::SetVector(const char *name, const vec4 &value) {
	vecs.insert_or_assign(name, value);
}

void Material::SetVectorArray(const char *name, const vec4 *value, int length) {
	vecarrs.insert_or_assign(name, move(vector<vec4>(value, value + length)));
}

void Material::SetMatrix(const char *name, const mat4 &value) {
	mats.insert_or_assign(name, value);
}

void Material::SetMatrixArray(const char *name, const mat4 *value, int length) {
	matarrs.insert_or_assign(name, move(vector<mat4>(value, value + length)));
}

void Material::UpdateUniforms() {
	GLuint location;
	for (auto &it : ints) {
		location = glGetUniformLocation(program, it.first.c_str());
		glUniform1i(location, it.second);
	}
	for (auto &it : intarrs) {
		location = glGetUniformLocation(program, it.first.c_str());
		glUniform1iv(location, it.second.size(), &it.second[0]);
	}
	for (auto &it : floats) {
		location = glGetUniformLocation(program, it.first.c_str());
		glUniform1f(location, it.second);
	}
	for (auto &it : floatarrs) {
		location = glGetUniformLocation(program, it.first.c_str());
		glUniform1fv(location, it.second.size(), &it.second[0]);
	}
	for (auto &it : vecs) {
		location = glGetUniformLocation(program, it.first.c_str());
		glUniform4fv(location, 1, (const GLfloat *)&it.second);
	}
	for (auto &it : vecarrs) {
		location = glGetUniformLocation(program, it.first.c_str());
		glUniform1fv(location, it.second.size(), (const GLfloat *)&it.second[0]);
	}
	for (auto &it : mats) {
		location = glGetUniformLocation(program, it.first.c_str());
		glUniform4fv(location, 1, (const GLfloat *)&it.second);
	}
	for (auto &it : matarrs) {
		location = glGetUniformLocation(program, it.first.c_str());
		glUniform1fv(location, it.second.size(), (const GLfloat *)&it.second[0]);
	}
}
*/
