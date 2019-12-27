#pragma once
#include <glm/glm.hpp>

#include "Object.h"

class Terrain :public Object
{
public:
	Terrain();
	void Update(const Camera& camera) override;
};

inline Terrain::Terrain()
{
	// Build Mesh
	Vertex vertices[] = {
		Vertex(glm::vec3(-100.0f,0.0f,-100.0f),	glm::vec2(0.5f,1.0f)),
		Vertex(glm::vec3(100.0f,0.0f,-100.0f),	glm::vec2(1.0f,0.0f)),
		Vertex(glm::vec3(-100.0f,0.0f,100.0f),	glm::vec2(0.0f,0.0f)),
		Vertex(glm::vec3(100.0f,0.0f,100.0f),	glm::vec2(1.0f,1.0f))
	};
	unsigned indices[] = { 2,1,0,
							1,2,3 };

	// Initialize Object
	mesh = new Mesh(vertices, sizeof(vertices) / sizeof(vertices[0]), indices, sizeof(indices) / sizeof(indices[0]));
	shader = new Shader("./resources/basicShader");
	texture = new Texture("./resources/textures/grass.jpg");
}

inline void Terrain::Update(const Camera& camera)
{
	shader->Bind();
	shader->Update(transform, camera);
	texture->Bind(0);
}
