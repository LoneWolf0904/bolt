#include <bolt/bolt.h>
#include <iostream>

using namespace bolt;

struct Test : Component

{

	void on_tick()
	{
		std::shared_ptr<Transform> transform = getEntity()->get_component<Transform>();
		rend::vec3 currentPosition = transform->getPosition();
		rend::vec3 currentRotation = transform->getRotation();

	
		if (getEntity()->getCore()->getKeyboard()->isKey(SDLK_w))
		{
			transform->setPosition(rend::vec3(currentPosition.x, 0, currentPosition.z - 0.05f));
			transform->setRotation(rend::vec3(0, 180, 0));
		}

		if (getEntity()->getCore()->getKeyboard()->isKey(SDLK_s))
		{
			transform->setPosition(rend::vec3(currentPosition.x, 0, currentPosition.z + 0.05f));
			transform->setRotation(rend::vec3(0, 0, 0));
		}


		if (getEntity()->getCore()->getKeyboard()->isKey(SDLK_a))
		{
			transform->setPosition(rend::vec3(currentPosition.x - 0.05f, 0, currentPosition.z));
			transform->setRotation(rend::vec3(0, -90, 0));
			
		}


		if (getEntity()->getCore()->getKeyboard()->isKey(SDLK_d))
		{
			transform->setPosition(rend::vec3(currentPosition.x + 0.05f, 0, currentPosition.z));
			transform->setRotation(rend::vec3(0, 90, 0));
		}
	}

	void on_gui()
	{
		/*rend::mat4 ortho = rend::ortho(0.0f, 800.0f, 0.0f, 600.0f);
		rend::mat4 model = rend::translate(rend::mat4(1.0f), rend::vec3(1.0f, 0.0f, 0.0f));
		rend::Mesh m_mesh = rend::Mesh(rend::GUI_QUAD_MESH);
		rend::Shader m_shader = rend::Shader(rend::TEXTURE_SHADER);*/

		//core()->gui()->image(100, 100, 75, 25, core->get_resources()->load<Texture>("textures/cat"));
		//getEntity()->getCore()->get_gui()

		//if (core()->gui()->button(100, 100, 75, 25, "Click Me!"))
		//{
		//	getEntity()->get_component<Transform>()->setRotation(rend::vec3(0, getEntity()->get_component<Transform>()->getRotation().y + 10.0f, 0));
		//}
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
	ent->add_component<SoundSource>();
	tr->set_texture(core->get_resources()->load<Texture>("textures/background"));
	ent->get_component<Transform>()->setPosition(rend::vec3(0, 0, -25));
	ent->get_component<Transform>()->setScale(rend::vec3(30.0f));

	std::shared_ptr<Entity> entControls = core->add_entity();
	std::shared_ptr<TriangleRenderer> controls = entControls->add_component<TriangleRenderer>();
	controls->set_texture(core->get_resources()->load<Texture>("textures/WASD"));
	entControls->get_component<Transform>()->setPosition(rend::vec3(4.5, -4.5, -10));
	entControls->get_component<Transform>()->setScale(rend::vec3(2.0f));

	std::shared_ptr<Entity> ent3 = core->add_entity();
	std::shared_ptr<Renderer> _render = ent3->add_component<Renderer>();
	std::shared_ptr<BoxCollider> bc = ent3->add_component<BoxCollider>();
	bc->setSize(rend::vec3(1, 1, 1));
	_render->onInitialize();
	_render->setTexture(core->get_resources()->load<Texture>("textures/curuthers/Whiskers_diffuse"));
	_render->setShader(core->get_resources()->load<Shader>("Shaders/Model2"));
	_render->setModel(core->get_resources()->load<Model>("textures/curuthers/curuthers"));
	ent3->get_component<Transform>()->setPosition(rend::vec3(0, 0, -10));
	ent3->get_component<Transform>()->setRotation(rend::vec3(0, 0, 0));
	ent3->get_component<Transform>()->setScale(rend::vec3(1.0f));
	ent3->add_component<RigidBody>();

	std::shared_ptr<Entity> ent4 = core->add_entity();
	std::shared_ptr<Renderer> _render1 = ent4->add_component<Renderer>();
	std::shared_ptr<BoxCollider> bc1 = ent4->add_component<BoxCollider>();
	bc1->setSize(rend::vec3(1, 1, 1));
	_render1->onInitialize();
	_render1->setTexture(core->get_resources()->load<Texture>("textures/curuthers/Whiskers_diffuse"));
	_render1->setShader(core->get_resources()->load<Shader>("Shaders/Model2"));
	_render1->setModel(core->get_resources()->load<Model>("textures/curuthers/curuthers"));
	ent4->get_component<Transform>()->setPosition(rend::vec3(3, 0, -10));
	ent4->get_component<Transform>()->setRotation(rend::vec3(0, -90, 0));
	ent4->get_component<Transform>()->setScale(rend::vec3(1.0f));
	ent4->add_component<RigidBody>();

	std::shared_ptr<Entity> ent5 = core->add_entity();
	std::shared_ptr<Renderer> _render2 = ent5->add_component<Renderer>();
	std::shared_ptr<BoxCollider> bc2 = ent5->add_component<BoxCollider>();
	bc2->setSize(rend::vec3(1, 1, 1));
	_render2->onInitialize();
	_render2->setTexture(core->get_resources()->load<Texture>("textures/curuthers/Whiskers_diffuse"));
	_render2->setShader(core->get_resources()->load<Shader>("Shaders/Model2"));
	_render2->setModel(core->get_resources()->load<Model>("textures/curuthers/curuthers"));
	ent5->get_component<Transform>()->setPosition(rend::vec3(-3, 0, -10));
	ent5->get_component<Transform>()->setRotation(rend::vec3(0, 90, 0));
	ent5->get_component<Transform>()->setScale(rend::vec3(1.0f));
	ent5->add_component<RigidBody>();

	std::shared_ptr<Entity> ent6 = core->add_entity();
	std::shared_ptr<Renderer> _render3 = ent6->add_component<Renderer>();
	std::shared_ptr<BoxCollider> bc3 = ent6->add_component<BoxCollider>();
	bc3->setSize(rend::vec3(1, 1, 1));
	_render3->onInitialize();
	_render3->setTexture(core->get_resources()->load<Texture>("textures/curuthers/Whiskers_diffuse"));
	_render3->setShader(core->get_resources()->load<Shader>("Shaders/Model2"));
	_render3->setModel(core->get_resources()->load<Model>("textures/curuthers/curuthers"));
	ent6->get_component<Transform>()->setPosition(rend::vec3(0, 0, -15));
	ent6->get_component<Transform>()->setRotation(rend::vec3(0, 90, 0));
	ent6->get_component<Transform>()->setScale(rend::vec3(1.0f));
	//ent6->add_component<RigidBody>();


	//std::shared_ptr<Entity> ent1 = core->add_entity();
	ent3->add_component<Test>();



	core->start();
	//core->add_entity();
	return 0;
}
