
#include <iostream>
#include "Resource.h"
#include <rend/rend.h>

namespace bolt
{
	struct Renderer;
	struct Model : Resource
	{
		void onLoad();

	private:
		friend struct Renderer;
		std::shared_ptr<rend::Model> m_model;
	};
}