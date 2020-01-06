#include <Common/Utility.hpp>
#include <Graphics/Texture.hpp>

using namespace System;
using namespace Engine;

Texture^ Texture::Find(String ^name) {
	Texture ^texture;
	m_textures.TryGetValue(name, texture);
	return texture;
}

Texture::Texture(String ^name, String ^texture_path) 
	: ManagedObject<Core::Texture>(new Core::Texture(Utility::StringToCharArray(texture_path))) {
	m_name = name;
	m_textures.Add(m_name, this);
}

void Texture::Destroy() {
	m_textures.Remove(m_name);
	ManagedObject<Core::Texture>::Destroy();
}