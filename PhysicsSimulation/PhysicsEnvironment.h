#pragma once
#include "PhysicsEntity.h"
#include <vector>

namespace Physics {
	class PhysicsEnvironment {

	public:
		static const float EARTH_GRAVITY;

		PhysicsEnvironment(float gravitationalAcceleration = EARTH_GRAVITY) {
			mGravitationalAcceleration = gravitationalAcceleration;
			mAllPhysicsEntities.reserve(20);
		};
		void registerEntity(PhysicsEntity* entity);
		void update(double deltaTime);
		void updateGravitationalAcceleration(float g);

	private:
		std::vector<PhysicsEntity*> mAllPhysicsEntities;
		float mGravitationalAcceleration;
	};
}

