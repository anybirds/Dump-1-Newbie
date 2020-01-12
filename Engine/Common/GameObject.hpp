#pragma once

#include <../Core/Common/GameObject.hpp>
#include <Common/ManagedObject.hpp>

namespace Engine {

	interface class IComponent;
	ref class Transform;

	/*
	An abstraction of an object in the scene.
	Has components that can describe the GameObject behavior.
	*/
	public ref class GameObject sealed : public ManagedObject<Core::GameObject> {
	private:
		static System::Collections::Generic::Dictionary<System::String^, GameObject^> ^m_gameObjects;

	public:
		static GameObject();
		static GameObject^ Find(System::String ^name);

	private:
		System::String ^m_name;
		Transform ^m_transform;
		System::Collections::Generic::Dictionary<System::Type^, IComponent^> ^m_components;
		
	internal:
		template <typename T> bool RemoveComponent();

	public:
		GameObject();
		GameObject(System::String ^name);

		template <typename T> T^ GetComponent();
		template <typename T> T^ AddComponent();

		virtual void Destroy() override;

		property System::String ^name {
			System::String ^get() {
				return m_name;
			}
			void set(System::String ^value) {
				m_gameObjects->Remove(m_name);
				m_name = value;
				m_gameObjects->Add(m_name, this);
			}
		}
		
		property Transform ^transform {
			Transform ^get() {
				return m_transform;
			}
		}
	};

	template <typename T>
	bool GameObject::RemoveComponent() {
		return m_components->Remove(T::typeid);
	}

	template <typename T>
	T^ GameObject::GetComponent() {
		Component ^component;
		m_components->TryGetValue(T::typeid, component);
		return dynamic_cast<T>(component);
	}

	template <typename T>
	T^ GameObject::AddComponent() {
		Component ^component = m_components[T::typeid];
		if (!component) {
			component = gcnew T(this);
		}
		return dynamic_cast<T>(component);
	}
}