#pragma once
#include <cstdint>
#include <string>

#include <SDL2/SDL.h>
#undef main

#include "Camera.h"

class Display
{
public:
	// Rule of 3
	Display(uint16_t width, uint16_t height, const std::string& title);
	virtual ~Display();
	Display(const Display& other) = delete;
	Display& operator=(const Display& other) = delete;

	// Display controlls
	void Update();
	void Clear(float red = 1.0f, float green = 1.0f, float blue = 1.0f, float alpha = 1.0f);

	// Camera controlls
	void SetCamera(Camera& camera);

	// G&S
	bool IsClosed() const;

private:
	// Window
	SDL_Window* m_window;
	SDL_GLContext m_glContext;
	bool m_isClosed;

	// Camera
	Camera* pCamera;

	// Timing
	double m_deltaTime;
	Uint64 m_NOW;
	Uint64 m_LAST;
};

