
#include "Component.h"
#include <rend/rend.h>

namespace bolt
{
	struct Texture;
	struct Shader;
	struct Model;
	struct Mesh;

	// Handles rendering of a model
	struct Renderer : Component
	{
		// Initializes the renderer
		void onInitialize();

		// Sets the texture for the model
		void setTexture(std::shared_ptr<Texture> texture);

		// Sets the shader for the model
		void setShader(std::shared_ptr<Shader> shader);

		// Sets the model to be rendered
		void setModel(std::shared_ptr<Model> model);
		void setMesh(std::shared_ptr<Mesh> mesh);

	private:
		// Handles actual rendering process
		void on_render();

		std::shared_ptr<Texture> m_texture;
		std::shared_ptr<Shader> m_shader;
		std::shared_ptr<Model> m_model;
		std::shared_ptr<Mesh> m_mesh;
	};
}