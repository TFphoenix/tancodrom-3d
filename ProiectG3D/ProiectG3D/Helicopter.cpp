#include "Helicopter.h"
#include<stdexcept>

Helicopter::Helicopter(Type type, Transform transform) :
	Object(transform),
	m_base(type, transform),
	m_leftWindow(type, Window::WindowType::Left, transform),
	m_rightWindow(type, Window::WindowType::Right, transform),
	m_bigBlades(type, Blades::BladesType::Big, transform),
	m_smallBlades(type, Blades::BladesType::Small, transform),
	m_type(type)
{
	m_components.push_back(dynamic_cast<Object*>(&m_base));
	m_components.push_back(dynamic_cast<Object*>(&m_leftWindow));
	m_components.push_back(dynamic_cast<Object*>(&m_rightWindow));
	m_components.push_back(dynamic_cast<Object*>(&m_bigBlades));
	m_components.push_back(dynamic_cast<Object*>(&m_smallBlades));
	if (m_type == ROUND)
	{
		m_support = new Support(ROUND, transform);
		m_components.push_back(dynamic_cast<Object*>(m_support));
	}

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

Helicopter::Base::Base(Type type, const Transform& transform) :Object(transform)
{
	if (type == ROUND)
	{
		mesh = new Mesh("./resources/models/RoundHelicopter/body.obj");
		texture = new Texture("./resources/textures/red_metal.jpg");
	}
	else
	{
		mesh = new Mesh("./resources/models/AlexHelicopter/helicopter_body_centered.obj");
		texture = new Texture("./resources/textures/helicopter.jpg");
	}
	shader = new Shader("./resources/shaders/LambertsLightShader");
}

void Helicopter::Base::Update(const Camera& camera)
{
	shader->Bind();
	shader->Update(transform, camera);
	texture->Bind(0);
}

Helicopter::Window::Window(Type type, WindowType wType, const Transform& transform) :Object(transform), m_type(wType)
{
	if (type == ROUND)
	{
		mesh = new Mesh("./resources/models/RoundHelicopter/windows.obj");
		texture = new Texture("./resources/textures/blackwindow.jpg");
	}
	else
	{
		switch (wType)
		{
		case WindowType::Left:
			mesh = new Mesh("./resources/models/AlexHelicopter/helicopter_left_window_centered.obj");
			break;
		case WindowType::Right:
			mesh = new Mesh("./resources/models/AlexHelicopter/helicopter_right_window_centered.obj");
			break;
		default:
			throw std::invalid_argument("Undefined Window type");
		}
		texture = new Texture("./resources/textures/laminate_black.jpg");
	}
	shader = new Shader("./resources/shaders/LambertsLightShader");
}

void Helicopter::Window::Update(const Camera& camera)
{
	shader->Bind();
	shader->Update(transform, camera);
	texture->Bind(0);
}

Helicopter::Blades::Blades(Type type, BladesType bType, const Transform& transform) :Object(transform), m_type(bType)
{
	switch (type)
	{
	case CLASSIC:
		switch (bType)
		{
		case BladesType::Big:
			mesh = new Mesh("./resources/models/AlexHelicopter/helicopter_main_blades_centered.obj");
			break;
		case BladesType::Small:
			mesh = new Mesh("./resources/models/AlexHelicopter/helicopter_tail_blades_centered.obj");
			this->transform.GetPosition().z -= 22.4f;
			this->transform.GetPosition().y += 11.1f;
			break;
		default:
			throw std::invalid_argument("Undefined Blades type");
		}
		texture = new Texture("./resources/textures/gray_metal.jpg");
		break;
	case ROUND:
		switch (bType)
		{
		case BladesType::Big:
			mesh = new Mesh("./resources/models/RoundHelicopter/big_blades.obj");
			break;
		case BladesType::Small:
			mesh = new Mesh("./resources/models/RoundHelicopter/small_blades_centered.obj");
			this->transform.GetPosition().z += 21.5f;
			this->transform.GetPosition().y += 8.2f;
			break;
		default:
			throw std::invalid_argument("Undefined Blades type");
		}
		texture = new Texture("./resources/textures/diaganal_metal.jpg");
		break;
	default:
		throw std::invalid_argument("Undefined Helicopter type");
	}

	shader = new Shader("./resources/shaders/LambertsLightShader");
}

void Helicopter::Blades::Update(const Camera& camera)
{
	shader->Bind();
	shader->Update(transform, camera);
	texture->Bind(0);
	if (m_type == BladesType::Big)
	{
		transform.GetRotation().y += 0.05f;
	}
	else
	{
		transform.GetRotation().x += 0.05f;
	}
}

Helicopter::Support::Support(Type type, const Transform& transform) :Object(transform)
{
	if (type == ROUND)
	{
		mesh = new Mesh("./resources/models/RoundHelicopter/support.obj");
		shader = new Shader("./resources/shaders/LambertsLightShader");
		texture = new Texture("./resources/textures/diaganal_metal.jpg");
	}
}

void Helicopter::Support::Update(const Camera& camera)
{
	shader->Bind();
	shader->Update(transform, camera);
	texture->Bind(0);
}
