#pragma once

#include <map>
#include <string>
#include <typeinfo>

#include <Core/Transform.hpp>

namespace Engine {

	class Component;

	/*
	Object

	An abstraction of an object in the scene.
	Has Components that can describe the object behavior.
	 */
	class Object final {
	private:
		std::string name;
		Transform transform;
		std::map<size_t, Component*> component; // <hash_code, Component>

	public:
		struct Data {
			const char *name;
			Transform::Data transform_data;
		};

		explicit Object(const Data &data);
		~Object();

		template <typename ComponentType>
		ComponentType* GetComponent();
		template <typename ComponentType>
		Object& AddComponent(const typename ComponentType::Data &data);
		template <typename ComponentType>
		Object& RemoveComponent();

		const std::string& GetName() const { return name; }
		Object& SetName(const std::string& name) { this->name = name; return *this; }
		Engine::Transform& GetTransform() { return transform; }
		const Engine::Transform& GetTransform() const { return transform; }
		Object& SetTransform(const Engine::Transform &transform) { this->transform = transform; return *this; }
	};

	template <typename ComponentType>
	ComponentType* Object::GetComponent() {
		size_t key = typeid(ComponentType).hash_code();
		auto it = component.find(key);
		if (it == component.end()) {
			return nullptr;
		}
		return dynamic_cast<ComponentType*>(it->second);
	}

	template <typename ComponentType>
	Object& Object::AddComponent(const typename ComponentType::Data &data) {
		size_t key = typeid(ComponentType).hash_code();
		ComponentType *value = new ComponentType(data);
		this->component.insert({ key, value });
		return *this;
	}

	template <typename ComponentType>
	Object& Object::RemoveComponent() {
		size_t key = typeid(ComponentType).hash_code();
		delete component[key];
		component.erase(key);
		return *this;
	}
}

