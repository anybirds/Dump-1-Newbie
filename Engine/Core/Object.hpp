#pragma once

#include <Core/Transform.hpp>

namespace Engine {

	/*
	Object

	An abstraction of an object in the scene.
	 */
	class Object {
	protected:
		Transform transform;
	public:
		struct Detail {
			Transform::Detail Transform;
		};

		Object(const Detail &object);
		virtual ~Object();

		virtual void Start() {}
		virtual void Update() {}

		const Engine::Transform& Transform() const { return transform; }
		Object& Transform(const Engine::Transform& transform) { this->transform = transform; return *this; }
	};
}