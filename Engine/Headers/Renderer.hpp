#pragma once

#include <GL/glew.h>
#include <glm/glm.hpp>
#include <GLFW/glfw3.h>

#include <Mesh.hpp>
#include <Material.hpp>
#include <Transform.hpp>

namespace Engine {
	class Renderer final {
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