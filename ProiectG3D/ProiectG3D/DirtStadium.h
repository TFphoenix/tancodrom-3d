#pragma once
#include "Object.h"

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
};

