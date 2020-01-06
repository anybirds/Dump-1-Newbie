#include <Common/Component.hpp>
#include <Common/Debug.hpp>

#ifdef DEBUG_COMMON
#define DEBUG
#endif

using namespace Core;

Component::Component(GameObject *object) : object(object) {

}

Component::~Component() {

}
