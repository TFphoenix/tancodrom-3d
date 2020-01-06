#include "DirtStadium.h"

DirtStadium::DirtStadium(const Transform& transform) :
	Object(transform),
	m_dirtMesh("./resources/models/DirtStadium/dirt.obj"),
	m_borderMesh("./resources/models/DirtStadium/border.obj"),
	m_dirtTexture("./resources/textures/dirt.jpg"),
	m_borderTexture("./resources/textures/concrete.jpg"),
	m_tank1(Tank::CLASSIC, transform),
	m_tank2(Tank::DOUBLE, transform),
	m_incrementX(true),
	m_reversal(1)
{
	shader = new Shader("./resources/shaders/LambertsLightShader");

	// Tanks Animation
	m_tank1.GetTransform().GetPosition().x -= 50.0f;
	m_tank2.GetTransform().GetPosition().x += 50.0f;
	m_tank1.GetTransform().GetPosition().z -= 25.0f;
	m_tank2.GetTransform().GetPosition().z += 25.0f;

	m_tank1.GetTransform().GetRotation().y -= glm::radians(90.0f);
	m_tank2.GetTransform().GetRotation().y -= glm::radians(180.0f);

	m_tank1.SetRotateTurret(false);
	m_tank2.SetRotateTurret(false);

	m_tank1.GetTransform().GetPosition().y += 8.0f;
	m_tank2.GetTransform().GetPosition().y += 8.0f;
}

void DirtStadium::UpdateThenDraw(const Camera& camera)
{
	// Stadium
	shader->Bind();
	shader->Update(transform, camera);
	m_borderTexture.Bind(0);
	m_borderMesh.Draw();
	m_dirtTexture.Bind(0);
	m_dirtMesh.Draw();

	// Tanks
	if (m_incrementX)
	{
		m_tank1.GetTransform().GetPosition().x += 0.1f * m_reversal;
		m_tank2.GetTransform().GetPosition().x -= 0.1f * m_reversal;
		if (m_reversal > 0)
		{
			if (m_tank1.GetTransform().GetPosition().x >= transform.GetPosition().x + 70.0f)
			{
				m_incrementX = false;
				m_tank1.GetTransform().GetRotation().y -= glm::radians(90.0f);
				m_tank2.GetTransform().GetRotation().y -= glm::radians(90.0f);
			}
		}
		else
		{
			if (m_tank1.GetTransform().GetPosition().x <= transform.GetPosition().x - 70.0f)
			{
				m_incrementX = false;
				m_tank1.GetTransform().GetRotation().y -= glm::radians(90.0f);
				m_tank2.GetTransform().GetRotation().y -= glm::radians(90.0f);
			}
		}
	}
	else
	{
		m_tank1.GetTransform().GetPosition().z += 0.1f * m_reversal;
		m_tank2.GetTransform().GetPosition().z -= 0.1f * m_reversal;
		if (m_reversal > 0)
		{
			if (m_tank1.GetTransform().GetPosition().z >= transform.GetPosition().z + 25.0f)
			{
				m_incrementX = true;
				m_reversal = -m_reversal;
				m_tank1.GetTransform().GetRotation().y -= glm::radians(90.0f);
				m_tank2.GetTransform().GetRotation().y -= glm::radians(90.0f);
			}
		}
		else
		{
			if (m_tank1.GetTransform().GetPosition().z <= transform.GetPosition().z - 25.0f)
			{
				m_incrementX = true;
				m_reversal = -m_reversal;
				m_tank1.GetTransform().GetRotation().y -= glm::radians(90.0f);
				m_tank2.GetTransform().GetRotation().y -= glm::radians(90.0f);
			}
		}
	}
	m_tank1.UpdateThenDraw(camera);
	m_tank2.UpdateThenDraw(camera);
}
