#include "DirtStadium.h"

DirtStadium::DirtStadium(const Transform& transform) :
	Object(transform),
	m_dirtMesh("./resources/models/DirtStadium/dirt.obj"),
	m_borderMesh("./resources/models/DirtStadium/border.obj"),
	m_dirtTexture("./resources/textures/dirt.jpg"),
	m_borderTexture("./resources/textures/concrete.jpg")
{
	shader = new Shader("./resources/shaders/LambertsLightShader");
}

void DirtStadium::UpdateThenDraw(const Camera& camera)
{
	shader->Bind();
	shader->Update(transform, camera);
	m_borderTexture.Bind(0);
	m_borderMesh.Draw();
	m_dirtTexture.Bind(0);
	m_dirtMesh.Draw();
}
