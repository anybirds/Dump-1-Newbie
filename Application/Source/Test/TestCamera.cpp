#include <Engine.hpp>

#include <Material/DefaultMaterial.hpp>
#include <Mesh/Geometry.hpp>

#ifdef DEBUG_APPLICATION
#define DEBUG
#endif

using namespace std;
using namespace glm;
using namespace Engine;

int test_camera(int argc, char **argv) {
	Window window(800, 600, __FUNCTION__);

#ifdef DEBUG
	cout << '[' << __FUNCTION__ << ']' << " window creation done ..." << endl;
#endif

	Mesh cube_mesh(Geometry::Cube);

#ifdef DEBUG
	cout << '[' << __FUNCTION__ << ']' << " mesh creation done ..." << endl;
#endif

	string vert_path = "Resource\\Shader\\test_camera_vertexshader.glsl";
	string frag_path = "Resource\\Shader\\test_camera_fragmentshader.glsl";
	DefaultMaterial material(vert_path, frag_path);

#ifdef DEBUG
	cout << '[' << __FUNCTION__ << ']' << " material shader compilation done ... " << endl;
#endif

	Transform cube_transform;

#ifdef DEBUG
	cout << '[' << __FUNCTION__ << ']' << " transform matrix calculation done ... " << endl;
#endif

	vec3 camera_pos(3.0f, 3.0f, 10.0f);
	Transform camera_transform(camera_pos);
	mat4 projection_normalization(perspective(radians(60.0f), (float)window.Width() / (float)window.Height(), 0.1f, 1000.0f));
	Camera camera(camera_transform, projection_normalization);

#ifdef DEBUG
	cout << '[' << __FUNCTION__ << ']' << " camera configuration done ... " << endl;
#endif

	Renderer::Camera(camera);
	Renderer cube_renderer(cube_mesh, material, cube_transform);

#ifdef DEBUG
	cout << '[' << __FUNCTION__ << ']' << " renderer configuration done ... " << endl;
#endif

	while (!window.Closed()) {
		cube_renderer.Render();
		
		window.SwapBuffers();
		glfwPollEvents();
	}
	return 0;
	
}