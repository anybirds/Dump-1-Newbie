#include <Engine.hpp>

#include <Material/DefaultMaterial.hpp>
#include <Mesh/Geometry.hpp>
#include <Test/Test.hpp>

#ifdef DEBUG_APPLICATION
#define DEBUG
#endif

using namespace std;
using namespace glm;
using namespace Engine;

int Test::TestGraphics(int argc, char **argv) {
	Window window(800, 600, __FUNCTION__);

#ifdef DEBUG
	cout << '[' << __FUNCTION__ << ']' << " window creation done ..." << endl;
#endif
	
	Mesh square_mesh(Geometry::Square);
	
	Model model("Resource\\Model\\bunny_model.obj");
	Mesh bunny_mesh(model.Mesh());

#ifdef DEBUG
	cout << '[' << __FUNCTION__ << ']' << " mesh creation done ..." << endl;
#endif

	string vert_path = "Resource\\Shader\\test_graphics_vert.glsl";
	string frag_path = "Resource\\Shader\\test_graphics_frag.glsl";
	DefaultMaterial material(vert_path, frag_path);

#ifdef DEBUG
	cout << '[' << __FUNCTION__ << ']' << " material shader compilation done ..." << endl;
#endif

	Texture texture("Resource\\Texture\\bunny_texture.png");
	material.Texture(texture);

#ifdef DEBUG
	cout << '[' << __FUNCTION__ << ']' << " texture loading done ..." << endl;
#endif

	// square at the left, bunny at the right
	Transform square_transform(vec3(-2.0f, 0.0f, 0.0f));
	Transform bunny_transform(vec3(2.0f, 0.0f, 0.0f), glm::rotate(mat4(1.0f), radians(90.0f), vec3(0.0f, 1.0f, 0.0f)), vec3(2.0f));

#ifdef DEBUG
	cout << '[' << __FUNCTION__ << ']' << " transform matrix calculation done ..." << endl;
#endif

	vec3 camera_pos(0.0f, 0.0f, 5.0f);
	Transform camera_transform(camera_pos);
	mat4 projection_normalization(perspective(radians(60.0f), (float)window.Width() / (float)window.Height(), 0.1f, 1000.0f));
	Camera camera(camera_transform, projection_normalization);

#ifdef DEBUG
	cout << '[' << __FUNCTION__ << ']' << " camera configuration done ..." << endl;
#endif

	Renderer::Camera(camera);
	Renderer square_renderer(square_mesh, material, square_transform);
	Renderer bunny_renderer(bunny_mesh, material, bunny_transform);
		
#ifdef DEBUG
	cout << '[' << __FUNCTION__ << ']' << " renderer configuration done ... " << endl;
#endif

	while (!window.Closed()) {
		square_renderer.Render();
		bunny_renderer.Render();

		window.SwapBuffers();
		glfwPollEvents();
	}
	return 0;
}