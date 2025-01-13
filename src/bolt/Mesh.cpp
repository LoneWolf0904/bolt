#include "Mesh.h"
#include <cstring>

namespace bolt
{
	void Mesh::onLoad()
	{
		m_mesh = std::make_shared<rend::Mesh>();
	}

}