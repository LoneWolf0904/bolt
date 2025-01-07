#include <memory>
#include <vector>
#include <stdexcept>


namespace bolt
{
	struct Core;
	struct Component;

	struct Entity
	{
		//static std::shared_ptr<Core> initialize;
		template <typename T>
		std::shared_ptr<T> add_component()
		{
			std::shared_ptr<T> rtn = std::make_shared<T>();

			rtn->m_entity = m_self;
			rtn->on_initialize();
			m_components.push_back(rtn);

			return rtn;
		}

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

		

		std::shared_ptr<Core> getCore();
		//std::shared_ptr<Transform> getTransform();

	private:
		friend struct bolt::Core;
		std::weak_ptr<Core> m_core;
		std::weak_ptr<Entity>m_self;
		std::vector<std::shared_ptr<Component> > m_components;
		//std::shared_ptr<Transform> m_transform;

		void tick();
		void render();
		
	};
}

