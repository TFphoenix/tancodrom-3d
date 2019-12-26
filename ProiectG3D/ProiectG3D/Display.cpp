#include "Display.h"

#include <GL/glew.h>
#include <iostream>

Display::Display(uint16_t width, uint16_t height, const std::string& title)
{
	SDL_Init(SDL_INIT_EVERYTHING);

	SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_BUFFER_SIZE, 32);
	SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 16);
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

	m_window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_OPENGL);
	m_glContext = SDL_GL_CreateContext(m_window);

	const GLenum status = glewInit();
	if (status != GLEW_OK)
	{
		std::cerr << "Glew failed to initialized!" << std::endl;
	}

	m_isClosed = false;

	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);
	glCullFace(GL_BACK);

	// Timing
	m_NOW = SDL_GetPerformanceCounter();
	m_LAST = 0;
	m_deltaTime = 0;
}

Display::~Display()
{
	SDL_GL_DeleteContext(m_glContext);
	SDL_DestroyWindow(m_window);
	SDL_Quit();
}

void Display::Update()
{
	// Swap Window
	SDL_GL_SwapWindow(m_window);

	// per-frame Time Logic
	m_LAST = m_NOW;
	m_NOW = SDL_GetPerformanceCounter();
	m_deltaTime = (m_NOW - m_LAST) * 1000 / static_cast<double>(SDL_GetPerformanceFrequency());

	// Event Handling
	SDL_Event e;
	while (SDL_PollEvent(&e))
	{
		// Quit
		if (e.type == SDL_QUIT)
		{
			m_isClosed = true;
		}
		// Keyboard
		else if (e.type == SDL_KEYDOWN)
		{
			const float cameraSpeed = static_cast<float>(m_deltaTime) * pCamera->cameraSpeedFactor;
			switch (e.key.keysym.sym)
			{
			case SDLK_ESCAPE:
				m_isClosed = true;
				break;
			case SDLK_w:
				pCamera->MoveForward(cameraSpeed / 2);
				break;
			case SDLK_s:
				pCamera->MoveForward(-cameraSpeed / 2);
				break;
			case SDLK_a:
				pCamera->MoveRight(cameraSpeed / 2);
				break;
			case SDLK_d:
				pCamera->MoveRight(-cameraSpeed / 2);
				break;
			default:
				break;
			}
		}
		// Mouse
		else if (e.type == SDL_MOUSEMOTION)
		{
			pCamera->MouseControl(e.motion.x, e.motion.y);
		}
	}
}

void Display::Clear(float red, float green, float blue, float alpha)
{
	glClearColor(red, green, blue, alpha);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void Display::SetCamera(Camera& camera)
{
	pCamera = &camera;
}

bool Display::IsClosed() const
{
	return m_isClosed;
}
