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

	Vertex terrainVertices[] = {
		Vertex(glm::vec3(-100.0f,0.0f,-100.0f),	glm::vec2(0.5f,1.0f)),
		Vertex(glm::vec3(100.0f,0.0f,-100.0f),	glm::vec2(1.0f,0.0f)),
		Vertex(glm::vec3(-100.0f,0.0f,100.0f),	glm::vec2(0.0f,0.0f)),
		Vertex(glm::vec3(100.0f,0.0f,100.0f),	glm::vec2(1.0f,1.0f))
	};
	unsigned indices[] = { 2,1,0,
							1,2,3 };

	// Meshes
	Mesh terrainMesh(terrainVertices, sizeof(terrainVertices) / sizeof(terrainVertices[0]), indices, sizeof(indices) / sizeof(indices[0]));
	Mesh tankMesh("./resources/models/tank_full.obj");
	// Shaders
	Shader basicShader("./resources/basicShader");
	Shader lambertShader("./resources/LambertsLightShader");
	// Textures
	Texture grassTexture("./resources/textures/grass.jpg");
	Texture tankTexture("./resources/textures/green.jpg");
	// Camera & Transform
	Camera camera(glm::vec3(0, 10, -10), 70.0f, static_cast<float>(Settings::WindowWidth) / Settings::WindowHeight, 0.01f, 1000.0f);
	display.SetCamera(camera);
	Transform transform;

	// Render loop
	while (!display.IsClosed())
	{
		display.Clear(0.0f, 0.15f, 0.3f);

		basicShader.Bind();
		basicShader.Update(transform, camera);
		grassTexture.Bind(0);
		terrainMesh.Draw();

		lambertShader.Bind();
		lambertShader.Update(transform, camera);
		tankTexture.Bind(0);
		tankMesh.Draw();

		display.Update();
	}

	return 0;
}
