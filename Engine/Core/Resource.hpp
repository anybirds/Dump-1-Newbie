#pragma once

#include <string>
#include <typeinfo>
#include <unordered_map>

namespace Engine {

	/*
	Resource

	Base class for all the resources such as Mateiral, Mesh, Model, Texture, etc.
	*/
	class Resource {
	private:
		std::string name;

	public:
		struct Data {
			const char *name;
		};

		Resource(const Data &name);
		virtual ~Resource();

		const std::string& GetName() const { return name; }
		Resource& SetName(const std::string &name) { this->name = name; return *this; }
	};

	/*
	ResourceManager

	Has mappings to find all the resources currently loaded to the game.
	*/
	class ResourceManager final {
	private:
		static ResourceManager resource_manager;

		template <typename ResourceType>
		static void AddResource(ResourceType &resource);
		template <typename ResourceType>
		static void RemoveResource(ResourceType &resource);

	public:
		template <typename ResourceType>
		static void AddResource(const typename ResourceType::Data &data);
		template <typename ResourceType>
		static ResourceType* FindResource(const char *name);

	private:
		std::unordered_map<std::string, Resource*> resource;

		ResourceManager();

	public:
		ResourceManager(const ResourceManager&) = delete;
		ResourceManager(ResourceManager&&) = delete;
		ResourceManager& operator=(const ResourceManager &) = delete;
		ResourceManager& operator=(ResourceManager&&) = delete;
		~ResourceManager();

		friend class Resource;
	};

	template <typename ResourceType>
	static void ResourceManager::AddResource(const typename ResourceType::Data &data) {
		ResourceType *resource = new ResourceType(data);
	}

	template <typename ResourceType>
	static void ResourceManager::AddResource(ResourceType &resource) {
		resource_manager.resource.emplace(resource.GetName(), &resource);
	}
	
	template <typename ResourceType>
	static void ResourceManager::RemoveResource(ResourceType &resource) {
		resource_manager.resource.erase(resource.GetName());
	}

	template <typename ResourceType>
	static ResourceType* ResourceManager::FindResource(const char *name) {
		auto it = resource_manager.resource.find(name);
		if (it == resource_manager.resource.end()) {
			return nullptr;
		}
		return dynamic_cast<ResourceType*>(it->second);
	}
}