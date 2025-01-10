#pragma once
#include <memory>

namespace bolt
{

	struct Entity;
	struct Component
	{
		virtual void on_initialize();
		virtual void on_tick();
		virtual void on_render();
		virtual void on_gui();
		std::shared_ptr<Entity> getEntity();

	private:
		friend struct bolt::Entity;
		std::weak_ptr<Entity> m_entity;
		void tick();
		void render();
		void gui();
	};
}