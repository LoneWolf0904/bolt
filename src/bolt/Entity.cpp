#include "Entity.h"
#include "Component.h"
#include "Transform.h"

namespace bolt
{
	void Entity::tick()
	{
		for (size_t ci = 0; ci < m_components.size(); ++ci)
		{
			m_components.at(ci)->tick();
		}
	}

	void Entity::render()
	{
		for (size_t ci = 0; ci < m_components.size(); ++ci)
		{
			m_components.at(ci)->render();
		}
	}

	void Entity::gui()
	{
		for (size_t ci = 0; ci < m_components.size(); ++ci)
		{
			m_components.at(ci)->gui();
		}
	}

	std::shared_ptr<Core> Entity::getCore()
	{
		return m_core.lock();
	}

	/*std::shared_ptr<Transform> Entity::getTransform()
	{
		return m_transform;
	}*/
}