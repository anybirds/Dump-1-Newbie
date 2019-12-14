#pragma once

#include <Core/Transform.hpp>
#include <Core/CameraObject.hpp>
#include <Graphics/Camera.hpp>
#include <Graphics/Mesh.hpp>
#include <Graphics/Material.hpp>

namespace Engine {

	/*
	Renderer

	Draw an object that has mesh and material.
	*/
	class Renderer final {
	private:
		const Transform *transform;

		const Mesh *mesh;
		const Material *material;

	public:
		struct Detail {
			const char *MeshName;
			const char *MaterialName;
		};

		explicit Renderer(const Detail &renderer);
		~Renderer();

		const Engine::Mesh& Mesh() const { return *mesh; }
		Renderer& Mesh(const Engine::Mesh &mesh) { this->mesh = &mesh; return *this; }
		const Engine::Material& Material() const { return *material; }
		Renderer& Material(const Engine::Material &material) { this->material = &material; return *this; }
		const Engine::Transform& Transform() const { return *transform; }
		Renderer& Transform(const Engine::Transform &transform) { this->transform = &transform; return *this; }

		void Render();
	};
}