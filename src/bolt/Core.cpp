#include "Core.h"
#include "Entity.h"
#include "Window.h"
#include <iostream>

struct window;

namespace bolt
{
	std::shared_ptr<Core> Core::initialize()
	{
		std::shared_ptr<Core> rtn = std::make_shared<Core>();
		rtn->m_window = std::make_shared<Window>();
		rtn->m_self = rtn;
		return rtn;
	}

	std::shared_ptr<Entity> Core::add_entity()
	{
		std::shared_ptr<Entity> rtn = std::make_shared<Entity>();

		rtn->m_self = rtn;
		rtn->m_core = m_self;
		m_entities.push_back(rtn);

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

			SDL_Rend_SwapWindow(m_window->m_raw);
		}
	}
}