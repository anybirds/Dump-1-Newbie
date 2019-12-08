#pragma once

#include <unordered_map>

namespace Engine {
	/*
	Object

	An abstraction of an object in the scene.
	 */
	class Object {
	public:
		template <typename TComponent>
		void Component(TComponent component);

		template <typename TComponent>
		TComponent Component();
	};
}