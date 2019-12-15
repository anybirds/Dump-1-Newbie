#pragma once

namespace Engine {
	
	class Scene;

	class Script {
	private:
		Scene &scene;

	public:
		Script(Scene &scene);
		virtual ~Script();
		virtual void Start() = 0;
		virtual void Update() = 0;
	};
}