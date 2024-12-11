#include <iostream>
#include "Component.h"
#include <gl/glew.h>
#include <rend/rend.h>

namespace bolt
{
	struct Texture;
	struct TriangleRenderer : Component
	{
	
		void on_initialize();
		void set_texture(std::shared_ptr<Texture> _texture);
	private:
		rend::Mesh m_mesh;
		std::shared_ptr<Texture> m_texture;
		rend::Shader m_shader;
		void on_render();
		
	};
}