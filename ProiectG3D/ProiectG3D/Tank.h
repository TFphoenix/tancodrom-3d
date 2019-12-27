#pragma once
#include "Object.h"

class Tank :public Object
{
public:
	Tank();

	void Update(const Camera& camera) override;
	void Draw() const override;
	void UpdateThenDraw(const Camera& camera) override;

private:
	class Base :public Object
	{
	public:
		Base();
		friend Tank;

		void Update(const Camera& camera) override;
	};

	class Turret :public Object
	{
	public:
		Turret();
		friend Tank;

		void Update(const Camera& camera) override;
	};

private:
	Base m_base;
	Turret m_turret;

};
