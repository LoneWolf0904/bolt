//#include "bolt.h"
#include <iostream>
#include "rend/rend.h"
#include <vector>
#include <memory>
#include "Component.h"
//#include "Transform.h"
//#include "BoxCollider.h"


namespace bolt
{
	//struct Component;
	struct BoxCollider;
	//struct Entity;
	struct Transform;
	struct RigidBody : Component
	{
		void on_tick();
		//std::vector<std::shared_ptr<T> >& _out;

	};
}

