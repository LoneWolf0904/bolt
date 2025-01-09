
#include <iostream>
#include <vector>

namespace bolt
{
	struct Core;
	struct Keyboard
	{
	public:
		bool isKey(int key);
		bool isKeyPressed(int key);
		bool isKeyReleased(int key);

	private:
		friend struct bolt::Core;
		std::vector<int> keys;
		std::vector<int> pressedKeys;
		std::vector<int> releasedKeys;

	};
}
