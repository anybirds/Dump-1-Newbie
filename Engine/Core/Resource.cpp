#include <Core/Resource.hpp>

using namespace std;
using namespace Engine;

Resource::Resource(const char *name) : name(name) {
	ResourceManager::AddResource(*this); 
}

Resource::~Resource() {
	ResourceManager::RemoveResource(*this);
}

ResourceManager ResourceManager::resource_manager;

ResourceManager::ResourceManager() {

}

ResourceManager::~ResourceManager() {
	for (auto item : resource) {
		delete item.second; 
	}
}

