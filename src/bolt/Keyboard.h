#include <iostream>
#include <vector>

namespace bolt
{
	struct Keyboard
	{
	public:
		void isKey(int key);
		bool isKeyPressed(int key);
		bool isKeyReleased(int key);

	private:
		std::vector<int> keys;
		std::vector<int> pressedKeys;
		std::vector<int> releasedKeys;

	};
}
