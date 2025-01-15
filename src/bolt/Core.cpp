#include "Core.h"
#include "Entity.h"
#include "Window.h"
#include "Transform.h"
#include "Keyboard.h"
#include "Resources.h"
#include <iostream>

struct window;

namespace bolt
{
	std::shared_ptr<Core> Core::initialize()
	{
		/*************************************************************************
			* Initialization
		*************************************************************************/
		ALCdevice* device = alcOpenDevice(NULL);

		if (!device)
		{
			throw std::runtime_error("Failed to open audio device");
		}

		ALCcontext* context = alcCreateContext(device, NULL);

		if (!context)
		{
			alcCloseDevice(device);
			throw std::runtime_error("Failed to create audio context");
		}

		if (!alcMakeContextCurrent(context))
		{
			alcDestroyContext(context);
			alcCloseDevice(device);
			throw std::runtime_error("Failed to make context current");
		}

		alListener3f(AL_POSITION, 0.0f, 0.0f, 0.0f);
		//alListener3f(AL_VELOCITY, 0.0f, 0.0f, 0.0f);



		/**********************************************************/

		std::shared_ptr<Core> rtn = std::make_shared<Core>();
		rtn->m_window = std::make_shared<Window>();
		rtn->m_keyboard = std::make_shared<Keyboard>();
		rtn->m_resources = std::make_shared<Resources>();
		rtn->m_self = rtn;
		return rtn;
	}

	std::shared_ptr<Entity> Core::add_entity()
	{
		std::shared_ptr<Entity> rtn = std::make_shared<Entity>();

		rtn->m_self = rtn;
		rtn->m_core = m_self;
		m_entities.push_back(rtn);
		rtn->add_component<Transform>();

		std::cout << rtn->m_core.lock().get() << std::endl;
		return rtn;
	}

	void Core::start()
	{
		m_running = false;

		while (!m_running)
		{
			SDL_Event event = { 0 };

			while (SDL_PollEvent(&event))
			{
				if (event.type == SDL_QUIT)
				{
					m_running = true;
				}

				if (event.type == SDL_KEYDOWN)
				{
					sys::out("Event\n");
					//SDL_KeyboardEvent keyEvent = event.key;

					m_keyboard->pressedKeys.push_back(event.key.keysym.sym);
					m_keyboard->keys.push_back(event.key.keysym.sym);
				}

				if (event.type == SDL_KEYUP)
				{
					m_keyboard->releasedKeys.push_back(event.key.keysym.sym);

					for (int i = 0; i < m_keyboard->keys.size(); ++i)
					{
						if (m_keyboard->keys[i] == event.key.keysym.sym)
						{
							m_keyboard->keys.erase(m_keyboard->keys.begin() + i);
							--i;
						}
					}
				}
			}

			for (size_t ei = 0; ei < m_entities.size(); ++ei)
			{
				m_entities.at(ei)->tick();
			}

			glClearColor(1.0f, 0.0f, 0.0f, 1.0f);
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

			//SDL_Rend_ClearWindow(m_window->m_raw);

			for (size_t ei = 0; ei < m_entities.size(); ++ei)
			{
				m_entities.at(ei)->render();
			}

			for (size_t ei = 0; ei < m_entities.size(); ++ei)
			{
				m_entities.at(ei)->gui();
			}

			m_keyboard->pressedKeys.clear();
			m_keyboard->releasedKeys.clear();
			SDL_Rend_SwapWindow(m_window->m_raw);
		}
	}

	std::shared_ptr<Keyboard> Core::getKeyboard()
	{
		return m_keyboard;
	}

	std::shared_ptr<Resources> Core::get_resources()
	{
		return m_resources;
	}

	/*std::shared_ptr<GUI> Core::get_gui()
	{
		return m_gui;
	}*/
}