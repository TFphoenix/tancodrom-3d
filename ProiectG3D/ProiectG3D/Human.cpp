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
		texture = new Texture("./resources/textures/skin1.jpg");
		mesh = new Mesh("./resources/models/Crowd/hands.obj");
		break;
	case OLGA:
		texture = new Texture("./resources/textures/skin2.jpg");
		mesh = new Mesh("./resources/models/Crowd/hands.obj");
		break;
	case STEVE:
		texture = new Texture("./resources/textures/skin1.jpg");
		mesh = new Mesh("./resources/models/Crowd/hands.obj");
		break;
	case OLGA_CROSSED:
		texture = new Texture("./resources/textures/skin2.jpg");
		mesh = new Mesh("./resources/models/Crowd/hands_crossed.obj");
		break;
	case STEVE_CROSSED:
		texture = new Texture("./resources/textures/skin1.jpg");
		mesh = new Mesh("./resources/models/Crowd/hands_crossed.obj");
		break;
	default:
		texture = new Texture("./resources/textures/skin2.jpg");
		mesh = new Mesh("./resources/models/Crowd/hands.obj");
	}
	
	shader = new Shader("./resources/shaders/basicShader");
}

Human::Feet::Feet(Type type, const Transform& transform) : Object(transform)
{
	switch (type)
	{
	case JOHN:
		texture = new Texture("./resources/textures/blue_trousers.jpg");
		break;
	case OLGA:
		texture = new Texture("./resources/textures/green_camo.jpg");
		break;
	case STEVE:
		texture = new Texture("./resources/textures/green_camo2.jpg");
		break;
	case OLGA_CROSSED:
		texture = new Texture("./resources/textures/green_camo.jpg");
		break;
	case STEVE_CROSSED:
		texture = new Texture("./resources/textures/green_camo2.jpg");
		break;
	case DIANA:
		texture = new Texture("./resources/textures/pink_fabric.jpg");
		break;
	default:
		break;
	}
	mesh = new Mesh("./resources/models/Crowd/feet.obj");
	shader = new Shader("./resources/shaders/basicShader");
}

Human::Body::Body(Type type, const Transform& transform) : Object(transform)
{
	switch (type)
	{
	case JOHN:
		texture = new Texture("./resources/textures/blue_fabric.jpg");
		break;
	case OLGA:
		texture = new Texture("./resources/textures/green_camo.jpg");
		break;
	case STEVE:
		texture = new Texture("./resources/textures/green_camo2.jpg");
		break;
	case OLGA_CROSSED:
		texture = new Texture("./resources/textures/green_camo.jpg");
		break;
	case STEVE_CROSSED:
		texture = new Texture("./resources/textures/green_camo2.jpg");
		break;
	case DIANA:
		texture = new Texture("./resources/textures/shirt.jpg");
		break;
	default:
		break;
	}
	mesh = new Mesh("./resources/models/Crowd/body.obj");
	shader = new Shader("./resources/shaders/basicShader");
}

Human::Head::Head(Type type, const Transform& transform) : Object(transform)
{
	switch (type)
	{
	case JOHN:
		texture = new Texture("./resources/textures/face1.jpg");
		break;
	case OLGA:
		texture = new Texture("./resources/textures/face2.jpg");
		break;
	case STEVE:
		texture = new Texture("./resources/textures/face3.jpg");
		break;
	case OLGA_CROSSED:
		texture = new Texture("./resources/textures/face2.jpg");
		break;
	case STEVE_CROSSED:
		texture = new Texture("./resources/textures/face3.jpg");
		break;
	case DIANA:
		texture = new Texture("./resources/textures/face4.jpg");
		break;
	default:
		break;
	}
	mesh = new Mesh("./resources/models/Crowd/head_sphere.obj");
	shader = new Shader("./resources/shaders/basicShader");
}
