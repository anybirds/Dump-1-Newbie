#include <../Core/Common/Transform.hpp>
#include <Common/GameObject.hpp>

using namespace System;
using namespace Engine;

GameObject^ GameObject::Find(String ^name) {
	GameObject ^gameObject;
	m_gameObjects.TryGetValue(name, gameObject);
	return gameObject;
}

GameObject::GameObject() : ManagedObject<Core::GameObject>(new Core::GameObject(new Core::Transform())) {

}

GameObject::GameObject(String ^name) : ManagedObject<Core::GameObject>(new Core::GameObject(new Core::Transform())), m_name(name) {
	m_gameObjects.Add(m_name, this);
}

void GameObject::Destroy() {
	m_gameObjects.Remove(m_name);
	ManagedObject<Core::GameObject>::Destroy();
}

