#include <iostream>
#include <rend/rend.h>
#include "Resource.h"

namespace bolt
{
	struct TriangleRenderer;

	struct Texture : Resource
	{
		void onLoad();

	private:
		friend struct bolt::TriangleRenderer;
		std::shared_ptr<rend::Texture> m_texture;
	};
}
