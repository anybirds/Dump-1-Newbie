#pragma once

#include <../Core/Graphics/Shader.hpp>
#include <Common/ManagedObject.hpp>

namespace Engine {
	public enum class ShaderType {
		Vertex,
		Fragment
	};

	public ref class Shader : ManagedObject<Core::Shader> {
	private:
		static System::Collections::Generic::Dictionary<System::String^, Shader^> ^m_shaders;

	public:
		static Shader();
		static Shader^ Find(System::String ^name);

	private:
		System::String ^m_name;

	public:
		Shader(System::String ^name, ShaderType type, System::String ^path);
		
		void Destroy() override;

		property System::String ^name {
			System::String ^get() {
				return m_name;
			}
			void set(System::String ^value) {
				m_shaders->Remove(m_name);
				m_name = value;
				m_shaders->Add(m_name, this);
			}
		}
	};
}