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
		// Check if texture is available, if not return
		if (!m_texture)
		{
			return;
		}

		// Create an identity matrix for model transformation
		rend::mat4 model(1.0f);

		// Get model matrix from entities transform
		model = getEntity()->get_component<Transform>()->model();
		
		// Apply projection and model transformations using the shader
		m_shader->m_shader->projection(rend::perspective(45.0f, 1.0f, 0.1f, 100.0f));
		m_shader->m_shader->model(model);
		m_shader->m_shader->model(*m_model->m_model);
		//m_shader->m_shader->uniform("u_Texture", *m_texture->m_texture);

		// Execute the render call using shader
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