//#include "bolt.h"
#include "RigidBody.h"
#include "Entity.h"
#include "BoxCollider.h"
#include "Core.h"
#include "Transform.h"
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

