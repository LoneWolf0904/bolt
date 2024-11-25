#include <iostream>
#include "Component.h"
#include <rend/rend.h>

namespace bolt
{
	struct Transform : Component
	{
		rend::mat4 model();

		void setPosition(rend::vec3 position) { m_position = position; }
		void setScale(rend::vec3 scale) { m_scale = scale; }
		void setRotation(rend::vec3 rotation) { m_rotation = rotation; }

	private:
		rend::vec3 m_position;
		rend::vec3 m_rotation;
		rend::vec3 m_scale;
	};
}
