#pragma once

#include <Core/Component.hpp>

namespace Engine {

	class Material;
	class Mesh;

	/*
	Renderer Component

	Responsible for rendering objects that have Mesh and Material.
	*/
	class Renderer final : public Component {
	private:
		const Mesh *mesh;
		const Material *material;

	public:
		struct Detail {
			Component::Detail Component;
			const char *MeshName;
			const char *MaterialName;
		};

		explicit Renderer(const Detail &renderer);
		~Renderer();

		const Engine::Mesh& Mesh() const { return *mesh; }
		Renderer& Mesh(const Engine::Mesh &mesh) { this->mesh = &mesh; return *this; }
		const Engine::Material& Material() const { return *material; }
		Renderer& Material(const Engine::Material &material) { this->material = &material; return *this; }

		void Render();
	};
}