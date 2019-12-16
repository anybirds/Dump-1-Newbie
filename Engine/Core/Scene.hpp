#pragma once

#include <set>
#include <unordered_map>

namespace Engine {

	class Object;
	class Renderer;
	class Script;

	/*
	Scene
	
	Has Objects that are currnetly in the Scene. 
	*/
	class Scene final {
	private:
		std::unordered_map<std::string, Object*> object;
		std::set<Renderer*> renderer;
		std::set<Script*> script;

	public:
		Scene();
		~Scene();
		
		// add Instantiate
		// add Find
		void Start();
		void Update();
		void Render();

		friend class Renderer;
		friend class Script;
	};
}