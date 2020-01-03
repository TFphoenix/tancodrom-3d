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

	void SetInt(const std::string &name, int value) const
	{
		glUniform1i(glGetUniformLocation(m_program, name.c_str()), value);
	}
	void SetFloat(const std::string &name, float value) const
	{
		glUniform1f(glGetUniformLocation(m_program, name.c_str()), value);
	}
	void SetVec3(const std::string &name, const glm::vec3 &value) const
	{
		glUniform3fv(glGetUniformLocation(m_program, name.c_str()), 1, &value[0]);
	}
	void SetVec3(const std::string &name, float x, float y, float z) const
	{
		glUniform3f(glGetUniformLocation(m_program, name.c_str()), x, y, z);
	}
	void SetMat4(const std::string &name, const glm::mat4 &mat) const
	{
		glUniformMatrix4fv(glGetUniformLocation(m_program, name.c_str()), 1, GL_FALSE, &mat[0][0]);
	}

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

