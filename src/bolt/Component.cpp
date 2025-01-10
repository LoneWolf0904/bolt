#include "Component.h"

namespace bolt
{
	void Component::on_initialize(){}
	void Component::on_tick(){}
	void Component::on_render(){}
	void Component::on_gui(){}

	std::shared_ptr<Entity> Component::getEntity()
	{
		return m_entity.lock();
	}

	void Component::tick()
	{
		on_tick();
	}

	void Component::render()
	{
		on_render();
	}

	void Component::gui()
	{
		on_gui();
	}
}