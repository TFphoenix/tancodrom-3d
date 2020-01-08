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
#include "Hangar.h"

int main()
{
	// Start Time
	std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();

	// Display
	Display display(Settings::WindowWidth, Settings::WindowHeight, "G3D - Tancodrom & Elicoptere");

	// Camera & Transform
	Camera camera(glm::vec3(0, 10, -100), 70.0f, static_cast<float>(Settings::WindowWidth) / Settings::WindowHeight, 0.01f, 1000.0f);
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

	objects.push_back(new Vegetation(Vegetation::Type::BUSH, Transform(glm::vec3(170, 0, -8))));
	objects.push_back(new Vegetation(Vegetation::Type::FLOWER, Transform(glm::vec3(170, 0, 0))));
	objects.push_back(new Vegetation(Vegetation::Type::FLOWER, Transform(glm::vec3(170, 0, 2))));
	objects.push_back(new Vegetation(Vegetation::Type::FLOWER, Transform(glm::vec3(170, 0, -2))));
	objects.push_back(new Vegetation(Vegetation::Type::FLOWER, Transform(glm::vec3(170, 0, -1))));
	objects.push_back(new Vegetation(Vegetation::Type::GRASS, Transform(glm::vec3(170, 0, 0))));
	objects.push_back(new Vegetation(Vegetation::Type::BUSH, Transform(glm::vec3(170, 0, 10))));

	objects.push_back(new Vegetation(Vegetation::Type::BUSH, Transform(glm::vec3(130, 0, -9))));
	objects.push_back(new Vegetation(Vegetation::Type::GRASS, Transform(glm::vec3(130, 0, 2))));
	objects.push_back(new Vegetation(Vegetation::Type::GRASS, Transform(glm::vec3(125, 0, -1))));
	objects.push_back(new Vegetation(Vegetation::Type::GRASS, Transform(glm::vec3(130, 0, -5))));
	objects.push_back(new Vegetation(Vegetation::Type::BUSH, Transform(glm::vec3(130, 0, 8))));

	objects.push_back(new Vegetation(Vegetation::Type::BUSH, Transform(glm::vec3(145, 0, 20))));
	objects.push_back(new Vegetation(Vegetation::Type::BUSH, Transform(glm::vec3(160, 0, 23))));
	objects.push_back(new Vegetation(Vegetation::Type::GRASS, Transform(glm::vec3(155, 0, 20))));

	objects.push_back(new Vegetation(Vegetation::Type::BUSH, Transform(glm::vec3(145, 0, -23))));
	objects.push_back(new Vegetation(Vegetation::Type::GRASS, Transform(glm::vec3(154, 0, -25))));
	objects.push_back(new Vegetation(Vegetation::Type::FLOWER, Transform(glm::vec3(155, 0, -25))));
	objects.push_back(new Vegetation(Vegetation::Type::BUSH, Transform(glm::vec3(160, 0, -23))));

	// Terrain
	objects.push_back(new Terrain);

	//// Tanks
	objects.push_back(new Tank(Tank::OLD, Transform(glm::vec3(-400, 9, -300), glm::vec3(0, glm::radians(-90.0f), glm::radians(-13.0f)), glm::vec3(1.2f, 1.2f, 1.2f))));
	objects.push_back(new Tank(Tank::CLASSIC, Transform(glm::vec3(-400, 9, -200), glm::vec3(0, glm::radians(-90.0f), glm::radians(-13.0f)), glm::vec3(1.2f, 1.2f, 1.2f))));
	objects.push_back(new Tank(Tank::DOUBLE, Transform(glm::vec3(-390, 9, -100), glm::vec3(0, 0, glm::radians(-13.0f)), glm::vec3(1.2f, 1.2f, 1.2f))));
	objects.push_back(new Tank(Tank::TURTLE, Transform(glm::vec3(-400, 9, 0), glm::vec3(0, glm::radians(-90.0f), glm::radians(-13.0f)), glm::vec3(1.2f, 1.2f, 1.2f))));
	objects.push_back(new Tank(Tank::TURTLE, Transform(glm::vec3(270, 0, -150))));
	objects.push_back(new Tank(Tank::CLASSIC, Transform(glm::vec3(270, 0, -200))));
	objects.push_back(new Tank(Tank::CLASSIC, Transform(glm::vec3(330, 0, -150))));
	objects.push_back(new Tank(Tank::OLD, Transform(glm::vec3(330, 0, -200))));
	objects.push_back(new Tank(Tank::DOUBLE, Transform(glm::vec3(300, 0, -250))));
	objects.push_back(new Tank(Tank::OLD, Transform(glm::vec3(300, 0, -170))));

	// Helicopters
	objects.push_back(new Helicopter(Helicopter::CLASSIC, Transform(glm::vec3(-20, 80, 0)), true));
	objects.push_back(new Helicopter(Helicopter::ROUND, Transform(glm::vec3(130, 70, 0)), true));
	objects.push_back(new Helicopter(Helicopter::CLASSIC, Transform(glm::vec3(-20, -5, 300), glm::vec3(0, glm::radians(180.0f), 0))));
	objects.push_back(new Helicopter(Helicopter::ROUND, Transform(glm::vec3(120, -5, 300))));

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

	//Skybox
	Skybox skybox;

	//Humans
	//Humans->cages
	objects.push_back(new Human(Human::JOHN, Transform(glm::vec3(0, 0, 250), glm::vec3(0, glm::radians(30.0f), 0))));
	objects.push_back(new Human(Human::JOHN, Transform(glm::vec3(5, 0, 260))));
	objects.push_back(new Human(Human::DIANA, Transform(glm::vec3(3, 0, 262))));
	objects.push_back(new Human(Human::STEVE, Transform(glm::vec3(10, 0, 255))));
	objects.push_back(new Human(Human::OLGA_CROSSED, Transform(glm::vec3(20, 0, 290), glm::vec3(0, glm::radians(180.0f), 0))));
	objects.push_back(new Human(Human::JOHN, Transform(glm::vec3(150, 0, 265), glm::vec3(0, glm::radians(45.0f), 0))));
	objects.push_back(new Human(Human::DIANA, Transform(glm::vec3(155, 0, 260), glm::vec3(0, glm::radians(180.0f), 0))));
	objects.push_back(new Human(Human::DIANA, Transform(glm::vec3(155, 0, 260), glm::vec3(0, glm::radians(180.0f), 0))));
	objects.push_back(new Human(Human::OLGA_CROSSED, Transform(glm::vec3(165, 0, 290), glm::vec3(0, glm::radians(180.0f), 0))));
	objects.push_back(new Human(Human::DIANA, Transform(glm::vec3(260, 0, 275), glm::vec3(0, glm::radians(20.0f), 0))));
	objects.push_back(new Human(Human::JOHN, Transform(glm::vec3(265, 0, 280))));
	objects.push_back(new Human(Human::STEVE_CROSSED, Transform(glm::vec3(255, 0, 290), glm::vec3(0, glm::radians(180.0f), 0))));
	//Humans->ramps
	objects.push_back(new Human(Human::OLGA_CROSSED, Transform(glm::vec3(-350, 0, 0), glm::vec3(0, glm::radians(45.0f), 0))));
	objects.push_back(new Human(Human::STEVE, Transform(glm::vec3(-355, 0, 5), glm::vec3(0, glm::radians(45.0f), 0))));
	objects.push_back(new Human(Human::DIANA, Transform(glm::vec3(-360, 0, -105), glm::vec3(0, glm::radians(315.0f), 0))));
	objects.push_back(new Human(Human::STEVE_CROSSED, Transform(glm::vec3(-365, 0, -110), glm::vec3(0, glm::radians(40.0f), 0))));
	objects.push_back(new Human(Human::OLGA_CROSSED, Transform(glm::vec3(-360, 0, -225), glm::vec3(0, glm::radians(90.0f), 0))));
	objects.push_back(new Human(Human::STEVE_CROSSED, Transform(glm::vec3(-360, 0, -170), glm::vec3(0, glm::radians(45.0f), 0))));
	objects.push_back(new Human(Human::JOHN, Transform(glm::vec3(-340, 0, -245), glm::vec3(0, glm::radians(315.0f), 0))));
	objects.push_back(new Human(Human::STEVE_CROSSED, Transform(glm::vec3(-360, 0, -315), glm::vec3(0, glm::radians(45.0f), 0))));
	objects.push_back(new Human(Human::JOHN, Transform(glm::vec3(-355, 0, -300), glm::vec3(0, glm::radians(315.0f), 0))));
	//Humans->landingpad
	objects.push_back(new Human(Human::JOHN, Transform(glm::vec3(35, 68, 15), glm::vec3(0, glm::radians(-90.0f), 0))));
	objects.push_back(new Human(Human::JOHN, Transform(glm::vec3(37, 68, 20), glm::vec3(0, glm::radians(-110.0f), 0))));
	objects.push_back(new Human(Human::DIANA, Transform(glm::vec3(155, 68, -35))));
	objects.push_back(new Human(Human::OLGA_CROSSED, Transform(glm::vec3(150, 68, -25))));
	objects.push_back(new Human(Human::JOHN, Transform(glm::vec3(165, 68, -30))));
	objects.push_back(new Human(Human::DIANA, Transform(glm::vec3(160, 68, -32))));
	objects.push_back(new Human(Human::STEVE, Transform(glm::vec3(30, 68, 30), glm::vec3(0, glm::radians(-90.0f), 0))));
	//Humans->dirtstadium
	objects.push_back(new Human(Human::DIANA, Transform(glm::vec3(-80, 0, 130), glm::vec3(0, glm::radians(-80.0f), 0))));
	objects.push_back(new Human(Human::JOHN, Transform(glm::vec3(-75, 0, 160), glm::vec3(0, glm::radians(-90.0f), 0))));
	objects.push_back(new Human(Human::STEVE_CROSSED, Transform(glm::vec3(-90, 0, 130), glm::vec3(0, glm::radians(90.0f), 0))));
	objects.push_back(new Human(Human::OLGA_CROSSED, Transform(glm::vec3(-90, 0, 170), glm::vec3(0, glm::radians(90.0f), 0))));
	//Humans->hangar
	objects.push_back(new Human(Human::OLGA_CROSSED, Transform(glm::vec3(250, 0, -110))));
	objects.push_back(new Human(Human::STEVE_CROSSED, Transform(glm::vec3(330, 0, -110))));
	objects.push_back(new Human(Human::STEVE, Transform(glm::vec3(325, 0, -125), glm::vec3(0, glm::radians(180.0f), 0))));
	objects.push_back(new Human(Human::OLGA, Transform(glm::vec3(300, 0, -135), glm::vec3(0, glm::radians(90.0f), 0))));
	objects.push_back(new Human(Human::DIANA, Transform(glm::vec3(250, 0, -200))));
	objects.push_back(new Human(Human::DIANA, Transform(glm::vec3(280, 0, -220), glm::vec3(0, glm::radians(85.0f), 0))));
	objects.push_back(new Human(Human::JOHN, Transform(glm::vec3(330, 0, -250))));
	objects.push_back(new Human(Human::OLGA, Transform(glm::vec3(320, 0, -130))));
	objects.push_back(new Human(Human::JOHN, Transform(glm::vec3(265, 0, -125), glm::vec3(0, glm::radians(180.0f), 0))));

	//Showcases
	objects.push_back(new Showcase(Showcase::OPEN_CAGE, Transform(glm::vec3(0, 0, 300))));
	objects.push_back(new Showcase(Showcase::CLOSED_CAGE, Transform(glm::vec3(70, 0, 300))));
	objects.push_back(new Showcase(Showcase::OPEN_CAGE, Transform(glm::vec3(140, 0, 300))));
	objects.push_back(new Showcase(Showcase::CLOSED_CAGE, Transform(glm::vec3(210, 0, 300))));
	objects.push_back(new Showcase(Showcase::CLOSED_CAGE, Transform(glm::vec3(280, 0, 300))));

	objects.push_back(new Showcase(Showcase::RAMP, Transform(glm::vec3(-400, 0, 0))));
	objects.push_back(new Showcase(Showcase::RAMP, Transform(glm::vec3(-400, 0, -100))));
	objects.push_back(new Showcase(Showcase::RAMP, Transform(glm::vec3(-400, 0, -200))));
	objects.push_back(new Showcase(Showcase::RAMP, Transform(glm::vec3(-400, 0, -300))));

	// Hangar
	objects.push_back(new Hangar(Transform(glm::vec3(300, 0, -200))));

	// Load Time measure: ~1.8s, ~2.5s, ~22.5s
	std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
	std::cout << "Load Time = " << std::chrono::duration_cast<std::chrono::milliseconds> (end - begin).count() / 1000.0f << "[seconds]" << std::endl;



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

		display.Update();
	}

	return 0;
}
