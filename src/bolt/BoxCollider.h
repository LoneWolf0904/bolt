
#include <iostream>
#include "Component.h"
#include <rend/rend.h>

namespace bolt
{
	// Represents a commponent for detecting collision
	struct BoxCollider : Component
	{
		// Collision check
		bool colliding(BoxCollider& _other);

		// Getters and Setters
		void setSize(rend::vec3 _size) { m_size = _size; }
		rend::vec3 getSize() { return m_size; }


	private:
		rend::vec3 m_size;
		rend::vec3 m_offset;

	};
}
