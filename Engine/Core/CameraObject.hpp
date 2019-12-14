#pragma once

#include <glm/glm.hpp>

#include <Core/Object.hpp>
#include <Graphics/Camera.hpp>

namespace Engine {

	/*
	CameraObject

	Camera object in the scene.
	 */
	class CameraObject : public Object {
	private:
		static const CameraObject *current;

	public:
		static const CameraObject *Current() { return current; }
		static void Current(const CameraObject &current) { CameraObject::current = &current; }

	private:
		Camera camera;

	public:
		struct Detail {
			Object::Detail Object;
			Camera::Detail Camera;
		};

		explicit CameraObject(const Detail &camera_object);
		virtual ~CameraObject();

		const Engine::Camera& Camera() const { return camera; }
	};
}