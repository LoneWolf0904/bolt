#include "BoxCollider.h"
#include "Entity.h"
#include "Transform.h"

namespace bolt
{
	bool BoxCollider::colliding(BoxCollider& _other)
	{
		rend::vec3 a = getEntity()->getTransform()->getPosition();
		rend::vec3 b = _other.getEntity()->getTransform()->getPosition();
		rend::vec3 ahs = m_size / 2.0f;
		rend::vec3 bhs = _other.m_size / 2.0f;

		// TODO: x
		if (a.x > b.x)
		{
			if (b.x + bhs.x < a.x - ahs.x)
			{
				return false;
			}
		}
		else
		{
			if (a.x + ahs.x < b.x - bhs.x)
			{
				return false;
			}
		}

		// TODO: y
		if (a.y > b.y)
		{
			if (b.y + bhs.y < a.y - ahs.y)
			{
				return false;
			}
		}
		else
		{
			if (a.y + ahs.y < b.y - bhs.y)
			{
				return false;
			}
		}

		// TODO: z
		if (a.z > b.z)
		{
			if (b.z + bhs.z < a.z - ahs.z)
			{
				return false;
			}
		}
		else
		{
			if (a.z + ahs.z < b.z - bhs.z)
			{
				return false;
			}
		}

	}
}