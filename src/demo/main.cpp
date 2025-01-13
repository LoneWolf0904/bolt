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

	void on_gui()
	{
		rend::mat4 ortho = rend::ortho(0.0f, 800.0f, 0.0f, 600.0f);
		rend::mat4 model = rend::translate(rend::mat4(1.0f), rend::vec3(1.0f, 0.0f, 0.0f));
		rend::Mesh m_mesh = rend::Mesh(rend::GUI_QUAD_MESH);
		rend::Shader m_shader = rend::Shader(rend::TEXTURE_SHADER);
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
	
	//std::shared_ptr<Entity> ent = core->add_entity();
	//std::shared_ptr<TriangleRenderer> tr = ent->add_component<TriangleRenderer>();
	////std::shared_ptr<Renderer> _render = ent->add_component<Renderer>();
	//ent->add_component<SoundSource>();
	//tr->set_texture(core->get_resources()->load<Texture>("textures/cat"));
	//ent->get_component<Transform>()->setPosition(rend::vec3(0, 0, -10));
	//ent->get_component<Transform>()->setScale(rend::vec3(5.0f));

	std::shared_ptr<Entity> ent3 = core->add_entity();
	std::shared_ptr<Renderer> _render = ent3->add_component<Renderer>();
	_render->onInitialize();
	_render->setTexture(core->get_resources()->load<Texture>("textures/curuthers/Whiskers_diffuse"));
	_render->setShader(core->get_resources()->load<Shader>("assets/shaders/basic"));
	_render->setModel(core->get_resources()->load<Model>("textures/curuthers/curuthers"));
	ent3->get_component<Transform>()->setPosition(rend::vec3(0, 0, -3));
	ent3->get_component<Transform>()->setScale(rend::vec3(1.0f));
	ent3->get_component<Transform>()->setRotation(rend::vec3(0, 0, 0));


	std::shared_ptr<Entity> ent1 = core->add_entity();
	ent1->add_component<Test>();



	core->start();
	//core->add_entity();
	return 0;
}
