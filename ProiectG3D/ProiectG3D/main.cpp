#include <GL/glew.h>
#include "Display.h"
#include "Settings.h"

#include "Terrain.h"
#include "Tank.h"

int main()
{
	// Display
	Display display(Settings::WindowWidth, Settings::WindowHeight, "G3D - Tancodrom & Elicoptere");

	// Camera & Transform
	Camera camera(glm::vec3(0, 10, -10), 70.0f, static_cast<float>(Settings::WindowWidth) / Settings::WindowHeight, 0.01f, 1000.0f);
	display.SetCamera(camera);

	// Objects
	Terrain terrain;
	Tank tank;

	// Render loop
	while (!display.IsClosed())
	{
		display.Clear(0.0f, 0.15f, 0.3f);

		
		// Terrain
		terrain.UpdateThenDraw(camera);

		// Tank
		tank.UpdateThenDraw(camera);

		
		display.Update();
	}

	return 0;
}
