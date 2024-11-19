#include <memory>
#include <vector>
#include "Resources.h"

namespace bolt
{
	struct Entity;
	struct Window;

	struct Core //: std::enable_shared_from_this<Core> junky
	{
		static std::shared_ptr<Core> initialize();
		void start();
		std::shared_ptr<Entity> add_entity();
		std::shared_ptr<Window> window() const;
		void update();
	private:
		std::shared_ptr<Window> m_window;
		std::vector<std::shared_ptr<Entity> > m_entities;
		std::weak_ptr<Core> m_self;
		bool m_running;
	};

	
}






