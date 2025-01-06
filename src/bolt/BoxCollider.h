#include <iostream>
#include "Component.h"
#include <rend/rend.h>

namespace bolt
{
	struct BoxCollider : Component
	{
		bool colliding(BoxCollider& _other);

	private:
		rend::vec3 m_size;
		rend::vec3 m_offset;

	};
}
