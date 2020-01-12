#include <exception>

#include <GL/glew.h>

#include <Common/Utility.hpp>
#include <Graphics/Shader.hpp>

using namespace std;
using namespace System;
using namespace Engine;

static Shader::Shader() {
	m_shaders = gcnew System::Collections::Generic::Dictionary<System::String^, Shader^>();
}

Shader^ Shader::Find(String ^name) {
	Shader ^shader;
	m_shaders->TryGetValue(name, shader);
	return shader;
}

Shader::Shader(String ^name, ShaderType type, String ^path) 
	: ManagedObject<Core::Shader>(nullptr), m_name(name) {
	switch (type) {
	case ShaderType::Vertex:
		instance = new Core::Shader(GL_VERTEX_SHADER, Utility::StringToCharArray(name));
		break;
	case ShaderType::Fragment:
		instance = new Core::Shader(GL_FRAGMENT_SHADER, Utility::StringToCharArray(name));
		break;
	default:
		break;
	}

	m_shaders->Add(m_name, this);
}

void Shader::Destroy() {
	m_shaders->Remove(m_name);
	ManagedObject<Core::Shader>::Destroy();
}