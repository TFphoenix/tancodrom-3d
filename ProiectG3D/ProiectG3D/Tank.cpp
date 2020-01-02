#include "Tank.h"

Tank::Tank()
{
	// currently empty
}

void Tank::UpdateThenDraw(const Camera& camera)
{
	m_base.UpdateThenDraw(camera);
	m_turret.UpdateThenDraw(camera);
}

void Tank::Update(const Camera& camera)
{
	m_base.Update(camera);
	m_turret.Update(camera);
}

void Tank::Draw() const
{
	m_base.Draw();
	m_turret.Draw();
}

Tank::Base::Base()
{
	mesh = new Mesh("./resources/models/LowPolyTank1/body.obj");
	shader = new Shader("./resources/shaders/LambertsLightShader");
	texture = new Texture("./resources/textures/green.jpg");
	transform.GetPosition().y += 0.1f;
}

void Tank::Base::Update(const Camera& camera)
{
	shader->Bind();
	shader->Update(transform, camera);
	texture->Bind(0);
}

Tank::Turret::Turret()
{
	mesh = new Mesh("./resources/models/LowPolyTank1/turret.obj");
	shader = new Shader("./resources/shaders/LambertsLightShader");
	texture = new Texture("./resources/textures/green.jpg");
	transform.GetPosition().y += 0.2f;
}

void Tank::Turret::Update(const Camera& camera)
{
	shader->Bind();
	shader->Update(transform, camera);
	texture->Bind(0);
	transform.GetRotation().y += 0.001f;
}
