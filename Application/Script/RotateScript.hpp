#pragma once

#include <Core/Component.hpp>
#include <Core/Script.hpp>

class RotateScript : public Engine::Component, public Engine::Script {
private:
	float rate;

public:
	struct Data : Component::Data {
		float rate;
	};
	
	explicit RotateScript(const Data &data);
	virtual ~RotateScript();
	virtual void Start();
	virtual void Update();
};