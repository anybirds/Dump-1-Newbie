#pragma once

#include <Graphics/Material.hpp>
#include <Graphics/Texture.hpp>

class DefaultMaterial final : public Engine::Material {
private:
	Engine::Texture *texture;

public:
	struct Data : Material::Data {
		const char *texture_name;
	};

	explicit DefaultMaterial(const Data &data);
	~DefaultMaterial();
	virtual void Uniform() const;
	const Engine::Texture& GetTexture() { return *texture; }
	DefaultMaterial& SetTexture(Engine::Texture &texture) { this->texture = &texture; return *this; }
};