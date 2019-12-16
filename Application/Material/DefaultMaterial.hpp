#pragma once

#include <Graphics/Material.hpp>
#include <Graphics/Texture.hpp>

class DefaultMaterial final : public Engine::Material {
private:
	Engine::Texture *texture;

public:
	struct Detail {
		const char *VertexShaderName;
		const char *FragmentShaderName;
		const char *TextureName;
	};
	explicit DefaultMaterial(const Detail &default_material);
	~DefaultMaterial();
	virtual void Uniform() const;
	const Engine::Texture& Texture() { return *texture; }
	DefaultMaterial& Texture(Engine::Texture &texture) { this->texture = &texture; return *this; }
};