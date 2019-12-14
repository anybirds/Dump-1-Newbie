#pragma once

#include <Core/CameraObject.hpp>
#include <Core/DrawableObject.hpp>
#include <Core/Object.hpp>

namespace Engine {
	class Scene final {
	private:
		CameraObject *camera;
		DrawableObject *square;
		DrawableObject *bunny;

	public:
		Scene();
		~Scene();
		
		// template <typename ObjectType> ObjectType& Instantiate(ObjectType::Detail);
		// template <typename ObjectType> ObjectType& Find(const char *name) const;
		void Start();
		void Update();
		void Render();
	};
}