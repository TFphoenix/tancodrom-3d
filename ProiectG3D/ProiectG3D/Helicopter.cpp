#include "Helicopter.h"
#include<stdexcept>

Helicopter::Helicopter(Transform transform) :
	Object(transform),
	m_base(transform),
	m_leftWindow(Window::Type::Left, transform),
	m_rightWindow(Window::Type::Right, transform),
	m_bigBlades(Blades::Type::Big, transform),
	m_smallBlades(Blades::Type::Small, transform)
{
	m_components.push_back(dynamic_cast<Object*>(&m_base));
	m_components.push_back(dynamic_cast<Object*>(&m_leftWindow));
	m_components.push_back(dynamic_cast<Object*>(&m_rightWindow));
	m_components.push_back(dynamic_cast<Object*>(&m_bigBlades));
	m_components.push_back(dynamic_cast<Object*>(&m_smallBlades));

	for (auto& obj : m_components)
	{
		obj->GetTransform().GetPosition().x += 20.0f;
		obj->GetTransform().GetPosition().y += 10.0f;
		obj->GetTransform().GetScale() += 2.0f;
	}
}

void Helicopter::Update(const Camera& camera)
{
	for (auto& obj : m_components)
	{
		obj->Update(camera);
	}
}

void Helicopter::Draw() const
{
	for (auto& obj : m_components)
	{
		obj->Draw();
	}
}

void Helicopter::UpdateThenDraw(const Camera& camera)
{
	bool levitate = false;
	if (++m_levitatingCondition == 10)
	{
		m_levitatingFactor += 1.0f;
		m_levitatingCondition = 0;
		levitate = true;
	}

	for (auto& obj : m_components)
	{
		if (levitate)
			obj->GetTransform().GetPosition().y += sinf(glm::radians(m_levitatingFactor));
		obj->UpdateThenDraw(camera);
	}
}

Helicopter::Base::Base(const Transform& transform) :Object(transform)
{
	mesh = new Mesh("./resources/models/AlexHelicopter/helicopter_body_centered.obj");
	shader = new Shader("./resources/shaders/LambertsLightShader");
	texture = new Texture("./resources/textures/helicopter.jpg");
}

void Helicopter::Base::Update(const Camera& camera)
{
	shader->Bind();
	shader->Update(transform, camera);
	texture->Bind(0);
}

Helicopter::Window::Window(Type type, const Transform& transform) :Object(transform), m_type(type)
{
	switch (type)
	{
	case Type::Left:
		mesh = new Mesh("./resources/models/AlexHelicopter/helicopter_left_window_centered.obj");
		break;
	case Type::Right:
		mesh = new Mesh("./resources/models/AlexHelicopter/helicopter_right_window_centered.obj");
		break;
	default:
		throw std::invalid_argument("Undefined Window type");
	}
	shader = new Shader("./resources/shaders/LambertsLightShader");
	texture = new Texture("./resources/textures/laminate_black.jpg");
}

void Helicopter::Window::Update(const Camera& camera)
{
	shader->Bind();
	shader->Update(transform, camera);
	texture->Bind(0);
}

Helicopter::Blades::Blades(Type type, const Transform& transform) :Object(transform), m_type(type)
{
	switch (type)
	{
	case Type::Big:
		mesh = new Mesh("./resources/models/AlexHelicopter/helicopter_main_blades_centered.obj");
		break;
	case Type::Small:
		mesh = new Mesh("./resources/models/AlexHelicopter/helicopter_tail_blades_centered.obj");
		this->transform.GetPosition().z -= 22.4f;
		this->transform.GetPosition().y += 11.1f;
		break;
	default:
		throw std::invalid_argument("Undefined Blades type");
	}
	shader = new Shader("./resources/shaders/LambertsLightShader");
	texture = new Texture("./resources/textures/gray_metal.jpg");
}

void Helicopter::Blades::Update(const Camera& camera)
{
	shader->Bind();
	shader->Update(transform, camera);
	texture->Bind(0);
	if (m_type == Type::Big)
	{
		transform.GetRotation().y += 0.05f;
	}
	else
	{
		transform.GetRotation().x += 0.05f;
	}
}
