#include <iostream>
#include "Component.h"
#include <gl/glew.h>
#include <rend/rend.h>

namespace bolt
{
	struct TriangleRenderer : Component
	{
	
		void on_initialize();
	private:
		rend::Mesh m_mesh;
		rend::Shader m_shader;
		void on_render();
		
	};
}