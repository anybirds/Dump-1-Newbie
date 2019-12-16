#pragma once

#include <Core/Component.hpp>
#include <Core/Script.hpp>

class RotateScript : public Engine::Component, public Engine::Script {
private:
	float rate;

public:
	struct Detail {
		Component::Detail Component;
		float Rate;
	};
	
	explicit RotateScript(const Detail &rotate_script);
	virtual ~RotateScript();
	virtual void Start();
	virtual void Update();
};