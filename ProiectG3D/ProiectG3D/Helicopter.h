#pragma once
#include  "Object.h"

class Helicopter : public Object
{
public:
	enum Type
	{
		CLASSIC,
		ROUND
	};

public:
	Helicopter(Type type = CLASSIC, Transform transform = Transform());

	void Update(const Camera& camera) override;
	void Draw() const override;
	void UpdateThenDraw(const Camera& camera) override;

private:
	class Base :public Object
	{
	public:
		Base(Type type, const Transform& transform);
		friend Helicopter;

		void Update(const Camera& camera) override;
	};

	class Window :public Object
	{
	public:
		enum class WindowType
		{
			Left,
			Right
		};

	public:
		Window(Type type, WindowType wType, const Transform& transform);
		friend Helicopter;

		void Update(const Camera& camera) override;

	private:
		WindowType m_type;
	};

	class Blades :public Object
	{
	public:
		enum class BladesType
		{
			Small,
			Big
		};

	public:
		Blades(Type type, BladesType bType, const Transform& transform);
		friend Helicopter;

		void Update(const Camera& camera) override;

	private:
		BladesType m_type;
	};

	class Support :public Object
	{
	public:
		Support(Type type, const Transform& transform);
		friend Helicopter;

		void Update(const Camera& camera) override;
	};

private:
	// Components
	Base m_base;
	Window m_leftWindow;
	Window m_rightWindow;
	Blades m_bigBlades;
	Blades m_smallBlades;
	Support* m_support;
	std::vector<Object*> m_components;

	// Logic
	float m_levitatingFactor = 0;
	int m_levitatingCondition = 0;
	Type m_type;
};

