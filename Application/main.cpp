#include <Engine.hpp>

#include <Material/DefaultMaterial.hpp>
#include <Mesh/Geometry.hpp>

#ifdef DEBUG_APPLICATION
#define DEBUG
#endif

using namespace std;
using namespace glm;
using namespace Engine;

int main(int argc, char **argv) {
	Window window({ 800, 600, __FUNCTION__ });

	Resource::Load();
	Scene scene; // replace this to Scene scene("");
	scene.Start();

	while (!window.Closed()) {
		scene.Update();
		scene.Render();
		
		window.SwapBuffers();
		glfwPollEvents(); // replace this to Input static function
	}
}