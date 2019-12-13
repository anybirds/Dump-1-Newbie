#pragma once

#include <glm/glm.hpp>

#include <Core/Object.hpp>
#include <Graphics/Camera.hpp>

namespace Engine {

	struct CameraObjectDetail {
		ObjectDetail Object;
		CameraDetail Camera;
	};

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
		CameraObject(const CameraObjectDetail &camera_object);
		virtual ~CameraObject();
		
		const Engine::Camera& Camera() const { return camera; }
	};
}