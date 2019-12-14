#pragma once

#include <set>

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
		Object *camera;
		Object *square;
		Object *bunny;

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