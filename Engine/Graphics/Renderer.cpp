#include <Common/GameObject.hpp>
#include <Graphics/Renderer.hpp>

using namespace System;
using namespace Engine;

Renderer::Renderer(GameObject ^gameObject) 
	: ManagedObject<Core::Renderer>(new Core::Renderer(gameObject->instance)), m_gameObject(gameObject) {
	
}

void Renderer::Render() {
	instance->Render();
}

void Renderer::Destroy() {
	m_gameObject->RemoveComponent<Renderer>();
	ManagedObject<Core::Renderer>::Destroy();
}
