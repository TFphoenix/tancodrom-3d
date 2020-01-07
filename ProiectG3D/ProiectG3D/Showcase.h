#pragma once
#include "Object.h"

class Showcase :public Object
{
public:
	enum Type
	{
		RAMP,
		CLOSED_CAGE,
		OPEN_CAGE
	};

public:
	Showcase(Type type = RAMP, const Transform& transform = Transform());
	void UpdateThenDraw(const Camera& camera) override;

public:
	class Base :public Object
	{
		friend Showcase;
		Base(Type type, const Transform& transform);
	}m_base;

	class Frame :public Object
	{
		friend Showcase;
		Frame(Type type, const Transform& transform);
		void Draw() const override;
	}m_frame;

private:
	Type m_type;
};

