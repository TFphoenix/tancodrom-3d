#pragma once
#include <string>
#include <GL/glew.h>

class Texture
{
public:
	Texture(const std::string& fileName);
	virtual ~Texture();
	Texture(const Texture& other) = delete;
	Texture& operator=(const Texture& other) = delete;

	void Bind(unsigned unit);

private:
	GLuint m_texture;

};

