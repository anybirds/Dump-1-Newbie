#include <Common/Debug.hpp>
#include <Common/GameObject.hpp>

#ifdef DEBUG_COMMON
#define DEBUG
#endif

using namespace Core;

GameObject::GameObject(Transform *transform) : transform(transform) {
	
}

GameObject::~GameObject() {

}