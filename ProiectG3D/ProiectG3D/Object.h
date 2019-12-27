#pragma once
#include "Mesh.h"
#include "Shader.h"
#include "Texture.h"

class Object
{
public:
	virtual void Update(const Camera& camera) = 0;
	virtual void Draw() const { mesh->Draw(); }
	virtual void UpdateThenDraw(const Camera& camera) { Update(camera); Draw(); }

protected:
	Object() :mesh(nullptr), shader(nullptr), texture(nullptr) {};
	virtual ~Object()
	{
		delete mesh;
		delete shader;
		delete texture;
	}

protected:
	Mesh* mesh;
	Shader* shader;
	Texture* texture;
	Transform transform;
};
