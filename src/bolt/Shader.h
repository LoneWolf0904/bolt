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
		friend struct bolt::Renderer;
		std::shared_ptr<rend::Shader> m_shader;
		//rend::Shader m_shader;
	};
	

}