#include <Engine.hpp>

using namespace Engine;

class DefaultMaterial final : public Material {
private:
	const Texture *texture;

public:
	struct Detail {
		const char *VertexShaderName;
		const char *FragmentShaderName;
		const char *TextureName;
	};
	DefaultMaterial(const Detail &default_material);
	~DefaultMaterial();
	virtual void Update() const;
	DefaultMaterial& Texture(const Engine::Texture &texture) { this->texture = &texture; return *this; }
};