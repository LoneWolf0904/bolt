#include <bolt/bolt.h>
#include <iostream>

using namespace bolt;

//struct Test : Component
//
//{
//	void on_initialize()
//	{
//		printf("Player::initialize\n");
//	}
//
//	void on_tick()
//	{
//		printf("Player::tick\n");
//	}
//
//	void on_render()
//	{
//		printf("Player::render\n");
//	}
//};

int main()
{
	std::cout << "Hello World!" << std::endl;

	std::shared_ptr<Core> core = Core::initialize();

	std::shared_ptr<Entity> ent = core->add_entity();
	ent->add_component<TriangleRenderer>();
	ent->get_component<Transform>()->setPosition(rend::vec3(5, 0, -10));
	ent->get_component<Transform>()->setScale(rend::vec3(5.0f));

	core->start();
	//core->add_entity();
	return 0;
}
