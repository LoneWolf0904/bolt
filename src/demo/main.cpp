#include <bolt/bolt.h>
#include <iostream>

using namespace bolt;

struct Test : Component

{
//	void on_initialize()
//	{
//		printf("Player::initialize\n");
//	}
//
	void on_tick()
	{
		//printf("Player::tick\n");
		if (getEntity()->getCore()->getKeyboard()->isKeyPressed(SDLK_a))
		{
			std::cout << "A is pressed" << std::endl;
		}
	}

	/*void on_render()
	{
		printf("Player::render\n");
	}*/
};

int main()
{

	std::cout << "Hello World!" << std::endl;

	std::shared_ptr<Core> core = Core::initialize();
	

	std::shared_ptr<Entity> ent = core->add_entity();
	std::shared_ptr<TriangleRenderer> tr = ent->add_component<TriangleRenderer>();
	tr->set_texture(core->get_resources()->load<Texture>("textures/cat"));
	ent->get_component<Transform>()->setPosition(rend::vec3(0, 0, -10));
	ent->get_component<Transform>()->setScale(rend::vec3(5.0f));

	std::shared_ptr<Entity> ent1 = core->add_entity();
	ent1->add_component<Test>();

	core->start();
	//core->add_entity();
	return 0;
}
