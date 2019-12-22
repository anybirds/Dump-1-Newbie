#include <Material/DefaultMaterial.hpp>
#include <Scene/Scene.hpp>
#include <Script/RotateScript.hpp>
#include <Engine.hpp>

using namespace std;
using namespace glm;
using namespace Engine;

#define DEBUG

Scene::Scene() {
	Model bunny_model({ "Resource\\Model\\bunny_model.obj" }); // remove this from here: model should be converted to resources before scene creation
	
	ResourceManager::AddResource<Mesh>(Geometry::Square);
	ResourceManager::AddResource<Mesh>(bunny_model.MeshData(0));
	ResourceManager::AddResource<Texture>({ "bunny_texture", "Resource\\Texture\\bunny_texture.png" });
	ResourceManager::AddResource<DefaultMaterial>({ "bunny_material", "Resource\\Shader\\unlit_vert.glsl", "Resource\\Shader\\unlit_frag.glsl", ResourceManager::FindResource<Texture>("bunny_texture") });

	Object *camera = new Object({ "Camera", { vec3(0.0f, 0.0f, 5.0f), mat4(1.0f), vec3(1.0f), nullptr } });
	camera->AddComponent<Camera>({ camera, perspective(radians(60.0f), 800.0f / 600.0f, 0.1f, 1000.0f) }); // width / height
	
	Object *square = new Object({ "Square", { vec3(-2.0f, 0.0f, 0.0f), mat4(1.0f), vec3(1.0f) } });
	square->AddComponent<Renderer>({ square, ResourceManager::FindResource<Mesh>("square_mesh"), ResourceManager::FindResource<Material>("bunny_material") });
	
	Object *bunny = new Object({ "Bunny", { vec3(2.0f, 0.0f, 0.0f), rotate(mat4(1.0f), radians(90.0f), vec3(0.0f, 1.0f, 0.0f)), vec3(2.0f) } });
	bunny->AddComponent<Renderer>({ bunny, ResourceManager::FindResource<Mesh>("bunny_mesh"), ResourceManager::FindResource<Material>("bunny_material") });
	bunny->AddComponent<RotateScript>({ bunny, 90.0f });
	
	Camera::SetCurrentCamera(*World::FindObject("Camera")->GetComponent<Camera>()); // scene should have current camera settings

#ifdef DEBUG
	cout << '[' << __FUNCTION__ << ']' << " Scene created." << endl;
#endif
}

Scene::Scene(const char *name) {

}

Scene::~Scene() {
	// track objects and resources by adding scene name to each 
}

