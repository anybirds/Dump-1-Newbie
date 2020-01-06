#pragma once

#include <Common/Component.hpp>

namespace Core {
	class Script final : public Component {
	public:
		Script(GameObject *object);
		~Script();
	};
}