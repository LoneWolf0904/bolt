#pragma once
#include <string>


namespace bolt
{
	struct Resource
	{
		virtual void onLoad() {};
		std::string getPath() const;

	private:
		friend struct Resources;
		std::string m_path;
		void load();
	};
}

