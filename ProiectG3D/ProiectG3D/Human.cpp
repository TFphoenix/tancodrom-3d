#include "Human.h"

Human::Human(Type type, const Transform& transform) :
	Object(transform),
	m_type(type),
	m_hands(type, transform),
	m_body(type, transform),
	m_feet(type, transform),
	m_head(type, transform)
{
	// empty
}

void Human::UpdateThenDraw(const Camera& camera)
{
	m_body.UpdateThenDraw(camera);
	m_head.UpdateThenDraw(camera);
	m_hands.UpdateThenDraw(camera);
	m_feet.UpdateThenDraw(camera);
}

Human::Hands::Hands(Type type, const Transform& transform) : Object(transform)
{
	switch (type)
	{
	case JOHN:
		mesh = new Mesh("./resources/models/Crowd/hands.obj");
		texture = new Texture("./resources/textures/skin.jpg");
		break;
	default:
		break;
	}
	shader = new Shader("./resources/shaders/basicShader");
}

Human::Feet::Feet(Type type, const Transform& transform) : Object(transform)
{
	switch (type)
	{
	case JOHN:
		mesh = new Mesh("./resources/models/Crowd/feet.obj");
		texture = new Texture("./resources/textures/blue_trousers.jpg");
		break;
	default:
		break;
	}
	shader = new Shader("./resources/shaders/basicShader");
}

Human::Body::Body(Type type, const Transform& transform) : Object(transform)
{
	switch (type)
	{
	case JOHN:
		mesh = new Mesh("./resources/models/Crowd/body.obj");
		texture = new Texture("./resources/textures/blue_fabric.jpg");
		break;
	default:
		break;
	}
	shader = new Shader("./resources/shaders/basicShader");
}

Human::Head::Head(Type type, const Transform& transform) : Object(transform)
{
	switch (type)
	{
	case JOHN:
		mesh = new Mesh("./resources/models/Crowd/head.obj");
		texture = new Texture("./resources/textures/face_resized.jpg");
		break;
	default:
		break;
	}
	shader = new Shader("./resources/shaders/basicShader");
}
