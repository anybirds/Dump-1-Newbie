#pragma once

#include <../Core/Graphics/Texture.hpp>
#include <Common/ManagedObject.hpp>

namespace Engine {

	/*
	Represents a texture that has been created by loading images.
	*/
	public ref class Texture sealed : public ManagedObject<Core::Texture> {
	private:
		static System::Collections::Generic::Dictionary<System::String^, Texture^> ^m_textures;

	public:
		static Texture();
		static Texture^ Find(System::String ^name);

	private:
		System::String ^m_name;

	public:
		/*used in App, Editor*/
		Texture(System::String ^name, System::String ^path);
		
		virtual void Destroy() override;

		property System::String ^name {
			System::String ^get() {
				return m_name;
			}
			void set(System::String ^value) {
				m_textures->Remove(m_name);
				m_name = value;
				m_textures->Add(m_name, this);
			}
		}
	};
}
