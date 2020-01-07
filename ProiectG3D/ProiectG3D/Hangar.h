#pragma once
#include "Object.h"

class Hangar :public Object
{
public:
	Hangar(const Transform& transform = Transform());
	void UpdateThenDraw(const Camera& camera) override;

private:
	class Base :public Object
	{
		friend Hangar;
		Base(const Transform& transform);
	}m_base;

	class Roof :public Object
	{
		friend Hangar;
		Roof(const Transform& transform);
	}m_roof;

	class Windows :public Object
	{
		friend Hangar;
		Windows(const Transform& transform);
	}m_windows;

	class Door :public Object
	{
		friend Hangar;
		Door(const Transform& transform);
	}m_door;

	class Garage :public Object
	{
		friend Hangar;
		Garage(const Transform& transform);
	}m_garage;

};

