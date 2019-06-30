#pragma once

#include <GL/glew.h>
#include <glm/glm.hpp>
#include <GLFW/glfw3.h>

#include <Mesh.hpp>
#include <Material.hpp>


namespace Engine {
	class Renderer final {
	private:
		Mesh *mesh;
		Material *material;
	public:
		Renderer(Mesh *mesh, Material *material);
		~Renderer();

		void Render();
	};
}