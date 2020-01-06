#include "Vegetation.h"

Vegetation::Vegetation(Type type, const Transform& transform) : Object(transform), rotations({ 0,45,90 })
{
	this->transform.GetScale().x = (3.0f);
	this->transform.GetScale().y = (3.0f);
	this->transform.GetScale().z = (3.0f);
	
	switch (type)
	{
	case Vegetation::Type::FLOWER:
		mesh = new Mesh("./resources/models/flower.obj");
		texture = new Texture("./resources/textures/flower.png");
		break;
	case Vegetation::Type::GRASS:
		mesh = new Mesh("./resources/models/grass.obj");
		texture = new Texture("./resources/textures/grass.png");
		break;
	case Vegetation::Type::BUSH:
		mesh = new Mesh("./resources/models/bush.obj");
		texture = new Texture("./resources/textures/bush.png");
		break;
	default:
		break;
	}
	shader = new Shader("./resources/shaders/basicShader");

}

void Vegetation::UpdateThenDraw(const Camera& camera)
{
	shader->Bind();
	texture->Bind(0);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);

	for (auto grade : rotations)
	{
		transform.GetRotation().y = glm::radians(grade);
		shader->Update(transform, camera);
		glCullFace(GL_FRONT);
		mesh->Draw();
		glCullFace(GL_BACK);
		mesh->Draw();
	}

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
}
