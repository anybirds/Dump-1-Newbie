#include <Engine.hpp>

#include <Material/DefaultMaterial.hpp>

#ifdef DEBUG_APPLICATION
#define DEBUG
#endif

using namespace std;
using namespace glm;
using namespace Engine;

int test_mesh_model(int argc, char **argv) {
	Window window(800, 600, __FUNCTION__);

#ifdef DEBUG
	cout << '[' << __FUNCTION__ << ']' << " window creation done ..." << endl;
#endif

	Model model("Resource\\Model\\bunny_model.obj");
	Mesh bunny_mesh(model.Mesh());

#ifdef DEBUG
	cout << '[' << __FUNCTION__ << ']' << " mesh creation done ..." << endl;
#endif

	string vert_path = "Resource\\Shader\\test_mesh_model_vertexshader.glsl";
	string frag_path = "Resource\\Shader\\test_mesh_model_fragmentshader.glsl";
	DefaultMaterial material(vert_path, frag_path);

#ifdef DEBUG
	cout << '[' << __FUNCTION__ << ']' << " material shader compilation done ... " << endl;
#endif

	Transform bunny_transform;
	bunny_transform.Scale(vec3(0.5f));

#ifdef DEBUG
	cout << '[' << __FUNCTION__ << ']' << " transform matrix calculation done ... " << endl;
#endif

	vec3 camera_pos(0.0f, 0.0f, 5.0f);
	Transform camera_transform(camera_pos);
	mat4 projection_normalization(perspective(radians(60.0f), (float)window.Width() / (float)window.Height(), 0.1f, 1000.0f));
	Camera camera(camera_transform, projection_normalization);

#ifdef DEBUG
	cout << '[' << __FUNCTION__ << ']' << " camera configuration done ... " << endl;
#endif

	Renderer::Camera(camera);
	Renderer bunny_renderer(bunny_mesh, material, bunny_transform);

#ifdef DEBUG
	cout << '[' << __FUNCTION__ << ']' << " renderer configuration done ... " << endl;
#endif

	while (!window.Closed()) {
		bunny_renderer.Render();

		window.SwapBuffers();
		glfwPollEvents();
	}
	return 0;
}