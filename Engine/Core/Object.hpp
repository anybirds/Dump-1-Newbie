#pragma once

#include <Core/Transform.hpp>

namespace Engine {

	struct ObjectDetail {
		TransformDetail Transform;
	};

	/*
	Object

	An abstraction of an object in the scene.
	 */
	class Object {
	protected:
		Transform transform;
	public:
		Object(const ObjectDetail &object);
		virtual ~Object();

		const Engine::Transform& Transform() const { return transform; }
		Object& Transform(const Engine::Transform& transform) { this->transform = transform; return *this; }
	};
}