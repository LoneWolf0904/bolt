
#include <iostream>
#include <rend/rend.h>
#include "Resource.h"

namespace bolt
{
	struct Renderer;

	struct Shader : Resource
	{
		void onLoad();

	private:
		friend struct Renderer;
		std::shared_ptr<rend::ModelShader> m_shader;
		//rend::Shader m_shader;
	};
	

}