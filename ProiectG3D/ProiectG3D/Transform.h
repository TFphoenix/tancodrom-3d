#pragma once
#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>

class Transform
{
public:
	// Constr.
	Transform(const glm::vec3& position = glm::vec3(), const glm::vec3& rotation = glm::vec3(), const glm::vec3& scale = glm::vec3(1.0f, 1.0f, 1.0f)) :
		m_position(position),
		m_rotation(rotation),
		m_scale(scale) {}

	// Model Matrix
	glm::mat4 GetModel() const
	{
		const glm::mat4 positionMatrix = glm::translate(m_position);
		const glm::mat4 rotationXMatrix = glm::rotate(m_rotation.x, glm::vec3(1, 0, 0));
		const glm::mat4 rotationYMatrix = glm::rotate(m_rotation.y, glm::vec3(0, 1, 0));
		const glm::mat4 rotationZMatrix = glm::rotate(m_rotation.z, glm::vec3(0, 0, 1));
		const glm::mat4 rotationMatrix = rotationZMatrix * rotationYMatrix*rotationXMatrix;
		const glm::mat4 scaleMatrix = glm::scale(m_scale);

		return positionMatrix * rotationMatrix * scaleMatrix;
	}

	// G&S
	glm::vec3& GetPosition() { return m_position; }
	glm::vec3& GetRotation() { return m_rotation; }
	glm::vec3& GetScale() { return m_scale; }
	void SetPosition(const glm::vec3& position) { m_position = position; }
	void SetRotation(const glm::vec3& rotation) { m_rotation = rotation; }
	void SetScale(const glm::vec3& scale) { m_scale = scale; }

private:
	glm::vec3 m_position;
	glm::vec3 m_rotation;
	glm::vec3 m_scale;

};

