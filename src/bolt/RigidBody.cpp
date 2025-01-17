#include "RigidBody.h"
#include "Entity.h"
#include "BoxCollider.h"
#include "Core.h"
#include "Transform.h"
#include <vector>
namespace bolt
{
	// Called on each tick to handle collisions and to adjust it's position
	void bolt::RigidBody::on_tick()
	{
		// Get all the colliders
		std::vector < std::shared_ptr<BoxCollider> > colliders;
		getEntity()->getCore()->find<BoxCollider>(colliders);

		rend::vec3* m_pos = &getEntity()->get_component<Transform>()->getPosition();

		// Iterate over all colliders to check for collisions
		for (int i = 0; i < colliders.size(); i++)
		{
			// Skip collision check with itself
			if (colliders[i]->getEntity() == getEntity())
			{
				continue;
			}

			// Check if collider is colliding with current entitieas collider
			if (colliders[i]->colliding(*this->getEntity()->get_component<BoxCollider>()))
			{
				//TODO
				float _amount = 0.001f; // amount to move entity
				float step = 0.001f;	// incremental step for position adjustments

				// Keep adjusting positions until collision is resolved
				while (true)
				{
					if (!colliders[i]->colliding(*this->getEntity()->get_component<BoxCollider>())) break;
					getEntity()->get_component<Transform>()->setPosition(rend::vec3{ getEntity()->get_component<Transform>()->getPosition().x + _amount,
						getEntity()->get_component<Transform>()->getPosition().y, getEntity()->get_component<Transform>()->getPosition().z });

					if (!colliders[i]->colliding(*this->getEntity()->get_component<BoxCollider>())) break;
					getEntity()->get_component<Transform>()->setPosition(rend::vec3{ getEntity()->get_component<Transform>()->getPosition().x - (_amount * 2),
						getEntity()->get_component<Transform>()->getPosition().y, getEntity()->get_component<Transform>()->getPosition().z });

					if (!colliders[i]->colliding(*this->getEntity()->get_component<BoxCollider>())) break;
					getEntity()->get_component<Transform>()->setPosition(rend::vec3{ getEntity()->get_component<Transform>()->getPosition().x + _amount,
						getEntity()->get_component<Transform>()->getPosition().y, getEntity()->get_component<Transform>()->getPosition().z });
					getEntity()->get_component<Transform>()->setPosition(rend::vec3{ getEntity()->get_component<Transform>()->getPosition().x,
						getEntity()->get_component<Transform>()->getPosition().y, getEntity()->get_component<Transform>()->getPosition().z + _amount });

					if (!colliders[i]->colliding(*this->getEntity()->get_component<BoxCollider>())) break;
					getEntity()->get_component<Transform>()->setPosition(rend::vec3{ getEntity()->get_component<Transform>()->getPosition().x,
						getEntity()->get_component<Transform>()->getPosition().y, getEntity()->get_component<Transform>()->getPosition().z - (_amount * 2) });

					if (!colliders[i]->colliding(*this->getEntity()->get_component<BoxCollider>())) break;
					getEntity()->get_component<Transform>()->setPosition(rend::vec3{ getEntity()->get_component<Transform>()->getPosition().x,
						getEntity()->get_component<Transform>()->getPosition().y, getEntity()->get_component<Transform>()->getPosition().z + _amount });
					getEntity()->get_component<Transform>()->setPosition(rend::vec3{ getEntity()->get_component<Transform>()->getPosition().x,
						getEntity()->get_component<Transform>()->getPosition().y + _amount, getEntity()->get_component<Transform>()->getPosition().z});

					if (!colliders[i]->colliding(*this->getEntity()->get_component<BoxCollider>())) break;
					getEntity()->get_component<Transform>()->setPosition(rend::vec3{ getEntity()->get_component<Transform>()->getPosition().x,
						getEntity()->get_component<Transform>()->getPosition().y - (_amount * 2), getEntity()->get_component<Transform>()->getPosition().z });

					if (!colliders[i]->colliding(*this->getEntity()->get_component<BoxCollider>())) break;
					getEntity()->get_component<Transform>()->setPosition(rend::vec3{ getEntity()->get_component<Transform>()->getPosition().x,
						getEntity()->get_component<Transform>()->getPosition().y + _amount, getEntity()->get_component<Transform>()->getPosition().z });
					_amount += step;
				}
			}
		}
	}
}

