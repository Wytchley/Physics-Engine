#pragma once
#include <string>
#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

namespace Graphics {

	using namespace std;

	class Display {

	public:
		Display(int width, int height, const char* title) {
			glfwInit();
			glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
			glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
			glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

			mWindow = glfwCreateWindow(width, height, title, NULL, NULL);
			glfwMakeContextCurrent(mWindow);

			mCurrentFrameTime = glfwGetTime();
		}

		GLFWwindow* getWindow();
		void destroyWindow();

		void calculateDeltaTime();
		double getDeltaTime();

	private:
		GLFWwindow* mWindow;
		double mPreviousFrameTime = 0.0;
		double mDeltaTime = 0.0;
		double mCurrentFrameTime = 0.0;

	};
}
