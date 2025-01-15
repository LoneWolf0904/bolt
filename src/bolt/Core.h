//#include "bolt.h"
#include <memory>
#include <vector>
#include <AL/al.h>
#include <AL/alc.h>
//#include "stb_vorbis.c"

namespace bolt
{
	struct Keyboard;
	struct Entity;
	struct Window;
	struct Resources;

	struct Core //: std::enable_shared_from_this<Core> junky
	{
		template <typename T>
		void find(std::vector<std::shared_ptr<T> >& _out)
		{
			// Go through each entity in core
			for (size_t ei = 0; ei < m_entities.size(); ++ei)
			{
				std::shared_ptr<Entity> e = m_entities.at(ei);

				// Go through each Component in Entity
				for (size_t ci = 0; ci < e->m_components.size(); ++ci)
				{
					std::shared_ptr<Component> c = e->m_components.at(ci);

					// Try to dynamic cast the Component to a T
					std::shared_ptr<T> t = std::dynamic_pointer_cast<T>(c);

					// If succeeds then add it to the output array
					if (t)
					{
						_out.push_back(t);
					}
				}
			}
		}

		static std::shared_ptr<Core> initialize();
		void start();
		std::shared_ptr<Entity> add_entity();
		std::shared_ptr<Window> window() const;
		void update();
		std::shared_ptr<Keyboard> getKeyboard();
		std::shared_ptr<Resources> get_resources();
		//std::shared_ptr<GUI> get_gui();
	private:
		std::shared_ptr<Window> m_window;
		std::vector<std::shared_ptr<Entity> > m_entities;
		std::weak_ptr<Core> m_self;
		std::shared_ptr<Keyboard> m_keyboard;
		std::shared_ptr<Resources> m_resources;
		//std::shared_ptr<GUI> m_gui;
		

		bool m_running;
	};

	
}






