#include <GL/glew.h>
#include "Display.h"
#include "Shader.h"
#include "Mesh.h"
#include "Texture.h"
#include "Transform.h"
#include "Settings.h"

int main()
{
	Display display(Settings::WindowWidth, Settings::WindowHeight, "G3D - Tancodrom & Elicoptere");

	Vertex planeVertices[] = {
		Vertex(glm::vec3(-100.0f,0.0f,-100.0f),	glm::vec2(0.5f,1.0f)),
		Vertex(glm::vec3(100.0f,0.0f,-100.0f),	glm::vec2(1.0f,0.0f)),
		Vertex(glm::vec3(-100.0f,0.0f,100.0f),	glm::vec2(0.0f,0.0f)),
		Vertex(glm::vec3(100.0f,0.0f,100.0f),	glm::vec2(1.0f,1.0f))
	};
	unsigned indices[] = { 2,1,0,
							1,2,3 };

	Mesh planeMesh(planeVertices, sizeof(planeVertices) / sizeof(planeVertices[0]), indices, sizeof(indices) / sizeof(indices[0]));
	Mesh tankMesh("./resources/models/tank_full.obj");
	Shader shader("./resources/testShader");
	Texture grassTexture("./resources/textures/grass.jpg");
	Texture tankTexture("./resources/textures/dark_green.jpg");
	Camera camera(glm::vec3(0, 10, -10), 70.0f, static_cast<float>(Settings::WindowWidth) / Settings::WindowHeight, 0.01f, 1000.0f);
	display.SetCamera(camera);
	Transform transform;

	/*float counter = 0.0f;
	transform.GetRotation().y = 60;*/

	while (!display.IsClosed())
	{
		display.Clear(0.0f, 0.15f, 0.3f);

		/*transform.GetPosition().x = sinf(counter);
		transform.GetRotation().y = sinf(counter)*cosf(counter);*/

		shader.Bind();
		shader.Update(transform, camera);

		grassTexture.Bind(0);
		planeMesh.Draw();

		tankTexture.Bind(0);
		tankMesh.Draw();

		display.Update();
		/*counter += 0.001f;*/
	}

	return 0;
}
