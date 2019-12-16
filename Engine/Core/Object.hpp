#pragma once

#include <map>
#include <string>
#include <typeinfo>

#include <Core/Transform.hpp>

namespace Engine {
	
	class Component;
	class Scene;
	
	/*
	Object

	An abstraction of an object in the scene.
	Has Components that can describe the object behavior.
	 */
	class Object final {
	private:
		Engine::Scene *scene;
		std::string name;
		Transform transform;
		std::map<size_t, Component*> component; // <hash_code, Component>
		
	public:
		struct Detail {
			Engine::Scene *Scene;
			const char *Name;
			Transform::Detail Transform;
		};

		explicit Object(const Detail &object);
		~Object();
		
		template <typename ComponentType> 
		ComponentType& GetComponent(); 

		template <typename ComponentType>
		Object& AddComponent(const typename ComponentType::Detail &component); 

		Engine::Scene& Scene() const { return *scene; }
		const std::string& Name() const { return name; }
		Object& Name(const std::string& name) { this->name = name; return *this; }
		Engine::Transform& Transform() { return transform; }
		const Engine::Transform& Transform() const { return transform; }
		Object& Transform(const Engine::Transform &transform) { this->transform = transform; return *this; }
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
	Object& Object::AddComponent(const typename ComponentType::Detail &component) {
		size_t key = typeid(ComponentType).hash_code();
		ComponentType *value = new ComponentType(component);
		this->component.insert({ key, value });
		return *this;
	}
}

