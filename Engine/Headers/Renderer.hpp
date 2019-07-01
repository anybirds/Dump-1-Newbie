#pragma once

#include <GL/glew.h>
#include <glm/glm.hpp>
#include <GLFW/glfw3.h>

#include <Mesh.hpp>
#include <Material.hpp>


namespace Engine {
	class Renderer final {
	private:
		const Mesh *mesh;
		const Material *material;

	public:
		Renderer(const Mesh &mesh, const Material &material);
		~Renderer();

		void Render();
	};
}