#include <../Core/Common/GameObject.hpp>
#include <Common/GameObject.hpp>
#include <Common/Script.hpp>

using namespace Engine;

Script::Script(GameObject ^gameObject) 
	: ManagedObject<Core::Script>(new Core::Script(gameObject->instance)), m_gameObject(gameObject) {

}
