#include <iostream>
#include "Resources.h"
#include <rend/rend.h>

namespace bolt
{
	struct Texture : Resource
	{
		void onLoad();

	private:
		std::shared_ptr<rend::Texture> m_texture;
	};
}
