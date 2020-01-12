#include <../Core/Common/GameObject.hpp>
#include <Common/GameObject.hpp>
#include <Common/Script.hpp>

using namespace Engine;

Script::Script(GameObject ^gameObject) 
	: ManagedObject<Core::Script>(new Core::Script()), m_gameObject(gameObject) {

}

void Script::Destroy() {
	m_gameObject = nullptr;
	ManagedObject<Core::Script>::Destroy();
}