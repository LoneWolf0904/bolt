#include "TriangleRenderer.h"

namespace bolt
{
	void TriangleRenderer::on_render()
	{
		printf("Rendering\n");

		m_shader.attribute("a_Position", *m_mesh.positions());
		m_shader.attribute("a_TexCoord", *m_mesh.texcoords());
		m_shader.uniform("u_Projection", rend::perspective(45.0f, 1.0f, 0.1f, 100.0f));
		m_shader.uniform("u_Model", rend::translate(rend::mat4(1.0f), rend::vec3(0.0f, 0.0f, -5.0f)));
		m_shader.render();
	}

	void TriangleRenderer::on_initialize()
	{
		m_mesh = rend::Mesh(rend::TRIANGLE_MESH);


	}
}
