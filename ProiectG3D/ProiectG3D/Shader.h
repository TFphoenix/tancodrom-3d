#pragma once
#include <string>
#include <GL/glew.h>

#include "Transform.h"
#include "Camera.h"

class Shader
{
public:
	Shader(const std::string& fileName);
	virtual ~Shader();
	Shader(const Shader& other) = delete;
	Shader& operator=(const Shader& other) = delete;

	void Bind();
	void Update(const Transform& transform, const Camera& camera);

private:
	std::string LoadShader(const std::string& fileName);
	void CheckShaderError(GLuint shader, GLuint flag, bool isProgram, const std::string& errorMessage);
	GLuint CreateShader(const std::string& text, unsigned int type);

private:
	static const unsigned s_numShaders = 2;
	//static const unsigned int s_numUniforms = 3;

private:
	enum
	{
		TRANSFORM_U,

		NUM_UNIFORMS
	};

private:
	GLuint m_program;
	GLuint m_shaders[s_numShaders];
	GLuint m_uniforms[NUM_UNIFORMS];
};

