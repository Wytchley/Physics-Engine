#pragma once

namespace Physics {
    class PhysicsEntity {
	public:
		virtual void update(double deltaTime) = 0;
	};
}

