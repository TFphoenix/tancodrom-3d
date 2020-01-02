#pragma once
#include "obj_loader.h"

#include <glm/glm.hpp>
#include <GL/glew.h>
#include <string>


struct Vertex
{
	Vertex(const glm::vec3& pos, const glm::vec2& texCoord, const glm::vec3& normal = glm::vec3(0, 0, 0)) :pos(pos), texCoord(texCoord), normal(normal) {}

	glm::vec3 pos;
	glm::vec2 texCoord;
	glm::vec3 normal;
};

class Mesh
{
public:
	Mesh(Vertex* vertices, unsigned numVertices, unsigned* indices, unsigned numIndices);
	Mesh(const std::string& fileName);
	virtual ~Mesh();
	Mesh(const Mesh& other) = delete;
	Mesh& operator=(const Mesh& other) = delete;

	void Draw();

private:
	void InitMesh(IndexedModel& model);

private:
	enum
	{
		POSITION_VB,
		TEXCOORD_VB,
		NORMAL_VB,
		INDEX_VB,

		NUM_BUFFERS
	};

private:
	GLuint m_vertexArrayObject;// VAO
	GLuint m_vertexArrayBuffers[NUM_BUFFERS];// VBO
	unsigned m_drawCount;

};

