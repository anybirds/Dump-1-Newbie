#pragma once

namespace Engine {
	
	ref class GameObject;

	public interface class IComponent {
		property GameObject ^gameObject {
			virtual GameObject ^get();
		}
	};
}