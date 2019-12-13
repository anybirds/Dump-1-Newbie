#pragma once

#include <Core/Object.hpp>
#include <Graphics/Material.hpp>
#include <Graphics/Mesh.hpp>
#include <Graphics/Renderer.hpp>

namespace Engine {

	struct DrawableObjectDetail {
		ObjectDetail Object;
		RendererDetail Renderer;
	};

	/*
	DrawableObject

	Drawable object in the scene. 
	Has mesh, material and renderer members that is responsible for rendering. 
	 */
	class DrawableObject : public Object {
	private:
		Renderer renderer;
	public:
		DrawableObject(const DrawableObjectDetail &drawable_object);
		virtual ~DrawableObject();

		Engine::Renderer& Renderer() { return renderer; }
	};
}