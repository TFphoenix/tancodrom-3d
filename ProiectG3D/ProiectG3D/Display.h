#pragma once
#include <cstdint>
#include <string>

#include <SDL2/SDL.h>
#undef main

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

	// G&S
	bool IsClosed() const;

private:
	SDL_Window* m_window;
	SDL_GLContext m_glContext;
	bool m_isClosed;
};

