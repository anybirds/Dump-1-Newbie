#pragma once

#include <unordered_map>

namespace Engine {
	/**
	 * @brief Engine::Object class is an abstraction of an object in the scene.
	 * @details Engine::Object class takes component based programming approach. 
	 */
	class Object {
	public:
		template <typename TComponent>
		void Component(TComponent component);

		template <typename TComponent>
		TComponent Component();
	};
}