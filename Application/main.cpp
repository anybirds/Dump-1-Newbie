#include <Engine.hpp>

#ifdef DEBUG_APPLICATION
#define DEBUG
#endif

using namespace std;
using namespace glm;
using namespace Engine;

int main(int argc, char **argv) {
	// replace this code block to Engine::Init();
	Window window({ __FUNCTION__, 800, 600 }); // replace this code to Window::Init({});
	Resource::Init(); // replace this to Resource::Init({""});

	Scene scene; // replace this to Scene scene({""});

	scene.Start();

	while (!window.Closed()) {
		Time::Update();

		scene.Update();
		scene.Render();
		
		window.SwapBuffers();
		glfwPollEvents(); // replace this to Input static function
	}
}