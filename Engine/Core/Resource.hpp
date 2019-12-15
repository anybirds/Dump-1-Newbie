#pragma once

#include <string>
#include <unordered_map>

namespace Engine {
	
	class Material;
	class Model;
	class Mesh;
	class Texture;

	/*
	Resource
	
	Has mappings to find all the resources currently loaded to the game. 
	*/
	class Resource final {
	private:
		static Resource resource;

	public:
		static void Init();
		static Material& FindMaterial(const std::string& name);
		static Model& FindModel(const std::string& name);
		static Mesh& FindMesh(const std::string& name);
		//static Shader& FindShader(const std::string& name);
		static Texture& FindTexture(const std::string& name);

	private:
		std::unordered_map<std::string, Material*> material;
		std::unordered_map<std::string, Model*> model;
		std::unordered_map<std::string, Mesh*> mesh;
		// std::unordered_map<std::string, Shader*> shader;
		std::unordered_map<std::string, Texture*> texture;

		Resource();

	public:
		Resource(const Resource &) = delete;
		Resource(Resource&&) = delete;
		Resource& operator=(const Resource &) = delete;
		Resource& operator=(Resource&&) = delete;
		~Resource();
	};
}