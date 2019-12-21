#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include <../Application/Script/RotateScript.hpp>
#include <Graphics/Camera.hpp>
#include <Core/Debug.hpp>
#include <Core/Object.hpp>
#include <Graphics/Renderer.hpp>
#include <Core/Scene.hpp>
#include <Core/Script.hpp>

#ifdef DEBUG_CORE
#define DEBUG
#endif

using namespace std;
using namespace glm;
using namespace Engine;

Scene::Scene() {
	Object *camera = new Object({ this, "Camera", { vec3(0.0f, 0.0f, 5.0f), mat4(1.0f), vec3(1.0f), nullptr } });
	camera->AddComponent<Camera>({ { camera }, perspective(radians(60.0f), 800.0f / 600.0f, 0.1f, 1000.0f) }); // width / height
	Camera::SetCurrentCamera(*camera->GetComponent<Camera>());

	Object *square = new Object({ this, "Square", { vec3(-2.0f, 0.0f, 0.0f), mat4(1.0f), vec3(1.0f) } });
	square->AddComponent<Renderer>({ { square }, "Square", "Bunny" });
	
	Object *bunny = new Object({ this, "Bunny", { vec3(2.0f, 0.0f, 0.0f), rotate(mat4(1.0f), radians(90.0f), vec3(0.0f, 1.0f, 0.0f)), vec3(2.0f) } });
	bunny->AddComponent<Renderer>({ { bunny }, "Bunny", "Bunny" });
	bunny->AddComponent<RotateScript>({ { bunny }, 90.0f });

	object.insert({ camera->GetName(), camera });
	object.insert({ square->GetName(), square });
	object.insert({ bunny->GetName(), bunny });
#ifdef DEBUG
	cout << '[' << __FUNCTION__ << ']' << " Scene created." << endl;
#endif
}

Scene::~Scene() {
	for (auto item : object) {
		delete item.second;
	}
}

void Scene::Start() {
	for (Script *item : script) {
		item->Start();
	}
}

void Scene::Update() {
	for (Script *item : script) {
		item->Update();
	}
}

void Scene::Render() {
	for (Renderer *item : renderer) {
		item->Render();
	}
}