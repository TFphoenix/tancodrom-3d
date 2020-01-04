#pragma once
#include "Mesh.h"
#include "Shader.h"
#include "Texture.h"

class Object
{
public:
	// Graphic
	virtual void Update(const Camera& camera) { shader->Bind(); shader->Update(transform, camera); texture->Bind(0); }
	virtual void Draw() const { mesh->Draw(); }
	virtual void UpdateThenDraw(const Camera& camera) { Update(camera); Draw(); }

	// G&S
	Transform& GetTransform() { return  transform; }

protected:
	// C&D
	Object(const Transform& transform = Transform()) :mesh(nullptr), shader(nullptr), texture(nullptr), transform(transform) {};
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
