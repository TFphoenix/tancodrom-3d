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
#include "Skybox.h"
#include "Showcase.h"
#include "Human.h"

int main()
{
	// Start Time
	std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();

	// Display
	Display display(Settings::WindowWidth, Settings::WindowHeight, "G3D - Tancodrom & Elicoptere");

	// Camera & Transform
	Camera camera(glm::vec3(0, 10, -10), 70.0f, static_cast<float>(Settings::WindowWidth) / Settings::WindowHeight, 0.01f, 1000.0f);
	display.SetCamera(camera);

	// Objects Vector
	std::vector<Object*> objects;

	// Vegetation
	objects.push_back(new Vegetation(Vegetation::Type::GRASS, Transform(glm::vec3(15, 0, -21))));
	objects.push_back(new Vegetation(Vegetation::Type::GRASS, Transform(glm::vec3(17, 0, -22))));
	objects.push_back(new Vegetation(Vegetation::Type::GRASS, Transform(glm::vec3(7, 0, -23))));
	objects.push_back(new Vegetation(Vegetation::Type::GRASS, Transform(glm::vec3(-3, 0, -23))));
	objects.push_back(new Vegetation(Vegetation::Type::GRASS, Transform(glm::vec3(-7, 0, -23))));
	objects.push_back(new Vegetation(Vegetation::Type::GRASS, Transform(glm::vec3(10, 0, -23))));
	objects.push_back(new Vegetation(Vegetation::Type::FLOWER, Transform(glm::vec3(-8, 0, -25))));
	objects.push_back(new Vegetation(Vegetation::Type::FLOWER, Transform(glm::vec3(-5, 0, -23))));
	objects.push_back(new Vegetation(Vegetation::Type::FLOWER, Transform(glm::vec3(-10, 0, -24))));
	objects.push_back(new Vegetation(Vegetation::Type::BUSH, Transform(glm::vec3(0, 0, -23))));
	objects.push_back(new Vegetation(Vegetation::Type::BUSH, Transform(glm::vec3(20, 0, -23))));
	objects.push_back(new Vegetation(Vegetation::Type::BUSH, Transform(glm::vec3(23, 0, 0))));
	objects.push_back(new Vegetation(Vegetation::Type::GRASS, Transform(glm::vec3(23, 0, -10))));
	objects.push_back(new Vegetation(Vegetation::Type::GRASS, Transform(glm::vec3(23, 0, -10))));
	objects.push_back(new Vegetation(Vegetation::Type::GRASS, Transform(glm::vec3(21, 0, -10))));
	objects.push_back(new Vegetation(Vegetation::Type::GRASS, Transform(glm::vec3(22, 0, -12))));
	objects.push_back(new Vegetation(Vegetation::Type::GRASS, Transform(glm::vec3(23, 0, -16))));
	objects.push_back(new Vegetation(Vegetation::Type::GRASS, Transform(glm::vec3(23, 0, -7))));
	objects.push_back(new Vegetation(Vegetation::Type::GRASS, Transform(glm::vec3(23, 0, 5))));
	objects.push_back(new Vegetation(Vegetation::Type::GRASS, Transform(glm::vec3(23, 0, 10))));
	objects.push_back(new Vegetation(Vegetation::Type::BUSH, Transform(glm::vec3(-23, 0, -5))));
	objects.push_back(new Vegetation(Vegetation::Type::BUSH, Transform(glm::vec3(-23, 0, 10))));
	objects.push_back(new Vegetation(Vegetation::Type::FLOWER, Transform(glm::vec3(-23, 0, 3))));
	objects.push_back(new Vegetation(Vegetation::Type::BUSH, Transform(glm::vec3(-10, 0, 23))));
	objects.push_back(new Vegetation(Vegetation::Type::BUSH, Transform(glm::vec3(5, 0, 23))));
	objects.push_back(new Vegetation(Vegetation::Type::GRASS, Transform(glm::vec3(-5, 0, 23))));
	objects.push_back(new Vegetation(Vegetation::Type::FLOWER, Transform(glm::vec3(23, 0, -17))));

	// Terrain
	objects.push_back(new Terrain);

	// Tanks
	objects.push_back(new Tank(Tank::CLASSIC, Transform(glm::vec3(50, 4, -50))));
	objects.push_back(new Tank(Tank::DOUBLE, Transform(glm::vec3(50, 0, 50))));
	objects.push_back(new Tank(Tank::TURTLE, Transform(glm::vec3(-50, 0, -50))));

	// Helicopters
	objects.push_back(new Helicopter(Helicopter::CLASSIC, Transform(glm::vec3(-20, 80, 0))));
	objects.push_back(new Helicopter(Helicopter::ROUND, Transform(glm::vec3(130, 70, 0))));

	// Helicopter Landing Pads
	objects.push_back(new HelicopterLandingPad);
	objects.push_back(new HelicopterLandingPad(Transform(glm::vec3(150, 0, 0))));

	// Big Spotlights
	objects.push_back(new BigSpotlight(Transform(glm::vec3(-100, 0, 90), glm::vec3(0, glm::radians(-45.0f), 0))));
	objects.push_back(new BigSpotlight(Transform(glm::vec3(-200, 0, 90))));
	objects.push_back(new BigSpotlight(Transform(glm::vec3(-300, 0, 90), glm::vec3(0, glm::radians(45.0f), 0))));
	objects.push_back(new BigSpotlight(Transform(glm::vec3(-100, 0, 210), glm::vec3(0, glm::radians(225.0f), 0))));
	objects.push_back(new BigSpotlight(Transform(glm::vec3(-200, 0, 210), glm::vec3(0, glm::radians(180.0f), 0))));
	objects.push_back(new BigSpotlight(Transform(glm::vec3(-300, 0, 210), glm::vec3(0, glm::radians(135.0f), 0))));

	// Stadium
	objects.push_back(new DirtStadium(Transform(glm::vec3(-200, 0, 150))));

	// Load Time measure: ~1.8s, ~2.5s
	std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
	std::cout << "Load Time = " << std::chrono::duration_cast<std::chrono::milliseconds> (end - begin).count() / 1000.0f << "[seconds]" << std::endl;

	//Skybox
	Skybox skybox;

	// Test
	Showcase ramp(Showcase::OPEN_CAGE, Transform(glm::vec3(50, 0, -50)));
	objects.push_back(new Human(Human::JOHN, Transform(glm::vec3(70, 0, -70))));
	objects.push_back(new Human(Human::OLGA, Transform(glm::vec3(80, 0, -70))));
	objects.push_back(new Human(Human::STEVE, Transform(glm::vec3(90, 0, -70))));
	objects.push_back(new Human(Human::DIANA, Transform(glm::vec3(100, 0, -70))));


	// Render loop
	while (!display.IsClosed())
	{
		display.Clear(0.0f, 0.15f, 0.3f);

		// Render skybox
		skybox.Draw(camera.GetView(), camera.GetProjection());

		// Render all objects in scene
		for (auto& object : objects)
		{
			object->UpdateThenDraw(camera);
		}

		// Test
		ramp.UpdateThenDraw(camera);

		display.Update();
	}

	return 0;
}
