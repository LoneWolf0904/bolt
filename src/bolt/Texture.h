
#include <iostream>
#include <rend/rend.h>
#include "Resource.h"

namespace bolt
{
	struct TriangleRenderer;
	struct Renderer;

	struct Texture : Resource
	{
		void onLoad();

	private:
		friend struct TriangleRenderer;
		friend struct Renderer;
		std::shared_ptr<rend::Texture> m_texture;
	};
}
