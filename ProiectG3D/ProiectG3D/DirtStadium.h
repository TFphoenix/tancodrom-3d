#pragma once
#include "Object.h"
#include "Tank.h"

class DirtStadium :public Object
{
public:
	DirtStadium(const Transform& transform = Transform());

	void UpdateThenDraw(const Camera& camera) override;

private:
	Mesh m_dirtMesh;
	Mesh m_borderMesh;
	Texture m_dirtTexture;
	Texture m_borderTexture;

	// Tanks Animation
	Tank m_tank1;
	Tank m_tank2;
	bool m_incrementX;
	float m_reversal;
};

