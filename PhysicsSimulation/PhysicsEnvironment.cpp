#include "PhysicsEnvironment.h"
#include "PhysicsEntity.h"
#include <vector>

namespace Physics {
	const float PhysicsEnvironment::EARTH_GRAVITY = -9.81f;


	void PhysicsEnvironment::registerEntity(PhysicsEntity* entity) {
		mAllPhysicsEntities.push_back(entity);
	}

	void PhysicsEnvironment::update(double deltaTime) {
		// Update all physics entities
		std::vector<PhysicsEntity*>::iterator it;
		for (it = mAllPhysicsEntities.begin(); it != mAllPhysicsEntities.end(); ++it) {
			(*it)->update(deltaTime);
		}
		
		mAllPhysicsEntities[0]->update(deltaTime);
		// Find and resolve collisions

	}

	void PhysicsEnvironment::updateGravitationalAcceleration(float g) {
		mGravitationalAcceleration = g;
	}

}