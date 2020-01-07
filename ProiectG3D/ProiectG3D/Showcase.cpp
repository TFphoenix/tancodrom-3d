#include "Showcase.h"

Showcase::Showcase(Type type, const Transform& transform) :
	Object(transform),
	m_type(type),
	m_base(type, transform),
	m_frame(type, transform)
{
	// empty
}

void Showcase::UpdateThenDraw(const Camera& camera)
{
	m_base.UpdateThenDraw(camera);
	m_frame.UpdateThenDraw(camera);
}

Showcase::Base::Base(Type type, const Transform& transform) :Object(transform)
{
	switch (type)
	{
	case RAMP:
		mesh = new Mesh("./resources/models/Miscellaneous/ramp.obj");
		break;
	case CLOSED_CAGE:
		mesh = new Mesh("./resources/models/Miscellaneous/cage_base.obj");
		break;
	case OPEN_CAGE:
		mesh = new Mesh("./resources/models/Miscellaneous/cage_base.obj");
		break;
	default:
		break;
	}
	shader = new Shader("./resources/shaders/LambertsLightShader");
	texture = new Texture("./resources/textures/black_metal3.jpg");
}

Showcase::Frame::Frame(Type type, const Transform& transform) : Object(transform)
{
	switch (type)
	{
	case RAMP:
		mesh = new Mesh("./resources/models/Miscellaneous/ramp_frame.obj");
		texture = new Texture("./resources/textures/stripes2_resized.jpg");
		break;
	case CLOSED_CAGE:
		mesh = new Mesh("./resources/models/Miscellaneous/cage_glass.obj");
		texture = new Texture("./resources/textures/transparent_glass.png");
		break;
	case OPEN_CAGE:
		mesh = new Mesh("./resources/models/Miscellaneous/cage_glass_small.obj");
		texture = new Texture("./resources/textures/transparent_glass.png");
		break;
	default:
		break;
	}
	shader = new Shader("./resources/shaders/basicShader");
}

void Showcase::Frame::Draw() const
{
	glCullFace(GL_FRONT);
	mesh->Draw();
	glCullFace(GL_BACK);
	mesh->Draw();
}
