#include "Tank.h"
#include<stdexcept>

// File Paths
const std::string Tank::s_turtleFile("FINAL/Turtle");
const std::string Tank::s_classicFile("FINAL/Classic");
const std::string Tank::s_doubleFile("FINAL/Double");

Tank::Tank(Type type, const Transform& transform) :
	Object(transform),
	m_base(type, transform),
	m_turret(type, transform),
	m_tracks(type, transform),
	m_type(type)
{
	m_turret.m_rotate = true;
}

void Tank::UpdateThenDraw(const Camera& camera)
{
	m_base.transform = transform;
	m_base.UpdateThenDraw(camera);
	m_turret.transform.SetPosition(transform.GetPosition());
	if (m_turret.m_rotate == false)
	{
		m_turret.transform.SetRotation(transform.GetRotation());
		m_turret.transform.SetScale(transform.GetScale());
	}
	m_turret.UpdateThenDraw(camera);
	m_tracks.transform = transform;
	m_tracks.UpdateThenDraw(camera);
}

void Tank::SetRotateTurret(bool rotateTurret)
{
	m_turret.m_rotate = rotateTurret;
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

Tank::Base::Base(Type type, const Transform& transform) :Object(transform)
{
	switch (type)
	{
	case TURTLE:
		mesh = new Mesh("./resources/models/" + s_turtleFile + "/base.obj");
		texture = new Texture("./resources/textures/camo2.jpeg");
		break;
	case CLASSIC:
		mesh = new Mesh("./resources/models/" + s_classicFile + "/base.obj");
		texture = new Texture("./resources/textures/brown_metal.jpg");
		break;
	case DOUBLE:
		mesh = new Mesh("./resources/models/" + s_doubleFile + "/base.obj");
		texture = new Texture("./resources/textures/green_camo.jpg");
		break;
	case OLD:
		mesh = new Mesh("./resources/models/FINAL/MC1/base.obj");
		texture = new Texture("./resources/textures/green_metal3.jpg");
		break;
	default:
		throw std::invalid_argument("Undefined tank type");
	}
	shader = new Shader("./resources/shaders/LambertsLightShader");
}

void Tank::Base::Update(const Camera& camera)
{
	shader->Bind();
	shader->Update(transform, camera);
	texture->Bind(0);
}

Tank::Turret::Turret(Type type, const Transform& transform) :Object(transform), m_rotate(true)
{
	switch (type)
	{
	case TURTLE:
		mesh = new Mesh("./resources/models/" + s_turtleFile + "/turret.obj");
		texture = new Texture("./resources/textures/green_metal3.jpg");
		break;
	case CLASSIC:
		mesh = new Mesh("./resources/models/" + s_classicFile + "/turret.obj");
		texture = new Texture("./resources/textures/brown_camo.jpeg");
		break;
	case DOUBLE:
		mesh = new Mesh("./resources/models/" + s_doubleFile + "/turret.obj");
		texture = new Texture("./resources/textures/green_camo.jpg");
		break;
	case OLD:
		mesh = new Mesh("./resources/models/FINAL/MC1/turret.obj");
		texture = new Texture("./resources/textures/green_metal3.jpg");
		break;
	default:
		throw std::invalid_argument("Undefined tank type");
	}
	shader = new Shader("./resources/shaders/LambertsLightShader");
}

void Tank::Turret::Update(const Camera& camera)
{
	shader->Bind();
	shader->Update(transform, camera);
	texture->Bind(0);
	if (m_rotate)
		transform.GetRotation().y += 0.005f;
	else
		transform.SetRotation(glm::vec3(0, 0, 0));
}

Tank::Tracks::Tracks(Type type, const Transform& transform) :Object(transform)
{
	switch (type)
	{
	case TURTLE:
		mesh = new Mesh("./resources/models/" + s_turtleFile + "/tracks.obj");
		texture = new Texture("./resources/textures/tracked_2.jpg");
		break;
	case CLASSIC:
		mesh = new Mesh("./resources/models/" + s_classicFile + "/tracks.obj");
		texture = new Texture("./resources/textures/tracked_2.jpg");
		break;
	case DOUBLE:
		mesh = new Mesh("./resources/models/" + s_doubleFile + "/tracks.obj");
		texture = new Texture("./resources/textures/tracked_2.jpg");
		break;
	case OLD:
		mesh = new Mesh("./resources/models/FINAL/MC1/tracks.obj");
		texture = new Texture("./resources/textures/black_metal4.jpg");
		break;
	default:
		throw std::invalid_argument("Undefined tank type");
	}
	shader = new Shader("./resources/shaders/LambertsLightShader");
	
}

void Tank::Tracks::Update(const Camera& camera)
{
	shader->Bind();
	shader->Update(transform, camera);
	texture->Bind(0);
}
