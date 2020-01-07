#include "Hangar.h"

Hangar::Hangar(const Transform& transform) :
	Object(transform),
	m_base(transform),
	m_roof(transform),
	m_windows(transform),
	m_door(transform),
	m_garage(transform)
{
	// empty
}

void Hangar::UpdateThenDraw(const Camera& camera)
{
	glCullFace(GL_FRONT);
	m_base.UpdateThenDraw(camera);
	m_roof.UpdateThenDraw(camera);
	m_windows.UpdateThenDraw(camera);
	m_door.UpdateThenDraw(camera);
	m_garage.UpdateThenDraw(camera);
	glCullFace(GL_BACK);
	m_base.UpdateThenDraw(camera);
	m_roof.UpdateThenDraw(camera);
	m_windows.UpdateThenDraw(camera);
	m_door.UpdateThenDraw(camera);
	m_garage.UpdateThenDraw(camera);
}

Hangar::Base::Base(const Transform& transform) :
	Object(transform)
{
	shader = new Shader("./resources/shaders/basicShader");
	mesh = new Mesh("./resources/models/Hangar/base.obj");
	texture = new Texture("./resources/textures/green_metal5_resized.jpg");
}

Hangar::Roof::Roof(const Transform& transform) :
	Object(transform)
{
	shader = new Shader("./resources/shaders/basicShader");
	mesh = new Mesh("./resources/models/Hangar/roof.obj");
	texture = new Texture("./resources/textures/green_metal6.jpg");
}

Hangar::Windows::Windows(const Transform& transform) :
	Object(transform)
{
	shader = new Shader("./resources/shaders/basicShader");
	mesh = new Mesh("./resources/models/Hangar/windows.obj");
	texture = new Texture("./resources/textures/window.png");
}

Hangar::Door::Door(const Transform& transform) :
	Object(transform)
{
	shader = new Shader("./resources/shaders/basicShader");
	mesh = new Mesh("./resources/models/Hangar/door.obj");
	texture = new Texture("./resources/textures/door.jpg");
}

Hangar::Garage::Garage(const Transform& transform) :
	Object(transform)
{
	shader = new Shader("./resources/shaders/basicShader");
	mesh = new Mesh("./resources/models/Hangar/garage.obj");
	texture = new Texture("./resources/textures/roof.jpg");
}
