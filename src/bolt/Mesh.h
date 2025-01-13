#include <iostream>
#include <rend/rend.h>
#include "Resource.h"

namespace bolt
{
	struct Renderer;

	struct Mesh : Resource
	{
		void onLoad();

	private:
		friend struct Renderer;
		std::shared_ptr<rend::Mesh> m_mesh;
	};
}