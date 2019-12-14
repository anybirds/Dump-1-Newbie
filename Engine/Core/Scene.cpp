#include <../Application/Mesh/Geometry.hpp>
#include <../Application/Material/DefaultMaterial.hpp>
#include <Engine.hpp>

#ifdef DEBUG_CORE
#define DEBUG
#endif

using namespace std;
using namespace glm;
using namespace Engine;

Scene::Scene() {
	camera = new Object({ "Camera", { vec3(0.0f, 0.0f, 5.0f), mat4(1.0f), vec3(1.0f), nullptr } });
	camera->SetComponent<Camera>({ perspective(radians(60.0f), 800.0f / 600.0f, 0.1f, 1000.0f) }); // width / height

	Camera::Current(camera->GetComponent<Camera>());

	square = new Object({ "Square", { vec3(-2.0f, 0.0f, 0.0f), mat4(1.0f), vec3(1.0f) } });
	square->SetComponent<Renderer>({ "Square", "Bunny" });
	
	bunny = new Object({ "Bunny", { vec3(2.0f, 0.0f, 0.0f), rotate(mat4(1.0f), radians(90.0f), vec3(0.0f, 1.0f, 0.0f)), vec3(2.0f) } });
	bunny->SetComponent<Renderer>({ "Bunny", "Bunny" });

	/*
	camera = new CameraObject({
	{ { vec3(0.0f, 0.0f, 5.0f), mat4(1.0f), vec3(1.0f), nullptr } },
	{ perspective(radians(60.0f), 800.0f / 600.0f, 0.1f, 1000.0f) } // width / height
		});

	CameraObject::Current(*camera);

	// square at the left, bunny at the right
	square = new DrawableObject({
		{ { vec3(-2.0f, 0.0f, 0.0f), mat4(1.0f), vec3(1.0f) } },
		{ "Square", "Bunny" }
		});

	bunny = new DrawableObject({
		{ { vec3(2.0f, 0.0f, 0.0f), rotate(mat4(1.0f), radians(90.0f), vec3(0.0f, 1.0f, 0.0f)), vec3(2.0f) } },
		{ "Bunny", "Bunny" }
		});
	*/

#ifdef DEBUG
	cout << '[' << __FUNCTION__ << ']' << " Scene created." << endl;
#endif
}

Scene::~Scene() {

}

/*
template <typename ObjectType>
ObjectType& Scene::Instantiate(ObjectType::Detail object) {

}
*/

void Scene::Start() {

}

void Scene::Update() {

}

void Scene::Render() {
	square->GetComponent<Renderer>().Render();
	bunny->GetComponent<Renderer>().Render();
	/*
	square->Renderer().Render();
	bunny->Renderer().Render();
	*/
}