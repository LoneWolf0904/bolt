#pragma once
#include <memory>

namespace bolt
{

	struct Entity;

	/**
	 * class Component
	 * Represents a base class for all components that can be attached to an entity.
	 */
	struct Component
	{
		/**
		 * Called when the component is initialized.
		 * Override this function in derived classes for custom initialization behavior.
		 */
		virtual void on_initialize();

		/**
		 * Called every frame to update the component.
		 * Override this function in derived classes for custom tick behavior.
		 */
		virtual void on_tick();

		/**
		* Called every frame to render the component.
		* Override this function in derived classes for custom rendering behavior.
		*/
		virtual void on_render();
		virtual void on_gui();

		/**
		 * Retrieves the entity to which this component is attached.
		 * return A shared pointer to the owning Entity.
		 */
		std::shared_ptr<Entity> getEntity();

	private:
		friend struct bolt::Entity;		///< Grants the Entity struct access to private members
		std::weak_ptr<Entity> m_entity; ///< Weak pointer to the owning entity.

		/**
		 * Internal function for ticking the component. Not intended for overriding.
		 */
		void tick();

		/**
	    * Internal function for rendering the component. Not intended for overriding.
	    */
		void render();
		void gui();
	};
}