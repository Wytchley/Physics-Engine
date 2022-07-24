#pragma once
#include <tuple>
#include <vector>
#include "PhysicsEntity.h"
#include "PhysicsEnvironment.h"

namespace Physics {
	
	using namespace std;

	class RigidBody2D : PhysicsEntity {

	public:
		// Constructor
		RigidBody2D(float mass, float xPos, float yPos, float xVel, float yVel, float xAcc, float yAcc, vector<float> vertices, PhysicsEnvironment* env) :
			mMass(mass), mXPos(xPos), mYPos(yPos),
			mXVelocity(xVel), mYVelocity(yVel), mXAcceleration(xAcc),
			mYAcceleration(yAcc) {
			mVertices = vertices;

			// Register object in environment and store reference to it
			env->registerEntity(this);
			mEnvironment = env;
		};

		// PhysicsEntity update method
		void update(double deltaTime) override;

		// Physics methods
		void applyForce(float x, float y);

		// SETTERS
		void setVelocity(float x, float y);
		void setAcceleration(float x, float y);
		void setPosition(float x, float y);

		// GETTERS
		tuple<float, float> getPosition();
		tuple<float, float> getVelocity();
		tuple<float, float> getAcceleration();
		double getSpeed();

	private:
		float mXPos, mYPos;
		float mXVelocity, mYVelocity;
		float mXAcceleration, mYAcceleration;
		float mMass;
		vector<float> mVertices;
		PhysicsEnvironment* mEnvironment;

	};
}