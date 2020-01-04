#pragma once
#include "Object.h"

class BigSpotlight :public Object
{
public:
	BigSpotlight(const Transform& transform = Transform());

	void UpdateThenDraw(const Camera& camera) override;

private:
	Mesh m_pillarMesh;
	Mesh m_panelMesh;
	Texture m_pillarTexture;
	Texture m_panelTexture;
	Shader m_pillarShader;
	Shader m_panelShader;
};

