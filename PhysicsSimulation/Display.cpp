#include "Display.h"
#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

namespace Graphics {

	GLFWwindow* Display::getWindow() {
		return mWindow;
	}

	void Display::destroyWindow() {
		glfwDestroyWindow(mWindow);
		glfwTerminate();
	}

	void Display::calculateDeltaTime() {
		mPreviousFrameTime = mCurrentFrameTime;
		mCurrentFrameTime = glfwGetTime();
		mDeltaTime = (mCurrentFrameTime - mPreviousFrameTime);
	}

	double Display::getDeltaTime() {
		return mDeltaTime;
	}
}