
#include <memory>
#include <vector>
#include <stdexcept>


namespace bolt
{
	struct Core;
	struct Component;

	/**
	 * class Entity
	 * Represents an entity in the game world. Entities can have multiple components attached.
	 */
	struct Entity
	{
		/**
		* Adds a component of type T to the entity.
		* tparam T The type of the component to add.
		* return A shared pointer to the newly added component.
		* throws std::runtime_error If the component fails to initialize.
		*/
		template <typename T>
		std::shared_ptr<T> add_component()
		{
			std::shared_ptr<T> rtn = std::make_shared<T>();

			rtn->m_entity = m_self;
			rtn->on_initialize();
			m_components.push_back(rtn);

			return rtn;
		}

		/**
		* Retrieves a component of type T attached to the entity.
		* tparam T The type of the component to retrieve.
		* return A shared pointer to the component.
		* throws std::runtime_error If the component is not found.
		*/
		template <typename T>
		std::shared_ptr<T> get_component()
		{
			for (size_t ci = 0; ci < m_components.size(); ++ci)
			{
				std::shared_ptr<T> rtn = std::dynamic_pointer_cast<T>(m_components.at(ci));
				if (rtn) return rtn;
			}
			throw std::runtime_error("Failed to find component");
		}

		
		/**
		* Retrieves the Core instance to which this entity belongs.
		* return A shared pointer to the Core.
		*/
		std::shared_ptr<Core> getCore();
		

	private:
		friend struct bolt::Core; ///< Grants core struct access to its private members
		std::weak_ptr<Core> m_core; ///< Weak pointer to the Core managing this entity.
		std::weak_ptr<Entity>m_self; ///< Weak pointer to this entity instance.
		std::vector<std::shared_ptr<Component> > m_components; ///< List of components attached to this entity.
		
		/**
		 * Internal function to update the entity each frame. Not intended for overriding.
		 */
		void tick();

		/**
		* brief Internal function to render the entity each frame. Not intended for overriding.
		*/
		void render();

		void gui();
		
	};
}

