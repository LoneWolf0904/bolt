#include "Shader.h"
#include <cstring>

namespace bolt
{
	void Shader::onLoad()
	{
		m_shader = std::make_shared<rend::ModelShader>();
		//m_shader->load(std::string(getPath() + ".vert").c_str(), std::string(getPath() + ".frag").c_str());*/

		//m_shader->load(rend::TEXTURE_SHADER);
		
	}
	
}