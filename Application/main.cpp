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

#ifdef DEBUG
	cout << '[' << __FUNCTION__ << ']' << " window creation done ..." << endl;
#endif

	Mesh square_mesh(Geometry::Square);

	Model model({ "Resource\\Model\\bunny_model.obj" });
	Mesh bunny_mesh(model.MeshDetail());

#ifdef DEBUG
	cout << '[' << __FUNCTION__ << ']' << " mesh creation done ..." << endl;
#endif

	Texture texture({ "Resource\\Texture\\bunny_texture.png" });

	DefaultMaterial material({
		"Resource\\Shader\\test_graphics_vert.glsl" ,
		"Resource\\Shader\\test_graphics_frag.glsl" ,
		&texture
		});

#ifdef DEBUG
	cout << '[' << __FUNCTION__ << ']' << " material shader compilation done ..." << endl;
#endif

	CameraObject camera({
		{ { vec3(0.0f, 0.0f, 5.0f), mat4(1.0f), vec3(1.0f), nullptr } },
		{ perspective(radians(60.0f), (float)window.Width() / (float)window.Height(), 0.1f, 1000.0f) }
		});

	CameraObject::Current(camera);

#ifdef DEBUG
	cout << '[' << __FUNCTION__ << ']' << " camera configuration done ..." << endl;
#endif

	// square at the left, bunny at the right
	DrawableObject square({
		{ { vec3(-2.0f, 0.0f, 0.0f), mat4(1.0f), vec3(1.0f) } },
		{ &square_mesh, &material }
		});

	DrawableObject bunny({
		{ { vec3(2.0f, 0.0f, 0.0f), rotate(mat4(1.0f), radians(90.0f), vec3(0.0f, 1.0f, 0.0f)), vec3(2.0f) } },
		{ &bunny_mesh, &material }
		});

#ifdef DEBUG
	cout << '[' << __FUNCTION__ << ']' << " object creation done ..." << endl;
#endif

	while (!window.Closed()) {
		square.Renderer().Render();
		bunny.Renderer().Render();

		window.SwapBuffers();
		glfwPollEvents();
	}
	return 0;
}