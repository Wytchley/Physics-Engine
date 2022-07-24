#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <string>
#include <tuple>
#include <vector>
#include "Display.h"
#include "RigidBody2D.h"
#include "PhysicsEnvironment.h"

using namespace Graphics;
using namespace Physics;
using namespace std;

int main() {

	Display display = Display(1100, 1100, "Physics Simulation");
	GLFWwindow* window = display.getWindow();
	glfwMakeContextCurrent(window);
	gladLoadGL();

	// Create physics environment
	PhysicsEnvironment physicsEnv = PhysicsEnvironment();

	vector<float> squareVerts = {1, 1, 2, 1, 2, 2, 1, 2};
	float squareVertsArray[] = {
		1.0f, 1.0f, 0.0f, 
		2.0f, 1.0f, 0.0f, 
		2.0f, 2.0f, 0.0f, 
		1.0f, 2.0f, 0.0f
	};
	
	RigidBody2D rigidbodySquare = RigidBody2D(1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, physicsEnv.EARTH_GRAVITY, squareVerts, &physicsEnv);

	glClearColor(0.0f, 0.55f, 0.36f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	glfwSwapBuffers(window);

	while(!glfwWindowShouldClose(window)) {
		// Get inputs and calculate necessary simulation values
		glfwPollEvents();
		display.calculateDeltaTime();

		// Update physics
		physicsEnv.update(display.getDeltaTime());

		// Calculate center of shape
		tuple<float, float> pos = rigidbodySquare.getPosition();
		cout << "Position: (" << get<0>(pos) << ", " << get<1>(pos) << ")" << endl;
	}

	display.destroyWindow();
	return 0;

}