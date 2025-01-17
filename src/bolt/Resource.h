#pragma once
#include <string>


namespace bolt
{

	// Represents the assets that can be loaded
	struct Resource
	{
		// function to load the resources, it's virtual so that it can be overloaded when derived
		virtual void onLoad() {};

		// gets the file path of the assets
		std::string getPath() const;

	private:
		friend struct Resources;
		std::string m_path;

		// Calls onLoad() function
		void load();
	};
}

