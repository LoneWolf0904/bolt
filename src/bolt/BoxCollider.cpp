#include "BoxCollider.h"
#include "Entity.h"
#include "Transform.h"

namespace bolt
{
	// Collision check
	bool BoxCollider::colliding(BoxCollider& _other)
	{
		// sets the position of both collider entities
		rend::vec3 a = getEntity()->get_component<Transform>()->getPosition();
		rend::vec3 b = _other.getEntity()->get_component<Transform>()->getPosition();

		// Get half the sizes of both the colliders
		rend::vec3 ahs = m_size / 2.0f;
		rend::vec3 bhs = _other.m_size / 2.0f;

		// TODO: Check for collision along the x-axis
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

		// TODO: Check for collision along y-axis
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

		// TODO: Check for collision along z-axis
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
		return true;
	}
}