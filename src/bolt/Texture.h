#include <iostream>
#include <rend/rend.h>
#include "Resource.h"

namespace bolt
{
	struct Resource;

	struct Texture : Resource
	{
		void onLoad();

	private:
		std::shared_ptr<rend::Texture> m_texture;
	};
}
