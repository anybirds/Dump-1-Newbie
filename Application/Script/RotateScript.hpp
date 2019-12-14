#pragma once

#include <Core/Component.hpp>
#include <Core/Script.hpp>

class RotateScript : public Engine::Component, public Engine::Script {
public:
	struct Detail {
		Component::Detail Component;
	};
	
	RotateScript(const Detail &rotate_script);
	virtual ~RotateScript();
	virtual void Start();
	virtual void Update();
};