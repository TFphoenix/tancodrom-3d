#pragma once
#include "Object.h"

class Human :public Object
{
public:
	enum Type {
		JOHN,
		OLGA,
		OLGA_CROSSED,
		STEVE,
		STEVE_CROSSED,
		DIANA
	};

public:
	Human(Type type = JOHN, const Transform& transform = Transform());
	void UpdateThenDraw(const Camera& camera) override;

private:
	class Hands :public Object
	{
		friend Human;
		Hands(Type type, const Transform& transform);
	}m_hands;

	class Feet :public Object
	{
		friend Human;
		Feet(Type type, const Transform& transform);
	}m_feet;

	class Body :public Object
	{
		friend Human;
		Body(Type type, const Transform& transform);
	}m_body;

	class Head :public Object
	{
		friend Human;
		Head(Type type, const Transform& transform);
	}m_head;

private:
	Type m_type;

};

