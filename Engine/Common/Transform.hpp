#pragma once 

#using <System.Numerics.dll>

#include <glm/glm.hpp>

#include <../Core/Common/Transform.hpp>
#include <Common/ManagedObject.hpp>

namespace Engine {

	/*
	Transform that has position, rotation, scale and hierarchical parent information.
	*/
	public ref class Transform : ManagedObject<Core::Transform> {
	private:
		Transform ^m_parent;

	public:
		Transform();

		property System::Numerics::Vector3 position {
			System::Numerics::Vector3 get() {
				const glm::vec3 &pos = instance->GetPosition();
				return System::Numerics::Vector3(pos.x, pos.y, pos.z);
			}
			void set(System::Numerics::Vector3 value) {
				instance->SetPosition(glm::vec3(value.X, value.Y, value.Z));
			}
		}
		
		property System::Numerics::Matrix4x4 rotation {
			System::Numerics::Matrix4x4 get() {
				const glm::mat4 &rot = instance->GetRotation();
				return System::Numerics::Matrix4x4(
					rot[0][0], rot[0][1], rot[0][2], rot[0][3],
					rot[1][0], rot[1][1], rot[1][2], rot[1][3],
					rot[2][0], rot[2][1], rot[2][2], rot[2][3],
					rot[3][0], rot[3][1], rot[3][2], rot[3][3]
					);
			}
			void set(System::Numerics::Matrix4x4 value) {
				instance->SetRotation(glm::mat4(
					value.M11, value.M12, value.M13, value.M14,
					value.M21, value.M22, value.M23, value.M24,
					value.M31, value.M32, value.M33, value.M34,
					value.M41, value.M42, value.M43, value.M44
				));
			}
		}

		property System::Numerics::Vector3 scale {
			System::Numerics::Vector3 get() {
				const glm::vec3 &scl = instance->GetScale();
				return System::Numerics::Vector3(scl.x, scl.y, scl.z);
			}

			void set(System::Numerics::Vector3 value) {
				instance->SetScale(glm::vec3(value.X, value.Y, value.Z));
			}
		}

		property Transform ^parent {
			Transform ^get() {
				return m_parent;
			}
			void set(Transform ^value) {
				/*todo: must prevent cyclic dependency*/
				instance->SetParent(value->instance);
				m_parent = value;
			}
		}

		property System::Numerics::Matrix4x4 matrix {
			System::Numerics::Matrix4x4 get() {
				const glm::mat4 &mat = instance->GetMatrix();
				return System::Numerics::Matrix4x4(
					mat[0][0], mat[0][1], mat[0][2], mat[0][3],
					mat[1][0], mat[1][1], mat[1][2], mat[1][3],
					mat[2][0], mat[2][1], mat[2][2], mat[2][3],
					mat[3][0], mat[3][1], mat[3][2], mat[3][3]
				);
			}
		}
	};
}