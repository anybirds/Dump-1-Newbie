#pragma once

#include <Core/Object.hpp>

namespace Engine {
	class Scene final {
	private:
		Object *camera;
		Object *square;
		Object *bunny;

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