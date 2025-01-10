
#include "Component.h"
#include <rend/rend.h>

namespace bolt
{
	struct Texture;
	struct Shader;
	struct Model;
	struct Mesh;

	struct Renderer : Component
	{
		void onInitialize();
		void setTexture(std::shared_ptr<Texture> texture);
		void setShader(std::shared_ptr<Shader> shader);
		void setModel(std::shared_ptr<Model> model);
		void setMesh(std::shared_ptr<Mesh> mesh);

	private:
		void onDisplay();

		std::shared_ptr<Texture> m_texture;
		std::shared_ptr<Shader> m_shader;
		std::shared_ptr<Model> m_model;
		std::shared_ptr<Mesh> m_mesh;
	};
}