#include <Common/Debug.hpp>
#include <Common/Script.hpp>

#ifdef DEBUG_COMMON
#define DEBUG
#endif

using namespace Core;

Script::Script(GameObject *object) : Component(object) {

}

Script::~Script() {
	
}