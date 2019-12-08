#pragma once

#include <Camera.hpp>
#include <Mesh.hpp>
#include <Material.hpp>
#include <Transform.hpp>

namespace Engine {
	/*
	Renderer

	Draw an object that has mesh and material.
	*/
	class Renderer final {
	private:
		static const Engine::Camera *camera;

	public:
		static const Engine::Camera &Camera() { return *camera; }
		static void Camera(const Engine::Camera &camera) { Renderer::camera = &camera; }

	private:
		const Mesh *mesh;
		const Material *material;
		const Transform *transform;
	
	public:
		Renderer(const Mesh &mesh, const Material &material);
		Renderer(const Mesh &mesh, const Material &material, const Transform &transform);
		~Renderer();

		void Render();
	};
}