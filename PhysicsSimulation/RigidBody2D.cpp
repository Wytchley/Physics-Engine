#include "RigidBody2D.h"
using std::tuple;

namespace Physics {
	
	void RigidBody2D::applyForce(float x, float y) {

	}
	
	void RigidBody2D::update(double deltaTime) {
		// Increase velocity due to acceleration
		mXVelocity += mXAcceleration * deltaTime;
		mYVelocity += mYAcceleration * deltaTime;

		// Alter position based on velocity
		mXPos += mXVelocity * deltaTime;
		mYPos += mYVelocity * deltaTime;
	}

	// ------------- SETTERS ------------- 
	void RigidBody2D::setVelocity(float x, float y) {
		mXVelocity = x;
		mYVelocity = y;
	}

	void RigidBody2D::setAcceleration(float x, float y) {
		mXAcceleration = x;
		mYAcceleration = y;
	}

	void RigidBody2D::setPosition(float x, float y) {
		mXPos = x;
		mYPos = y;
	}

	// ------------- GETTERS -------------
	tuple<float, float> RigidBody2D::getPosition()  {
		return (tuple<float, float> {mXPos, mYPos});
	}

	tuple<float, float> RigidBody2D::getVelocity()  {
		return (tuple<float, float> {mXVelocity, mYVelocity});
	}

	tuple<float, float> RigidBody2D::getAcceleration()  {
		return (tuple<float, float> {mXVelocity, mYVelocity});
	}

	double RigidBody2D::getSpeed()  {
		return sqrt(pow(mXVelocity, 2) + pow(mYVelocity, 2));
	}
}