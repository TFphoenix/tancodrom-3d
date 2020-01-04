#pragma once
#include  "Object.h"

class Helicopter : public Object
{
public:
	Helicopter(Transform transform = Transform());

	void Update(const Camera& camera) override;
	void Draw() const override;
	void UpdateThenDraw(const Camera& camera) override;

private:
	class Base :public Object
	{
	public:
		Base(const Transform& transform);
		friend Helicopter;

		void Update(const Camera& camera) override;
	};

	class Window :public Object
	{
	public:
		enum class Type
		{
			Left,
			Right
		};

	public:
		Window(Type type, const Transform& transform);
		friend Helicopter;

		void Update(const Camera& camera) override;

	private:
		Type m_type;
	};

	class Blades :public Object
	{
	public:
		enum class Type
		{
			Small,
			Big
		};

	public:
		Blades(Type type, const Transform& transform);
		friend Helicopter;

		void Update(const Camera& camera) override;

	private:
		Type m_type;
	};

private:
	// Components
	Base m_base;
	Window m_leftWindow;
	Window m_rightWindow;
	Blades m_bigBlades;
	Blades m_smallBlades;
	std::vector<Object*> m_components;

	// Logic
	float m_levitatingFactor = 0;
	int m_levitatingCondition = 0;
};

