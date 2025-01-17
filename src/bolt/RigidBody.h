#include <iostream>
#include "rend/rend.h"
#include <vector>
#include <memory>
#include "Component.h"



namespace bolt
{
	//struct Component;
	struct BoxCollider;
	//struct Entity;
	struct Transform;
	struct RigidBody : Component
	{
		void on_tick();
		

	};
}

