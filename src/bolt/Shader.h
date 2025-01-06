#include <iostream>
#include <rend/rend.h>
#include "Resource.h"

namespace bolt
{
	struct Shader : Resource
	{
		void onLoad();

	private:
		std::shared_ptr<rend::Shader> m_shader;
	};
	

}