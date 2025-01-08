#include "Component.h"
#include <rend/rend.h>

namespace bolt
{
	struct Texture;
	struct Shader;

	struct Renderer : Component
	{
		void onInitialize();
		void setTexture(std::shared_ptr<Texture> tex);

	private:
		void onDisplay();

		std::shared_ptr<Texture> m_texture;
		std::shared_ptr<Shader> m_shader;
	};
}