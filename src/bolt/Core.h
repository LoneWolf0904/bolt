/**
 * file Core.h
 * Contains the definition of the Core class for the Bolt framework.
 */
#include <memory>
#include <vector>
#include <AL/al.h>
#include <AL/alc.h>

namespace bolt
{
	struct Keyboard;
	struct Entity;
	struct Window;
	struct Resources;

	/**
	* Class Core
	* Manages the main gameloop, entities, and resources.
	*/

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

		/**
		* Initializes the Core system and returns a shared pointer to it.
		* 
		*/
		static std::shared_ptr<Core> initialize();

		void start(); ///< starts the main game loop
		std::shared_ptr<Entity> add_entity(); ///< Adds a new entity to the Core System
		std::shared_ptr<Window> window() const; ///< Retrieves the main application window
		void update();
		std::shared_ptr<Keyboard> getKeyboard(); ///< Retrieves keyboard instance for input handling
		std::shared_ptr<Resources> get_resources();	///< Retrieves resources manager for handling resource
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






