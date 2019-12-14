#pragma once

#include <Graphics/Material.hpp>
#include <Graphics/Texture.hpp>

class DefaultMaterial final : public Engine::Material {
private:
	const Engine::Texture *texture;

public:
	struct Detail {
		const char *VertexShaderName;
		const char *FragmentShaderName;
		const char *TextureName;
	};
	DefaultMaterial(const Detail &default_material);
	~DefaultMaterial();
	virtual void Uniform() const;
	DefaultMaterial& Texture(const Engine::Texture &texture) { this->texture = &texture; return *this; }
};