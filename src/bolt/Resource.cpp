#include "Resource.h"

namespace bolt
{
	/*virtual void Resource::onLoad()
	{

	}*/

	std::string Resource::getPath() const
	{
		return m_path;
	}

	void Resource::load()
	{
		onLoad();
	}
}