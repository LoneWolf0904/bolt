
#include <iostream>
#include "rend/rend.h"
#include <vector>
#include <memory>
#include "bolt.h"

namespace bolt
{
	struct RigidBody : Component
	{
		void onTick();
		//std::vector<std::shared_ptr<T> >& _out;

	};
}

