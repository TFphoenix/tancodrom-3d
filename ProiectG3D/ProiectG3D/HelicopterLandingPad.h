#pragma once
#include "Object.h"

class HelicopterLandingPad :public Object
{
public:
	HelicopterLandingPad(Transform transform = Transform());

	void UpdateThenDraw(const Camera& camera) override;

private:
	Mesh m_panelMesh;
	Mesh m_pillarMesh;
	Mesh m_ladderMesh;
	Texture m_panelTexture;
	Texture m_pillarTexture;
	Texture m_ladderTexture;

};

