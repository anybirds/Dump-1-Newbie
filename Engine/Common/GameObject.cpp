#include <../Core/Common/Transform.hpp>
#include <Common/GameObject.hpp>
#include <Common/Transform.hpp>

using namespace System;
using namespace Engine;

static GameObject::GameObject() {
	m_gameObjects = gcnew System::Collections::Generic::Dictionary<System::String^, GameObject^>();
}

GameObject^ GameObject::Find(String ^name) {
	GameObject ^gameObject;
	m_gameObjects->TryGetValue(name, gameObject);
	return gameObject;
}

GameObject::GameObject() 
	: ManagedObject<Core::GameObject>(new Core::GameObject()), m_transform(gcnew Transform()) {

}

GameObject::GameObject(String ^name) 
	: ManagedObject<Core::GameObject>(new Core::GameObject()), m_name(name), m_transform(gcnew Transform()) {
	m_gameObjects->Add(m_name, this);
}

void GameObject::Destroy() {
	m_name = nullptr;
	m_transform = nullptr;
	m_components = nullptr;
	m_gameObjects->Remove(m_name);
	ManagedObject<Core::GameObject>::Destroy();
}

