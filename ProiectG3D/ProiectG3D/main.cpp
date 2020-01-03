#include <GL/glew.h>
#include "Display.h"
#include "Settings.h"

#include "Terrain.h"
#include "Tank.h"
#include "Helicopter.h"

int main()
{
	// Display
	Display display(Settings::WindowWidth, Settings::WindowHeight, "G3D - Tancodrom & Elicoptere");

	// Camera & Transform
	Camera camera(glm::vec3(0, 10, -10), 70.0f, static_cast<float>(Settings::WindowWidth) / Settings::WindowHeight, 0.01f, 1000.0f);
	display.SetCamera(camera);

	// Objects
	Terrain terrain;
	Tank tank1;
	Tank tank2(Tank::DOUBLE, Transform(glm::vec3(20, 0, -20)));
	Tank tank3(Tank::TURTLE, Transform(glm::vec3(-20, 0, -20)));
	Helicopter helicopter;

	// Render loop
	while (!display.IsClosed())
	{
		display.Clear(0.0f, 0.15f, 0.3f);


		// Terrain
		terrain.UpdateThenDraw(camera);

		// Tanks
		tank1.UpdateThenDraw(camera);
		tank2.UpdateThenDraw(camera);
		tank3.UpdateThenDraw(camera);

		// Helicopter
		helicopter.UpdateThenDraw(camera);


		display.Update();
	}

	return 0;
}
