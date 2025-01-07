#include <iostream>
#include "Component.h"
#include "rend/rend.h"
#include <vector>
#include <memory>

namespace bolt
{
	struct RigidBody : Component
	{
		void onTick();
		//std::vector<std::shared_ptr<T> >& _out;

	};
}