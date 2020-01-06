#include <Common/GameObject.hpp>
#include <Graphics/Camera.hpp>

using namespace Engine;

Camera::Camera(GameObject ^gameObject) 
	: ManagedObject<Core::Camera>(new Core::Camera(gameObject->instance)), m_gameObject(gameObject) {

}

void Camera::Destroy() {
	m_gameObject->RemoveComponent<Camera>();
	ManagedObject<Core::Camera>::Destroy();
}