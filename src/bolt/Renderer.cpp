#include "Renderer.h"
#include "Transform.h"
#include "Entity.h"
#include "Texture.h"
#include "Model.h"
#include "Core.h"
#include "Resources.h"
#include "Shader.h"
#include "Mesh.h"

namespace bolt
{
	void Renderer::on_render()
	{
		if (!m_texture)
		{
			return;
		}

		rend::mat4 model(1.0f);

		model = getEntity()->get_component<Transform>()->model();
		
		m_shader->m_shader->projection(rend::perspective(45.0f, 1.0f, 0.1f, 100.0f));
		m_shader->m_shader->model(model);
		m_shader->m_shader->model(*m_model->m_model);
		//m_shader->m_shader->uniform("u_Texture", *m_texture->m_texture);
		m_shader->m_shader->render();
	}

	void Renderer::onInitialize()
	{
		m_mesh = getEntity()->getCore()->get_resources()->load<Mesh>("textures/curuthers/curuthers");
	}

	void Renderer::setShader(std::shared_ptr<Shader> shader)
	{
		m_shader = shader;
	}

	void Renderer::setModel(std::shared_ptr<Model> model)
	{
		m_model = model;
	}

	void Renderer::setMesh(std::shared_ptr<Mesh> mesh)
	{
		m_mesh = mesh;
	}

	void Renderer::setTexture(std::shared_ptr<Texture> texture)
	{
		m_texture = texture;
	}


}