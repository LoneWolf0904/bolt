#include "Renderer.h"
#include "Transform.h"
#include "Entity.h"
#include "Texture.h"
#include "Model.h"
#include "Core.h"
#include "Resources.h"
#include "Shader.h"

namespace bolt
{
	void Renderer::onDisplay()
	{
		if (!m_texture)
		{
			return;
		}

		rend::mat4 model(1.0f);

		model = getEntity()->get_component<Transform>()->model();
		m_shader->m_shader->attribute("a_Position", *m_mesh->m_model->getMesh()->positions());
		m_shader->m_shader->attribute("a_TexCoord", *m_mesh->m_model->getMesh()->texcoords());
		m_shader->m_shader->uniform("u_Projection", rend::perspective(45.0f, 1.0f, 0.1f, 100.0f));
		m_shader->m_shader->uniform("u_Model", model);
		m_shader->m_shader->uniform("u_Texture", *m_texture->m_texture);
		m_shader->m_shader->render();
	}

	void Renderer::onInitialize()
	{
		m_mesh = getEntity()->getCore()->get_resources()->load<Model>("models/default");
	}

	void Renderer::setShader(std::shared_ptr<Shader> shader)
	{
		m_shader = shader;
	}

	void Renderer::setModel(std::shared_ptr<Model> model)
	{
		m_mesh = model;
	}

	void Renderer::setTexture(std::shared_ptr<Texture> texture)
	{
		m_texture = texture;
	}
}