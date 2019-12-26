#pragma once
#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>

#include "Settings.h"

struct Camera
{
public:
	Camera(const glm::vec3& pos, float fov, float aspect, float zNear, float zFar)
	{
		this->pos = pos;
		this->forward = glm::vec3(0.0f, 0.0f, 1.0f);
		this->up = glm::vec3(0.0f, 1.0f, 0.0f);
		this->projection = glm::perspective(fov, aspect, zNear, zFar);

		lastX = Settings::WindowWidth / 2.0f;
		lastY = Settings::WindowHeight / 2.0f;
	}

	glm::mat4 GetViewProjection() const
	{
		return projection * glm::lookAt(pos, pos + forward, up);
	}

	void MoveForward(float amt)
	{
		pos += forward * amt;
	}

	void MoveRight(float amt)
	{
		pos += glm::cross(up, forward) * amt;
	}

	void Pitch(float angle)
	{
		glm::vec3 right = glm::normalize(glm::cross(up, forward));

		forward = glm::vec3(glm::normalize(glm::rotate(angle, right) * glm::vec4(forward, 0.0)));
		up = glm::normalize(glm::cross(forward, right));
	}

	void RotateY(float angle)
	{
		static const glm::vec3 UP(0.0f, 1.0f, 0.0f);

		glm::mat4 rotation = glm::rotate(angle, UP);

		forward = glm::vec3(glm::normalize(rotation * glm::vec4(forward, 0.0)));
		up = glm::vec3(glm::normalize(rotation * glm::vec4(up, 0.0)));
	}

	void MouseControl(float xPos, float yPos)
	{
		const float xChange = (xPos - lastX)*mouseSensitivity;
		const float yChange = (yPos - lastY)*mouseSensitivity;

		ProcessMouseMovement(xChange, yChange);
		lastX = xPos;
		lastY = yPos;
	}

private:
	void ProcessMouseMovement(float xOffset, float yOffset, bool constrainPitch = true)
	{
		yaw += xOffset;
		pitch += yOffset;

		// Ensuring no overhead camera movement appears
		if (constrainPitch) {
			if (pitch > 89.0f)
			{
				pitch = 89.0f;
				yOffset = 0;
			}
			if (pitch < -89.0f)
			{
				pitch = -89.0f;
				yOffset = 0;
			}
		}

		const float radRotationAngle = xOffset * glm::pi<float>() / 180.0f;
		const float radPitchAngle = -yOffset * glm::pi<float>() / 180.0f;
		RotateY(-radRotationAngle);
		Pitch(-radPitchAngle);
	}

public:
	const float cameraSpeedFactor = 2.5f;

private:
	// Mouse
	const float mouseSensitivity = 0.1f;
	float lastX = 0.f, lastY = 0.f;
	// Euler Angles
	float yaw = 0.0f;
	float pitch = 0.0f;


private:
	glm::mat4 projection;
	glm::vec3 pos;
	glm::vec3 forward;
	glm::vec3 up;
};
