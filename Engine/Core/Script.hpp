#pragma once

namespace Engine {
	
	class Component;

	class Script {
	private:
		const Component *component;
	public:
		Script(const Component &component);
		virtual ~Script();
		virtual void Start() = 0;
		virtual void Update() = 0;
	};
}