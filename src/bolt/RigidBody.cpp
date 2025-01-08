#include "RigidBody.h"
//#include "Entity.h"
#include <vector>
namespace bolt
{
	void bolt::RigidBody::onTick()
	{
		std::vector < std::shared_ptr<BoxCollider> > colliders;
		getEntity()->getCore()->find<BoxCollider>(colliders);

		rend::vec3* m_pos = &getEntity()->get_component<Transform>()->getPosition();

		for (int i = 0; i < colliders.size(); i++)
		{
			if (colliders[i]->getEntity() == getEntity())
			{
				continue;
			}

			if (colliders[i]->colliding(*this->getEntity()->get_component<BoxCollider>()))
			{
				//TODO
				float _amount = 0.1f;
				float step = 0.1f;

				while (true)
				{
					if (!colliders[i]->colliding(*this->getEntity()->get_component<BoxCollider>())) break;
					m_pos->x += _amount;

					if (!colliders[i]->colliding(*this->getEntity()->get_component<BoxCollider>())) break;
					m_pos->x -= _amount;
					m_pos->x -= _amount;

					if (!colliders[i]->colliding(*this->getEntity()->get_component<BoxCollider>())) break;
					m_pos->x += _amount;
					m_pos->z += _amount;

					if (!colliders[i]->colliding(*this->getEntity()->get_component<BoxCollider>())) break;
					m_pos->z -= _amount;
					m_pos->z -= _amount;

					if (!colliders[i]->colliding(*this->getEntity()->get_component<BoxCollider>())) break;
					m_pos->z += _amount;
					m_pos->y += _amount;

					if (!colliders[i]->colliding(*this->getEntity()->get_component<BoxCollider>())) break;
					m_pos->y -= _amount;
					m_pos->y -= _amount;

					if (!colliders[i]->colliding(*this->getEntity()->get_component<BoxCollider>())) break;
					m_pos->y += _amount;
					_amount += step;
				}
			}
		}
	}
}

