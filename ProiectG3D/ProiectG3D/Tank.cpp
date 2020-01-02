#include "Tank.h"

Tank::Tank()
{
	// currently empty
}

void Tank::UpdateThenDraw(const Camera& camera)
{
	m_base.UpdateThenDraw(camera);
	m_turret.UpdateThenDraw(camera);
	//m_tracks.UpdateThenDraw(camera);
}

void Tank::Update(const Camera& camera)
{
	m_base.Update(camera);
	m_turret.Update(camera);
	m_tracks.Update(camera);
}

void Tank::Draw() const
{
	m_base.Draw();
	m_turret.Draw();
	m_tracks.Draw();
}

Tank::Base::Base()
{
	mesh = new Mesh("./resources/models/TeoTank/base.obj");
	shader = new Shader("./resources/shaders/LambertsLightShader");
	texture = new Texture("./resources/textures/green_camo.jpg");
}

void Tank::Base::Update(const Camera& camera)
{
	shader->Bind();
	shader->Update(transform, camera);
	texture->Bind(0);
}

Tank::Turret::Turret()
{
	mesh = new Mesh("./resources/models/TeoTank/turret.obj");
	shader = new Shader("./resources/shaders/LambertsLightShader");
	texture = new Texture("./resources/textures/green_camo.jpg");
}

void Tank::Turret::Update(const Camera& camera)
{
	shader->Bind();
	shader->Update(transform, camera);
	texture->Bind(0);
	transform.GetRotation().y += 0.001f;
}

Tank::Tracks::Tracks()
{
	mesh = new Mesh("./resources/models/LowPolyTank1/tracks.obj");
	shader = new Shader("./resources/shaders/LambertsLightShader");
	texture = new Texture("./resources/textures/green.jpg");
}

void Tank::Tracks::Update(const Camera& camera)
{
	shader->Bind();
	shader->Update(transform, camera);
	texture->Bind(0);
}
