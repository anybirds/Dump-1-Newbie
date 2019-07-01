#include <Window.hpp>

using namespace Engine;

/*
"test_window" tests if the window creation is successful. 
The result should be a black background window "test_window" with the size of 800 * 600.
*/
int test_window(int argc, char **argv) {
	Window window(800, 600, __FUNCTION__);
	while (!window.Closed()) {
		window.SwapBuffers();
		glfwPollEvents();
	}

	return 0;
}