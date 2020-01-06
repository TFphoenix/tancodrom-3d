#include <GL/glew.h>
#include <chrono>
#include <iostream>

#include "Display.h"
#include "Settings.h"

#include "Terrain.h"
#include "Tank.h"
#include "Helicopter.h"
#include "HelicopterLandingPad.h"
#include "BigSpotlight.h"
#include "DirtStadium.h"
#include "Vegetation.h"

int main()
{
	// Start Time
	std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();

	// Display
	Display display(Settings::WindowWidth, Settings::WindowHeight, "G3D - Tancodrom & Elicoptere");

	// Camera & Transform
	Camera camera(glm::vec3(0, 10, -10), 70.0f, static_cast<float>(Settings::WindowWidth) / Settings::WindowHeight, 0.01f, 1000.0f);
	display.SetCamera(camera);

	// Objects
	Vegetation vegetation1(Vegetation::Type::BUSH,Transform(glm::vec3(30,0,150)));
	Vegetation vegetation2(Vegetation::Type::FLOWER, Transform(glm::vec3(50,0,150)));
	Vegetation vegetation3(Vegetation::Type::GRASS, Transform(glm::vec3(75,0,150)));
	Terrain terrain;
	Tank tank1(Tank::CLASSIC, Transform(glm::vec3(50, 0, -50)));
	Tank tank2(Tank::DOUBLE, Transform(glm::vec3(50, 0, 50)));
	Tank tank3(Tank::TURTLE, Transform(glm::vec3(-50, 0, -50)));
	Helicopter helicopter(Helicopter::CLASSIC, Transform(glm::vec3(-20, 80, 0)));
	HelicopterLandingPad landingPad;
	BigSpotlight spotlight1(Transform(glm::vec3(-100, 0, 90), glm::vec3(0, glm::radians(-45.0f), 0)));
	BigSpotlight spotlight2(Transform(glm::vec3(-200, 0, 90)));
	BigSpotlight spotlight3(Transform(glm::vec3(-300, 0, 90), glm::vec3(0, glm::radians(45.0f), 0)));
	BigSpotlight spotlight1r(Transform(glm::vec3(-100, 0, 210), glm::vec3(0, glm::radians(225.0f), 0)));
	BigSpotlight spotlight2r(Transform(glm::vec3(-200, 0, 210), glm::vec3(0, glm::radians(180.0f), 0)));
	BigSpotlight spotlight3r(Transform(glm::vec3(-300, 0, 210), glm::vec3(0, glm::radians(135.0f), 0)));
	DirtStadium stadium(Transform(glm::vec3(-200, 0, 150)));

	// Load Time measure: ~1.8s, ~2.5s
	std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
	std::cout << "Load Time = " << std::chrono::duration_cast<std::chrono::milliseconds> (end - begin).count() / 1000.0f << "[seconds]" << std::endl;


	// Render loop
	while (!display.IsClosed())
	{
		display.Clear(0.0f, 0.15f, 0.3f);

		//Vegetation
		vegetation1.UpdateThenDraw(camera);
		vegetation2.UpdateThenDraw(camera);
		vegetation3.UpdateThenDraw(camera);
		
		// Terrain
		terrain.UpdateThenDraw(camera);

		// Tanks
		tank1.UpdateThenDraw(camera);
		tank2.UpdateThenDraw(camera);
		tank3.UpdateThenDraw(camera);

		// Helicopter
		helicopter.UpdateThenDraw(camera);

		// Buildings
		landingPad.UpdateThenDraw(camera);
		spotlight1.UpdateThenDraw(camera);
		spotlight2.UpdateThenDraw(camera);
		spotlight3.UpdateThenDraw(camera);
		spotlight1r.UpdateThenDraw(camera);
		spotlight2r.UpdateThenDraw(camera);
		spotlight3r.UpdateThenDraw(camera);
		stadium.UpdateThenDraw(camera);



		display.Update();
	}

	return 0;
}
