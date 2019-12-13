#include <Engine.hpp>

using namespace Engine;

struct DefaultMaterialDetail {
	const char *VertexShaderName;
	const char *FragmentShaderName;
	const Texture *Texture;
};

class DefaultMaterial final : public Material {
private:
	const Texture *texture;

public:
	DefaultMaterial(const DefaultMaterialDetail &default_material);
	~DefaultMaterial();
	virtual void Update();
	DefaultMaterial& Texture(const Engine::Texture &texture) { this->texture = &texture; return *this; }
};