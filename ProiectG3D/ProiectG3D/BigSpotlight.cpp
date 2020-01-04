#include "BigSpotlight.h"

BigSpotlight::BigSpotlight(const Transform& transform) :
	Object(transform),
	m_pillarMesh("./resources/models/BigSpotlight/pillar.obj"),
	m_panelMesh("./resources/models/BigSpotlight/panel.obj"),
	m_pillarTexture("./resources/textures/black_metal.jpg"),
	m_panelTexture("./resources/textures/spotlight.jpg"),
	m_pillarShader("./resources/shaders/LambertsLightShader"),
	m_panelShader("./resources/shaders/basicShader")
{
	// empty
}

void BigSpotlight::UpdateThenDraw(const Camera& camera)
{
	// Pillar
	m_pillarShader.Bind();
	m_pillarShader.Update(transform, camera);
	m_pillarTexture.Bind(0);
	m_pillarMesh.Draw();

	// Panel
	m_panelShader.Bind();
	m_panelShader.Update(transform, camera);
	m_panelTexture.Bind(0);
	m_panelMesh.Draw();
}
