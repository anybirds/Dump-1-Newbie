#include <Window.hpp>

using namespace Engine;

/*
"test_window" tests if the window creation is successful. 
The result should be a black background window "test_window" with the size of 800 * 600.
*/
int test_window(int argc, char **argv) {
	Window::Initialize();
	Window window(800, 600, "test_window");
	window.Viewport(0, 0, 800, 600);
	while (!window.Closed()) {
		window.SwapBuffers();
		glfwPollEvents();
	}
	Window::Terminate();

	return 0;
}