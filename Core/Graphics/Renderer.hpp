#pragma once

#include <Common/Component.hpp>

namespace Core {

	class Material;
	class Mesh;
	
	/*
	Responsible for rendering GameObjects that have Mesh and Material.
	*/
	class Renderer final : public Component {
	private:
		Mesh *mesh;
		Material *material;

	public:
		Renderer(GameObject *object, Mesh *mesh = nullptr, Material *material = nullptr);
		~Renderer();

		const Mesh* GetMesh() const { return mesh; }
		void SetMesh(Mesh *mesh) { this->mesh = mesh; }
		const Material* GetMaterial() const { return material; }
		void SetMaterial(Material *material) { this->material = material; }

		void Render();
	};
}