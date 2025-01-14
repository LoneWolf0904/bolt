
#include <iostream>
#include "Component.h"
#include <rend/rend.h>

namespace bolt
{
	struct BoxCollider : Component
	{
		bool colliding(BoxCollider& _other);

		void setSize(rend::vec3 _size) { m_size = _size; }
		rend::vec3 getSize() { return m_size; }


	private:
		rend::vec3 m_size;
		rend::vec3 m_offset;

	};
}
