#pragma once

namespace Engine {
	
	class Script {
	public:
		Script();
		virtual ~Script();
		virtual void Start() = 0;
		virtual void Update() = 0;
	};
}