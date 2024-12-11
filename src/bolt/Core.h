#include <memory>
#include <vector>

namespace bolt
{
	struct Keyboard;
	struct Entity;
	struct Window;
	struct Resources;

	struct Core //: std::enable_shared_from_this<Core> junky
	{
		static std::shared_ptr<Core> initialize();
		void start();
		std::shared_ptr<Entity> add_entity();
		std::shared_ptr<Window> window() const;
		void update();
		std::shared_ptr<Keyboard> getKeyboard();
		std::shared_ptr<Resources> get_resources();
	private:
		std::shared_ptr<Window> m_window;
		std::vector<std::shared_ptr<Entity> > m_entities;
		std::weak_ptr<Core> m_self;
		std::shared_ptr<Keyboard> m_keyboard;
		std::shared_ptr<Resources> m_resources;

		bool m_running;
	};

	
}






