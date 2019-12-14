#pragma once

#include <string>
#include <unordered_map>

#include <Graphics/Material.hpp>
#include <Graphics/Mesh.hpp>
#include <Graphics/Model.hpp>
#include <Graphics/Texture.hpp>

namespace Engine {
	class Resource final {
	private:
		static Resource resource;

	public:
		static void Init();
		static Material& FindMaterial(const string& name);
		static Model& FindModel(const string& name);
		static Mesh& FindMesh(const string& name);
		//static Shader& FindShader(const string& name);
		static Texture& FindTexture(const string& name);

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