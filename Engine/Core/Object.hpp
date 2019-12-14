#pragma once

#include <map>
#include <string>
#include <typeinfo>

#include <Core/Component.hpp>
#include <Core/Transform.hpp>

namespace Engine {

	/*
	Object

	An abstraction of an object in the scene.
	 */
	class Object final {
	private:
		std::string name;
		Transform transform;
		std::map<size_t, Engine::Component*> component; // <hash_code, Component>

	public:
		struct Detail {
			const char *Name;
			Transform::Detail Transform;
		};

		Object(const Detail &object);
		~Object();
		
		template <typename ComponentType> 
		ComponentType& GetComponent(); 

		template <typename ComponentType>
		Object& SetComponent(const typename ComponentType::Detail &component); 

		const Engine::Transform& Transform() const { return transform; }
		Object& Transform(const Engine::Transform& transform) { this->transform = transform; return *this; }
	};

	template <typename ComponentType>
	ComponentType& Object::GetComponent() {
		size_t key = typeid(ComponentType).hash_code();
		auto it = component.find(key);
		if (it == component.end()) {
			// exception
		}
		return dynamic_cast<ComponentType&>(*it->second);
	}

	template <typename ComponentType>
	Object& Object::SetComponent(const typename ComponentType::Detail &component) {
		size_t key = typeid(ComponentType).hash_code();
		ComponentType *value = new ComponentType(component);
		this->component.insert({ key, value });
		value->Object(*this);
		return *this;
	}
}

