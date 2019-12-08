#include <Engine.hpp>

using namespace std;
using namespace Engine;

class DefaultMaterial final : public Material {
private:
	const Texture *texture;

public:
	DefaultMaterial(const string &vert_path, const string &frag_path);
	~DefaultMaterial();
	virtual void Update();
	void Texture(const Engine::Texture &texture) { this->texture = &texture; }
};