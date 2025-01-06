#include "TriangleRenderer.h"
#include "Entity.h"
#include "Transform.h"
#include "Texture.h"
#include <stdexcept>

namespace bolt
{

	void TriangleRenderer::on_render()
	{
		//printf("Rendering\n");

		if (!m_texture) return;

		glm::mat4 model(1.0f);
		model = getEntity()->get_component<Transform>()->model();

		m_shader.attribute("a_Position", *m_mesh.positions());
		m_shader.attribute("a_TexCoord", *m_mesh.texcoords());
		m_shader.uniform("u_Projection", rend::perspective(45.0f, 1.0f, 0.1f, 100.0f));
		m_shader.uniform("u_Model", model);
		m_shader.uniform("u_Texture", *m_texture->m_texture);
		m_shader.render();
	}

	void TriangleRenderer::on_initialize()
	{
		m_mesh = rend::Mesh(rend::TRIANGLE_MESH);


	}

	void TriangleRenderer::set_texture(std::shared_ptr<Texture> _texture)
	{
		m_texture = _texture;
	}
}
