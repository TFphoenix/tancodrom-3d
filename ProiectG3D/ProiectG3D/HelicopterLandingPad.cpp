#include "HelicopterLandingPad.h"


HelicopterLandingPad::HelicopterLandingPad(Transform transform) :
	Object(transform),
	m_panelMesh("./resources/models/HelicopterStand/HelicopterStand_panel.obj"),
	m_pillarMesh("./resources/models/HelicopterStand/HelicopterStand_base.obj"),
	m_ladderMesh("./resources/models/HelicopterStand/HelicopterStand_ladder.obj"),
	m_panelTexture("./resources/textures/helicopter_landing.jpg"),
	m_pillarTexture("./resources/textures/concrete.jpg"),
	m_ladderTexture("./resources/textures/yellow_metal.jpg")

{
	shader = new Shader("./resources/shaders/LambertsLightShader");
}

void HelicopterLandingPad::UpdateThenDraw(const Camera& camera)
{
	shader->Bind();
	shader->Update(transform, camera);
	m_pillarTexture.Bind(0);
	m_pillarMesh.Draw();
	m_panelTexture.Bind(0);
	m_panelMesh.Draw();
	m_ladderTexture.Bind(0);
	m_ladderMesh.Draw();
}
