#pragma once

namespace Engine {
	template <typename T>
	public ref class ManagedObject {
	private:
		T *m_instance;
		
	protected:
		ManagedObject(T *instance) : m_instance(instance) {}

	public:
		virtual ~ManagedObject() {
			delete instance;
		}

		!ManagedObject() {
			delete instance;
		}

		virtual void Destroy() {
			delete instance;
			instance = nullptr;
		}
		virtual bool IsEmpty() {
			return !instance;
		}

		property T *instance {
			T *get() {
				return m_instance;
			}
			void set(T *value) {
				m_instance = value;
			}
		}
	};
}