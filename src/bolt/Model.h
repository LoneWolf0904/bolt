#include <iostream>
#include "Resource.h"
#include <rend/rend.h>

namespace bolt
{
	struct Model : Resource
	{
		void onLoad();

	private:
		std::shared_ptr<rend::Model> m_model;
	};
}