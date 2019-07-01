#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

#include <Material.hpp>

using namespace Engine;

Material::Material() {

}

Material::Material(const string &vert_path, const string &frag_path) {
	UseShaders(vert_path, frag_path);
}

Material::Material(const string &vert_path, const string &geom_path, const string &frag_path) {
	UseShaders(vert_path, geom_path, frag_path);
}

Material::~Material() {
	glDeleteProgram(program);
}

GLuint Material::CompileShader(const char *path, GLenum type) {
	GLuint shader;
	switch (type) {
	case GL_VERTEX_SHADER:
		shader = glCreateShader(GL_VERTEX_SHADER);
		break;
	case GL_GEOMETRY_SHADER:
		shader = glCreateShader(GL_GEOMETRY_SHADER);
		break;
	case GL_FRAGMENT_SHADER:
		shader = glCreateShader(GL_FRAGMENT_SHADER);
		break;
	default:
		// Not readched
		break;
	}

	if (!shader) {
		throw ShaderCreationException();
	}

	ifstream file(path);
	if (!file.is_open()) {
		throw ShaderNotFoundException(path);
	}

	stringstream buf;
	buf << file.rdbuf();
	string source = buf.str();
	const char *source_char = source.c_str();
	glShaderSource(shader, 1, &source_char, NULL);
	
	glCompileShader(shader);
	GLint status = 0;
	glGetShaderiv(shader, GL_COMPILE_STATUS, &status);
	if (status == GL_FALSE) {
		throw ShaderCompilationException(shader);
	}

	return shader;
}

void Material::UseShaders(const string &vert_path, const string &frag_path) {
	// Delete the program that is alreay linked
	// todo: this is terribly inefficient when there alreay is a compiled version of vertex and fragment shaders. 
	glDeleteProgram(program);

	GLuint vert_shader;
	GLuint frag_shader;

	// Compile shaders
	try {
		vert_shader = CompileShader(vert_path.c_str(), GL_VERTEX_SHADER);
		frag_shader = CompileShader(frag_path.c_str(), GL_FRAGMENT_SHADER);
	}
	catch (exception& e) {
		cout << e.what() << endl;
		return;
	}

	// Attach shaders and Link the program
	program = glCreateProgram();
	glAttachShader(program, vert_shader);
	glAttachShader(program, frag_shader);
	glLinkProgram(program);
	glDeleteShader(vert_shader);
	glDeleteShader(frag_shader);
}

void Material::UseShaders(const string &vert_path, const string &geom_path, const string &frag_path) {

}