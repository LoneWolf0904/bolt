#include "Model.h"

namespace bolt
{
	void Model::onLoad()
	{
		//TODO
		m_model = std::make_shared < rend::Model>(std::string(getPath() + ".obj").c_str());
	}
}