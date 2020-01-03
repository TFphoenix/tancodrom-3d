#include "Tank.h"

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
	// empty
}

void Tank::UpdateThenDraw(const Camera& camera)
{
	m_base.UpdateThenDraw(camera);
	m_turret.UpdateThenDraw(camera);
	m_tracks.UpdateThenDraw(camera);
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
		texture = new Texture("./resources/textures/green_metal3.jpg");
		break;
	case CLASSIC:
		mesh = new Mesh("./resources/models/" + s_classicFile + "/base.obj");
		texture = new Texture("./resources/textures/brown_metal.jpg");
		break;
	case DOUBLE:
		mesh = new Mesh("./resources/models/" + s_doubleFile + "/base.obj");
		texture = new Texture("./resources/textures/green_camo.jpg");
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

Tank::Turret::Turret(Type type, const Transform& transform) :Object(transform)
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
	transform.GetRotation().y += 0.001f;
}

Tank::Tracks::Tracks(Type type, const Transform& transform) :Object(transform)
{
	switch (type)
	{
	case TURTLE:
		mesh = new Mesh("./resources/models/" + s_turtleFile + "/tracks.obj");
		break;
	case CLASSIC:
		mesh = new Mesh("./resources/models/" + s_classicFile + "/tracks.obj");
		break;
	case DOUBLE:
		mesh = new Mesh("./resources/models/" + s_doubleFile + "/tracks.obj");
		break;
	default:
		throw std::invalid_argument("Undefined tank type");
	}
	shader = new Shader("./resources/shaders/LambertsLightShader");
	texture = new Texture("./resources/textures/tracked_2.jpg");
}

void Tank::Tracks::Update(const Camera& camera)
{
	shader->Bind();
	shader->Update(transform, camera);
	texture->Bind(0);
}
